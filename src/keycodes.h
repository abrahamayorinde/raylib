#ifndef KEYCODES_H
#define KEYCODES_H
struct parse_key {
	char *name;
	unsigned int rawcode;
	unsigned int scancode;
} keynames[] = {

	{"KEY_RESERVED", 0, 0}, 
	{"KEY_ESC", 1, 256},
	{"KEY_1", 2, 49},
	{"KEY_2", 3, 50},
	{"KEY_3", 4, 51},
	{"KEY_4", 5, 52},
	{"KEY_5", 6, 53},
	{"KEY_6", 7, 54},
	{"KEY_7", 8, 55},
	{"KEY_8", 9, 56},
	{"KEY_9", 10, 57},
	{"KEY_0", 11, 48},
	{"KEY_MINUS", 12, 45},
	{"KEY_EQUAL", 13, 61},
	{"KEY_BACKSPACE", 14, 259},
	{"KEY_TAB", 15, 258},
	{"KEY_Q", 16, 81},
	{"KEY_W", 17, 87},
	{"KEY_E", 18, 69},
	{"KEY_R", 19, 82},
	{"KEY_T", 20, 84},
	{"KEY_Y", 21, 89},
	{"KEY_U", 22, 85},
	{"KEY_I", 23, 73},
	{"KEY_O", 24, 79},
	{"KEY_P", 25, 80},
	{"KEY_LEFTBRACE", 26, 91},
	{"KEY_RIGHTBRACE", 27, 93},
	{"KEY_ENTER", 28, 257},
	{"KEY_LEFTCTRL", 29, 341},
	{"KEY_A", 30, 65},
	{"KEY_S", 31, 83},
	{"KEY_D", 32, 68},
	{"KEY_F", 33, 70},
	{"KEY_G", 34, 71},
	{"KEY_H", 35, 72},
	{"KEY_J", 36, 74},
	{"KEY_K", 37, 75},
	{"KEY_L", 38, 76},
	{"KEY_SEMICOLON", 39, 59},
	{"KEY_APOSTROPHE", 40, 39},
	{"KEY_GRAVE", 41, 96},
	{"KEY_LEFTSHIFT", 42, 340},
	{"KEY_BACKSLASH", 43, 92},
	{"KEY_Z", 44, 90},
	{"KEY_X", 45, 88},
	{"KEY_C", 46, 67},
	{"KEY_V", 47, 86},
	{"KEY_B", 48, 66},
	{"KEY_N", 49, 78},
	{"KEY_M", 50, 77},
	{"KEY_COMMA", 51, 44},
	{"KEY_DOT", 52, 46},
	{"KEY_SLASH", 53, 47},
	{"KEY_RIGHTSHIFT", 54, 344},
	{"KEY_KPASTERISK", 55, 332},
	{"KEY_LEFTALT", 56, 342},
	{"KEY_SPACE", 57, 32},
	{"KEY_CAPSLOCK", 58, 280},
	{"KEY_F1", 59, 290},
	{"KEY_F2", 60, 291},
	{"KEY_F3", 61, 292},
	{"KEY_F4", 62, 293},
	{"KEY_F5", 63, 294},
	{"KEY_F6", 64, 295},
	{"KEY_F7", 65, 296},
	{"KEY_F8", 66, 297},
	{"KEY_F9", 67, 298},
	{"KEY_F10", 68, 299},
	{"KEY_NUMLOCK", 69, 282},
	{"KEY_SCROLLLOCK", 70, 281},
	{"KEY_KP7", 71, 327},
	{"KEY_KP8", 72, 328},
	{"KEY_KP9", 73, 329},
	{"KEY_KPMINUS", 74, 333},
	{"KEY_KP4", 75, 324},
	{"KEY_KP5", 76, 325},
	{"KEY_KP6", 77, 326},
	{"KEY_KPPLUS", 78, 334},
	{"KEY_KP1", 79, 321},
	{"KEY_KP2", 80, 322},
	{"KEY_KP3", 81, 323},
	{"KEY_KP0", 82, 320},
	{"KEY_KPDOT", 83, 330}, // [ ] Converte
	{"KEY_NULL",84, 0},  // KEY NOT ASSIGNRD
	{"KEY_ZENKAKUHANKAKU", 85, 85},
	{"KEY_102ND", 86, 86},
	{"KEY_F11", 87, 300},
	{"KEY_F12", 88, 301},
	{"KEY_RO", 89, 89},
	{"KEY_KATAKANA", 90, 90},
	{"KEY_HIRAGANA", 91, 91},
	{"KEY_HENKAN", 92, 92},
	{"KEY_KATAKANAHIRAGANA", 93, 93},
	{"KEY_MUHENKAN", 94, 94},
	{"KEY_KPJPCOMMA", 95, 95},
	{"KEY_KPENTER", 96, 335},
	{"KEY_RIGHTCTRL", 97, 345},
	{"KEY_KPSLASH", 98, 331},
	{"KEY_SYSRQ", 99, 283},
	{"KEY_RIGHTALT", 100, 346},
	{"KEY_LINEFEED", 101, 101},
	{"KEY_HOME", 102, 268},
	{"KEY_UP", 103, 265},
	{"KEY_PAGEUP", 104, 266},
	{"KEY_LEFT", 105, 263},
	{"KEY_RIGHT", 106, 262},
	{"KEY_END", 107, 269},
	{"KEY_DOWN", 108, 264},
	{"KEY_PAGEDOWN", 109, 267},
	{"KEY_INSERT", 110, 260},
	{"KEY_DELETE", 111, 261},
	{"KEY_MACRO", 112, 112},
	{"KEY_MUTE", 113, 113},
	{"KEY_VOLUMEDOWN", 114, 114},
	{"KEY_VOLUMEUP", 115, 115},
	{"KEY_POWER", 116, 116},
	{"KEY_KPEQUAL", 117, 117},
	{"KEY_KPPLUSMINUS", 118, 118},
	{"KEY_PAUSE", 119, 119},
	{"KEY_SCALE", 120, 120},
	{"KEY_KPCOMMA", 121, 121},
	{"KEY_HANGEUL", 122, 122},
	{"KEY_HANJA", 123, 123},
	{"KEY_YEN", 124, 124},
	{"KEY_LEFTMETA", 125, 125},
	{"KEY_RIGHTMETA", 126, 347},
	{"KEY_COMPOSE", 127, 127},
	{"KEY_STOP", 128, 128},
	{"KEY_AGAIN", 129, 129},
	{"KEY_PROPS", 130, 130},
	{"KEY_UNDO", 131, 131},
	{"KEY_FRONT", 132, 132},
	{"KEY_COPY", 133, 133},
	{"KEY_OPEN", 134, 134},
	{"KEY_PASTE", 135, 135},
	{"KEY_FIND", 136, 136},
	{"KEY_CUT", 137, 137},
	{"KEY_HELP", 138, 138},
	{"KEY_MENU", 139, 139},
	{"KEY_CALC", 140, 140},
	{"KEY_SETUP", 141, 141},
	{"KEY_SLEEP", 142, 142},
	{"KEY_WAKEUP", 143, 143},
	{"KEY_FILE", 144, 144},
	{"KEY_SENDFILE", 145, 145},
	{"KEY_DELETEFILE", 146, 146},
	{"KEY_XFER", 147, 147},
	{"KEY_PROG1", 148, 148},
	{"KEY_PROG2", 149, 149},
	{"KEY_WWW", 150, 150},
	{"KEY_MSDOS", 151, 151},
	{"KEY_SCREENLOCK", 152, 152},
	{"KEY_ROTATE_DISPLAY", 153, 153},
	{"KEY_CYCLEWINDOWS", 154, 154},
	{"KEY_MAIL", 155, 155},
	{"KEY_BOOKMARKS", 156, 156},
	{"KEY_COMPUTER", 157, 157},
	{"KEY_BACK", 158, 158},
	{"KEY_FORWARD", 159, 159},
	{"KEY_CLOSECD", 160, 160},
	{"KEY_EJECTCD", 161, 161},
	{"KEY_EJECTCLOSECD", 162, 162},
	{"KEY_NEXTSONG", 163, 163},
	{"KEY_PLAYPAUSE", 164, 164},
	{"KEY_PREVIOUSSONG", 165, 165},
	{"KEY_STOPCD", 166, 166},
	{"KEY_RECORD", 167, 167},
	{"KEY_REWIND", 168, 168},
	{"KEY_PHONE", 169, 169},
	{"KEY_ISO", 170, 170},
	{"KEY_CONFIG", 171, 171},
	{"KEY_HOMEPAGE", 172, 172},
	{"KEY_REFRESH", 173, 173},
	{"KEY_EXIT", 174, 174},
	{"KEY_MOVE", 175, 175},
	{"KEY_EDIT", 176, 176},
	{"KEY_SCROLLUP", 177, 177},
	{"KEY_SCROLLDOWN", 178, 178},
	{"KEY_KPLEFTPAREN", 179, 179},
	{"KEY_KPRIGHTPAREN", 180, 180},
	{"KEY_NEW", 181, 181},
	{"KEY_REDO", 182, 182},
	{"KEY_F13", 183, 183},
	{"KEY_F14", 184, 184},
	{"KEY_F15", 185, 185},
	{"KEY_F16", 186, 186},
	{"KEY_F17", 187, 187},
	{"KEY_F18", 188, 188},
	{"KEY_F19", 189, 189},
	{"KEY_F20", 190, 190},
	{"KEY_F21", 191, 191},
	{"KEY_F22", 192, 192},
	{"KEY_F23", 193, 193},
	{"KEY_F24", 194, 194},
	{"KEY_PLAYCD", 200, 200},
	{"KEY_PAUSECD", 201, 201},
	{"KEY_PROG3", 202, 202},
	{"KEY_PROG4", 203, 203},
	{"KEY_DASHBOARD", 204, 204},
	{"KEY_SUSPEND", 205, 205},
	{"KEY_CLOSE", 206, 206},
	{"KEY_PLAY", 207, 207},
	{"KEY_FASTFORWARD", 208, 208},
	{"KEY_BASSBOOST", 209, 209},
	{"KEY_PRINT", 210, 210},
	{"KEY_HP", 211, 211},
	{"KEY_CAMERA", 212, 212},
	{"KEY_SOUND", 213, 213},
	{"KEY_QUESTION", 214, 214},
	{"KEY_EMAIL", 215, 215},
	{"KEY_CHAT", 216, 216},
	{"KEY_SEARCH", 217, 217},
	{"KEY_CONNECT", 218, 218},
	{"KEY_FINANCE", 219, 219},
	{"KEY_SPORT", 220, 220},
	{"KEY_SHOP", 221, 221},
	{"KEY_ALTERASE", 222, 222},
	{"KEY_CANCEL", 223, 223},
	{"KEY_BRIGHTNESSDOWN", 224, 224},
	{"KEY_BRIGHTNESSUP", 225, 225},
	{"KEY_MEDIA", 226, 226},
	{"KEY_SWITCHVIDEOMODE", 227, 227},
	{"KEY_KBDILLUMTOGGLE", 228, 228},
	{"KEY_KBDILLUMDOWN", 229, 229},
	{"KEY_KBDILLUMUP", 230, 230},
	{"KEY_SEND", 231, 231},
	{"KEY_REPLY", 232, 232},
	{"KEY_FORWARDMAIL", 233, 233},
	{"KEY_SAVE", 234, 234},
	{"KEY_DOCUMENTS", 235, 235},
	{"KEY_BATTERY", 236, 236},
	{"KEY_BLUETOOTH", 237, 237},
	{"KEY_WLAN", 238, 238},
	{"KEY_UWB", 239, 239},
	{"KEY_UNKNOWN", 240, 240},
	{"KEY_VIDEO_NEXT", 241, 241},
	{"KEY_VIDEO_PREV", 242, 242},
	{"KEY_BRIGHTNESS_CYCLE", 243, 243},
	{"KEY_BRIGHTNESS_AUTO", 244, 244},
	{"KEY_DISPLAY_OFF", 245, 245},
	{"KEY_WWAN", 246, 246},
	{"KEY_RFKILL", 247, 247},
	{"KEY_MICMUTE", 248, 248},
	{"KEY_OK", 0x160, 0x160},
	{"KEY_SELECT", 0x161, 0x161},
	{"KEY_GOTO", 0x162, 0x162},
	{"KEY_CLEAR", 0x163, 0x163},
	{"KEY_POWER2", 0x164, 0x164},
	{"KEY_OPTION", 0x165, 0x165},
	{"KEY_INFO", 0x166, 0x166},
	{"KEY_TIME", 0x167, 0x167},
	{"KEY_VENDOR", 0x168, 0x168},
	{"KEY_ARCHIVE", 0x169, 0x169},
	{"KEY_PROGRAM", 0x16a, 0x16a},
	{"KEY_CHANNEL", 0x16b, 0x16b},
	{"KEY_FAVORITES", 0x16c, 0x16c},
	{"KEY_EPG", 0x16d, 0x16d},
	{"KEY_PVR", 0x16e, 0x16e},
	{"KEY_MHP", 0x16f, 0x16f},
	{"KEY_LANGUAGE", 0x170, 0x170},
	{"KEY_TITLE", 0x171, 0x171},
	{"KEY_SUBTITLE", 0x172, 0x172},
	{"KEY_ANGLE", 0x173, 0x173},
	{"KEY_ZOOM", 0x174, 0x174},
	{"KEY_MODE", 0x175, 0x175},
	{"KEY_KEYBOARD", 0x176, 0x176},
	{"KEY_SCREEN", 0x177, 0x177},
	{"KEY_PC", 0x178, 0x178},
	{"KEY_TV", 0x179, 0x179},
	{"KEY_TV2", 0x17a, 0x17a},
	{"KEY_VCR", 0x17b, 0x17b},
	{"KEY_VCR2", 0x17c, 0x17c},
	{"KEY_SAT", 0x17d, 0x17d},
	{"KEY_SAT2", 0x17e, 0x17e},
	{"KEY_CD", 0x17f, 0x17f},
	{"KEY_TAPE", 0x180, 0x180},
	{"KEY_RADIO", 0x181, 0x181},
	{"KEY_TUNER", 0x182, 0x182},
	{"KEY_PLAYER", 0x183, 0x183},
	{"KEY_TEXT", 0x184, 0x184},
	{"KEY_DVD", 0x185, 0x185},
	{"KEY_AUX", 0x186, 0x186},
	{"KEY_MP3", 0x187, 0x187},
	{"KEY_AUDIO", 0x188, 0x188},
	{"KEY_VIDEO", 0x189, 0x189},
	{"KEY_DIRECTORY", 0x18a, 0x18a},
	{"KEY_LIST", 0x18b, 0x18b},
	{"KEY_MEMO", 0x18c, 0x18c},
	{"KEY_CALENDAR", 0x18d, 0x18d},
	{"KEY_RED", 0x18e, 0x18e},
	{"KEY_GREEN", 0x18f, 0x18f},
	{"KEY_YELLOW", 0x190, 0x190},
	{"KEY_BLUE", 0x191, 0x191},
	{"KEY_CHANNELUP", 0x192, 0x192},
	{"KEY_CHANNELDOWN", 0x193, 0x193},
	{"KEY_FIRST", 0x194, 0x194},
	{"KEY_LAST", 0x195, 0x195},
	{"KEY_AB", 0x196, 0x196},
	{"KEY_NEXT", 0x197, 0x197},
	{"KEY_RESTART", 0x198, 0x198},
	{"KEY_SLOW", 0x199, 0x199},
	{"KEY_SHUFFLE", 0x19a, 0x19a},
	{"KEY_BREAK", 0x19b, 0x19b},
	{"KEY_PREVIOUS", 0x19c, 0x19c},
	{"KEY_DIGITS", 0x19d, 0x19d},
	{"KEY_TEEN", 0x19e, 0x19e},
	{"KEY_TWEN", 0x19f, 0x19f},
	{"KEY_VIDEOPHONE", 0x1a0, 0x1a0},
	{"KEY_GAMES", 0x1a1, 0x1a1},
	{"KEY_ZOOMIN", 0x1a2, 0x1a2},
	{"KEY_ZOOMOUT", 0x1a3, 0x1a3},
	{"KEY_ZOOMRESET", 0x1a4, 0x1a4},
	{"KEY_WORDPROCESSOR", 0x1a5, 0x1a5},
	{"KEY_EDITOR", 0x1a6, 0x1a6},
	{"KEY_SPREADSHEET", 0x1a7, 0x1a7},
	{"KEY_GRAPHICSEDITOR", 0x1a8, 0x1a8},
	{"KEY_PRESENTATION", 0x1a9, 0x1a9},
	{"KEY_DATABASE", 0x1aa, 0x1aa},
	{"KEY_NEWS", 0x1ab, 0x1ab},
	{"KEY_VOICEMAIL", 0x1ac, 0x1ac},
	{"KEY_ADDRESSBOOK", 0x1ad, 0x1ad},
	{"KEY_MESSENGER", 0x1ae, 0x1ae},
	{"KEY_DISPLAYTOGGLE", 0x1af, 0x1af},
	{"KEY_SPELLCHECK", 0x1b0, 0x1b0},
	{"KEY_LOGOFF", 0x1b1, 0x1b1},
	{"KEY_DOLLAR", 0x1b2, 0x1b2},
	{"KEY_EURO", 0x1b3, 0x1b3},
	{"KEY_FRAMEBACK", 0x1b4, 0x1b4},
	{"KEY_FRAMEFORWARD", 0x1b5, 0x1b5},
	{"KEY_CONTEXT_MENU", 0x1b6, 0x1b6},
	{"KEY_MEDIA_REPEAT", 0x1b7, 0x1b7},
	{"KEY_10CHANNELSUP", 0x1b8, 0x1b8},
	{"KEY_10CHANNELSDOWN", 0x1b9, 0x1b9},
	{"KEY_IMAGES", 0x1ba, 0x1ba},
	{"KEY_DEL_EOL", 0x1c0, 0x1c0},
	{"KEY_DEL_EOS", 0x1c1, 0x1c1},
	{"KEY_INS_LINE", 0x1c2, 0x1c2},
	{"KEY_DEL_LINE", 0x1c3, 0x1c3},
	{"KEY_FN", 0x1d0, 0x1d0},
	{"KEY_FN_ESC", 0x1d1, 0x1d1},
	{"KEY_FN_F1", 0x1d2, 0x1d2},
	{"KEY_FN_F2", 0x1d3, 0x1d3},
	{"KEY_FN_F3", 0x1d4, 0x1d4},
	{"KEY_FN_F4", 0x1d5, 0x1d5},
	{"KEY_FN_F5", 0x1d6, 0x1d6},
	{"KEY_FN_F6", 0x1d7, 0x1d7},
	{"KEY_FN_F7", 0x1d8, 0x1d8},
	{"KEY_FN_F8", 0x1d9, 0x1d9},
	{"KEY_FN_F9", 0x1da, 0x1da},
	{"KEY_FN_F10", 0x1db, 0x1db},
	{"KEY_FN_F11", 0x1dc, 0x1dc},
	{"KEY_FN_F12", 0x1dd, 0x1dd},
	{"KEY_FN_1", 0x1de, 0x1de},
	{"KEY_FN_2", 0x1df, 0x1df},
	{"KEY_FN_D", 0x1e0, 0x1e0},
	{"KEY_FN_E", 0x1e1, 0x1e1},
	{"KEY_FN_F", 0x1e2, 0x1e2},
	{"KEY_FN_S", 0x1e3, 0x1e3},
	{"KEY_FN_B", 0x1e4, 0x1e4},
	{"KEY_BRL_DOT1", 0x1f1, 0x1f1},
	{"KEY_BRL_DOT2", 0x1f2, 0x1f2},
	{"KEY_BRL_DOT3", 0x1f3, 0x1f3},
	{"KEY_BRL_DOT4", 0x1f4, 0x1f4},
	{"KEY_BRL_DOT5", 0x1f5, 0x1f5},
	{"KEY_BRL_DOT6", 0x1f6, 0x1f6},
	{"KEY_BRL_DOT7", 0x1f7, 0x1f7},
	{"KEY_BRL_DOT8", 0x1f8, 0x1f8},
	{"KEY_BRL_DOT9", 0x1f9, 0x1f9},
	{"KEY_BRL_DOT10", 0x1fa, 0x1fa},
	{"KEY_NUMERIC_0", 0x200, 0x200},
	{"KEY_NUMERIC_1", 0x201, 0x201},
	{"KEY_NUMERIC_2", 0x202, 0x202},
	{"KEY_NUMERIC_3", 0x203, 0x203},
	{"KEY_NUMERIC_4", 0x204, 0x204},
	{"KEY_NUMERIC_5", 0x205, 0x205},
	{"KEY_NUMERIC_6", 0x206, 0x206},
	{"KEY_NUMERIC_7", 0x207, 0x207},
	{"KEY_NUMERIC_8", 0x208, 0x208},
	{"KEY_NUMERIC_9", 0x209, 0x209},
	{"KEY_NUMERIC_STAR", 0x20a, 0x20a},
	{"KEY_NUMERIC_POUND", 0x20b, 0x20b},
	{"KEY_NUMERIC_A", 0x20c, 0x20c},
	{"KEY_NUMERIC_B", 0x20d, 0x20d},
	{"KEY_NUMERIC_C", 0x20e, 0x20e},
	{"KEY_NUMERIC_D", 0x20f, 0x20f},
	{"KEY_CAMERA_FOCUS", 0x210, 0x210},
	{"KEY_WPS_BUTTON", 0x211, 0x211},
	{"KEY_TOUCHPAD_TOGGLE", 0x212, 0x212},
	{"KEY_TOUCHPAD_ON", 0x213, 0x213},
	{"KEY_TOUCHPAD_OFF", 0x214, 0x214},
	{"KEY_CAMERA_ZOOMIN", 0x215, 0x215},
	{"KEY_CAMERA_ZOOMOUT", 0x216, 0x216},
	{"KEY_CAMERA_UP", 0x217, 0x217},
	{"KEY_CAMERA_DOWN", 0x218, 0x218},
	{"KEY_CAMERA_LEFT", 0x219, 0x219},
	{"KEY_CAMERA_RIGHT", 0x21a, 0x21a},
	{"KEY_ATTENDANT_ON", 0x21b, 0x21b},
	{"KEY_ATTENDANT_OFF", 0x21c, 0x21c},
	{"KEY_ATTENDANT_TOGGLE", 0x21d, 0x21d},
	{"KEY_LIGHTS_TOGGLE", 0x21e, 0x21e},
	{"KEY_ALS_TOGGLE", 0x230, 0x230},
	{"KEY_BUTTONCONFIG", 0x240, 0x240},
	{"KEY_TASKMANAGER", 0x241, 0x241},
	{"KEY_JOURNAL", 0x242, 0x242},
	{"KEY_CONTROLPANEL", 0x243, 0x243},
	{"KEY_APPSELECT", 0x244, 0x244},
	{"KEY_SCREENSAVER", 0x245, 0x245},
	{"KEY_VOICECOMMAND", 0x246, 0x246},
	{"KEY_BRIGHTNESS_MIN", 0x250, 0x250},
	{"KEY_BRIGHTNESS_MAX", 0x251, 0x251},
	{"KEY_KBDINPUTASSIST_PREV", 0x260, 0x260},
	{"KEY_KBDINPUTASSIST_NEXT", 0x261, 0x261},
	{"KEY_KBDINPUTASSIST_PREVGROUP", 0x262, 0x262},
	{"KEY_KBDINPUTASSIST_NEXTGROUP", 0x263, 0x263},
	{"KEY_KBDINPUTASSIST_ACCEPT", 0x264, 0x264},
	{"KEY_KBDINPUTASSIST_CANCEL", 0x265, 0x265},
	{"KEY_RIGHT_UP", 0x266, 0x266},
	{"KEY_RIGHT_DOWN", 0x267, 0x267},
	{"KEY_LEFT_UP", 0x268, 0x268},
	{"KEY_LEFT_DOWN", 0x269, 0x269},
	{"KEY_ROOT_MENU", 0x26a, 0x26a},
	{"KEY_MEDIA_TOP_MENU", 0x26b, 0x26b},
	{"KEY_NUMERIC_11", 0x26c, 0x26c},
	{"KEY_NUMERIC_12", 0x26d, 0x26d},
	{"KEY_AUDIO_DESC", 0x26e, 0x26e},
	{"KEY_3D_MODE", 0x26f, 0x26f},
	{"KEY_NEXT_FAVORITE", 0x270, 0x270},
	{"KEY_STOP_RECORD", 0x271, 0x271},
	{"KEY_PAUSE_RECORD", 0x272, 0x272},
	{"KEY_VOD", 0x273, 0x273},
	{"KEY_UNMUTE", 0x274, 0x274},
	{"KEY_FASTREVERSE", 0x275, 0x275},
	{"KEY_SLOWREVERSE", 0x276, 0x276},
	{"KEY_DATA", 0x277, 0x277},
	{"KEY_MAX", 0x2ff, 0x2ff},
	{ NULL, 0}
};

#endif
