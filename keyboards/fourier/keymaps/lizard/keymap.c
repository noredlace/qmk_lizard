#include "fourier.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_BASE TG(_BASE)
#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_FN3 MO(_FN3)
#define KC_FN4 TG(_FN4)
#define KC_SPFN1 LT(_FN1, KC_SPACE)
#define KC_SPFN2 LT(_FN2, KC_SPACE)
#define KC_BSFN1 LT(_FN1, KC_BSPC)
#define KC_BSFN2 LT(_FN2, KC_BSPC)
#define KC_ENFN1 LT(_FN1, KC_ENT)
#define KC_ENFN2 LT(_FN2, KC_ENT)
#define KC_MODSH SFT_T(KC_SLSH)
#define KC_RST RESET
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_RGB_M_P RGB_M_P
#define KC_RGB_M_B RGB_M_B
#define KC_RGB_M_R RGB_M_R
#define KC_RGB_M_SW RGB_M_SW
#define KC_RGB_M_SN RGB_M_SN
#define KC_RGB_M_K RGB_M_K
#define KC_RGB_M_X RGB_M_X
#define KC_RGB_M_G RGB_M_G




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = KC_KEYMAP(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    ESC , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,DEL ,BSPC,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    TAB  , A  , S  , D  , F  , G  , H  , J  , K  , L  ,QUOT, ENTER  ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    LSFT   , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,MODSH, FN4 ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    LCTL ,LGUI,LALT, TRNS, SPFN2,  ENFN1 ,RGUI ,RALT , FN3 , RCTL 
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),
  
  [_FN1] = KC_KEYMAP(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    TILD,EXLM, AT ,HASH,DLR ,PERC,CIRC,AMPR, UP ,LBRC,RBRC,UNDS,PLUS,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
         ,    ,    ,INS ,PGUP,HOME,    ,LEFT,DOWN , RGHT, COLN,        ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
           ,    ,    ,DEL ,PGDN,END ,    ,    ,    ,    ,    ,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
         ,    ,     ,    ,  TRNS  ,  TRNS,     ,     ,     ,      
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN2] = KC_KEYMAP(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    GRV , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    RST  ,RHUI,RSAI,RVAI,VOLU,LBRC,RBRC, 4  , 5  , 6  ,SCLN,        ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    RMOD   ,RHUD,RSAD,RVAD,VOLD,LCBR,RCBR, 1  , 2  , 3  , UP ,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    RTOG ,    ,     ,    ,   TRNS  ,  TRNS,  0  ,LEFT ,DOWN , RGHT 
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),


  
   [_FN3] = KC_KEYMAP(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    TILD,RST, AT ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,LPRN,RPRN,UNDS,PLUS,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
         ,    ,    ,INS ,PGUP,HOME,    ,RGB_M_P,RGB_M_B,RGB_M_R,RGB_M_SW,        ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
           ,    ,    ,DEL ,PGDN,END ,    ,RGB_M_SN,RGB_M_K,RGB_M_X,RGB_M_G,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
         ,    ,     ,    ,  TRNS,  TRNS ,     ,     ,     ,      
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

 
   [_FN4] = KC_KEYMAP(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    ESC , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,DEL ,BSPC,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    TAB  , A  , S  , D  , F  , G  , H  , J  , K  , L  ,QUOT, ENTER  ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    LSFT   , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH, TRNS ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    LCTL ,LGUI,LALT, TRNS, ENFN2,  SPFN1 ,RGUI ,RALT , FN3 , RCTL 
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  )
  
};

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
