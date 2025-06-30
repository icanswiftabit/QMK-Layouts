 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

//Sets up what the OLED screens display.

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);

    bool isSwapped = keymap_config.swap_lctl_lgui || keymap_config.swap_rctl_rgui;
    bool isGameActive = get_highest_layer(layer_state) == 3;

    if (isSwapped && isGameActive) {
        oled_write_ln_P(PSTR("SWAP"), false);
        oled_write_ln_P(PSTR("GAME"), false);
    } else if (isSwapped) {
        oled_write_ln_P(PSTR("SWAP"), false);
        oled_write_P(PSTR("\n"), false);
    } else if (isGameActive) {
        oled_write_P(PSTR("\n"), false);
        oled_write_ln_P(PSTR("GAME"), false);
    } else {
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("\n"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    }
	return false;
}

#endif