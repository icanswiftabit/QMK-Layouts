/*
Copyright 2026 Blazej Wdowikowski

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "debounce.h"

enum layers {
    _BASE,
    _FN,
    _GAME
};

enum custom_keycodes {
    MC_ZED = SAFE_RANGE,
    MC_XO,
    MC_FORK,
    MC_TMUX_COMMAND,
    LOCK_SCREEN
};

enum tap_dances {
    TD_MESS_TELEGRAM_OPEN,
    TD_XCODE_ZED_OPEN
};

enum combo_events {
    LBRC_COMBO,
    RBRC_COMBO,
    EQL_COMBO,
    MINS_COMBO,
    ARROW_COMBO,
    COMMAND_PALETTE_COMBO,
    BACKSPACE_COMBO,
    GRAVE_COMBO
};

const uint16_t PROGMEM lbrc_combo[]            = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rbrc_combo[]            = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM eql_combo[]             = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM mins_combo[]            = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM arrow_combo[]           = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM command_palette_combo[] = {KC_RGUI, KC_RALT, COMBO_END};
const uint16_t PROGMEM backspace_combo[]       = {KC_ESC, KC_A, COMBO_END};
const uint16_t PROGMEM grave_combo[]           = {KC_Z, SC_LSPO, COMBO_END};

combo_t key_combos[] = {
    [LBRC_COMBO]            = COMBO_ACTION(lbrc_combo),
    [RBRC_COMBO]            = COMBO_ACTION(rbrc_combo),
    [EQL_COMBO]             = COMBO(eql_combo, KC_EQL),
    [MINS_COMBO]            = COMBO(mins_combo, KC_MINS),
    [ARROW_COMBO]           = COMBO_ACTION(arrow_combo),
    [COMMAND_PALETTE_COMBO] = COMBO(command_palette_combo, RGUI(RSFT(KC_P))),
    [BACKSPACE_COMBO]       = COMBO(backspace_combo, KC_BSPC),
    [GRAVE_COMBO]           = COMBO(grave_combo, KC_GRV)
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_MESS_TELEGRAM_OPEN] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_F12), KC_F13),
    [TD_XCODE_ZED_OPEN]     = ACTION_TAP_DANCE_DOUBLE(S(KC_F17), KC_F17)
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return get_highest_layer(layer_state | default_layer_state) != _GAME;
}

static uint8_t mod_state;

static void update_control_gui_swap_led(void) {
#ifdef LED_CAPS_LOCK_PIN
    gpio_write_pin(LED_CAPS_LOCK_PIN, keymap_config.swap_lctl_lgui ? LED_PIN_ON_STATE : !LED_PIN_ON_STATE);
#endif
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    mod_state = get_mods();

    switch (combo_index) {
        case ARROW_COMBO:
            if (pressed) {
                tap_code16(KC_MINS);
                tap_code16(S(KC_DOT));
            }
            break;

        case LBRC_COMBO:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_LBRC);
                    set_mods(mod_state);
                } else {
                    tap_code16(S(KC_LBRC));
                }
            }
            break;

        case RBRC_COMBO:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_RBRC);
                    set_mods(mod_state);
                } else {
                    tap_code16(S(KC_RBRC));
                }
            }
            break;
    }
}

void matrix_scan_user(void) {
    update_control_gui_swap_led();
}

bool led_update_user(led_t led_state) {
    update_control_gui_swap_led();
    return false;
}

bool isSwapped;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case LOCK_SCREEN:
            isSwapped = keymap_config.swap_lctl_lgui || keymap_config.swap_rctl_rgui;
            if (isSwapped) {
                tap_code16(LGUI(KC_L));
            } else {
                tap_code16(LGUI(LCTL(KC_Q)));
            }
            return false;

        case MC_ZED:
            SEND_STRING("!zed ." SS_TAP(X_ENTER));
            return false;

        case MC_XO:
            SEND_STRING("!xo ." SS_TAP(X_ENTER));
            return false;

        case MC_FORK:
            SEND_STRING("!fork ." SS_TAP(X_ENTER));
            return false;

        case MC_TMUX_COMMAND:
            tap_code16(G(KC_B));
            tap_code16(S(KC_SCLN));
            return false;

        case KC_SLSH:
            mod_state = get_mods();
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
}

/*
Layer diagrams:

[_BASE]
,--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------.
|   Fn   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  NO  |  NO  |  \   | Bspc |LockQ |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|  Tab   |  Q   |  W   |  F   |  P   |  G   |  J   |  L   |  U   |  Y   |  ;   |  NO  |  NO  |  \   | Vol+ |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|  Esc   |  A   |  R   |  S   |  T   |  D   |  H   |  N   |  E   |  I   |  O   |  '   |  NO  |Enter | Vol- |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|  LSPO  | NUBS |  Z   |  X   |  C   |  V   |  B   |  K   |  M   |  ,   |  .   |  /?  | RSPC |  Up  | Mute |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
| LCtrl  | LAlt   | LGui   |             Space             | RGui   | RAlt   | Left   | Down   | Right  |
`--------+--------+--------+-------------------------------+--------+--------+--------+--------+--------'

[_FN]
,--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------+------.
|   NO   | Slack  | iTerm  |Xcode/Zd|  Fork  | 1Pass  |  NO  |  NO  | !zed | !xo  |!fork |  NO  |  NO  | Boot | Boot |      |
|--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------|------|
| Game   | Safari |   NO   |        |        |        |      |      |      |      |      |      |      |      | Bri+ |
|--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------|------|
|CG_TOGG | Msg/Tg |  Mail  | Things |        |        |      |      |      |      |      |      |      |      | Bri- |
|--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------|------|
|        |        | MEH(F) | G(Down)| G(Up)  | C-b:   |LCAG(G)|     |      |      |      |      | Ms1  | MsUp |HyprF19|
|--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------|------|
| LAG(') |  G(')  |        |             Enter             |        |        | MsLft  | MsDwn  | MsRgt  |
`--------+--------+--------+-------------------------------+--------+--------+--------+--------+--------'

[_GAME]
,--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------.
|  Base  |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|        |      |      |      |      |      |      | Esc  | Tab  |  Q   |  W   |  E   |  R   |  T   |      |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|        |      |      |      |      |      |      |      | LSft |  A   |  S   |  D   |      |  F   |      |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|        |      |      |      |      |      |      |  K   |  Z   |  X   |  C   |  V   |  B   |      | LAlt |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|        |        |        |             Space             |   M    |   L    | Space  | LGui   |        |
`--------+--------+--------+-------------------------------+--------+--------+--------+--------+--------'

Legend: Slack=C(F13), iTerm=LCA(F16), Xcode/Zd=KC_F17/S(KC_F17),
Fork=LAG(F16), Safari=C(F16), Msg/Tg=S(KC_F12)/KC_F13,
Mail=S(F13), Things=A(F16), LockQ=C(G(Q)).
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_wired(
        MO(_FN),  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_NO,  KC_NO, KC_BSLS, KC_BSPC, LOCK_SCREEN,
        KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,   KC_G,   KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_NO,      KC_NO,        KC_BSLS, KC_VOLU,
        KC_ESC,  KC_A,    KC_R,    KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,    KC_NO,      KC_ENT,  KC_VOLD,
        SC_LSPO, KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    SC_RSPC,      KC_UP,   KC_MUTE,
        KC_LCTL, KC_LALT, KC_LGUI,          KC_SPC,                         KC_RGUI, KC_RALT,                  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT_wired(
        KC_NO,   C(KC_F13), LCA(KC_F16), TD(TD_XCODE_ZED_OPEN), LAG(KC_F16), A(KC_F7), KC_NO,   KC_NO,   MC_ZED,  MC_XO,   MC_FORK, KC_NO, KC_NO,   QK_BOOT, QK_BOOT, KC_TRNS,
        DF(_GAME), C(KC_F16), KC_NO,       KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRIU,
        CG_TOGG, TD(TD_MESS_TELEGRAM_OPEN), S(KC_F13),   A(KC_F16), KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID,
        KC_TRNS,  KC_TRNS,   S(A(G(KC_F))), G(KC_DOWN), G(KC_UP), MC_TMUX_COMMAND, LCAG(KC_G), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_UP, HYPR(KC_F19),
        LAG(KC_QUOT), G(KC_QUOT), KC_TRNS,           KC_ENT,                                 KC_TRNS, KC_TRNS,            KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
    ),

    [_GAME] = LAYOUT_wired(
        DF(_BASE),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_TRNS, KC_F,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS, KC_LALT,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_SPC,                                      KC_M,    KC_L,             KC_SPC,  KC_LGUI, KC_TRNS
    )
};
