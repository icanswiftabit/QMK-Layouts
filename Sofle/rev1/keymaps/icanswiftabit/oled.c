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
 
    bool SWAPPED_CMD;
    if (keymap_config.swap_lctl_lgui || keymap_config.swap_rctl_rgui) {
        SWAPPED_CMD = true;
    } else {
        SWAPPED_CMD = false;
    }
    oled_write_ln_P(PSTR("SWAP"), SWAPPED_CMD);

    oled_write_P(PSTR("\n\n"), false);

    switch (get_highest_layer(layer_state)) {
    case 3:
        oled_write_ln_P(PSTR("GAME"), false);
        break;
    default:
        oled_write_P(PSTR("\n\n"), false);
        break;
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