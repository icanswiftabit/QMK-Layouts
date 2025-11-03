/* Copyright 2019 Josh Johnson
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
#include QMK_KEYBOARD_H

bool toggleMic = false;
bool toggleAppverk = false;
bool spaceNavigation = false;

enum {
    TD_DOT_COMMA,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_DOT_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA),
};

// Remeber your keyboard is rotated 45°
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_TRANSPARENT,   KC_TRANSPARENT,
    KC_BACKSPACE, KC_KP_7, KC_KP_8, KC_KP_9,
    KC_TAB, KC_KP_4, KC_KP_5, KC_KP_6,
    KC_NUM, KC_KP_1, KC_KP_2, KC_KP_3,
    KC_ENTER/*TG(1)*/, KC_KP_ENTER, KC_0, TD(TD_DOT_COMMA)
    ),

  [1] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_F12, LSFT(KC_F12), LCTL(KC_F12), LALT(KC_F12),
    KC_F13, LSFT(KC_F13), LCTL(KC_F13), LALT(KC_F13),
    KC_F15, LSFT(KC_F15), HYPR(KC_F15), LALT(KC_F15),
    KC_TRANSPARENT, LSFT(KC_F16), LCTL(KC_F16), _______
    ),

  [2] = LAYOUT(
    _______,           _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
    ),

  [3] = LAYOUT(
    _______,           _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
    ),
};


// ------RGB------
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, 0}
    );
const rgblight_segment_t PROGMEM mic_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
    );
// const rgblight_segment_t PROGMEM appverk_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 12, HSV_WHITE}
//     );


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    mic_layer
    // appverk_layer
    );

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    layer_state_set_user(layer_state);
}

// --------------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case LALT(KC_F12):
        //     if (record->event.pressed) {
        //         toggleAppverk = false;
        //         toggleNord = !toggleNord;
        //     } else {}
        //     break;
        // case LALT(KC_F13):
        //     if (record->event.pressed) {
        //         toggleNord = false;
        //         toggleAppverk = !toggleAppverk;
        //     } else {}
        //     break;
        // case HYPR(KC_F18):
        //     if (record->event.pressed) {
        //         toggleAppverk = false;
        //         toggleNord = false;
        //     } else {}
        //     break;
        case LALT(KC_F12):
            if (record->event.pressed) {
                spaceNavigation = !spaceNavigation;
            }
        break;
        case LCTL(KC_F12):
                if (record->event.pressed) {
                toggleMic = !toggleMic;
            }
            break;
    }
    
    rgblight_set_layer_state(1, toggleMic);
    // rgblight_set_layer_state(2,toggleAppverk);
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    // clockwise = !clockwise; // Encoders are inverted
    // /* Left Encoder */
    // if (index == 0) { 
    //     if (clockwise) {
    //         tap_code(KC_MNXT);
    //     } else {
    //         tap_code(KC_MPRV);
    //     }
    //     /* Right Encoder */
    // } else if (index == 1) { 
    //     if (clockwise) {
    //         // if (spaceNavigation) {
    //         //     tap_code16(C(KC_RIGHT));
    //         // } else {
    //         tap_code(KC_BRIU);
    //         // }
    //     } else {
    //         // if (spaceNavigation) {
    //         //     tap_code16(C(KC_LEFT));
    //         // } else {
    //         tap_code(KC_BRID);
    //         // }
    //     }
    // }
    return false;
}
