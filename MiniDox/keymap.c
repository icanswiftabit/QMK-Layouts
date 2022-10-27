#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _PROGRAMS 1
#define _GAMES 2
#define _WINDOWS 3
#define _NUMBERS 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PROGRAMS,
  GAMES,
  WINDOWS,
  NUMBERS,
  // HYPER_G,
  // HYPER_U,
};

// Tap Dance

void tap_hyper_code(uint16_t keycode) {
  register_code(KC_LCTRL);
  register_code(KC_LALT);
  register_code(KC_LGUI);
  tap_code(keycode);
  unregister_code(KC_LGUI);
  unregister_code(KC_LALT);
  unregister_code(KC_LCTRL);
}

void tap_mod_code(uint16_t modKeycod, uint16_t keycode) {
  register_code(modKeycod);
  tap_code(keycode);
  unregister_code(modKeycod);
}

void f17_dance (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_mod_code(KC_LCTRL, KC_F17);
    reset_tap_dance(state);
  } else if (state->count == 2) {
    tap_mod_code(KC_LALT, KC_F17);
    reset_tap_dance(state);
  } else if (state->count >= 3) {
    tap_mod_code(KC_LGUI, KC_F17);
    reset_tap_dance(state);
  }
}

enum {
 CT_F17 = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
 [CT_F17] = ACTION_TAP_DANCE_FN (f17_dance)
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
                 KC_Q, KC_W, KC_E,KC_R, KC_T,     KC_Y, KC_U, KC_I, KC_O, KC_P, \
                KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J,  KC_K, KC_L, KC_BSPACE, \
                KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_RSPC, \
                   KC_LCPO, KC_RALT, KC_LGUI,     LT(_NUMBERS, KC_ENTER), KC_SPACE, MO(_PROGRAMS) \
),

[_PROGRAMS] = LAYOUT( \
  KC_F12, LSFT(KC_F12), LCTL(KC_F12), LALT(KC_F12), LSFT(LCTL(KC_F12)),     LSFT(LCTL(KC_F16)), TD(CT_F17), LSFT(KC_F16), LCTL(KC_F16), KC_F16, \
  KC_F13, LSFT(KC_F13), LCTL(KC_F13), LALT(KC_F13), LSFT(LCTL(KC_F13)),     XXXXXXX, KC_F6, KC_F7, KC_F8, TG(_GAMES), \
  KC_F14, LSFT(KC_F14), LCTL(KC_F14), LALT(KC_F14), LSFT(LCTL(KC_F14)),     KC_MEDIA_PLAY_PAUSE, KC__VOLDOWN, KC__MUTE, KC__VOLUP, TG(_WINDOWS), \
                                         XXXXXXX, KC_F15, LSFT(KC_F15),     KC_MEDIA_REWIND, KC_MEDIA_FAST_FORWARD, XXXXXXX \
),

[_GAMES] = LAYOUT(                  
                KC_H, KC_Q, KC_W,KC_E, KC_R,     KC_7, KC_8, KC_9, KC_0, KC_P, \
           KC_LSHIFT, KC_A, KC_S, KC_D, KC_F,     KC_4, KC_5,  KC_6, KC_L, KC_BSPACE, \
                KC_B, KC_Z, KC_X, KC_C, KC_V,     KC_1, KC_2, KC_3, KC_DOT, KC_TAB, \
                 KC_LCTRL, KC_RALT, KC_SPACE,     KC_ENTER, KC_ESC, TG(_GAMES) \
),

[_WINDOWS] = LAYOUT( \
                 KC_Q, KC_W, KC_E,KC_R, KC_T,     KC_Y, KC_U, KC_I, KC_O, KC_P, \
                KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J,  KC_K, KC_L, KC_BSPACE, \
                KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, \
                  KC_LGUI, KC_RALT, KC_LCTRL,     LT(_NUMBERS, KC_ENTER), KC_SPACE, TG(_WINDOWS) \
),

[_NUMBERS] = LAYOUT( \
                    KC_1, KC_2, KC_3, KC_4, KC_5,     KC_6, KC_7, KC_8, KC_9, KC_0, \
  KC_BSLASH, KC_LBRC, KC_RBRC, KC_SCLN, KC_SLASH,     KC_ESC, _______,   KC_UP, _______, KC_BSPACE, \
 KC_GRAVE, KC_QUOTE, KC_MINUS, KC_EQUAL, _______,     KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT, \
                      _______,  _______, _______,     XXXXXXX, KC_TAB, XXXXXXX                 \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// void tap_hyper_code(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     register_code(KC_LCTRL);wwwwwwfffffffs
//     register_code(KC_LALT);
//     register_code(KC_LGUI);
//     tap_code(keycode);
//   } else {ssssssdddddasdadsadsadadasdassdfsdfsdfsdfdssdfsdfsdfew
//     unregister_code(KC_LGUI);
//     unregister_code(KC_LALT);
//     unregister_code(KC_LCTRL);
//   }
// }

void active_layer(uint16_t layer, keyrecord_t *record) {
  if (record->event.pressed) {
        layer_on(layer);
      } else {
        layer_off(layer);
      }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case NUMBERS:
      active_layer(_NUMBERS, record);
      return false;
      break;
    case PROGRAMS:
     active_layer(_PROGRAMS, record);
      return false;
      break;
    case GAMES:
      active_layer(_GAMES, record);
      return false;
      break;
    case WINDOWS:
      active_layer(_WINDOWS, record);
      return false;
      break;
    // case HYPER_G:
    //   tap_hyper_code(KC_G, record);
    //   return false;
    //   break;
    // case HYPER_U:
    //   tap_hyper_code(KC_U, record);
    //   return false;
    //   break;
  }
  return true;
}