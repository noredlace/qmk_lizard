/*
 * Copyright 2018 Jack Humbert <jack.humb@gmail.com>
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

#include "encoder.h"

#ifndef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
#endif

#ifndef NUMBER_OF_ENCODERS
  #error "Number of encoders not defined by NUMBER_OF_ENCODERS"
#endif

#if !defined(ENCODERS_PAD_A) || !defined(ENCODERS_PAD_B)
  #error "No encoder pads defined by ENCODERS_PAD_A and ENCODERS_PAD_B"
#endif

static pin_t encoders_pad_a[NUMBER_OF_ENCODERS] = ENCODERS_PAD_A;
static pin_t encoders_pad_b[NUMBER_OF_ENCODERS] = ENCODERS_PAD_B;

static uint8_t encoder_state[NUMBER_OF_ENCODERS] = {0};

__attribute__ ((weak))
void encoder_update_user(int8_t index, bool clockwise) { }

__attribute__ ((weak))
void encoder_update_kb(int8_t index, bool clockwise) {
  encoder_update_user(index, clockwise);
}

void encoder_init(void) {
  for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
    setPinInputHigh(encoders_pad_a[i]);
    setPinInputHigh(encoders_pad_b[i]);

    encoder_state[i] = readPin(encoders_pad_a[i]);
  }
}

void encoder_read(void) {
  for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
    uint8_t aState = readPin(encoders_pad_a[i]);
    uint8_t bState = readPin(encoders_pad_b[i]);
	
	if(bState == 2){
        bState = 1;
    }
    if (encoder_state[i] != aState){
      if (bState != aState){
        encoder_update_kb(i, CLOCKWISE);
      } else {
        encoder_update_kb(i, COUNTRECLOCKWISE);
      }
    }
    encoder_state[i] = aState;
  }
}
