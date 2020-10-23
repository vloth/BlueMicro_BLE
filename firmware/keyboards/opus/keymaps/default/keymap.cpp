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
    {KEYMAP(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)};

 
void setupKeymap() {

    uint32_t press[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOTE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, 
    LAYER_1, KC_SPC,  KC_LGUI, KC_RALT, KC_ENTER, LAYER_2);

    uint32_t tap[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    KC_ESC,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO);

    uint32_t hold[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    MOD_LCTRL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO);

    uint32_t singletap[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO);
        
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
    KC_DEL,  _______,  _______, MOD(MOD_LGUI, KC_X),  MOD(MOD_LGUI, KC_C), MOD(MOD_LGUI, KC_V), KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
    PRINT_INFO,   _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______);

    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  _______, _______, _______, _______, _______, KC_MINS, KC_EQL,   KC_LCBR,  KC_RCBR, KC_PIPE, KC_GRV,
    PRINT_BATTERY,   _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS,  KC_LBRC,  KC_RBRC, KC_BSLS, KC_TILD,
    _______, _______, _______, _______, _______, _______);

    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L0, Method::PRESS,   press[row][col]);
            matrix[row][col].addActivation(_L0, Method::MT_TAP,  tap[row][col]);
            matrix[row][col].addActivation(_L0, Method::MT_HOLD, hold[row][col]);
            matrix[row][col].addActivation(_L0, Method::DT_TAP,  singletap[row][col]);
            matrix[row][col].addActivation(_L1, Method::PRESS,   layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS,   layer2[row][col]);
        }
    }

}

