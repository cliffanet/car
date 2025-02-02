/*
    Led
*/

#ifndef _chassis_led_H
#define _chassis_led_H

#include "../def.h"
#include <stdint.h>
#include <stddef.h>

namespace led {

    // Коды светодиодов
    typedef enum {
        INTR = 0,
        INTB,
        C1,
        C2,
        C3
    } code_t;

    bool ison(code_t led);
    void on(code_t led);
    void off(code_t led);
    void toggle(code_t led);
}; // namespace led

#endif // _chassis_led_H
