#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include "lights.h"
#include "controller.h"

// make it brief
#define _DELAY_IN_RED 10000

uint8_t traffic_stopped = 0;

void start_traffic()
{
    _delay_ms(_RUN_TIME);

    // red to amber already delays for us due to being a dual light emitter
    red_to_amber();
    amber_to_green();
    
    traffic_stopped = 0;
}

void stop_traffic()
{
    green_to_amber();
    _delay_ms(_DELAY_TIME);

    amber_to_red();
    _delay_ms(_DELAY_IN_RED);

    start_traffic();
}

void on_press()
{
    _delay_ms(200);
    if (!traffic_stopped)
    {
        traffic_stopped = 1;
        stop_traffic();
    }
}

uint8_t is_stop_button_pressed()
{
    if (PIND & _STOP_BUTTON)
    {
        return 1;
    }

    return 0;
}