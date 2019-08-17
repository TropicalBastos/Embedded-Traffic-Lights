#ifndef F_CPU
#define F_CPU 16000000UL // or whatever may be your frequency
#endif
 
#include <avr/io.h>
#include <util/delay.h>
#include "lights.h"
#include "controller.h"

int main(void)
{
    DDRD = 0b00000000;
    DDRB = _PIN_12 | _PIN_11 | _PIN_10;
    while(1)
    {
        switch_on(_GREEN);

        if (is_stop_button_pressed())
            on_press();
    }

    return 0;
}