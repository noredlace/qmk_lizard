#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,ENT ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,BSPC ,     DEL, N  , M  ,COMM,DOT ,SLSH,RGHT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LOWR, SPC,         ENT ,RASE,LGUI
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH, DLR,PERC,               CIRC, 7  , 8  , 9  ,RPRN,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      F1 , F1 , F2 , F3 , F4 , F5 ,                F6 , 4  , 5  , 6  , 0  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      F7 , F7 , F8 , F9 , F10, F11,                F12, 1  , 2  , 3  ,PLUS,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,LCBR,LPRN,     RPRN,RCBR, 0  , P2 , P3 ,MINS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      LALT ,    ,DEL ,         DEL ,    , P0 
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 ,LBRC,RBRC,BSPC ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR, UP ,MINS, EQL,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MPRV,MNXT,VOLU,PGUP,UNDS,               EQL ,LEFT,DOWN,RGHT, P6 ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,MSTP,MPLY,VOLD,PGDN,MINS,PGUP,     VOLU,PLUS,END , P1 , P2 , P3 ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,PGDN,         VOLD,    ,    
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      RGB_TOG, RGB_MOD, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, RESET  , RGB_HUI, RGB_SAI, RGB_VAI, _______,                            RGB_M_P, RGB_M_B, RGB_M_R,RGB_M_SW, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      KC_CAPS, DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                           RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      BL_STEP, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
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
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

// How long (in ms) to wait between animation steps for the breathing mode
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};

// How long (in ms) to wait between animation steps for the rainbow mode
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {60, 20, 5};

// How long (in ms) to wait between animation steps for the swirl mode
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {20, 10, 5};

// How long (in ms) to wait between animation steps for the snake mode
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {20, 10, 5};

// How long (in ms) to wait between animation steps for the knight modes
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {127, 63, 31};

// These control which colors are selected for the gradient mode
const uint16_t RGBLED_GRADIENT_RANGES[] PROGMEM = {360, 240, 180, 120, 90};
