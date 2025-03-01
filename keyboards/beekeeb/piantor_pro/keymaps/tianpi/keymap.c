//
////
////////
////////////////
////////////////////////////////
////////////////////////////////////////////////////////////////

#include QMK_KEYBOARD_H
#include "quantum.h"

#include "tianpi.c"

////////////////////////////////////////////////////////////////
// https://docs.qmk.fm/keycodes
//
// ╭─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────╮
// │ LT5 │ LT4 │ LT3 │ LT2 │ LT1 │ LT0 │ RT0 │ RT1 │ RT2 │ RT3 │ RT4 │ RT5 │
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LM5 │ LM4 │ LM3 │ LM2 │ LM1 │ LM0 │ RM0 │ RM1 │ RM2 │ RM3 │ RM4 │ RM5 │
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LB5 │ LB4 │ LB3 │ LB2 │ LB1 │ LB0 │ RB0 │ RB1 │ RB2 │ RB3 │ RB4 │ RB5 │
// ╰─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────╯
//                   │ LH2 │ LH1 │ LH0 │ RH0 │ RH1 │ RH2 │
//                   ╰─────┴─────┴─────┴─────┴─────┴─────╯
//
// ┌───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┐
// │   │   │   │   │   │   │         │   │   │   │   │   │   │
// ├───┼───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┼───┤
// │   │   │   │   │   │   │         │   │   │   │   │   │   │
// ├───┼───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┼───┤
// │   │   │   │   │   │   │         │   │   │   │   │   │   │
// └───┴───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┴───┘
//                 ┌───┬───┬───┐ ┌───┬───┬───┐
//                 │   │   │   │ │   │   │   │
//                 └───┴───┴───┘ └───┴───┴───┘
//

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

////////////////////////////////

  [BASE] = LAYOUT_split_3x6_3(
// ╭─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────╮
// │ LT5 │ LT4 │ LT3 │ LT2 │ LT1 │ LT0 │ RT0 │ RT1 │ RT2 │ RT3 │ RT4 │ RT5 │
    QK_CAPS_WORD_TOGGLE,

    KC_Q,
    KC_W,
    KC_E,
    KC_R,
    KC_F,

    KC_Y,
    KC_U,
    KC_I,
    KC_O,
    KC_P,

    TG(NUM),
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LM5 │ LM4 │ LM3 │ LM2 │ LM1 │ LM0 │ RM0 │ RM1 │ RM2 │ RM3 │ RM4 │ RM5 │
    KC_ENTER,

    MT(MOD_LALT, KC_A),
    MT(MOD_LCTL, KC_S),
    LT(SYM, KC_D),
    MT(MOD_LSFT, KC_T),
    KC_G,

    KC_K,
    MT(MOD_LSFT, KC_N),
    LT(SYM, KC_H),
    MT(MOD_LCTL, KC_L),
    MT(MOD_LALT, KC_QUOTE),

    KC_ESCAPE,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LB5 │ LB4 │ LB3 │ LB2 │ LB1 │ LB0 │ RB0 │ RB1 │ RB2 │ RB3 │ RB4 │ RB5 │
    KEY_UNDO,

    MT(MOD_RALT, KC_Z),
    MT(MOD_LGUI, KC_X),
    LT(NUM, KC_C),
    KC_V,
    KC_B,

    KC_J,
    KC_M,
    KC_COMMA,
    MT(MOD_LGUI, KC_DOT),
    MT(MOD_RALT, KC_EXCLAIM),

    TO(BASE),
// ╰─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────╯
//                   │ LH2 │ LH1 │ LH0 │ RH0 │ RH1 │ RH2 │
    KC_ESCAPE,
    LT(NAV, KC_BACKSPACE),
    MT(MOD_LCTL, KC_TAB),

    LT(FUNFUN, KC_UNDERSCORE),
    LT(FUN, KC_SPACE),
    KC_SLASH
//                   ╰─────┴─────┴─────┴─────┴─────┴─────╯
  ),

