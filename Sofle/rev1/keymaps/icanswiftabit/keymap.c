/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// clang-format off

#include QMK_KEYBOARD_H
#include "oled.c"

#define KC_MICLOCK LALT(LGUI(LCTL(LSFT(KC_F19))))

enum custom_keycodes {
  ARROW_MACRO = SAFE_RANGE,
  LOCK_SCREEN,
  FLIP_TABLE,
  PUT_TABLE,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};

// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MO(2),
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  KC_ESC,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  SC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                     KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    SC_RSPC,
  KC_MUTE, KC_LEFT_CTRL,KC_LEFT_ALT,KC_LEFT_GUI,KC_SPACE, LT(1, KC_ENTER),      MO(1),  KC_BSPC, KC_RGUI,KC_RIGHT_ALT,LGUI(LSFT(KC_P)),
                                                              KC_ENTER, KC_RIGHT, KC_UP, KC_LEFT, KC_DOWN
),

[1] = LAYOUT(
  S(A(G(KC_F))), LCAG(KC_G), HYPR(KC_G), LALT(LCTL(KC_LEFT)),LALT(LCTL(KC_RIGHT)),LALT(KC_F7),                     KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,_______, _______, _______, _______,
  LGUI(KC_UP),   LALT(LGUI(KC_QUOTE)),LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   LGUI(KC_QUOTE), TD(DANCE_0),                      KC_MS_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_BTN2,
  LGUI(KC_DOWN),   LCTL(KC_F16),   TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    LSFT(KC_F13),                      _______, _______, _______, _______, _______, _______,
  _______,  _______, _______, _______, _______, LALT(KC_F16),                      _______,    _______, _______,  _______, _______,  _______,
                 KC_MICLOCK, _______,_______,_______,_______, _______,      _______,  _______, _______, _______, _______,
                                                              _______, _______, _______, _______, _______
),

[2] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,    _______,    _______,    _______,    _______,    _______,     _______,    _______,    _______,    _______,    TG(3), LOCK_SCREEN,
  _______, _______,   _______, _______,  _______, _______,                       _______, _______, _______, _______, CG_TOGG, FLIP_TABLE,
  _______,  _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, PUT_TABLE,
                       _______,_______, _______, _______, _______, _______,       _______, _______, _______, _______, QK_BOOT,
                                                              _______, _______, _______, _______, _______
),

[3] = LAYOUT(
  KC_MICLOCK, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  _______,  _______,   _______,  _______, _______,                        _______, _______,   _______, _______,_______, _______,
  _______, KC_LEFT_SHIFT,  _______,  _______,  _______, _______,                       _______,  _______, _______, _______,  _______, _______,
  KC_K,    _______, _______, _______, _______, _______,                           _______, _______, _______, _______,   _______, _______,
                         _______,_______, _______, KC_M, KC_L, KC_SPACE,       _______, _______, _______, _______, _______,
                                                              KC_ENTER, KC_RIGHT, KC_UP, KC_LEFT, KC_DOWN
)
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [1] = { ENCODER_CCW_CW(KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};

const uint16_t PROGMEM combo0[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ARROW_COMBO[] = { KC_W, KC_F, KC_P, COMBO_END};       
const uint16_t PROGMEM combo3[] = { KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo5[] = { LGUI(LSFT(KC_P)), KC_RIGHT_ALT, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_ESCAPE, KC_A, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_MINUS),
    COMBO(combo1, KC_EQUAL),
    COMBO(ARROW_COMBO, ARROW_MACRO),
    COMBO(combo3, KC_LBRC),
    COMBO(combo4, KC_RBRC),
    COMBO(combo5, RGUI(KC_SPACE)),
    COMBO(combo6, KC_BSPC),
};

uint8_t mod_state;
bool isSwapped;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods(); 
  switch (keycode) {
    case FLIP_TABLE:
        if (record->event.pressed) {
            SEND_STRING("(╯°□°）╯︵ ┻━┻");
        }
        return false;

    case PUT_TABLE:
        if (record->event.pressed) {
            SEND_STRING("┬─┬ノ( º _ ºノ)");
        }
        return false;

    case ARROW_MACRO:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_MINUS)SS_DELAY(100)  SS_LSFT(SS_TAP(X_DOT)));
        }
        return false;

    case LOCK_SCREEN:
        isSwapped = keymap_config.swap_lctl_lgui || keymap_config.swap_rctl_rgui;
        if (record->event.pressed) {
            if (isSwapped) {
                tap_code16(LGUI(KC_L));
            } else {
                tap_code16(LGUI(LCTL(KC_Q)));
            }
        }
        return false;
       

    case KC_SLSH:
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_SLSH);
                set_mods(mod_state);
            } else {
                tap_code16(S(KC_SLSH));
            }
            return false;
        }
        return true;
    case KC_LBRC:
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_LBRC);
                set_mods(mod_state);
            } else {
                tap_code16(S(KC_LBRC));
            }
            return false;
        }
        return true;
    case KC_RBRC:
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_RBRC);
                set_mods(mod_state);
            } else {
                tap_code16(S(KC_RBRC));
            }
            return false;
        }
        return true;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[4];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_F12));
        tap_code16(LSFT(KC_F12));
        tap_code16(LSFT(KC_F12));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_F12));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_F12)); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_F12)); register_code16(LSFT(KC_F12));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_F12)); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_F12)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_F13));
        tap_code16(LCTL(KC_F13));
        tap_code16(LCTL(KC_F13));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_F13));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_F13)); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LGUI(LSFT(KC_F17))))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_F13)); register_code16(LCTL(KC_F13));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_F13)); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_F17))))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_F13)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F17);
        tap_code16(KC_F17);
        tap_code16(KC_F17);
    }
    if(state->count > 3) {
        tap_code16(KC_F17);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_F17); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F17)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F17); register_code16(KC_F17);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_F17); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F17)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F17); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LGUI(KC_F16)));
        tap_code16(LALT(LGUI(KC_F16)));
        tap_code16(LALT(LGUI(KC_F16)));
    }
    if(state->count > 3) {
        tap_code16(LALT(LGUI(KC_F16)));
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(LALT(LGUI(KC_F16))); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F13)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LGUI(KC_F16))); register_code16(LALT(LGUI(KC_F16)));
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(LALT(LGUI(KC_F16))); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F13)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LGUI(KC_F16))); break;
    }
    dance_state[3].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
};
