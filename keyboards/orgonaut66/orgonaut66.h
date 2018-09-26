#ifndef ORGONAUT66_H
#define ORGONAUT66_H

#include "quantum.h"


//default keymap by kbfirmware based off rows and columsn of the matrix
/*
#define KEYMAP( \
	K00, K01, K02,           K05, K06, K07, \
	K10, K11, K12,           K15, K16, K17, \
	K20, K21, K22,           K25, K26, K27, \
	K30, K31, K32, K33, K34, K35, K36, K37, \
	K40, K41, K42, K43, K44, K45, K46, K47, \
	K50, K51, K52, K53, K54, K55, K56, K57, \
	K60, K61, K62, K63, K64, K65, K66, K67, \
	K70, K71, K72, K73, K74, K75, K76, K77, \
	K80, K81, K82, K83, K84, K85, K86, K87  \
) { \
	{ K00,   K01,   K02,   KC_NO, KC_NO, K05,   K06,   K07 }, \
	{ K10,   K11,   K12,   KC_NO, KC_NO, K15,   K16,   K17 }, \
	{ K20,   K21,   K22,   KC_NO, KC_NO, K25,   K26,   K27 }, \
	{ K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37 }, \
	{ K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47 }, \
	{ K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57 }, \
	{ K60,   K61,   K62,   K63,   K64,   K65,   K66,   K67 }, \
	{ K70,   K71,   K72,   K73,   K74,   K75,   K76,   K77 }, \
	{ K80,   K81,   K82,   K83,   K84,   K85,   K86,   K87 }  \
}
*/

//attempt to create keymap based off physical layout and not diode layout
#define KEYMAP( \
	     K20, K10, K00,           K01, K11, K12, \
		 K02, K05, K15,           K16, K06, K07, \
		 K17, K40, K30,           K31, K21, K22, \
		 K32, K33, K34, K35, K25, K26, K36, K37, \
		 K27, K60, K50, K51, K41, K42, K43, K53, \
		 K54, K44, K45, K46, K56, K57, K47, K80, \
		 K70, K61, K52, K62, K63, K64, K65, K55, \
		 K66, K67, K77, K87, K81, K71, K72, K82, \
		 K73, K83, K84, K74, K85, K75, K76, K86   \
)   \
{ \
	{ K00,   K01,   K02,   KC_NO, KC_NO, K05,   K06,   K07 }, \
	{ K10,   K11,   K12,   KC_NO, KC_NO, K15,   K16,   K17 }, \
	{ K20,   K21,   K22,   KC_NO, KC_NO, K25,   K26,   K27 }, \
	{ K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37 }, \
	{ K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47 }, \
	{ K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57 }, \
	{ K60,   K61,   K62,   K63,   K64,   K65,   K66,   K67 }, \
	{ K70,   K71,   K72,   K73,   K74,   K75,   K76,   K77 }, \
	{ K80,   K81,   K82,   K83,   K84,   K85,   K86,   K87 }  \
}


#endif