//
//  KeyCodes.h
//  Tomato
//
//  Created by Game on 12/11/24.
//

#ifndef KeyCodes_h
#define KeyCodes_h

#ifdef TOMATO_GLFW

    #define TOMATO_KEY_SPACE              32
    #define TOMATO_KEY_APOSTROPHE         39  /* ' */
    #define TOMATO_KEY_COMMA              44  /* , */
    #define TOMATO_KEY_MINUS              45  /* - */
    #define TOMATO_KEY_PERIOD             46  /* . */
    #define TOMATO_KEY_SLASH              47  /* / */
    #define TOMATO_KEY_0                  48
    #define TOMATO_KEY_1                  49
    #define TOMATO_KEY_2                  50
    #define TOMATO_KEY_3                  51
    #define TOMATO_KEY_4                  52
    #define TOMATO_KEY_5                  53
    #define TOMATO_KEY_6                  54
    #define TOMATO_KEY_7                  55
    #define TOMATO_KEY_8                  56
    #define TOMATO_KEY_9                  57
    #define TOMATO_KEY_SEMICOLON          59  /* ; */
    #define TOMATO_KEY_EQUAL              61  /* = */
    #define TOMATO_KEY_A                  65
    #define TOMATO_KEY_B                  66
    #define TOMATO_KEY_C                  67
    #define TOMATO_KEY_D                  68
    #define TOMATO_KEY_E                  69
    #define TOMATO_KEY_F                  70
    #define TOMATO_KEY_G                  71
    #define TOMATO_KEY_H                  72
    #define TOMATO_KEY_I                  73
    #define TOMATO_KEY_J                  74
    #define TOMATO_KEY_K                  75
    #define TOMATO_KEY_L                  76
    #define TOMATO_KEY_M                  77
    #define TOMATO_KEY_N                  78
    #define TOMATO_KEY_O                  79
    #define TOMATO_KEY_P                  80
    #define TOMATO_KEY_Q                  81
    #define TOMATO_KEY_R                  82
    #define TOMATO_KEY_S                  83
    #define TOMATO_KEY_T                  84
    #define TOMATO_KEY_U                  85
    #define TOMATO_KEY_V                  86
    #define TOMATO_KEY_W                  87
    #define TOMATO_KEY_X                  88
    #define TOMATO_KEY_Y                  89
    #define TOMATO_KEY_Z                  90
    #define TOMATO_KEY_LEFT_BRACKET       91  /* [ */
    #define TOMATO_KEY_BACKSLASH          92  /* \ */
    #define TOMATO_KEY_RIGHT_BRACKET      93  /* ] */
    #define TOMATO_KEY_GRAVE_ACCENT       96  /* ` */
    #define TOMATO_KEY_WORLD_1            161 /* non-US #1 */
    #define TOMATO_KEY_WORLD_2            162 /* non-US #2 */

    /* Function keys */
    #define TOMATO_KEY_ESCAPE             256
    #define TOMATO_KEY_ENTER              257
    #define TOMATO_KEY_TAB                258
    #define TOMATO_KEY_BACKSPACE          259
    #define TOMATO_KEY_INSERT             260
    #define TOMATO_KEY_DELETE             261
    #define TOMATO_KEY_RIGHT              262
    #define TOMATO_KEY_LEFT               263
    #define TOMATO_KEY_DOWN               264
    #define TOMATO_KEY_UP                 265
    #define TOMATO_KEY_PAGE_UP            266
    #define TOMATO_KEY_PAGE_DOWN          267
    #define TOMATO_KEY_HOME               268
    #define TOMATO_KEY_END                269
    #define TOMATO_KEY_CAPS_LOCK          280
    #define TOMATO_KEY_SCROLL_LOCK        281
    #define TOMATO_KEY_NUM_LOCK           282
    #define TOMATO_KEY_PRINT_SCREEN       283
    #define TOMATO_KEY_PAUSE              284
    #define TOMATO_KEY_F1                 290
    #define TOMATO_KEY_F2                 291
    #define TOMATO_KEY_F3                 292
    #define TOMATO_KEY_F4                 293
    #define TOMATO_KEY_F5                 294
    #define TOMATO_KEY_F6                 295
    #define TOMATO_KEY_F7                 296
    #define TOMATO_KEY_F8                 297
    #define TOMATO_KEY_F9                 298
    #define TOMATO_KEY_F10                299
    #define TOMATO_KEY_F11                300
    #define TOMATO_KEY_F12                301
    #define TOMATO_KEY_F13                302
    #define TOMATO_KEY_F14                303
    #define TOMATO_KEY_F15                304
    #define TOMATO_KEY_F16                305
    #define TOMATO_KEY_F17                306
    #define TOMATO_KEY_F18                307
    #define TOMATO_KEY_F19                308
    #define TOMATO_KEY_F20                309
    #define TOMATO_KEY_F21                310
    #define TOMATO_KEY_F22                311
    #define TOMATO_KEY_F23                312
    #define TOMATO_KEY_F24                313
    #define TOMATO_KEY_F25                314
    #define TOMATO_KEY_KP_0               320
    #define TOMATO_KEY_KP_1               321
    #define TOMATO_KEY_KP_2               322
    #define TOMATO_KEY_KP_3               323
    #define TOMATO_KEY_KP_4               324
    #define TOMATO_KEY_KP_5               325
    #define TOMATO_KEY_KP_6               326
    #define TOMATO_KEY_KP_7               327
    #define TOMATO_KEY_KP_8               328
    #define TOMATO_KEY_KP_9               329
    #define TOMATO_KEY_KP_DECIMAL         330
    #define TOMATO_KEY_KP_DIVIDE          331
    #define TOMATO_KEY_KP_MULTIPLY        332
    #define TOMATO_KEY_KP_SUBTRACT        333
    #define TOMATO_KEY_KP_ADD             334
    #define TOMATO_KEY_KP_ENTER           335
    #define TOMATO_KEY_KP_EQUAL           336
    #define TOMATO_KEY_LEFT_SHIFT         340
    #define TOMATO_KEY_LEFT_CONTROL       341
    #define TOMATO_KEY_LEFT_ALT           342
    #define TOMATO_KEY_LEFT_SUPER         343
    #define TOMATO_KEY_RIGHT_SHIFT        344
    #define TOMATO_KEY_RIGHT_CONTROL      345
    #define TOMATO_KEY_RIGHT_ALT          346
    #define TOMATO_KEY_RIGHT_SUPER        347
    #define TOMATO_KEY_MENU               348

#else
    #only_glfw_is_supported_for_now
#endif


#endif /* KeyCodes_h */
