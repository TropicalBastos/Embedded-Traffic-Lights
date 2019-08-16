#include "lights.h"

int light_arr[] = { _PIN_12, _PIN_11, _PIN_10 };

void switch_off(uint8_t light)
{
    PORTB = light & (~light);
}

void switch_on(uint8_t light)
{
    PORTB = PORTB | light;
}