const std = @import("std");

// This has been tested to work with zig master branch as of commit 87de821 or May 14 2023
pub fn addRaylib(b: *std.Build, target: std.zig.CrossTarget, optimize: std.builtin.OptimizeMode, options: Options) *std.Build.CompileStep {
    const raylib_flags = &[_][]const u8{
        "-std=gnu99",
        "-D_GNU_SOURCE",
        "-DGL_SILENCE_DEPRECATION=199309L",
        "-fno-sanitize=undefined", // https://github.com/raysan5/raylib/issues/1891
    };

    const raylib = b.addStaticLibrary(.{
        .name = "raylib",
        .target = target,
        .optimize = optimize,
    });
    raylib.linkLibC();

    raylib.addIncludePath(srcdir ++ "/external/glfw/include");

    raylib.addCSourceFiles(&.{
        srcdir ++ "/raudio.c",
        srcdir ++ "/rcore.c",
        srcdir ++ "/rmodels.c",
        srcdir ++ "/rshapes.c",
        srcdir ++ "/rtext.c",
        srcdir ++ "/rtextures.c",
        srcdir ++ "/utils.c",
    }, raylib_flags);

    var gen_step = std.build.Step.WriteFile.create(b);
    raylib.step.dependOn(&gen_step.step);

    if (options.raygui) {
        _ = gen_step.add(srcdir ++ "/raygui.c", "#define RAYGUI_IMPLEMENTATION\n#include \"raygui.h\"\n");
        raylib.addCSourceFile(srcdir ++ "/raygui.c", raylib_flags);
        raylib.addIncludePath(srcdir ++ "/../../raygui/src");
    }

    if (options.raymath) {
        _ = gen_step.add(srcdir ++ "/raymath.c", "#define RAYMATH_IMPLEMENTATION\n#include \"raymath.h\"\n");
        raylib.addCSourceFile(srcdir ++ "/raymath.c", raylib_flags);
    }

    if (options.physac) {
        _ = gen_step.add(srcdir ++ "/physac.c", "#define PHYSAC_IMPLEMENTATION\n#include \"physac.h\"\n");
        raylib.addCSourceFile(srcdir ++ "/physac.c", raylib_flags);
        raylib.addIncludePath(srcdir ++ "/../../physac/src");
    }

    switch (target.getOsTag()) {
        .windows => {
            raylib.addCSourceFiles(&.{srcdir ++ "/rglfw.c"}, raylib_flags);
            raylib.linkSystemLibrary("winmm");
            raylib.linkSystemLibrary("gdi32");
            raylib.linkSystemLibrary("opengl32");
            raylib.addIncludePath("external/glfw/deps/mingw");

            raylib.defineCMacro("PLATFORM_DESKTOP", null);
        },
        .linux => {
            raylib.addCSourceFiles(&.{srcdir ++ "/rglfw.c"}, raylib_flags);
            raylib.linkSystemLibrary("GL");
            raylib.linkSystemLibrary("rt");
            raylib.linkSystemLibrary("dl");
            raylib.linkSystemLibrary("m");
            raylib.linkSystemLibrary("X11");
            raylib.addIncludePath("/usr/include");

            raylib.defineCMacro("PLATFORM_DESKTOP", null);
        },
        .freebsd, .openbsd, .netbsd, .dragonfly => {
            raylib.addCSourceFiles(&.{srcdir ++ "/rglfw.c"}, raylib_flags);
            raylib.linkSystemLibrary("GL");
            raylib.linkSystemLibrary("rt");
            raylib.linkSystemLibrary("dl");
            raylib.linkSystemLibrary("m");
            raylib.linkSystemLibrary("X11");
            raylib.linkSystemLibrary("Xrandr");
            raylib.linkSystemLibrary("Xinerama");
            raylib.linkSystemLibrary("Xi");
            raylib.linkSystemLibrary("Xxf86vm");
            raylib.linkSystemLibrary("Xcursor");

            raylib.defineCMacro("PLATFORM_DESKTOP", null);
        },
        .macos => {
            // On macos rglfw.c include Objective-C files.
            const raylib_flags_extra_macos = &[_][]const u8{
                "-ObjC",
            };
            raylib.addCSourceFiles(
                &.{srcdir ++ "/rglfw.c"},
                raylib_flags ++ raylib_flags_extra_macos,
            );
            raylib.linkFramework("Foundation");
            raylib.linkFramework("CoreServices");
            raylib.linkFramework("CoreGraphics");
            raylib.linkFramework("AppKit");
            raylib.linkFramework("IOKit");

            raylib.defineCMacro("PLATFORM_DESKTOP", null);
        },
        .emscripten => {
            raylib.defineCMacro("PLATFORM_WEB", null);
            raylib.defineCMacro("GRAPHICS_API_OPENGL_ES2", null);

            if (b.sysroot == null) {
                @panic("Pass '--sysroot \"$EMSDK/upstream/emscripten\"'");
            }

            const cache_include = std.fs.path.join(b.allocator, &.{ b.sysroot.?, "cache", "sysroot", "include" }) catch @panic("Out of memory");
            defer b.allocator.free(cache_include);

            var dir = std.fs.openDirAbsolute(cache_include, std.fs.Dir.OpenDirOptions{ .access_sub_paths = true, .no_follow = true }) catch @panic("No emscripten cache. Generate it!");
            dir.close();

            raylib.addIncludePath(cache_include);
        },
        else => {
            @panic("Unsupported OS");
        },
    }

    return raylib;
}

const Options = struct {
    raygui: bool = false,
    raymath: bool = false,
    physac: bool = false,
};

pub fn build(b: *std.Build) void {
    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = b.standardTargetOptions(.{});
    // Standard optimization options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall. Here we do not
    // set a preferred release mode, allowing the user to decide how to optimize.
    const optimize = b.standardOptimizeOption(.{});

    const raymath = b.option(bool, "raymath", "Compile with raymath support");
    const raygui = b.option(bool, "raygui", "Compile with raygui support");
    const physac = b.option(bool, "physac", "Compile with physac support");

    const lib = addRaylib(b, target, optimize, .{
        .raymath = raymath orelse false,
        .raygui = raygui orelse false,
        .physac = physac orelse false,
    });

    lib.installHeader("src/raylib.h", "raylib.h");

    if (raymath orelse false) {
        lib.installHeader("src/raymath.h", "raymath.h");
    }

    if (raygui orelse false) {
        lib.installHeader("../raygui/src/raygui.h", "raygui.h");
    }

    if (physac orelse false) {
        lib.installHeader("../physac/src/physac.h", "physac.h");
    }

    b.installArtifact(lib);
}

const srcdir = struct {
    fn getSrcDir() []const u8 {
        return std.fs.path.dirname(@src().file).?;
    }
}.getSrcDir();
