/*
Copyright 2020 <Pierre Constantineau, Julian Komaromy>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "advanced_keycodes.h"
#include "hid_keycodes.h"

#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

// State inputA  inputB  
//   A     0        0
//   B     0        1
//   C     1        0
//   D     1        1

// State Transitions
// A -> B  = CW
// A -> C  = CCW
// A -> D  = not valid
// B -> A  = CCW
// B -> C  = not valid
// B -> D  = CW
// C -> A  = CW
// C -> B  = not valid
// C -> D  = CCW
// D -> A  = not valid
// D -> B  = CCW
// D -> C  = CW


class RotaryEncoder {
    public:
        RotaryEncoder(uint16_t detectKeyCodeA, uint16_t detectKeyCodeB, uint16_t sendKeyCodeCW, uint16_t sendKeyCodeCCW);
    private:
        static uint16_t C2AKeycode;
        static uint16_t C2BKeycode;
        static uint16_t CWKeycode;
        static uint16_t CCWKeycode;   


    };

#endif /* KEY_H */