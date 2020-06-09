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
#include "RotaryEncoder.h"

std::vector<RotaryEncoder> encoders ;

RotaryEncoder::RotaryEncoder(uint16_t detectKeyCodeA, uint16_t detectKeyCodeB, uint16_t sendKeyCodeCW, uint16_t sendKeyCodeCCW)
{
    C2AKeycode = detectKeyCodeA ;
    C2BKeycode = detectKeyCodeB ;
    CWKeycode  = sendKeyCodeCW ;
    CCWKeycode = sendKeyCodeCCW ;  
    statusA = false;
    statusB = false;
    State = Encoderstate::ENCODER_STATE_UNKNOWN;
}

void RotaryEncoder::StartDetect()
{
    statusA = false;
    statusB = false;
}

void RotaryEncoder::ProcessKeycode(uint16_t KeyCode)
{
    if (KeyCode == C2AKeycode) 
    {
       statusA = true;
    }
    else if (KeyCode == C2AKeycode) 
    {
       statusB = true;
    }
}


uint16_t RotaryEncoder::CompleteDetectTest(void)
{
    if (statusA) // A
    {
        if (statusB) // A & B
        {
            return CWKeycode;
        } 
        else         // A & !B
        {
            return CWKeycode+1; // we see this once
        }       
    } 
    else //!A
    {
         if (statusB) // !A & B
        {
            return CWKeycode+2;
        } 
        else         // !A & !B
        {
            return 0;  // we see this
        }         
    }
}

uint16_t RotaryEncoder::CompleteDetect(void)
{
    Encoderstate newState;

    // State inputA  inputB  
    //   A     0        0
    //   B     0        1
    //   C     1        0
    //   D     1        1
    if (statusA) // A
    {
        if (statusB) // A & B
        {
            newState = Encoderstate::ENCODER_STATE_D;
        } 
        else         // A & !B
        {
            newState = Encoderstate::ENCODER_STATE_C;
        }       
    } 
    else //!A
    {
         if (statusB) // !A & B
        {
            newState = Encoderstate::ENCODER_STATE_B;
        } 
        else         // !A & !B
        {
            newState = Encoderstate::ENCODER_STATE_A;
        }         
    }
    
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
    switch (State)
    {
        case Encoderstate::ENCODER_STATE_UNKNOWN: 
                State = newState;
                return 0;
            break;
        case Encoderstate::ENCODER_STATE_A: 
            switch (newState)
            {
                case Encoderstate::ENCODER_STATE_B: // CW
                    State = newState;
                    return CWKeycode;
                    break;
                case Encoderstate::ENCODER_STATE_C: // CCW
                    State = newState;
                    return CCWKeycode;
                    break;
            }
            break;
        case Encoderstate::ENCODER_STATE_B:
            switch (newState)
            {
                case Encoderstate::ENCODER_STATE_A: // CCW
                    State = newState;
                    return CCWKeycode;
                    break;
                case Encoderstate::ENCODER_STATE_D: // CW
                    State = newState;
                    return CWKeycode;
                    break;
            } 
            break;
        case Encoderstate::ENCODER_STATE_C: 
            switch (newState)
            {
                case Encoderstate::ENCODER_STATE_A: // CW
                    State = newState;
                    return CWKeycode;
                    break;
                case Encoderstate::ENCODER_STATE_D: // CCW
                    State = newState;
                    return CCWKeycode;
                    break;
            } 
            break;
        case Encoderstate::ENCODER_STATE_D: 
            switch (newState)
            {
                case Encoderstate::ENCODER_STATE_B: // CCW
                    State = newState;
                    return CCWKeycode;
                    break;
                case Encoderstate::ENCODER_STATE_C: // CW
                    State = newState;
                    return CWKeycode;
                    break;
            }
            break;
    }
    State = newState;
    return 0;
}