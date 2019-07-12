#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUMBERS 1
#define _PROGRAMS 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBERS,
  PROGRAMS,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty */       
[_QWERTY] = LAYOUT( \
                 KC_Q, KC_W, KC_E,KC_R, KC_T,     KC_Y, KC_U, KC_I, KC_O, KC_P, \
                KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J,  KC_K, KC_L, KC_BSPACE, \
                KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_RSPC, \
                  KC_LCPO, KC_LALT, KC_LGUI,     LT(_NUMBERS, KC_ENTER), KC_SPACE, OSL(_PROGRAMS) \
),

/* Numbers */       
[_NUMBERS] = LAYOUT( \
                 KC_1, KC_2, KC_3, KC_4, KC_5,     KC_6, KC_7, KC_8, KC_9, KC_0, \
 KC_BSLASH, KC_LBRC, KC_RBRC, KC_SCLN, KC_SLASH,     KC_ESC, _______,   KC_UP, _______, KC_BSPACE, \
 KC_GRAVE, KC_QUOTE, KC_MINUS, KC_EQUAL, _______,     KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT, \
                      _______,  _______, _______,     XXXXXXX, KC_TAB, XXXXXXX                 \
),

/* Programs
 *
 *                   ,------------------------------------------------.     ,---------------------------------------------.
 *                   |F12|LSFT(F12)|LCTL(F12)|LALT(F12)|LSFT(LCTL(F12)|     |     |     |         |         |         |         |
 *                   |------------+---------+---------+---------+-----|     |-----+---------+---------+---------+---------|
 *                   |F13|LSFT(F13)|LCTL(F13)|LALT(F13)|LSFT(LCTL(F13)|     |     |     |         |         |         |         |
 *                   |------------+---------+---------+---------+-----|     |-----+---------+---------+---------+---------|
 *                   |F14|LSFT(F14)|LCTL(F14)|LALT(F14)|LSFT(LCTL(F14)|     |     |     |         |         |         |         |
 *                   `-----------------------------------------------'     `---------------------------------------------'
 *                                          ,-----------------------.     ,-----,-------------.
 *                                          |      |      |         |     |     |      |      |
 *                                          `-------------|         |     |     |-------------'
 *                                                        |         |     |     |
 *                                                        `---------'     `-----'
 */       
[_PROGRAMS] = LAYOUT( \
KC_F12, LSFT(KC_F12), LCTL(KC_F12), LALT(KC_F12), LSFT(LCTL(KC_F12)),     LSFT(LCTL(KC_F16)), LALT(KC_F16), LSFT(KC_F16), LCTL(KC_F16), KC_F16, \
KC_F13, LSFT(KC_F13), LCTL(KC_F13), LALT(KC_F13), LSFT(LCTL(KC_F13)),     XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, \
KC_F14, LSFT(KC_F14), LCTL(KC_F14), LALT(KC_F14), LSFT(LCTL(KC_F14)),     XXXXXXX, KC__VOLDOWN, KC__MUTE, KC__VOLUP, XXXXXXX, \
                                      XXXXXXX,  KC_F15, LSFT(KC_F15),    XXXXXXX, XXXXXXX, XXXXXXX \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
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
      if (record->event.pressed) {
        layer_on(_NUMBERS);
      } else {
        layer_off(_NUMBERS);
      }
      return false;
      break;
    case PROGRAMS:
      if (record->event.pressed) {
        layer_on(_PROGRAMS);
      } else {
        layer_off(_PROGRAMS);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
