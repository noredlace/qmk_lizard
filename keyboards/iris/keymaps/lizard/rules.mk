RGBLIGHT_ENABLE = yes
BACKLIGHT_ENABLE = yes
NKRO_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
	
	TAP_DANCE_ENABLE = yes
endif
