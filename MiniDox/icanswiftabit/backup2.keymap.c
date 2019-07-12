#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUMBERS 1
#define _ARROWS 2
#define _PROGRAMS 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBERS,
  ARROWS,
  PROGRAMS,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

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
 *                              ,-----------------------------------.     ,---------------,--------------.
 *                              | PROGRAMS |  BACK   |              |     |               | SPACE |      |
 *                              `--------------------| NUMBERS(ENT) |     | NUMBERS2(TAB) |-------+------'
 *                                                   |              |     |               |
 *                                                   `--------------'     `---------------'
 */       
[_QWERTY] = LAYOUT( \
                KC_Q,         KC_W,         KC_E,         KC_R, KC_T,     KC_Y, KC_U,          KC_I,         KC_O,         KC_P,    \
        LSFT_T(KC_A), LCTL_T(KC_S), RALT_T(KC_D), LGUI_T(KC_F), KC_G,     KC_H, RGUI_T(KC_J),  RALT_T(KC_K), RCTL_T(KC_L), KC_RSFT, \
                KC_Z,         KC_X,         KC_C,         KC_V, KC_B,     KC_N, KC_M,          KC_COMM,      KC_DOT,       XXXXXXX, \
                     OSL(_PROGRAMS), KC_BSPACE, LT(_NUMBERS, KC_ENT),    LT(_ARROWS, KC_TAB), KC_SPACE,     XXXXXXX    \
),

/* Numbers
 *
 *                    ,---------------------------------------------.     ,-------------------------------------------.
 *                    |         |    `    |    -    |    =    |     |     |     |    7    |    8    |    9    |       |
 *                    |---------+---------+---------+---------+-----|     |-----+---------+---------+---------+-------|
 *                    | KC_LSFT |LCTL_T([)|RALT_T(])|LGUI_T(\)|     |     |     |RGUI_T(4)|RALT_T(5)|RCTL_T(6)|KC_RSFT|
 *                    |---------+---------+---------+---------+-----|     |-----+---------+---------+---------+-------|
 *                    |         |    ;    |    '    |    /    |     |     |     |    1    |    2    |    3    |       |
 *                    `---------------------------------------------'     `-------------------------------------------'
 *                                          ,-----------------------.     ,-----,-------------.
 *                                          | CAPS | ESC  |         |     |     |   0  |      |
 *                                          `-------------|         |     |     |------+------'
 *                                                        |         |     |     |
 *                                                        `---------'     `-----'
 */       
[_NUMBERS] = LAYOUT( \
 XXXXXXX,          KC_GRV,         KC_MINS,         KC_EQL,  XXXXXXX,      XXXXXXX, KC_7,         KC_8,         KC_9,         XXXXXXX,    \
 KC_LSFT, LCTL_T(KC_LBRC), RALT_T(KC_RBRC), LGUI_T(KC_BSLS), XXXXXXX,      XXXXXXX, RGUI_T(KC_4), RALT_T(KC_5), RCTL_T(KC_6) , KC_RSFT, \
 XXXXXXX,         KC_SCLN,         KC_QUOT,         KC_SLSH, XXXXXXX,      XXXXXXX, KC_1,         KC_2,      KC_3,       XXXXXXX, \
                                           KC_CAPS,  KC_ESC, XXXXXXX,      XXXXXXX, KC_0, XXXXXXX                 \
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
                                      XXXXXXX,  KC_F15, LSFT(KC_F15),    XXXXXXX, XXXXXXX, XXXXXXX                 \
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
