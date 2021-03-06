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
bool toggleCam = false;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
          KC_MUTE,   KC_MPLY,
    KC_LSHIFT, KC_7, KC_8, KC_9,
    KC_LCTRL, KC_4, KC_5, KC_6,
    KC_LALT, KC_1, KC_2, KC_3,
    KC_LGUI, TG(1), KC_0, KC_DOLLAR
  ),
  [1] = LAYOUT( /* Meeting Controls */
        _______,           _______,
    LSFT(KC_F18) /*  Toggle mic  */ , _______, _______, _______,
    LCTL(KC_F18) /*  Toggle cam  */, _______, _______, _______,
    LALT(KC_F18) /*  Toggle both */, _______, _______, _______,
    LGUI(KC_F18), _______, _______, _______
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

const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 12, 0}
    );
const rgblight_segment_t PROGMEM meeting_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 5, HSV_GREEN},
        {6, 12, HSV_GREEN}
    );
const rgblight_segment_t PROGMEM mic_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 5, HSV_RED}
    );
const rgblight_segment_t PROGMEM cam_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {6, 12, HSV_RED}
    );
const rgblight_segment_t PROGMEM micAndCam_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 12, HSV_RED}
    );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        base_layer,
        meeting_layer,
        mic_layer,
        cam_layer,
        micAndCam_layer
    );

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));

    if (rgblight_get_layer_state(1)) {
        // Restore state 
        rgblight_set_layer_state(2,toggleMic);
        rgblight_set_layer_state(3,toggleCam);
    } else { 
        // Allow base_layer rgb exclusively
        rgblight_set_layer_state(2, layer_state_cmp(state, 2));
        rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    }
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    layer_state_set_user(layer_state);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        // Mic
        case LSFT(KC_F18):
        if (record->event.pressed) {
            toggleMic = !toggleMic;
        } else {}
        break;
        
        // Cam
        case LCTL(KC_F18):
        if (record->event.pressed) {
            toggleCam = !toggleCam;
        } else {}
        break;

        // Both
        case LALT(KC_F18):
        if (record->event.pressed) {
            if (!toggleCam || !toggleMic) {
                toggleCam = true;
                toggleMic = true;    
            } else {
                toggleCam = !toggleCam;
                toggleMic = !toggleMic;
            }
            
        } else {}
        break;
    }

    if (rgblight_get_layer_state(1)) {
        rgblight_set_layer_state(2,toggleMic);
        rgblight_set_layer_state(3,toggleCam);
    }

    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left Encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Right Encoder */
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
}
