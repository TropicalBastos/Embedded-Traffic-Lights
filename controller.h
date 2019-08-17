#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <avr/io.h>

#define _PIN_5 0b00100000
#define _STOP_BUTTON _PIN_5

void start_traffic();
void stop_traffic();
void on_press();
uint8_t is_stop_button_pressed();

#endif // CONTROLLER_H