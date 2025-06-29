#include "print.h"
#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_0_255,
  ST_MACRO_0,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           LGUI(KC_UP),                                    LGUI(KC_LEFT),  KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,       
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           LGUI(KC_DOWN),                                  LGUI(KC_RIGHT), KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_BSLS,        
    KC_ESCAPE,      KC_A,           KC_R,           KC_S,           KC_T,           KC_D,           KC_BSPC,                                                                        CW_TOGG,        KC_H,           KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,       
    SC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_K,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       SC_RSPC,        
    KC_LBRC,        KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_SPACE,       LALT(LGUI(LCTL(LSFT(KC_F19)))),                                                                                                LCTL(LGUI(KC_Q)),KC_BSPC,        KC_RIGHT_GUI,   KC_RIGHT_ALT,   LGUI(LSFT(KC_P)),KC_RBRC,        
    LT(1,KC_ENTER), LALT(KC_F7),    MO(2),                          LALT(LGUI(LCTL(LSFT(KC_F13)))),LCTL(KC_SPACE), MO(1)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,LALT(LCTL(KC_LEFT)),LALT(LCTL(KC_RIGHT)),KC_TRANSPARENT, LGUI(KC_R),                                     KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, 
    KC_TRANSPARENT, LALT(LGUI(KC_QUOTE)),LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   LGUI(KC_QUOTE), TD(DANCE_0),    TD(DANCE_1),                                    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_MS_BTN2,     
    KC_TRANSPARENT, LCTL(KC_F16),   TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    LSFT(KC_F13),   LGUI(LSFT(KC_ENTER)),                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_DQUO,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_F16),                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LBRC,        KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_TRANSPARENT, MT(MOD_LALT, KC_RBRC),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          RGB_TOG,                                        KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MOON_LED_LEVEL,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_0_255,    
    QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(4),                                                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    CG_TOGG, TG(3),          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_K,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_J,           KC_NO,          KC_TRANSPARENT, KC_M,           KC_L,           KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT,                 KC_F12,         LCTL(KC_F12),   LCTL(KC_F11)
  ),
  [4] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,                                          KC_LEFT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_I,           KC_Q,           KC_W,           KC_R,           KC_E,           KC_DOWN,                                        KC_RIGHT,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_G,           KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_T,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT, 
    KC_Z,           KC_C,           KC_Z,           KC_X,           KC_G,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_F,           KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
const uint16_t PROGMEM combo0[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_RIGHT_ALT, LGUI(LSFT(KC_P)), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_MINUS),
    COMBO(combo1, KC_EQUAL),
    COMBO(combo2, ST_MACRO_0),
    COMBO(combo3, LGUI(KC_SPACE)),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [2] = { {0,0,0}, {0,0,0}, {108,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,201}, {0,0,201}, {0,0,0}, {0,0,201}, {0,0,201}, {0,0,201}, {0,0,201}, {0,0,0}, {0,0,201}, {108,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {79,251,148}, {0,218,204}, {79,251,148}, {0,0,0}, {0,0,0}, {79,251,148}, {0,218,204}, {79,251,148}, {0,0,0}, {0,0,0}, {0,0,0}, {79,251,148}, {79,251,148}, {0,0,0}, {0,0,0}, {79,251,148}, {0,218,204}, {79,251,148}, {0,0,0}, {79,251,148}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {79,251,148}, {0,0,0}, {0,0,0}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  const uint8_t cgtogg_led_index = 35; 
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  // Check if Control/GUI swap is active
  if (keymap_config.swap_lctl_lgui || keymap_config.swap_rctl_rgui) {
        // Blue when swap is ON (HSV: 170,255,255 → RGB: 0,0,255)
        rgb_matrix_set_color(cgtogg_led_index, 0, 0, 255);
    } else {
        // Turn off when swap is OFF
        rgb_matrix_set_color(cgtogg_led_index, 0, 0, 0);
    }
  return true;
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods(); 
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));
    }
    break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    case HSV_0_0_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(0,0,255);
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
    // case KC_F18:
    //     uprintf("F18");
    //     if (record->event.pressed) {
    //         bool ctlgui_swapped = keymap_config.swap_lctl_lgui || keymap_config.swap_rctl_rgui;
    //         bool hyper_active = (mod_state & MOD_MASK_CSAG);
    //         // uprintf("F18 pressed | swap: %d | mod_state: 0x%02X | gui_active: %d \n", ctlgui_swapped, mod_state, hyper_active);
    //         // Get actual modifier state after swap
    //         if (hyper_active) {
    //             if (ctlgui_swapped) {
    //                 del_mods(MOD_MASK_CSAG);
    //                 // uprintf("lock windows");
    //                 tap_code16(C(KC_L));
    //             } else {
    //                 del_mods(MOD_MASK_CG);
    //                 // uprintf("lock mac");
    //                 tap_code16(C(G(KC_Q)));
    //             }
    //         }
    //         return false;
    //     }
    //     return true;
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

static tap dance_state[5];

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
        tap_code16(LALT(LCTL(LGUI(KC_G))));
        tap_code16(LALT(LCTL(LGUI(KC_G))));
        tap_code16(LALT(LCTL(LGUI(KC_G))));
    }
    if(state->count > 3) {
        tap_code16(LALT(LCTL(LGUI(KC_G))));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LGUI(LSFT(KC_G))))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(LGUI(KC_G)))); register_code16(LALT(LCTL(LGUI(KC_G))));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_G))))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(LGUI(KC_G)))); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_F13));
        tap_code16(LCTL(KC_F13));
        tap_code16(LCTL(KC_F13));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_F13));
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_F13)); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LGUI(LSFT(KC_F17))))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_F13)); register_code16(LCTL(KC_F13));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_F13)); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_F17))))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_F13)); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F17);
        tap_code16(KC_F17);
        tap_code16(KC_F17);
    }
    if(state->count > 3) {
        tap_code16(KC_F17);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_F17); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F17)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F17); register_code16(KC_F17);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_F17); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F17)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F17); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LGUI(KC_F16)));
        tap_code16(LALT(LGUI(KC_F16)));
        tap_code16(LALT(LGUI(KC_F16)));
    }
    if(state->count > 3) {
        tap_code16(LALT(LGUI(KC_F16)));
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LALT(LGUI(KC_F16))); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F13)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LGUI(KC_F16))); register_code16(LALT(LGUI(KC_F16)));
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LALT(LGUI(KC_F16))); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F13)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LGUI(KC_F16))); break;
    }
    dance_state[4].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
};
