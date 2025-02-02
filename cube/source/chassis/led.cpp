/*
    Led
*/

#include "led.h"
#include "../sys/proc.h"
#include "../sys/stm32drv.h"

typedef struct {
    GPIO_TypeDef *  gpiox;              // группа пинов
    uint16_t        pin;                // пин
} pin_t;

static pin_t _pinall[] = {
    // INTR
    { GPIOC, GPIO_PIN_11 },
    // INTB
    { GPIOC, GPIO_PIN_12 },
    // C1
    { GPIOC, GPIO_PIN_1 },
    // C2
    { GPIOC, GPIO_PIN_2 },
    // C3
    { GPIOC, GPIO_PIN_3 },
};

inline const pin_t *pin(led::code_t l) {
    return (l >= 0) && (l < 5) ? _pinall + l : NULL;
}

namespace led {
    bool ison(code_t led) {
        auto p = pin(led);
        return p && (HAL_GPIO_ReadPin(p->gpiox, p->pin) == GPIO_PIN_SET);
    }

    void on(code_t led) {
        auto p = pin(led);
        if (p)
            HAL_GPIO_WritePin(p->gpiox, p->pin, GPIO_PIN_SET);
    }

    void off(code_t led) {
        auto p = pin(led);
        if (p)
            HAL_GPIO_WritePin(p->gpiox, p->pin, GPIO_PIN_RESET);
    }

    void toggle(code_t led) {
        auto p = pin(led);
        if (p)
            HAL_GPIO_TogglePin(p->gpiox, p->pin);
    }

}; // namespace led