////////////////////////////////

  [NUM] = LAYOUT_split_3x6_3(
// ╭─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────╮
// │ LT5 │ LT4 │ LT3 │ LT2 │ LT1 │ LT0 │ RT0 │ RT1 │ RT2 │ RT3 │ RT4 │ RT5 │
    _______,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,

    KC_ASTERISK,
    KC_7,
    KC_8,
    KC_9,
    KC_COMMA,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LM5 │ LM4 │ LM3 │ LM2 │ LM1 │ LM0 │ RM0 │ RM1 │ RM2 │ RM3 │ RM4 │ RM5 │
    _______,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    KC_LSFT,
    XXXXXXX,

    KC_PLUS,
    KC_4,
    KC_5,
    KC_6,
    KC_0,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LB5 │ LB4 │ LB3 │ LB2 │ LB1 │ LB0 │ RB0 │ RB1 │ RB2 │ RB3 │ RB4 │ RB5 │
    _______,

    XXXXXXX,
    KC_DOT,
    KC_COMMA,
    KEY_PASTE,
    XXXXXXX,

    KC_LEFT_PAREN,
    KC_1,
    KC_2,
    KC_3,
    KC_DOT,
    _______,
// ╰─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────╯
//                   │ LH2 │ LH1 │ LH0 │ RH0 │ RH1 │ RH2 │
    _______,
    _______,
    _______,

    _______,
    _______,
    _______
//                   ╰─────┴─────┴─────┴─────┴─────┴─────╯
  ),

////////////////////////////////

  [SYM] = LAYOUT_split_3x6_3(
// ╭─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────╮
// │ LT5 │ LT4 │ LT3 │ LT2 │ LT1 │ LT0 │ RT0 │ RT1 │ RT2 │ RT3 │ RT4 │ RT5 │
    _______,

    KC_TILDE,
    KC_AT,
    KC_HASH,
    KC_DOLLAR,
    KC_PERCENT,

    KC_ASTERISK,
    KC_MINUS,
    KC_SLASH,
    KC_PIPE,
    KC_EQUAL,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LM5 │ LM4 │ LM3 │ LM2 │ LM1 │ LM0 │ RM0 │ RM1 │ RM2 │ RM3 │ RM4 │ RM5 │
    _______,

    KC_GRAVE,
    KC_ASTERISK,
    KC_PLUS,
    MT(MOD_LSFT, KC_EQUAL),
    KC_DOT,

    KC_SEMICOLON,
    MT(MOD_LSFT, KC_LEFT_PAREN),
    KC_LEFT_BRACKET,
    KC_LEFT_CURLY_BRACE,
    KC_LT,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LB5 │ LB4 │ LB3 │ LB2 │ LB1 │ LB0 │ RB0 │ RB1 │ RB2 │ RB3 │ RB4 │ RB5 │
    _______,

    KC_EXCLAIM,
    KC_LT,
    KC_AMPERSAND,
    KC_CIRCUMFLEX,
    KC_COMMA,

    KC_DOUBLE_QUOTE,
    KC_RIGHT_PAREN,
    KC_RIGHT_BRACKET,
    KC_RIGHT_CURLY_BRACE,
    KC_GT,

    _______,
// ╰─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────╯
//                   │ LH2 │ LH1 │ LH0 │ RH0 │ RH1 │ RH2 │
    _______,
    _______,
    _______,

    _______,
    _______,
    _______
//                   ╰─────┴─────┴─────┴─────┴─────┴─────╯
  ),

////////////////////////////////

  [FUN] = LAYOUT_split_3x6_3(
// ╭─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────╮
// │ LT5 │ LT4 │ LT3 │ LT2 │ LT1 │ LT0 │ RT0 │ RT1 │ RT2 │ RT3 │ RT4 │ RT5 │
    _______,

    KC_F1,
    KC_F4,
    KC_F7,
    KC_F10,
    KC_F13,

    KC_INSERT,
    KC_PAUSE,
    KC_MEDIA_NEXT_TRACK,
    KC_AUDIO_VOL_UP,
    KC_BRIGHTNESS_UP,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LM5 │ LM4 │ LM3 │ LM2 │ LM1 │ LM0 │ RM0 │ RM1 │ RM2 │ RM3 │ RM4 │ RM5 │
    _______,

    KC_F2,
    KC_F5,
    KC_F8,
    KC_F11,
    KC_F14,

    KC_NUM_LOCK,
    KC_PRINT_SCREEN,
    KC_MEDIA_PLAY_PAUSE,
    KC_AUDIO_MUTE,
    XXXXXXX,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LB5 │ LB4 │ LB3 │ LB2 │ LB1 │ LB0 │ RB0 │ RB1 │ RB2 │ RB3 │ RB4 │ RB5 │
    _______,

    KC_F3,
    KC_F6,
    KC_F9,
    KC_F12,
    KC_F15,

    KC_SCROLL_LOCK,
    XXXXXXX,
    KC_MEDIA_PREV_TRACK,
    KC_AUDIO_VOL_DOWN,
    KC_BRIGHTNESS_DOWN,

    _______,
// ╰─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────╯
//                   │ LH2 │ LH1 │ LH0 │ RH0 │ RH1 │ RH2 │
    _______,
    _______,
    _______,

    _______,
    _______,
    _______
//                   ╰─────┴─────┴─────┴─────┴─────┴─────╯
  ),

