/*******************************************************************************************
*
*   rcamera - Basic camera system for multiple camera modes
*
*   CONFIGURATION:
*
*   #define CAMERA_IMPLEMENTATION
*       Generates the implementation of the library into the included file.
*       If not defined, the library is in header only mode and can be included in other headers
*       or source files without problems. But only ONE file should hold the implementation.
*
*   #define CAMERA_STANDALONE
*       If defined, the library can be used as standalone as a camera system but some
*       functions must be redefined to manage inputs accordingly.
*
*   CONTRIBUTORS:
*       Ramon Santamaria:   Supervision, review, update and maintenance
*       Christoph Wagner:   Redesign (2022)
*       Marc Palau:         Initial implementation (2014)
*
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2015-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#ifndef RCAMERA_H
#define RCAMERA_H

// The only dependency // TODO review standalone mode
#include "raymath.h"

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
//...
#if defined(CAMERA_STANDALONE)
#define CAMERA_CULL_DISTANCE_NEAR 0.01
#define CAMERA_CULL_DISTANCE_FAR 1000.0
#else
#define CAMERA_CULL_DISTANCE_NEAR  RL_CULL_DISTANCE_NEAR
#define CAMERA_CULL_DISTANCE_FAR  RL_CULL_DISTANCE_FAR
#endif

//----------------------------------------------------------------------------------
// Types and Structures Definition
// NOTE: Below types are required for CAMERA_STANDALONE usage
//----------------------------------------------------------------------------------
// TODO review
#if defined(CAMERA_STANDALONE)
    // Vector2 type
    typedef struct Vector2 {
        float x;
        float y;
    } Vector2;

    // Vector3 type
    typedef struct Vector3 {
        float x;
        float y;
        float z;
    } Vector3;

    // Camera type, defines a camera position/orientation in 3d space
    typedef struct Camera3D {
        Vector3 position;       // Camera position
        Vector3 target;         // Camera target it looks-at
        Vector3 up;             // Camera up vector (rotation over its axis)
        float fovy;             // Camera field-of-view apperture in Y (degrees) in perspective, used as near plane width in orthographic
        int type;               // Camera type, defines projection type: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC
    } Camera3D;

    // Camera system modes
    typedef enum {
        CAMERA_CUSTOM = 0,
        CAMERA_FREE,
        CAMERA_ORBITAL,
        CAMERA_FIRST_PERSON,
        CAMERA_THIRD_PERSON
    } CameraMode;

    // Camera projection modes
    typedef enum {
        CAMERA_PERSPECTIVE = 0,
        CAMERA_ORTHOGRAPHIC
    } CameraProjection;
#endif

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

#if defined(CAMERA_STANDALONE)
void SetCameraMode(Camera3D* camera, int mode);
Vector3 GetCameraForward(Camera3D* camera);
Vector3 GetCameraUp(Camera3D* camera);
Vector3 GetCameraRight(Camera3D* camera);
void CameraMoveForward(Camera3D* camera, float distance);
void CameraMoveUp(Camera3D* camera, float distance);
void CameraMoveRight(Camera3D* camera, float distance);
void CameraZoom(Camera3D* camera, float delta);
void CameraYaw(Camera3D* camera, float angle);
void CameraPitch(Camera3D* camera, float angle);
void CameraRoll(Camera3D* camera, float angle);
void CameraViewBobbing(Camera3D* camera);
Matrix GetCameraViewMatrix(Camera3D* camera);
Matrix GetCameraProjectionMatrix(Camera3D* camera, float aspect);
#endif

#if defined(__cplusplus)
}
#endif

#endif // CAMERA_H


/***********************************************************************************
*
*   CAMERA IMPLEMENTATION
*
************************************************************************************/

#if defined(CAMERA_IMPLEMENTATION)

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------

#define CAMERA_MOVE_SPEED                               0.09f
#define CAMERA_ROTATION_SPEED                           0.03f

// Camera mouse movement sensitivity
#define CAMERA_MOUSE_MOVE_SENSITIVITY                   0.5f    // TODO: it should be independant of framerate
#define CAMERA_MOUSE_SCROLL_SENSITIVITY                 1.5f

#define CAMERA_ORBITAL_SPEED                            0.01f       // Radians per frame


// When walking, y-position of the player moves up-down at step frequency (swinging) but
// also the body slightly tilts left-right on every step, when all the body weight is left over one foot (tilting)
#define CAMERA_FIRST_PERSON_STEP_FREQUENCY               1.8f       // Step frequency when walking (steps per second)
#define CAMERA_FIRST_PERSON_SWINGING_DELTA               0.03f      // Maximum up-down swinging distance when walking
#define CAMERA_FIRST_PERSON_TILTING_DELTA                0.005f     // Maximum left-right tilting distance when walking

