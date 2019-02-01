#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUMBERS1 1
#define _NUMBERS2 2
#define _ARROWS 3
#define _PROGRAMS 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBERS1,
  NUMBERS2,
  ARROWS,
  PROGRAMS,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 *                    ,---------------------------------------------.     ,-----------------------------------------------.
 *                    |    Q    |    W    |    E    |    R    |  T  |     |    Y    |    U    |    I    |    O    |   P   |
 *                    |---------+---------+---------+---------+-----|     |---------+---------+---------+---------+-------|
 *                    |LSFT_T(A)|LCTL_T(S)|RALT_T(D)|LGUI_T(F)|  G  |     |    H    |RGUI_T(J)|RALT_T(K)|RCTL_T(L)|KC_RSFT|
 *                    |---------+---------+---------+---------+-----|     |---------+---------+---------+---------+-------|
 *                    |    Z    |    X    |    C    |    V    |  B  |     |    N    |    M    |    ,    |    .    |       |
 *                    `---------------------------------------------'     `-----------------------------------------------'
 *                              ,-----------------------------------.     ,------,-------------.
 *                              |OSL(_PROGRAMS)| BACK |              |     |      | SPACE|      |
 *                              `--------------------| NUMBERS(ENT) |     | TAB  |------+------'
 *                                                   |              |     |      |
 *                                                   `--------------'     `------'
 */       
[_QWERTY] = LAYOUT( \
                KC_Q,         KC_W,         KC_E,         KC_R, KC_T,     KC_Y, KC_U,         KC_I,         KC_O,         KC_P,    \
        LSFT_T(KC_A), LCTL_T(KC_S), RALT_T(KC_D), LGUI_T(KC_F), KC_G,     KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), KC_RSFT, \
                KC_Z,         KC_X,         KC_C,         KC_V, KC_B,     KC_N, KC_M,         KC_COMM,      KC_DOT,       XXXXXXX, \
                      OSL(_PROGRAMS), KC_BSPACE, LT(_NUMBERS1, KC_ENT),    LT(_NUMBERS2, KC_TAB), LT(_ARROWS, KC_SPACE), XXXXXXX                 \
),

/* Numbers 1
 *
 *                    ,---------------------------------------------.     ,-------------------------------------------.
 *                    |         |    `    |    -    |    =    |     |     |     |    7    |    8    |    9    |   0   |
 *                    |---------+---------+---------+---------+-----|     |-----+---------+---------+---------+-------|
 *                    | KC_LSFT |LCTL_T([)|RALT_T(])|LGUI_T(\)|  G  |     |     |RGUI_T(4)|RALT_T(5)|RCTL_T(6)|KC_RSFT|
 *                    |---------+---------+---------+---------+-----|     |-----+---------+---------+---------+-------|
 *                    |         |    ;    |    '    |    /    |     |     |     |    1    |    2    |    3    |       |
 *                    `---------------------------------------------'     `-------------------------------------------'
 *                                          ,-----------------------.     ,-----,-------------.
 *                                          |      |      |         |     |     |   0  |      |
 *                                          `-------------| NUMBERS |     |     |------+------'
 *                                                        |         |     |     |
 *                                                        `---------'     `-----'
 */       
[_NUMBERS1] = LAYOUT( \
 XXXXXXX,          KC_GRV,         KC_MINS,         KC_EQL,  XXXXXXX,      XXXXXXX, KC_7,         KC_8,         KC_9,         XXXXXXX,    \
 KC_LSFT, LCTL_T(KC_LBRC), RALT_T(KC_RBRC), LGUI_T(KC_BSLS), XXXXXXX,      XXXXXXX, RGUI_T(KC_4), RALT_T(KC_5), RCTL_T(KC_6) , KC_RSFT, \
 XXXXXXX,         KC_SCLN,         KC_QUOT,         KC_SLSH, XXXXXXX,      XXXXXXX, KC_1,         KC_2,      KC_3,       XXXXXXX, \
                                           XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_0, XXXXXXX                 \
),

