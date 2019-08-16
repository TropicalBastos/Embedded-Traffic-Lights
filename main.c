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
        switch_on(_RED);
        _delay_ms(_RUN_TIME);

        // red to amber already delays for us due to being a dual light emitter
        red_to_amber();
        amber_to_green();
        
        _delay_ms(_RUN_TIME);

        green_to_amber();
        _delay_ms(_DELAY_TIME);

        amber_to_red();
    }

    return 0;
}