// PLAYER (used by camera)
#define PLAYER_MOVEMENT_SENSITIVITY                     2.0f

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
// TODO review
// Camera actions
//typedef enum {
//    CAMERA_MOVE_FORWARD = 0,
//    CAMERA_MOVE_BACK,
//    CAMERA_MOVE_RIGHT,
//    CAMERA_MOVE_LEFT,
//    CAMERA_MOVE_UP,
//    CAMERA_MOVE_DOWN,
//    CAMERA_YAW_RIGHT,
//    CAMERA_YAW_LEFT,
//    CAMERA_PITCH_UP,
//    CAMERA_PITCH_DOWN,
//    CAMERA_ROLL_RIGHT,
//    CAMERA_ROLL_LEFT,
//} CameraActions;


//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Module specific Functions Declaration
//----------------------------------------------------------------------------------

// Rotates the given vector around the given axis
// Note: angle must be provided in radians
Vector3 Vector3RotateAxis(Vector3 v, Vector3 axis, float angle) { // TODO there is a better way without the intermediate matrix
    Matrix rot = MatrixRotate(axis, angle);
    return Vector3Transform(v, rot);
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------

// Select camera mode (multiple camera modes available)
void SetCameraMode(Camera3D *camera, int mode)
{
    camera->mode = mode;

    // Reset roll
    camera->up = (Vector3){ 0.0f, 1.0f, 0.0f };

    // Enable view bobbing in CAMERA_FIRST_PERSON
    if (camera->mode == CAMERA_FIRST_PERSON)
    {
        camera->swingCounter = 1; // Enable
    }
    else
    {
        camera->swingCounter = 0; // Disable
    }

    // Catch cursor
#ifndef CAMERA_STANDALONE
    // Note: This is engine specific functionality
    DisableCursor();
#endif
}

// Returns the cameras forward vector (normalized)
Vector3 GetCameraForward(Camera3D *camera)
{
    return Vector3Normalize(Vector3Subtract(camera->target, camera->position));
}

// Returns the cameras up vector (normalized)
// Note: The up vector might not be perpendicular to the forward vector
Vector3 GetCameraUp(Camera3D *camera)
{
    return Vector3Normalize(camera->up);
}

// Returns the cameras right vector (normalized)
Vector3 GetCameraRight(Camera3D *camera)
{
    Vector3 forward = GetCameraForward(camera);
    Vector3 up = GetCameraUp(camera);
    return Vector3CrossProduct(forward, up);
}

// Moves the camera in its forward direction
void CameraMoveForward(Camera3D *camera, float distance)
{
    Vector3 forward = GetCameraForward(camera);

    if (camera->mode == CAMERA_FIRST_PERSON ||
        camera->mode == CAMERA_THIRD_PERSON)
    {
        // Project vector onto world plane
        forward.y = 0;
        forward = Vector3Normalize(forward);
    }

    // Scale by distance
    forward = Vector3Scale(forward, distance);

    // Move position and target
    camera->position = Vector3Add(camera->position, forward);
    camera->target = Vector3Add(camera->target, forward);
}

// Moves the camera in its up direction
void CameraMoveUp(Camera3D *camera, float distance)
{
    Vector3 up = GetCameraUp(camera);
    
    // Scale by distance
    up = Vector3Scale(up, distance);

    // Move position and target
    camera->position = Vector3Add(camera->position, up);
    camera->target = Vector3Add(camera->target, up);
}

// Moves the camera target in its current right direction
void CameraMoveRight(Camera3D *camera, float distance)
{
    Vector3 right = GetCameraRight(camera);

    if (camera->mode == CAMERA_FIRST_PERSON ||
        camera->mode == CAMERA_THIRD_PERSON)
    {
        // Project vector onto world plane
        right.y = 0;
        right = Vector3Normalize(right);
    }

    // Scale by distance
    right = Vector3Scale(right, distance);

    // Move position and target
    camera->position = Vector3Add(camera->position, right);
    camera->target = Vector3Add(camera->target, right);
}

// Moves the camera position closer/farther to/from the camera target
void CameraZoom(Camera3D *camera, float delta)
{
    float distance = Vector3Distance(camera->position, camera->target);

    // Apply delta
    distance += delta;

    // Distance must be greater than 0
    if (distance < 0) distance = 0.001f;

    // Set new distance by moving the position along the forward vector
    Vector3 forward = GetCameraForward(camera);
    camera->position = Vector3Add(camera->target, Vector3Scale(forward, -distance));
}

// Rotates the camera around its up vector
// Yaw is "looking left and right"
// Note: angle must be provided in radians
void CameraYaw(Camera3D *camera, float angle)
{
    // Rotation axis
    Vector3 up = GetCameraUp(camera);

    // View vector
    Vector3 target_position = Vector3Subtract(camera->target, camera->position);

    // Rotate view vector around up axis
    target_position = Vector3RotateAxis(target_position, up, angle);

    if (camera->mode == CAMERA_FREE ||
        camera->mode == CAMERA_FIRST_PERSON)
    {
        // Move target relative to position
        camera->target = Vector3Add(camera->position, target_position);
    }
    else if (camera->mode == CAMERA_THIRD_PERSON ||
             camera->mode == CAMERA_ORBITAL)
    {
        // Move position relative to target
        camera->position = Vector3Subtract(camera->target, target_position);
    }
}

// Rotates the camera around its right vector
// Pitch is "looking up and down"
// Note: angle must be provided in radians
void CameraPitch(Camera3D *camera, float angle)
{
    // Up direction
    Vector3 up = GetCameraUp(camera);

    // View vector
    Vector3 target_position = Vector3Subtract(camera->target, camera->position);

    if (camera->mode == CAMERA_FIRST_PERSON ||
        camera->mode == CAMERA_THIRD_PERSON ||
        camera->mode == CAMERA_ORBITAL)
    {
        // In these camera modes we clamp the Pitch angle
        // to allow only viewing straight up or down.

        // Clamp view up
        float max_angle_up = Vector3Angle(up, target_position);
        max_angle_up -= 0.001f; // avoid numerical errors
        if (angle > max_angle_up) angle = max_angle_up;

        // Clamp view down
        float max_angle_down = Vector3Angle(Vector3Negate(up), target_position);
        max_angle_down *= -1.0f; // downwards angle is negative
        max_angle_down += 0.001f; // avoid numerical errors
        if (angle < max_angle_down) angle = max_angle_down;
    }

    // Rotation axis
    Vector3 right = GetCameraRight(camera);

    // Rotate view vector around right axis
    target_position = Vector3RotateAxis(target_position, right, angle);

    if (camera->mode == CAMERA_FREE)
    {
        // Move target relative to position
        camera->target = Vector3Add(camera->position, target_position);

        // Rotate up direction around right axis
        camera->up = Vector3RotateAxis(camera->up, right, angle);
    }
    else if (camera->mode == CAMERA_FIRST_PERSON)
    {
        // Move target relative to position
        camera->target = Vector3Add(camera->position, target_position);
    }
    else if (camera->mode == CAMERA_THIRD_PERSON ||
             camera->mode == CAMERA_ORBITAL)
    {
        // Move position relative to target
        camera->position = Vector3Subtract(camera->target, target_position);
    }
}

// Rotates the camera around its forward vector
// Roll is "turning your head sideways to the left or right"
// Note: angle must be provided in radians
void CameraRoll(Camera3D *camera, float angle)
{
    // Rotation axis
    Vector3 forward = GetCameraForward(camera);

    // Rotate up direction around forward axis
    camera->up = Vector3RotateAxis(camera->up, forward, angle);
}

// Moves camera slightly to simulate a walking motion
// Note: Only active if camera->swingCounter > 0
void CameraViewBobbing(Camera3D* camera)
{
    if (camera->swingCounter > 0)
    {
        // NOTE: We delay the target movement relative to the position movement to create a little pitch with each step.
        camera->position.y = camera->position.y - 0.25f * sinf((camera->swingCounter + 1) / CAMERA_FIRST_PERSON_STEP_TRIGONOMETRIC_DIVIDER) / CAMERA_FIRST_PERSON_STEP_DIVIDER;
        camera->target.y = camera->target.y - 0.25f * sinf((camera->swingCounter - 1) / CAMERA_FIRST_PERSON_STEP_TRIGONOMETRIC_DIVIDER) / CAMERA_FIRST_PERSON_STEP_DIVIDER;

        // Update counter for next frame
        camera->swingCounter %= 2147483647 /* INT_MAX */; // Counter must be positive
        camera->swingCounter++;
    }
}

// Returns the camera view matrix
Matrix GetCameraViewMatrix(Camera3D *camera)
{
    return MatrixLookAt(camera->position, camera->target, camera->up);
}

// Returns the camera projection matrix
Matrix GetCameraProjectionMatrix(Camera3D *camera, float aspect)
{
    if (camera->projection == CAMERA_PERSPECTIVE)
    {
        return MatrixPerspective(camera->fovy * DEG2RAD, aspect, CAMERA_CULL_DISTANCE_NEAR, CAMERA_CULL_DISTANCE_FAR);
    }
    else if (camera->projection == CAMERA_ORTHOGRAPHIC)
    {
        double top = camera->fovy / 2.0;
        double right = top * aspect;
        return MatrixOrtho(-right, right, -top, top, CAMERA_CULL_DISTANCE_NEAR, CAMERA_CULL_DISTANCE_FAR);
    }
    
    return MatrixIdentity();
}


#ifndef CAMERA_STANDALONE

static int init_frames = 3; // TODO review and remove

// Update camera position for selected mode
void UpdateCamera(Camera3D *camera)
{
    // Avoid inital mouse "jump"
    if (init_frames > 0) {
        SetMousePosition(0, 0);
        init_frames--;
        return;
    }
    Vector2 mousePositionDelta = GetMouseDelta();
    
    // Camera movement
    if (IsKeyDown(KEY_W)) CameraMoveForward(camera, CAMERA_MOVE_SPEED);
    if (IsKeyDown(KEY_S)) CameraMoveForward(camera, -CAMERA_MOVE_SPEED);
    if (IsKeyDown(KEY_D)) CameraMoveRight(camera, CAMERA_MOVE_SPEED);
    if (IsKeyDown(KEY_A)) CameraMoveRight(camera, -CAMERA_MOVE_SPEED);
    if (IsKeyDown(KEY_SPACE)) CameraMoveUp(camera, CAMERA_MOVE_SPEED);
    if (IsKeyDown(KEY_LEFT_CONTROL)) CameraMoveUp(camera, -CAMERA_MOVE_SPEED);

    // Camera rotation
    if (IsKeyDown(KEY_DOWN)) CameraPitch(camera, -CAMERA_ROTATION_SPEED);
    if (IsKeyDown(KEY_UP)) CameraPitch(camera, CAMERA_ROTATION_SPEED);
    if (IsKeyDown(KEY_RIGHT)) CameraYaw(camera, -CAMERA_ROTATION_SPEED);
    if (IsKeyDown(KEY_LEFT)) CameraYaw(camera, CAMERA_ROTATION_SPEED);
    if (IsKeyDown(KEY_Q)) CameraRoll(camera, -CAMERA_ROTATION_SPEED);
    if (IsKeyDown(KEY_E)) CameraRoll(camera, CAMERA_ROTATION_SPEED);

    CameraYaw(camera, mousePositionDelta.x * -CAMERA_MOUSE_MOVE_SENSITIVITY);
    CameraPitch(camera, mousePositionDelta.y * -CAMERA_MOUSE_MOVE_SENSITIVITY);

    // Zoom target distance
    CameraZoom(camera, -GetMouseWheelMove());
    if (IsKeyPressed(KEY_KP_SUBTRACT)) CameraZoom(camera, 2.0f);
    if (IsKeyPressed(KEY_KP_ADD)) CameraZoom(camera, -2.0f);

    // Switch camera mode
    if (IsKeyPressed(KEY_ONE)) SetCameraMode(camera, CAMERA_FREE);
    if (IsKeyPressed(KEY_TWO)) SetCameraMode(camera, CAMERA_FIRST_PERSON);
    if (IsKeyPressed(KEY_THREE)) SetCameraMode(camera, CAMERA_THIRD_PERSON);
    if (IsKeyPressed(KEY_FOUR)) SetCameraMode(camera, CAMERA_ORBITAL);

    // Switch camera projection
    if (IsKeyPressed(KEY_P)) {
        if (camera->projection == CAMERA_PERSPECTIVE) {
            // Create isometric view
            camera->mode = CAMERA_THIRD_PERSON;
            // Note: The target distance is related to the render distance in the orthographic projection
            camera->position = (Vector3){ 0.0f, 2.0f, -100.0f };
            camera->target = (Vector3){ 0.0f, 2.0f, 0.0f };
            camera->up = (Vector3){ 0.0f, 1.0f, 0.0f };
            camera->projection = CAMERA_ORTHOGRAPHIC;
            camera->fovy = 20.0f; // near plane width in CAMERA_ORTHOGRAPHIC
            CameraYaw(camera, -135 * DEG2RAD);
            CameraPitch(camera, -45 * DEG2RAD);
        }
        else if (camera->projection == CAMERA_ORTHOGRAPHIC)
        {
            // Reset to default view
             camera->mode = CAMERA_THIRD_PERSON;
            // Note: The target distance is related to the render distance in the orthographic projection
            camera->position = (Vector3){ 0.0f, 2.0f, 10.0f };
            camera->target = (Vector3){ 0.0f, 2.0f, 0.0f };
            camera->up = (Vector3){ 0.0f, 1.0f, 0.0f };
            camera->projection = CAMERA_PERSPECTIVE;
            camera->fovy = 60.0f;
        }
    }

    // Apply view bobbing when moving around (per default only active in CAMERA_FIRST_PERSON)
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)) CameraViewBobbing(camera);
}

#endif // !CAMERA_STANDALONE


#endif // CAMERA_IMPLEMENTATION