/* Numbers 2
 *
 *                    ,---------------------------------------------.     ,-------------------------------------------.
 *                    |         |    `    |    -    |    =    |     |     |     |    7    |    8    |    9    |   0   |
 *                    |---------+---------+---------+---------+-----|     |-----+---------+---------+---------+-------|
 *                    | KC_LSFT |LCTL_T([)|RALT_T(])|LGUI_T(\)|  G  |     |     |RGUI_T(4)|RALT_T(5)|RCTL_T(6)|KC_RSFT|
 *                    |---------+---------+---------+---------+-----|     |-----+---------+---------+---------+-------|
 *                    |         |    ;    |    '    |    /    |     |     |     |    1    |    2    |    3    |       |
 *                    `---------------------------------------------'     `-------------------------------------------'
 *                                          ,-----------------------.     ,-----,-------------.
 *                                          |      | CAPS |         |     |     |   0  |      |
 *                                          `-------------|   ESC   |     |     |------+------'
 *                                                        |         |     |     |
 *                                                        `---------'     `-----'
 */       
[_NUMBERS2] = LAYOUT( \
 XXXXXXX,          KC_GRV,         KC_MINS,         KC_EQL,  XXXXXXX,      XXXXXXX, KC_7,         KC_8,         KC_9,         XXXXXXX,    \
 KC_LSFT, LCTL_T(KC_LBRC), RALT_T(KC_RBRC), LGUI_T(KC_BSLS), XXXXXXX,      XXXXXXX, RGUI_T(KC_4), RALT_T(KC_5), RCTL_T(KC_6) , KC_RSFT, \
 XXXXXXX,         KC_SCLN,         KC_QUOT,         KC_SLSH, XXXXXXX,      XXXXXXX, KC_1,         KC_2,      KC_3,       XXXXXXX, \
                                           XXXXXXX, KC_CAPS,  KC_ESC,      XXXXXXX, KC_0, XXXXXXX                 \
),

/* Arrows
 *
 *                    ,---------------------------------------------.     ,---------------------------------------------.
 *                    |         |   NEXT  |   PLAY  |   NEXT  |     |     |     |         |         |         |         |
 *                    |---------+---------+---------+---------+-----|     |-----+---------+---------+---------+---------|
 *                    |         |         |         |         |     |     |     | AR LEFT |  AR UP  | AR DOWN | AR RGHT |
 *                    |---------+---------+---------+---------+-----|     |-----+---------+---------+---------+---------|
 *                    |         |  VOL DN | VOL MUTE|  VOL UP |     |     |     |  HOME   |  PG UP  |  PG DN  |   END   |
 *                    `---------------------------------------------'     `---------------------------------------------'
 *                                          ,-----------------------.     ,-----,-------------.
 *                                          |      | DEL  |         |     |     |      |      |
 *                                          `-------------|         |     |     |-------------'
 *                                                        |         |     |     |
 *                                                        `---------'     `-----'
 */       
[_ARROWS] = LAYOUT( \
                         XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                         _______, _______, _______, _______, XXXXXXX,     XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, \
                         XXXXXXX, KC__VOLDOWN, KC__MUTE, KC__VOLUP, XXXXXXX,     XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END, \
                                           XXXXXXX,  KC_DEL, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX                 \
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
KC_F12, LSFT(KC_F12), LCTL(KC_F12), LALT(KC_F12), LSFT(LCTL(KC_F12)),     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
KC_F13, LSFT(KC_F13), LCTL(KC_F13), LALT(KC_F13), LSFT(LCTL(KC_F13)),     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
KC_F14, LSFT(KC_F14), LCTL(KC_F14), LALT(KC_F14), LSFT(LCTL(KC_F14)),     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                           XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX                 \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, _______, _______,      _______, _______, _______, TSKMGR, CALTDEL, \
  RESET,   _______, _______, _______, _______,      _______, _______, _______, _______,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
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
