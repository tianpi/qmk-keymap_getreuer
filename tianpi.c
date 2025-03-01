//
////
////////
////////////////
////////////////////////////////
////////////////////////////////////////////////////////////////

#include "quantum.h"

////////////////////////////////

#ifndef ACHORDION_ENABLE
#define ACHORDION_ENABLE
#endif

#ifndef CUSTOM_SHIFT_KEYS_ENABLE
// #define CUSTOM_SHIFT_KEYS_ENABLE
#endif

////////////////

#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif  // ACHORDION_ENABLE

#ifdef CUSTOM_SHIFT_KEYS_ENABLE
#include "features/custom_shift_keys.h"
#endif  // CUSTOM_SHIFT_KEYS_ENABLE

#ifdef LAYER_LOCK_ENABLE
#include "features/layer_lock.h"
#endif  // LAYER_LOCK_ENABLE

#ifdef ORBITAL_MOUSE_ENABLE
#include "features/orbital_mouse.h"
#endif  // ORBITAL_MOUSE_ENABLE

#ifdef SENTENCE_CASE_ENABLE
#include "features/sentence_case.h"
#endif  // SENTENCE_CASE_ENABLE

////////////////////////////////////////////////////////////////

enum layers {
  BASE,
  NUM,
  SYM,
  FUN,
  FUNFUN,
  NAV,
  _TEMPLATE,
};

////////////////////////////////////////////////////////////////

enum custom_keycodes {
  _KEY_USER = SAFE_RANGE,
  KEY_UNDO,
  KEY_REDO,
  KEY_CUT,
  KEY_COPY,
  KEY_PASTE,
  KEY_MACRO_X,
};

////////////////////////////////////////////////////////////////
// Tap-hold configuration (https://docs.qmk.fm/tap_hold)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  ////////////////
  // switch (keycode) {
  //   case MOD_LM3:
  //   case MOD_RM3:
  //     return TAPPING_TERM + 15;
  // }

  ////////////////

  return TAPPING_TERM;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  ////////////////
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  // switch (keycode) {
  //   // case HOME_N:
  //   //   return QUICK_TAP_TERM;  // Enable key repeating.
  // }

  ////////////////

  return 0;  // Otherwise, force hold and disable key repeating.
}

////////////////////////////////////////////////////////////////
// Achordion (https://getreuer.info/posts/keyboards/achordion)

#ifdef ACHORDION_ENABLE

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  ////////////////
  // Also allow same-hand holds when the other key is in the rows outside the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboards are split.

  // uint8_t row = other_record->event.key.row % (MATRIX_ROWS / 2);
  // if (!(1 <= row && row <= 3)) {
  //   return true;
  // }

  ////////////////
  // Exceptionally allow same-hand chords

  switch (tap_hold_keycode) {
    case MT(MOD_LCTL, KC_TAB):
      return true;
      break;
    case MT(MOD_LALT, KC_A):
      if (other_keycode == MT(MOD_LCTL, KC_TAB)) return true;
      break;
  }

  ////////////////

  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 800;  // Use a timeout of 800 ms.
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode,
                                        uint16_t next_keycode) {
  ////////////////
  // Disable streak detection on LT keys.

  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;
  }

  ////////////////
  // Exceptions so that certain hotkeys don't get blocked as streaks.

  ////////////////
  // Otherwise, tap_hold_keycode is a mod-tap key.

  const uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 100;  // A short streak timeout for Shift mod-tap keys.
  }

  ////////////////

  return 220;  // A longer timeout otherwise.
}

#endif  // ACHORDION_ENABLE

////////////////////////////////////////////////////////////////
// https://docs.qmk.fm/features/key_overrides

// clang-format off
const key_override_t* key_overrides[] = {
    /* modifier */
    &ko_make_with_layers(MOD_MASK_SHIFT, QK_CAPS_WORD_TOGGLE, KC_CAPS_LOCK, (1 << BASE)), /* TODO: NOK */
    &ko_make_with_layers(MOD_MASK_SHIFT, KEY_UNDO, KEY_REDO, (1 << BASE)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLON, (1 << BASE) | (1 << NUM) | (1 << SYM)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON, (1 << BASE) | (1 << NUM) | (1 << SYM)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_EXCLAIM, KC_QUESTION, (1 << BASE) | (1 << SYM)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH, (1 << BASE) | (1 << SYM)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_EQUAL, KC_EQUAL, (1 << NUM) | (1 << SYM)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_QUOTE, (1 << SYM)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_GRAVE, KC_CIRCUMFLEX, (1 << SYM)),
    /* modifier + function */
    &ko_make_with_layers(MOD_MASK_SHIFT, MT(MOD_RALT, KC_EXCLAIM), KC_QUESTION, (1 << BASE)),
    &ko_make_with_layers(MOD_MASK_SHIFT, LT(FUNFUN, KC_UNDERSCORE), KC_MINUS, (1 << BASE)),
    &ko_make_with_layers(MOD_MASK_SHIFT, LT(NAV, KC_BACKSPACE), KC_DELETE, (1 << BASE)),
};
// clang-format on

