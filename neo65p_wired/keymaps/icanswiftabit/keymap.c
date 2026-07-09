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
    LOCK_SCREEN,
    GAME_TOGGLE
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
    GRAVE_COMBO,
    FN_COMBO
};

const uint16_t PROGMEM lbrc_combo[]            = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rbrc_combo[]            = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM eql_combo[]             = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM mins_combo[]            = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM arrow_combo[]           = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM command_palette_combo[] = {KC_RGUI, KC_RALT, COMBO_END};
const uint16_t PROGMEM backspace_combo[]       = {KC_ESC, KC_A, COMBO_END};
const uint16_t PROGMEM grave_combo[]           = {KC_Z, SC_LSPO, COMBO_END};
const uint16_t PROGMEM fn_combo[]              = {KC_A, KC_R, COMBO_END};

combo_t key_combos[] = {
    [LBRC_COMBO]            = COMBO_ACTION(lbrc_combo),
    [RBRC_COMBO]            = COMBO_ACTION(rbrc_combo),
    [EQL_COMBO]             = COMBO(eql_combo, KC_EQL),
    [MINS_COMBO]            = COMBO(mins_combo, KC_MINS),
    [ARROW_COMBO]           = COMBO_ACTION(arrow_combo),
    [COMMAND_PALETTE_COMBO] = COMBO(command_palette_combo, RGUI(RSFT(KC_P))),
    [BACKSPACE_COMBO]       = COMBO(backspace_combo, KC_BSPC),
    [GRAVE_COMBO]           = COMBO(grave_combo, KC_GRV),
    [FN_COMBO]              = COMBO_ACTION(fn_combo)
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_MESS_TELEGRAM_OPEN] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_F12), KC_F13),
    [TD_XCODE_ZED_OPEN]     = ACTION_TAP_DANCE_DOUBLE(S(KC_F17), KC_F17)
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return get_highest_layer(layer_state | default_layer_state) != _GAME;
}

static uint8_t mod_state;

enum {
    STATUS_LED_BLINK_PERIOD_MS = 1000,
    STATUS_LED_BLINK_ON_MS     = 125,
    STATUS_LED_BLINK_GAP_MS    = 125
};

static bool is_game_layer_active(void) {
    return get_highest_layer(default_layer_state) == _GAME;
}

static bool is_cg_swapped(void) {
    return keymap_config.swap_lctl_lgui || keymap_config.swap_rctl_rgui;
}

static void write_caps_led(bool on) {
#ifdef LED_CAPS_LOCK_PIN
    gpio_write_pin(LED_CAPS_LOCK_PIN, on ? LED_PIN_ON_STATE : !LED_PIN_ON_STATE);
#endif
}

static void update_status_led(void) {
    bool cg   = is_cg_swapped();
    bool game = is_game_layer_active();

    if (cg && game) {
        uint16_t elapsed = timer_read() % STATUS_LED_BLINK_PERIOD_MS;
        write_caps_led(elapsed < STATUS_LED_BLINK_ON_MS ||
                       (elapsed >= STATUS_LED_BLINK_ON_MS + STATUS_LED_BLINK_GAP_MS &&
                        elapsed < 2 * STATUS_LED_BLINK_ON_MS + STATUS_LED_BLINK_GAP_MS));
    } else if (cg) {
        write_caps_led(true);
    } else {
        write_caps_led(false);
    }
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

        case FN_COMBO:
            if (pressed) {
                layer_on(_FN);
            } else {
                layer_off(_FN);
            }
            break;
    }
}

void matrix_scan_user(void) {
    update_status_led();
}

