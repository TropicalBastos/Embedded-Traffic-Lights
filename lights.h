#ifndef LIGHTS_H
#define LIGHTS_H

#include <avr/io.h>

#define _PIN_13 0b00100000
#define _PIN_12 0b00010000
#define _PIN_11 0b00001000
#define _PIN_10 0b00000100

#define _RED _PIN_12
#define _AMBER _PIN_11
#define _GREEN _PIN_10

#define _DELAY_TIME 1500
#define _RUN_TIME 5000

void switch_off(uint8_t light);
void switch_on(uint8_t light);
void red_to_amber();
void amber_to_green();
void green_to_amber();
void amber_to_red();
void light_to_light(uint8_t light1, uint8_t light2);

#endif // LIGHTS_H