#include QMK_KEYBOARD_H
#include "version.h"

#define _QWERTY 0
#define _NUMBERS1 1
#define _NUMBERS2 2
#define _ARROWS 3
#define _PROGRAMS 4
#define _ADJUST 16

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBERS1,
  NUMBERS2,
  ARROWS,
  PROGRAMS,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 *
 * ,----------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |        |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+--------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |    E   |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |    D   |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |      |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |Z/Ctrl|   X  |    C   |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |      |        |
 * `--------+------+------+--------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |PROGRAMS| BACK |                                       |SPACE |      |      |      |      |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | NUMB |      |      |       |      |        |      |
 *                                 | ERS  |      |------|       |------|        | TAB  |
 *                                 | (ENT)|      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R, KC_T, TG(SYMB),
  XXXXXXX, LSFT_T(KC_A), LCTL_T(KC_S), RALT_T(KC_D), LGUI_T(KC_F), KC_G,
  XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V, KC_B, ALL_T(KC_NO),
  XXXXXXX, XXXXXXX, XXXXXXX, OSL(_PROGRAMS), KC_BSPACE,
                                                                                XXXXXXX, XXXXXXX,
                                                                                         XXXXXXX,
                                                         LT(_NUMBERS1, KC_ENT), KC_BSPC, XXXXXXX,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
  KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), KC_RSFT,
  XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, XXXXXXX, XXXXXXX,
  LT(_ARROWS, KC_SPACE) XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX, LT(_NUMBERS2, KC_TAB)
),

/* Numbers 1
 *
 * ,----------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |        |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+--------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |    E   |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |    D   |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |      |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |Z/Ctrl|   X  |    C   |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |      |        |
 * `--------+------+------+--------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |PROGRAMS| BACK |                                       |SPACE |      |      |      |      |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | NUMB |      |      |       |      |        |      |
 *                                 | ERS  |      |------|       |------|        | TAB  |
 *                                 | (ENT)|      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_NUMBERS1] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R, KC_T, TG(SYMB),
  XXXXXXX, LSFT_T(KC_A), LCTL_T(KC_S), RALT_T(KC_D), LGUI_T(KC_F), KC_G,
  XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V, KC_B, ALL_T(KC_NO),
  XXXXXXX, XXXXXXX, XXXXXXX, OSL(_PROGRAMS), KC_BSPACE,
                                                                                XXXXXXX, XXXXXXX,
                                                                                         XXXXXXX,
                                                         LT(_NUMBERS1, KC_ENT), KC_BSPC, XXXXXXX,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
  KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), KC_RSFT,
  XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, XXXXXXX, XXXXXXX,
  LT(_ARROWS, KC_SPACE) XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX, LT(_NUMBERS2, KC_TAB)
),

/* Numbers 2
 *
 * ,----------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |        |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+--------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |    E   |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |    D   |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |      |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |Z/Ctrl|   X  |    C   |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |      |        |
 * `--------+------+------+--------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |PROGRAMS| BACK |                                       |SPACE |      |      |      |      |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | NUMB |      |      |       |      |        |      |
 *                                 | ERS  |      |------|       |------|        | TAB  |
 *                                 | (ENT)|      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_NUMBERS2] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R, KC_T, TG(SYMB),
  XXXXXXX, LSFT_T(KC_A), LCTL_T(KC_S), RALT_T(KC_D), LGUI_T(KC_F), KC_G,
  XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V, KC_B, ALL_T(KC_NO),
  XXXXXXX, XXXXXXX, XXXXXXX, OSL(_PROGRAMS), KC_BSPACE,
                                                                                XXXXXXX, XXXXXXX,
                                                                                         XXXXXXX,
                                                         LT(_NUMBERS1, KC_ENT), KC_BSPC, XXXXXXX,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
  KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), KC_RSFT,
  XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, XXXXXXX, XXXXXXX,
  LT(_ARROWS, KC_SPACE) XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX, LT(_NUMBERS2, KC_TAB)
),

/* Arrows
 *
 * ,----------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |        |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+--------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |    E   |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |    D   |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |      |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |Z/Ctrl|   X  |    C   |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |      |        |
 * `--------+------+------+--------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |PROGRAMS| BACK |                                       |SPACE |      |      |      |      |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | NUMB |      |      |       |      |        |      |
 *                                 | ERS  |      |------|       |------|        | TAB  |
 *                                 | (ENT)|      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_ARROWS] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R, KC_T, TG(SYMB),
  XXXXXXX, LSFT_T(KC_A), LCTL_T(KC_S), RALT_T(KC_D), LGUI_T(KC_F), KC_G,
  XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V, KC_B, ALL_T(KC_NO),
  XXXXXXX, XXXXXXX, XXXXXXX, OSL(_PROGRAMS), KC_BSPACE,
                                                                                XXXXXXX, XXXXXXX,
                                                                                         XXXXXXX,
                                                         LT(_NUMBERS1, KC_ENT), KC_BSPC, XXXXXXX,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
  KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), KC_RSFT,
  XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, XXXXXXX, XXXXXXX,
  LT(_ARROWS, KC_SPACE) XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX, LT(_NUMBERS2, KC_TAB)
),

/* Programs
 *
 * ,----------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |        |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+--------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |    E   |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |    D   |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |      |        |
 * |--------+------+------+--------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |Z/Ctrl|   X  |    C   |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |      |        |
 * `--------+------+------+--------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |PROGRAMS| BACK |                                       |SPACE |      |      |      |      |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | NUMB |      |      |       |      |        |      |
 *                                 | ERS  |      |------|       |------|        | TAB  |
 *                                 | (ENT)|      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_PROGRAMS] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R, KC_T, TG(SYMB),
  XXXXXXX, LSFT_T(KC_A), LCTL_T(KC_S), RALT_T(KC_D), LGUI_T(KC_F), KC_G,
  XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V, KC_B, ALL_T(KC_NO),
  XXXXXXX, XXXXXXX, XXXXXXX, OSL(_PROGRAMS), KC_BSPACE,
                                                                                XXXXXXX, XXXXXXX,
                                                                                         XXXXXXX,
                                                         LT(_NUMBERS1, KC_ENT), KC_BSPC, XXXXXXX,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
  KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), KC_RSFT,
  XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, XXXXXXX, XXXXXXX,
  LT(_ARROWS, KC_SPACE) XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX, LT(_NUMBERS2, KC_TAB)
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case NUMBERS1:
      if (record->event.pressed) {
        layer_on(_NUMBERS1);
      } else {
        layer_off(_NUMBERS1);
      }
      return false;
      break;
    case NUMBERS2:
      if (record->event.pressed) {
        layer_on(_NUMBERS2);
      } else {
        layer_off(_NUMBERS2);
      }
      return false;
      break;
    case ARROWS:
      if (record->event.pressed) {
        layer_on(_ARROWS);
      } else {
        layer_off(_ARROWS);
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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
