#include "orgonaut66.h"
#include <string.h>

extern keymap_config_t keymap_config;

enum orgonaut_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST,
  _TEST
};

enum orgonaut_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  TEST,
  FUNCTION,
  MACRO_1,
  MACRO_2
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	


/*
	[_QWERTY] = KEYMAP(
		KC_1,    KC_2,    KC_5,                        KC_6,    KC_9,    KC_0, 
		KC_ESC,  KC_3,    KC_4,                        KC_7,    KC_8,    KC_BSPC, 
		KC_DEL,  KC_E,    KC_R,                        KC_U,    KC_I,    KC_BSLS, 
		KC_Q,    KC_W,    KC_T,    KC_LBRC,   KC_RBRC, KC_Y,    KC_O,    KC_P, 
		KC_TAB,  KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_ENT, 
		KC_A,    KC_S,    KC_C,    KC_PGUP,   KC_PGDN, KC_COMM, KC_L,    KC_SCLN, 
		KC_LCTL, KC_X,    KC_V,    KC_B,      KC_N,    KC_M,    KC_DOT,  KC_SLSH, 
		KC_Z,    KC_LCTL, KC_LGUI, MO(1),     MO(2),   KC_DOWN, KC_UP,   KC_LSFT, 
		KC_LSFT, KC_LCTL, KC_LALT, KC_SPC,    KC_ENT,  KC_LEFT, KC_RGHT, KC_LCTL),
		*/

/*
	[_QWERTY] = KEYMAP(
		KC_1, KC_2, KC_5, KC_6, KC_9, KC_0, 
		KC_ESC, KC_3, KC_4, KC_7, KC_8, KC_BSPC, 
		KC_DEL, KC_E, KC_R, KC_U, KC_I, KC_BSLS, 
		KC_Q, KC_W, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_O, KC_P, 
		KC_TAB, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_ENT, 
		KC_A, KC_S, KC_C, KC_PGUP, KC_PGDN, KC_COMM, KC_L, KC_SCLN, 
		KC_LCTL, KC_X, KC_V, KC_B, KC_N, KC_M, KC_DOT, KC_SLSH, 
		KC_Z, KC_LCTL, KC_LGUI, LOWER, RAISE, KC_DOWN, KC_UP, KC_LSFT, 
		KC_LSFT, FUNCTION, KC_LALT, KC_SPC, KC_ENT, KC_LEFT, KC_RGHT, RESET),

	[_LOWER] = KEYMAP(
		KC_EXLM, KC_AT, KC_TRNS, KC_TRNS, KC_9, KC_MINS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_7, KC_8, KC_TRNS, 
		KC_L, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_6, KC_PLUS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_3, KC_ASTR, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_ENT, KC_SLSH, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS),

	[_RAISE] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLCK, KC_TRNS, KC_RGHT, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MPLY, KC_TRNS),

	[_ADJUST] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_A, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_FUNCTION] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_F, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
*/
	
	/* Qwerty
 * +------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------+
 * | Del  | Esc  |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |     Bksp    |  	
 * +----+-+------+------+------+------+------+------+------+------+------+------+------+------+------+--------+----+
 *      |   Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   ]  |   Y  |   U  |   I  |   O  |   P  |  Pipe  |
 * |----+-+------+------+------+------+-------------+------+------+------+------+------+------+------+--------+--------+
 * |    Ctrl     |   A  |   S  |   D  |   F  |   G  | PgDn | PgUp |   H  |   J  |   K  |   L  |   ;  |    Enter        |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+--------------+------+
 * |   Shift     |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |    Shift     | Fn   | 
 * |-------------+------+------+------+------+------+------+------+------+------+------+------+---------------------+------+
 * |             |Fn    | Ctrl | Alt  | GUI  |Lower | Space| Enter|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
 	

	[_QWERTY] = lizardKeys(
	 KC_DEL, KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
			 KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_LBRC, KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE, 
		     KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_PGDN, KC_PGUP,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
		     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  FUNCTION, 
				       KC_F,    KC_LCTL, KC_LGUI, KC_LALT, LOWER,  KC_SPC,  KC_ENT,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
   ),
	
		

	[_FUNCTION] = lizardKeys(
     KC_F,   RESET,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  			 KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
  			 KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGDN, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  			 KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_TRNS,
  		               KC_F,    KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS, KC_SPC,  KC_ENT,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),


	[_LOWER] = lizardKeys(
     KC_L,   KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  			 KC_TAB,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_Y,    KC_4,    KC_5,    KC_6,    KC_PLUS, KC_PIPE,
  			 KC_LCTL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_G,    KC_PGDN, KC_PGUP, KC_H,    KC_1,    KC_2,    KC_3,    KC_MINS, KC_QUOT,
  			 KC_LSFT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_B,                      KC_N,    KC_0,    KC_0,    KC_ENT,  KC_SLSH, KC_RSFT,  KC_TRNS,
  			           KC_F,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  KC_ENT,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

	[_RAISE] = lizardKeys(
     KC_R,   KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  			 KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_UP,   KC_O,    KC_P,    KC_PIPE,
  			 KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGDN, KC_PGUP, KC_H,    KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, KC_QUOT,
  			 KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_TRNS,
  			           KC_F,    KC_LCTL, KC_LGUI, KC_LALT,KC_TRNS,  KC_SPC,  KC_ENT,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

	[_ADJUST] = lizardKeys(
     KC_A,   KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  			 KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
  			 KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGDN, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  			 KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_TRNS,
  			           KC_F,    KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS, KC_SPC,  KC_ENT,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
)


};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	  
	  
	case MACRO_1:
	  if (record->event.pressed) {
		SEND_STRING("cd /mnt/c/Users/EJ/Documents");
		register_code(KC_ENT);
		return false; 
	  }
	case MACRO_2:
	  if (record->event.pressed) {
		  //navigate to folder
		SEND_STRING("cd /mnt/c/Users/EJ/Documents/Github/qmk_lizard");
		register_code(KC_ENT);
		unregister_code(KC_ENT);
		
		//send command to compile
		SEND_STRING("make planck:lizard");
		register_code(KC_ENT);
		unregister_code(KC_ENT);
		
		return false; 
	  }
 

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        #ifdef BACKLIGHT_ENABLE
          //breathing_period_set(2);
          //breathing_pulse();
        #endif
        //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        //breathing_period_set(2);
        //breathing_pulse();
		//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
	  
	case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
        //breathing_period_set(2);
        //breathing_pulse();
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
		//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_FUNCTION);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
		//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
	  

  }
  return true;
}