////////////////////////////////////////////////////////////////
// Custom shift keys (https://getreuer.info/posts/keyboards/custom-shift-keys)

#ifdef CUSTOM_SHIFT_KEYS_ENABLE

const custom_shift_key_t custom_shift_keys[] = {
    {KC_LEFT_BRACKET, KC_RIGHT_BRACKET},
    {KC_PLUS, KC_MINUS},
    {KC_BACKSPACE, KC_DELETE},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

#endif  // CUSTOM_SHIFT_KEYS_ENABLE

////////////////////////////////////////////////////////////////
// User macro callbacks (https://docs.qmk.fm/feature_macros)
// https://docs.qmk.fm/feature_macros#advanced-macro-functions
// https://docs.qmk.fm/feature_advanced_keycodes#checking-modifier-state

void keyboard_post_init_user(void) {}

////////////////////////////////

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  ////////////////

#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) {
    return false;
  }
#endif  // ACHORDION_ENABLE

#ifdef CUSTOM_SHIFT_KEYS_ENABLE
  if (!process_custom_shift_keys(keycode, record)) {
    return false;
  }
#endif  // CUSTOM_SHIFT_KEYS_ENABLE

  ////////////////

#if 0
  const uint8_t mods = get_mods();
  const uint8_t mods_all = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                            | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
  );
  const uint8_t mods_shift = mods_all & MOD_MASK_SHIFT;
  const bool mod_alt = mods_all & MOD_BIT(KC_LALT);
#endif

  ////////////////
  // https://docs.qmk.fm/features/send_string#keycodes

  switch (keycode) {
    case KEY_UNDO:
      if (record->event.pressed) SEND_STRING(SS_LCTL("z"));
      break;
    case KEY_REDO:
      if (record->event.pressed) SEND_STRING(SS_LCTL("y"));
      break;
    case KEY_CUT:
      if (record->event.pressed) SEND_STRING(SS_LCTL("x"));
      break;
    case KEY_COPY:
      if (record->event.pressed) SEND_STRING(SS_LCTL("c"));
      break;
    case KEY_PASTE:
      if (record->event.pressed) SEND_STRING(SS_LCTL("v"));
      break;
  }

  ////////////////
  // https://getreuer.info/posts/keyboards/faqs/index.html#mt-doesnt-work-with-this-keycode-qmk
  // https://docs.qmk.fm/mod_tap#changing-tap-function

  switch (keycode) {
    case MT(MOD_RALT, KC_EXCLAIM):  // BASE
      if (record->tap.count && record->event.pressed) {
        if (!(get_mods() & MOD_MASK_SHIFT)) {
          tap_code16(KC_EXCLAIM);
          return false;
        }
      }
      break;

    case LT(FUNFUN, KC_UNDERSCORE):  // BASE
      if (record->tap.count && record->event.pressed) {
        if (!(get_mods() & MOD_MASK_SHIFT)) {
          tap_code16(KC_UNDERSCORE);
          return false;
        }
      }
      break;

    case MT(MOD_LSFT, KC_GT):  // SYM
      if (record->tap.count && record->event.pressed) {
        if (!(get_mods() & MOD_MASK_SHIFT)) {
          tap_code16(KC_GT);
          return false;
        }
      }
      break;

    case MT(MOD_LSFT, KC_LEFT_PAREN):  // SYM
      if (record->tap.count && record->event.pressed) {
        if (!(get_mods() & MOD_MASK_SHIFT)) {
          tap_code16(KC_LEFT_PAREN);
          return false;
        }
      }
      break;
  }

  ////////////////

  return true;
}

////////////////////////////////

void matrix_scan_user(void) {
  ////////////////

#ifdef ACHORDION_ENABLE
  achordion_task();
#endif  // ACHORDION_ENABLE
}

////////////////////////////////////////////////////////////////
////////////////////////////////
////////////////
////////
////
//
