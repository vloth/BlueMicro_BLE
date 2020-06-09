/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
        KEYMAP2ARRAY(KEYMAP(
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    
            KC_NO,    KC_NO,    KC_NO,    KC_NO,  
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    
            KC_NO,    KC_NO,    KC_NO,    KC_NO
        ));



 
void setupKeymap() {

        uint32_t press[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        ENC01_B,    KC_LSHIFT,    ENC03_A,   ENC04_A,  // ENC_A
        ENC01_A,    KC_RSHIFT,    ENC03_B,   ENC04_B,  // ENC_B
        KC_1,     KC_2,    KC_3,     KC_4,      // Encoder Push Button
        KC_5,     KC_6,    KC_7,    KC_8            // MX Switches
        );

    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L0, Method::PRESS, press[row][col]);
        }
    }

// RotaryEncoder::RotaryEncoder(uint16_t detectKeyCodeA, uint16_t detectKeyCodeB, uint16_t sendKeyCodeCW, uint16_t sendKeyCodeCCW)

encoders.push_back(RotaryEncoder(ENC01_B, ENC01_A, KC_A, KC_B));
encoders.push_back(RotaryEncoder(ENC02_A, ENC02_B, KC_C, KC_D));
encoders.push_back(RotaryEncoder(ENC03_A, ENC03_B, KC_E, KC_F));
encoders.push_back(RotaryEncoder(ENC04_A, ENC04_B, KC_G, KC_H));

}

