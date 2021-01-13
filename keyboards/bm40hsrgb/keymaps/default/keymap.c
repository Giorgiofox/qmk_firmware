/* Copyright 2020 Giorgio Campiotti BM40RGB
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


enum planck_keycodes {
  RGB_SLD,
  XSS,
  SOLID,
  RANDOM,
  EICAR
};

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,

  _LAYER5
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    LT(5,KC_ESC),   KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,      
    LT(4,KC_TAB),   KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       RSFT_T(KC_ENTER),
    KC_TRANSPARENT,    KC_LCTRL,       KC_LGUI,        KC_LALT,        LOWER,          KC_SPACE,          RAISE,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
),


[_LOWER] = LAYOUT_planck_grid(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_DELETE,      
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_UNDS,        KC_PLUS,        KC_LBRACKET,    KC_RBRACKET,    KC_PIPE,        
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_SCOLON,      KC_COLN,        KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, 
    KC_COMMA,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_SPACE),          KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
),


[_RAISE] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_TRNS,        KC_UNDERSCORE,  KC_EQL,         KC_AT,          KC_GRAVE,      
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRNS,        KC_MINUS,       KC_PLUS,        KC_BSLS,        KC_TRNS, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,          KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
),


[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   UC_MOD,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, SOLID,  RGB_SLD, KC_TRANSPARENT, KC_SYSTEM_SLEEP ,
    _______, _______, _______, _______, _______, _______, _______, RGB_TOG,  RGB_VAD,  RGB_VAI, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______, RGB_MOD,  RGB_HUD,  RGB_HUI, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, RGB_SAD,  RGB_SAI, _______, _______
),



  // [_ADJUST] = LAYOUT_planck_grid( //ADJUST
  //   KC_TRANSPARENT, KC_TRANSPARENT, UC_MOD,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LED_LEVEL,      SOLID, RGB_SLD, KC_TRANSPARENT, KC_SYSTEM_SLEEP,
  //   KC_TRANSPARENT, KC_TRANSPARENT, AU_ON,          AU_OFF,         AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, RESET,          
  //   KC_TRANSPARENT, KC_TRANSPARENT, MU_ON,          MU_OFF,         MU_TOG,         MU_MOD,         KC_TRANSPARENT, RGB_MOD,        RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_TRANSPARENT, 
  //   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, RGB_SAD, RGB_SAI, TOGGLE_LAYER_COLOR, KC_TRANSPARENT
  // ),




 [_LAYER4] = LAYOUT_planck_grid( //TAB
    LT(5,KC_ESCAPE),KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_MS_WH_UP,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_MS_WH_DOWN,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,          KC_TRANSPARENT, KC_0,           KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER5] = LAYOUT_planck_grid( //ESC
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC(0x000E8), RANDOM, KC_TRANSPARENT, KC_TRANSPARENT, UC(0x000F9), UC(0x000EC), UC(0x000F2), KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, UC(0x000E0), UC(0x020AC), UC(0x000B0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, XSS, UC(0x30C4), EICAR, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),



};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

/*
#define HSV_WHITE 0, 0, 255
#define HSV_RED 0, 255, 255
#define HSV_CORAL 11, 176, 255
#define HSV_ORANGE 28, 255, 255
#define HSV_GOLDENROD 30, 218, 218
#define HSV_GOLD 36, 255, 255
#define HSV_YELLOW 43, 255, 255
#define HSV_CHARTREUSE 64, 255, 255
#define HSV_GREEN 85, 255, 255
#define HSV_GREEN 106, 255, 255
#define HSV_TURQUOISE 123, 90, 112
#define HSV_TEAL 128, 255, 128
#define HSV_CYAN 128, 255, 255
#define HSV_AZURE 132, 102, 255
#define HSV_BLUE 170, 255, 255
#define HSV_PURPLE 191, 255, 255
#define HSV_MAGENTA 213, 255, 255
#define HSV_PINK 234, 128, 255
#define HSV_BLACK 0, 0, 0
#define HSV_OFF HSV_BLACK
*/


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {HSV_YELLOW}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {226,255,255}, 
            {226,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {226,255,255}, 
            {226,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {130,255,255}, {HSV_YELLOW}, 
            {226,255,255}, {HSV_RED}, {HSV_GREEN}, {HSV_BLUE}, {169,120,255}, {169,120,255}, {169,120,255}, {226,255,255}, {226,255,255}, {226,255,255}, {226,255,255} },

    [1] = { {0,0,0}, {0,0,0},      {0,0,0},       {0,0,0},      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_RED}, 
            {0,0,0}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {0,0,0}, {0,0,0}, {HSV_YELLOW}, {HSV_YELLOW}, {0,0,0}, 
            {0,0,0}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {0,0,0}, {0,0,0}, {HSV_YELLOW}, {HSV_YELLOW}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    //RAISE
    [2] = { {0,0,0}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_CYAN}, {HSV_CYAN}, {HSV_CYAN}, {HSV_CYAN}, {HSV_MAGENTA}, {HSV_MAGENTA}, {0,0,0}, 
            {0,0,0}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {0,0,0}, {HSV_ORANGE}, {HSV_ORANGE}, {0,0,0}, {0,0,0},
             {0,0,0}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {0,0,0}, {HSV_ORANGE}, {HSV_ORANGE}, {0,0,0}, {0,0,0}, 
             {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_CYAN}, {HSV_CYAN}, {HSV_CYAN}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    //ADJUST
    [3] = { {0,0,0}, {0,0,0}, {HSV_GREEN}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_WHITE}, {HSV_YELLOW}, {0,0,0}, {0,0,0}, {HSV_CYAN}, 
            {0,0,0}, {0,0,0}, {153,255,255}, {153,255,255}, {153,255,255}, {0,0,0}, {0,0,0}, {33,255,255}, {33,255,255}, {33,255,255}, {0,0,0}, {14,255,255}, 
            {0,0,0}, {0,0,0}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,0}, {33,255,255}, {33,255,255}, {33,255,255}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {33,255,255}, {33,255,255}, {HSV_YELLOW}, {HSV_YELLOW}, {0,0,0}, {0,0,0} },
    //TAB
    [4] = { {0,0,0}, {HSV_CYAN},  {HSV_GREEN}, {HSV_CYAN  }, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_GREEN}, {0,0,0}, 
            {0,0,0}, {0,0,0},     {0,0,0},     {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_GREEN}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_GREEN}, {HSV_GREEN}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {0,0,0}, {0,0,0} },
    //ESC
    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {HSV_GREEN}, {HSV_YELLOW}, {0,0,0}, {0,0,0}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {HSV_GREEN}, {HSV_RED}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_PINK}, {HSV_PINK}, {HSV_PINK}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
              


};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
   
        

        case SOLID:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(HSV_CYAN);
      }
      return false;
      
      case RANDOM:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            tap_random_base64();
            //SEND_STRING("rnd");
        } 
        break;
    case RGB_SLD:
      if (record->event.pressed) {
         rgblight_mode(0);
        set_layer_color(0);
      }
      return false;
  }
  return true;
}


void rgb_matrix_indicators_user(void) {
//0  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
   //H+H*a e set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}