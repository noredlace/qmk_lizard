#include QMK_KEYBOARD_H
#include <print.h>

enum crawl_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum crawl_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  TEST,
  FUNCTION,
  MACRO_1,
  MACRO_2
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = KEYMAP(
    KC_1, KC_2, KC_3, KC_4, RESET,
    KC_Q, LOWER, KC_SPACE, RAISE, KC_0, KC_ENT),

	[_LOWER] = KEYMAP(
    KC_1, KC_2, KC_3, KC_4, RESET,
    KC_L, KC_TRNS, KC_0, RAISE, KC_0, KC_ENT),

	[_RAISE] = KEYMAP(
    KC_1, KC_2, KC_3, KC_4, RESET,
    KC_R, LOWER, KC_BSPC, KC_TRNS, KC_0, KC_ENT),

	[_ADJUST] = KEYMAP(
    KC_1, KC_2, KC_3, KC_4, RESET,
    KC_A, KC_TRNS, KC_BSPC, KC_TRNS, KC_0, RESET)
	
};

void matrix_init_user(void) {
  debug_config.matrix = 1;
  debug_config.keyboard = 1;
  debug_config.enable = 1;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode){

		case LOWER:
			if (record->event.pressed){
				layer_on(_LOWER);
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
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_RAISE);
				//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;


	}
	return true;
}

void encoder_update_user(int8_t index, bool clockwise) {
	print("encode\n");
  if (index == 0) {
	
    if (clockwise) {
      register_code(KC_VOLU);
      unregister_code(KC_VOLU);
    } else {
      register_code(KC_VOLD);
      unregister_code(KC_VOLD);
    }
  }
}



