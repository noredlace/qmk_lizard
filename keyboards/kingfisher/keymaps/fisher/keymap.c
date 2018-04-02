#include "kingfisher.h"
#include "issi.h"
#include "lighting.h"
#include "action_layer.h"

//Define a shorter 'transparent' key code to make the keymaps more compact
// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP(\
  /* Keymap VANILLA: (Base Layer) Default Layer
   *   ,---------------------------------------------------------------------.
   *   |ESC |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |   [|   ]|   \|
   *   |---------------------------------------------------------------------|
   *   |Tab  |  A |  S |  D |  F |  G |  H |  J |  K |  L |   ;|   '| RETURN|
   *   |---------------------------------------------------------------------| 
   *   |SHIFT   |   Z|   X|   C|   V|   B|   N|   M|   ,|   .|   /|SHIFT |ADJUST|
   *   |---------------------------------------------------------------------|
   *    |ADJUST|CTRL||ALT|   WIN    |RAISE|    SPACE   ||LEFT|UP|DOWN|RIGHT|
   *    `-------------------------------------------------------------------'  
   */
   KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LPRN, KC_DEL, KC_BSPC,\
   KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_SCLN,   KC_ENT, MO(_ADJUST),\
   KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
	KC_LCTL, MO(_ADJUST), KC_LALT, MO(_RAISE), MO(_LOWER), KC_SPACE, XXXXXXX, KC_RALT, KC_MINS, KC_EQL, KC_LCTL),
   [_LOWER] = KEYMAP(\

		   _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______,\
		   _______,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, XXXXXXX,   XXXXXXX, XXXXXXX,\
		   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  		   _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, KC_F11, KC_F12, _______),

   [_RAISE] = KEYMAP(\

		   KC_GRV, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, _______, KC_CALC, KC_PGUP, KC_UP, KC_PGDN, _______, KC_RPRN, _______, _______,\
		   KC_CAPS,  _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,   _______, XXXXXXX,\
		   _______,  _______, _______, _______, _______, _______, KC_END, _______, _______, _______, _______, _______, \
		   _______, KC_LGUI, _______, _______, XXXXXXX, _______, XXXXXXX, _______, _______, _______, _______),
		   
   [_ADJUST] = KEYMAP(\

		   _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,\
		   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,\
		   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		   RESET, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, KC_LBRC, KC_RBRC, _______),
};

const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(LFK_CLEAR),                               // FN0 - reset layers
    ACTION_FUNCTION(LFK_ESC_TILDE),                           // FN1 - esc+shift = ~, else escape
  };


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {
	
}

