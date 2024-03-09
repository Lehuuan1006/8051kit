#include <reg51.h>
#include "stdutils.h"
#include "nec_ir.h"

sbit RELAY_PIN = P0^0;
sbit DIGIT_1 = P2^2;
sbit DIGIT_2 = P2^3;
sbit DIGIT_3 = P2^4;
void displayDigit(unsigned char digit) {
    switch (digit) {
        case 0: P0 = 0x3f; break; 
        case 1: P0 = 0x06; break;
        case 2: P0 = 0x5b; break;
        case 3: P0 = 0x4f; break;
        case 4: P0 = 0x66; break;
        case 5: P0 = 0x6d; break;
        case 6: P0 = 0x7d; break;
        case 7: P0 = 0x07; break;
        case 8: P0 = 0x7f; break;
        case 9: P0 = 0x6f; break;
        default: P0 = 0x00; break;
    }
}

void main()
{
    uint32_t key;
		RELAY_PIN = 0;	  // Turn OFF the relay during Init
    IR_RemoteInit();  // Initialtile the INTO and Timer0 for decoding the IR pulses

    while(1)
    {
        key = IR_RemoteGetKey();  // Read the key press, it returns key code if key press is detected, else it returns 0

        switch(key)
        {
        case IR_CODE_1: displayDigit(1); DIGIT_1 = 1; DIGIT_2 = 1; DIGIT_3 = 1; break;
        case IR_CODE_2: displayDigit(2); DIGIT_1 = 0; DIGIT_2 = 1; DIGIT_3 = 1; break;
				case IR_CODE_3: displayDigit(3); DIGIT_1 = 1; DIGIT_2 = 0; DIGIT_3 = 1; break;
				case IR_CODE_4: displayDigit(4); DIGIT_1 = 0; DIGIT_2 = 0; DIGIT_3 = 1; break;
				case IR_CODE_5: displayDigit(5); DIGIT_1 = 1; DIGIT_2 = 1; DIGIT_3 = 0; break;
				case IR_CODE_6: displayDigit(6); DIGIT_1 = 0; DIGIT_2 = 1; DIGIT_3 = 0; break;
				case IR_CODE_7: displayDigit(7); DIGIT_1 = 1; DIGIT_2 = 0; DIGIT_3 = 0; break;
				case IR_CODE_8: displayDigit(8); DIGIT_1 = 0; DIGIT_2 = 0; DIGIT_3 = 0; break;
        default: break;
        }
    }		
}
