#pragma once


#ifdef AUDIO_ENABLE
  //#define STARTUP_SONG SONG(PLANCK_SOUND)
  #define STARTUP_SONG SONG(PREONIC_SOUND)

#endif


#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 10

#undef TAPPING_TERM
#define TAPPING_TERM 200
#undef RGBW

#undef IGNORE_MOD_TAP_INTERRUPT

#define AUTO_SHIFT_TIMEOUT 145
#define NO_AUTO_SHIFT_ALPHA

#define FIRMWARE_VERSION u8"WWPBz/blglj"
#define RGB_MATRIX_STARTUP_SPD 60




#define UNICODE_SELECTED_MODES UC_LNX,UC_WINC