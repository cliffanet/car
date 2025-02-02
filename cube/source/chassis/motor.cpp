/*
    Motor
*/

#include "motor.h"
#include "../sys/proc.h"
#include "../sys/stm32drv.h"

typedef struct {
    GPIO_TypeDef *  gpiox;               // группа пинов
    uint16_t        pin;                // пин
} pin_t;

typedef struct {
    pin_t in1, in2;
    bool rev;
} mot_t;

static mot_t _motall[] = {
    // L_A
    { { GPIOC, GPIO_PIN_8 },    { GPIOC, GPIO_PIN_9 },  true },
    // L_B
    { { GPIOA, GPIO_PIN_9 },    { GPIOA, GPIO_PIN_8 },  true },
    // R_A
    { { GPIOB, GPIO_PIN_12 },   { GPIOB, GPIO_PIN_13 }, false },
    // R_B
    { { GPIOB, GPIO_PIN_15 },   { GPIOB, GPIO_PIN_14 }, false },
};

inline const mot_t *mot(motor::code_t m) {
    return (m >= 0) && (m < 4) ? _motall + m : NULL;
}

namespace motor {
    dir_t isrun(code_t _m) {
        auto m = mot(_m);
        if (!m)
            return OFF;

        return OFF;
    }

    void run(code_t _m, dir_t dir) {
        auto m = mot(_m);
        if (!m)
            return;

        switch (dir) {
            case OFF:
                HAL_GPIO_WritePin(m->in1.gpiox, m->in1.pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(m->in2.gpiox, m->in2.pin, GPIO_PIN_RESET);
                break;
            
            case FWD:
                HAL_GPIO_WritePin(m->in1.gpiox, m->in1.pin, m->rev ? GPIO_PIN_RESET : GPIO_PIN_SET);
                HAL_GPIO_WritePin(m->in2.gpiox, m->in2.pin, m->rev ? GPIO_PIN_SET : GPIO_PIN_RESET);
                break;
            
            case BAC:
                HAL_GPIO_WritePin(m->in1.gpiox, m->in1.pin, m->rev ? GPIO_PIN_SET : GPIO_PIN_RESET);
                HAL_GPIO_WritePin(m->in2.gpiox, m->in2.pin, m->rev ? GPIO_PIN_RESET : GPIO_PIN_SET);
                break;
            
            case BRK:
                HAL_GPIO_WritePin(m->in1.gpiox, m->in1.pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(m->in2.gpiox, m->in2.pin, GPIO_PIN_SET);
                break;
        }
    }
}; // namespace motor
