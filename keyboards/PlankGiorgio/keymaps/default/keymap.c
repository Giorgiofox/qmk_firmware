/* Copyright 2020 GiorgioCampiotti
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

//#include "keymap_italian.h"


extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _ESC
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
  ADJUST,
  MEH,
  EICAR,
  XSS,
  XSS1
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// L = .-.. 
// R = .-. 
// F = ..-. 

#define LO E__NOTE(_C5), Q__NOTE(_C5),E__NOTE(_C5),E__NOTE(_C5)//, B__NOTE(_C3), W__NOTE(_C3), Q__NOTE(_C3)
#define RA E__NOTE(_C5), Q__NOTE(_C5),E__NOTE(_C5)//, B__NOTE(_C3), W__NOTE(_C3), Q__NOTE(_C3)
#define FUN E__NOTE(_C5),E__NOTE(_C5), Q__NOTE(_C5),E__NOTE(_C5)//, B__NOTE(_C3), W__NOTE(_C3), Q__NOTE(_C3)


#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float s1[][2]              = SONG(LO);
  float s2[][2]              = SONG(RA);
  float s3[][2]              = SONG(FUN);
  float s4[][2]              = SONG(LO);
  float s5[][2]              = SONG(IMPERIAL_MARCH);
  float s6[][2]              = SONG(E1M1_DOOM);
  float s7[][2]              = SONG(COIN_SOUND);
  float s8[][2]              = SONG(ONE_UP_SOUND);
  float s9[][2]              = SONG(SONIC_RING);
#endif



/*
enum unicode_names {
    A,
    E,
    I,
    O,
    U
};

const uint32_t PROGMEM unicode_map[] = {
    [A]  = 0x00E0,  // 
    [E] = 0x00E8,  // 
    [I]  = 0x00EC, // 
    [O]  = 0x00F2, // 
    [U]  = 0x1F40D, // 
};

*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid( // default layer
        LT(5,KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
        LT(3, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MT(MOD_LSFT, KC_ENT), 
        MO(4), KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_SPC, MO(2), RALT_T(KC_LEFT), KC_DOWN, KC_UP, KC_RGHT),

[_LOWER] = LAYOUT_planck_grid( // lower level
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, 
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, 
        KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCA(KC_BSPC), KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

[_RAISE] = LAYOUT_planck_grid( //reaise level 
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, 
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_UNDERSCORE, KC_EQL, KC_AT, KC_GRAVE, 
        KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_MINUS, KC_PLUS, KC_BSLS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

[_ADJUST] = LAYOUT_planck_grid( //mouse and other functions level, also activable with rasie+lower

        KC_TRNS, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_MS_WH_UP, KC_TRNS, 
        KC_CAPSLOCK, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_MS_WH_DOWN, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MEDIA_PLAY_PAUSE, KC_TRNS, KC_0, KC_DOT, KC_COMM, KC_TRNS),

[_FUNCTION] = LAYOUT_planck_grid( //Function Key

        TO(0), RGB_TOG, RGB_MOD, RGB_HUI, KC_TRNS, RGB_MODE_PLAIN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLEP, 
        TG(3), AU_TOG, MU_TOG, MU_MOD, CK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MODE_KNIGHT, KC_TRNS, KC_PGUP, KC_WAKE, 
        KC_TRNS, XSS1, XSS, RCS(KC_C), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDOWN, RESET, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(1), KC_MEDIA_PLAY_PAUSE, TG(2), KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT),

[_ESC] = LAYOUT_planck_grid( //ESC Key used for accent and some special key/functions

        KC_TRNS, UC_MOD, UC_WINC, UC(0x000E8), KC_TRNS, KC_TRNS, KC_TRNS, UC(0x000F9), UC(0x000EC), UC(0x000F2), KC_TRNS, KC_TRNS, 
        KC_TRNS, UC(0x000E0), UC(0x020AC), UC(0x000B0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UC_LNX, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, UC(0x30C4), EICAR, KC_TRNS, KC_TRNS, MEH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(1), KC_TRNS, TG(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};


/*

euro 0x020AC
copyright 0x000A9
registered 0x000AE
trademark 0x02122
agrave 0x000E0
egrave 0x000E8
igrave 0x000EC
ograve 0x000F2
ugrave 0x000F9
degree 0x000B0
katana 0x30C4
meh ¯\_(ツ)_/¯
eicar X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*
*/

//KC_ASTG autoshit toggle

//uint32_t layer_state_set_user(uint32_t state) {
//  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//}


// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 2, HSV_RED}       // Light 4 LEDs, starting with LED 6
  //  {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_PURPLE}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_GREEN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active

const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_YELLOW}
);
// etc


// etc..

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,    // Overrides other layers
    my_layer4_layer,     // Overrides other layers
    my_layer5_layer     // Overrides other layers

);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));


 //return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case MEH:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
           // SEND_STRING("¯\_(ツ)_/¯");
                    send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
                            } else {
            // when keycode QMKBEST is released
        }
        break;
    case EICAR:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case XSS1:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("<script>alert(\"XSS\");</script>");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case XSS:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("<script>alert(document.cookie);</script>");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:

      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        //    PLAY_SONG(s1);
        #endif //AUDIO_ENABLE
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
         //   PLAY_SONG(s2);
        #endif //AUDIO_ENABLE
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case FUNCTION:
              SEND_STRING("UTILITY DEBUG");

      if (record->event.pressed) {

        #ifdef AUDIO_ENABLE
            PLAY_SONG(s2);
        #endif //AUDIO_ENABLE
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
      break;   
          case ADJUST:
      if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
            PLAY_SONG(s2);
        #endif //AUDIO_ENABLE
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;       
  }
  return true;
}


/*

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:

    case LOWER:
      return false;
    default:
      return true;
  }
}

*/