bool led_update_user(led_t led_state) {
    (void)led_state;
    update_status_led();
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

        case GAME_TOGGLE:
            if (is_cg_swapped()) {
                set_single_default_layer(_GAME);
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
| LockQ* |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | MPLY | MNXT |    Bspc     |      |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|  Tab   |  Q   |  W-  |  F-  | P->  |  G   |  J   |  L   |  U=  |  Y=  |  ;   |  NO  |  NO  |  \   |      | Vol+ |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
| Esc+A  | A+R  | R+FN |  S{  |  T{  |  D   |  H   |  N}  |  E}  |  I   |  O   |  '   | Enter              | Vol- |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|    LSPO+`     |  Z`  |  X   |  C   |  V   |  B   |  K   |  M   |  ,   |  .   | ?//  | RSPC        |  Up  | Mute |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
| LCtrl  | LAlt   | LGui   |     Space                      | RGui+P | RAlt+P |        | Left   | Down   | Right  |
`--------+--------+--------+-----------------------------------------+--------+--------+--------+--------+--------'

[_FN]
,--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------+------.
| Boot*  | Fetch  |  Pull  |  Push  | C-b:*  | Tests |       |      |!zed* | !xo* |!fork*|      |      |      |      |      |
|--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------|------|
| CG*    |        |        | iTerm  |  Zed   | Xcode |       |      |      |      |      |      |      |     |       | Bri+ |
|--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------|------|
| Game*  |  A+R => _FN     | Slack  |  Fork  | Safari|       |      |      |      |      |      |                    | Bri- |
|--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------|------|
|                 |        | Msg/Tg |  Mail  | Things |1Pass |      |      |      |      |      | Ms1        | MsUp | Dark  |
|--------+--------+--------+--------+--------+--------+------+------+------+------+------+------+------+------+------|------|
|        | PrevSp | NextSp |     Enter                                |        |        |        | MsLft  | MsDwn  | MsRgt  |
`--------+--------+--------+---------------------------------------------------+--------+--------+--------+--------+--------'

[_GAME]
,--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------.
|        |      |      |      |      |      |      |      |  1   |  2   |  3   |  4   |  5   |      |      |      |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|        |      |      |      |      |      |      | Esc  | Tab  |  Q   |  W   |  E   |  R   |  T   |      |      |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|  Base  |      |      |      |      |      |      |      | LSft |  A   |  S   |  D   | F                  |      |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|               |      |      |      |      |      |  K   |  Z   |  X   |  C   |  V   | B |           LAlt |      |
|--------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|------|
|        |        |        |     Space                      |   M    |   L    |        | Space  | LGui   |        |
`--------+--------+--------+-----------------------------------------+--------+--------+--------+--------+--------'

Legend:
Apps: Slack=C(F13), iTerm=LCA(F16), Zed=S(F17), Xcode=F17,
Fork=LAG(F16), Safari=C(F16), Msg/Tg=tap S(F12)/double F13,
Mail=S(F13), Things=A(F16), 1Pass=A(F7).
Utilities: Fetch=S(A(G(F))), Pull=G(Down), Push=G(Up),
C-b:=G(B) then S(;), Tests=LCAG(G), PrevSp=LAG(KC_QUOT),
NextSp=G(KC_QUOT), Dark=HYPR(F19).
Macros: !zed="zed .", !xo="xo .", !fork="fork .".
Combos shown inline: A+R=hold _FN, S+T={ or [ with Shift,
N+E=} or ] with Shift, U+Y==, W+F=-, W+F+P=->,
RGui+RAlt=G(S(P)), Esc+A=Backspace, Z+LSPO=Grave.
Combos are disabled while _GAME is active.
Custom processing: * marks custom/QMK-side behavior. LockQ=C(G(Q)) normally
or G(L) when CG_TOGG is active; Game only sets _GAME as default when CG_TOGG
is active; /? sends ? unshifted and / with Shift. Caps LED is on for CG_TOGG
and blinks when CG_TOGG+_GAME.
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_wired(
        LOCK_SCREEN,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MPLY,  KC_MNXT, KC_BSLS, KC_BSPC, KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,   KC_G,   KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_NO,      KC_NO,        KC_BSLS, KC_VOLU,
        KC_ESC,  KC_A,    KC_R,    KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,    KC_NO,      KC_ENT,  KC_VOLD,
        SC_LSPO, KC_NO, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    SC_RSPC,      KC_UP,   KC_MUTE,
        KC_LCTL, KC_LALT, KC_LGUI,          KC_SPC,                         KC_RGUI, KC_RALT,                  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT_wired(
        QK_BOOT, S(A(G(KC_F))), G(KC_DOWN), G(KC_UP), MC_TMUX_COMMAND, LCAG(KC_G), KC_TRNS, KC_TRNS, MC_ZED,  MC_XO,   MC_FORK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        CG_TOGG, KC_TRNS,   KC_TRNS,     LCA(KC_F16), S(KC_F17), KC_F17,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRIU,
        GAME_TOGGLE, KC_TRNS, KC_TRNS,   C(KC_F13), LAG(KC_F16), C(KC_F16), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID,
        KC_TRNS,  KC_TRNS,   KC_TRNS, TD(TD_MESS_TELEGRAM_OPEN), S(KC_F13), A(KC_F16), A(KC_F7), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_UP, HYPR(KC_F19),
        KC_TRNS, LAG(KC_QUOT),G(KC_QUOT),           KC_ENT,                                 KC_TRNS, KC_TRNS,            KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
    ),

    [_GAME] = LAYOUT_wired(
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,   KC_4,   KC_5, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,
        DF(_BASE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_TRNS, KC_F,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_SPC,                                      KC_M,    KC_L,             KC_SPC,  KC_LGUI, KC_TRNS
    )
};
