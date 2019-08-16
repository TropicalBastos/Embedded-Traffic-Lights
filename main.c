#ifndef F_CPU
#define F_CPU 16000000UL // or whatever may be your frequency
#endif
 
#include <avr/io.h>
#include <util/delay.h>
#include "lights.h"

int main(void)
{
    DDRB = _PIN_12 | _PIN_11 | _PIN_10;
    while(1)
    {
        // LED on
        switch_on(_RED);
        _delay_ms(500);
 
        //LED off
        switch_off(_RED);
        _delay_ms(500);
    }

    return 0;
}