////////////////////////////////

  [FUNFUN] = LAYOUT_split_3x6_3(
// ╭─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────╮
// │ LT5 │ LT4 │ LT3 │ LT2 │ LT1 │ LT0 │ RT0 │ RT1 │ RT2 │ RT3 │ RT4 │ RT5 │
    _______,

    KC_F15,
    KC_F16,
    KC_F17,
    KC_F18,
    KC_F19,

    KC_F20,
    KC_F21,
    KC_F22,
    KC_F23,
    KC_F24,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LM5 │ LM4 │ LM3 │ LM2 │ LM1 │ LM0 │ RM0 │ RM1 │ RM2 │ RM3 │ RM4 │ RM5 │
    _______,

    KC_F15,
    KC_F16,
    KC_F17,
    KC_F18,
    KC_F19,

    KC_F20,
    KC_F21,
    KC_F22,
    KC_F23,
    KC_F24,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LB5 │ LB4 │ LB3 │ LB2 │ LB1 │ LB0 │ RB0 │ RB1 │ RB2 │ RB3 │ RB4 │ RB5 │
    _______,

    KC_F15,
    KC_F16,
    KC_F17,
    KC_F18,
    KC_F19,

    KC_F20,
    KC_F21,
    KC_F22,
    KC_F23,
    KC_F24,

    _______,
// ╰─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────╯
//                   │ LH2 │ LH1 │ LH0 │ RH0 │ RH1 │ RH2 │
    _______,
    _______,
    _______,

    _______,
    _______,
    _______
//                   ╰─────┴─────┴─────┴─────┴─────┴─────╯
  ),

////////////////////////////////

  [NAV] = LAYOUT_split_3x6_3(
// ╭─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────╮
// │ LT5 │ LT4 │ LT3 │ LT2 │ LT1 │ LT0 │ RT0 │ RT1 │ RT2 │ RT3 │ RT4 │ RT5 │
    _______,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,

    KEY_CUT,
    KC_DELETE,
    KC_UP,
    KC_BACKSPACE,
    KC_PAGE_UP,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LM5 │ LM4 │ LM3 │ LM2 │ LM1 │ LM0 │ RM0 │ RM1 │ RM2 │ RM3 │ RM4 │ RM5 │
    _______,

    KC_LALT,
    KC_LCTL,
    XXXXXXX,
    KC_LSFT,
    XXXXXXX,

    KEY_COPY,
    KC_LEFT,
    KC_DOWN,
    KC_RIGHT,
    KEY_PASTE,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LB5 │ LB4 │ LB3 │ LB2 │ LB1 │ LB0 │ RB0 │ RB1 │ RB2 │ RB3 │ RB4 │ RB5 │
    _______,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,

    KC_TAB,
    KC_HOME,
    KC_APPLICATION,
    KC_END,
    KC_PAGE_DOWN,

    _______,
// ╰─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────╯
//                   │ LH2 │ LH1 │ LH0 │ RH0 │ RH1 │ RH2 │
    _______,
    _______,
    _______,

    _______,
    _______,
    _______
//                   ╰─────┴─────┴─────┴─────┴─────┴─────╯
  ),

////////////////////////////////

  [_TEMPLATE] = LAYOUT_split_3x6_3(
// ╭─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────╮
// │ LT5 │ LT4 │ LT3 │ LT2 │ LT1 │ LT0 │ RT0 │ RT1 │ RT2 │ RT3 │ RT4 │ RT5 │
    _______,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LM5 │ LM4 │ LM3 │ LM2 │ LM1 │ LM0 │ RM0 │ RM1 │ RM2 │ RM3 │ RM4 │ RM5 │
    _______,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,

    _______,
// ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
// │ LB5 │ LB4 │ LB3 │ LB2 │ LB1 │ LB0 │ RB0 │ RB1 │ RB2 │ RB3 │ RB4 │ RB5 │
    _______,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,

    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,
    XXXXXXX,

    _______,
// ╰─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────╯
//                   │ LH2 │ LH1 │ LH0 │ RH0 │ RH1 │ RH2 │
    _______,
    _______,
    _______,

    _______,
    _______,
    _______
//                   ╰─────┴─────┴─────┴─────┴─────┴─────╯
  ),

};

////////////////////////////////////////////////////////////////
////////////////////////////////
////////////////
////////
////
//
