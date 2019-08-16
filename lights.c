#ifndef F_CPU
#define F_CPU 16000000UL // or whatever may be your frequency
#endif

#include "lights.h"
#include <avr/io.h>
#include <util/delay.h>

int light_arr[] = { _PIN_12, _PIN_11, _PIN_10 };

void switch_off(uint8_t light)
{
    PORTB = light & (~light);
}

void switch_on(uint8_t light)
{
    PORTB = PORTB | light;
}

void red_to_amber()
{
    switch_on(_AMBER);
     _delay_ms(_DELAY_TIME);
}

void amber_to_green()
{
    switch_off(_RED);
    switch_off(_AMBER);
    switch_on(_GREEN);
}

void green_to_amber()
{
    switch_off(_GREEN);
    switch_on(_AMBER);
}

void amber_to_red()
{
    switch_off(_AMBER);
    switch_on(_RED);
}

void light_to_light(uint8_t light1, uint8_t light2)
{
    switch_off(light1);
    switch_on(light2);
}