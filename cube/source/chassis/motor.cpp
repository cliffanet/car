/*
    Motor
*/

#include "motor.h"
#include "../sys/stm32drv.h"
#include "../sys/proc.h"
#include "../sys/display.h"
#include "../display/u8g2_fonts.h"
#include "../chassis/led.h"

#define MOT_PIN_SLEEP       GPIOC, GPIO_PIN_7
#define MOT_PIN_FLT_L       GPIOA, GPIO_PIN_15
#define MOT_PIN_FLT_R       GPIOC, GPIO_PIN_6

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


static bool _flt_l = false, _flt_r = false;
static uint8_t _blink = 0;

static enum {
    DIR_STOP,
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} _dir = DIR_STOP;

static void _proc() {
    _flt_l = HAL_GPIO_ReadPin(MOT_PIN_FLT_L) == GPIO_PIN_RESET;
    _flt_r = HAL_GPIO_ReadPin(MOT_PIN_FLT_R) == GPIO_PIN_RESET;

    _blink++;
}

static void _draw(DsplGfx &gfx) {
    if (_flt_l && (_blink%10 > 4)) {
        gfx.color(COLOR_RED);
        DsplFontU8g2 f(u8g2_font_open_iconic_play_4x_t);
        gfx.symb(480 - 64, 25, f, 'I');
    }
    if (_flt_r && (_blink%10 > 4)) {
        gfx.color(COLOR_RED);
        DsplFontU8g2 f(u8g2_font_open_iconic_play_4x_t);
        gfx.symb(480 - 32, 25, f, 'J');
    }

    if (_dir > DIR_STOP) {
        gfx.color(COLOR_GREEN);
        DsplFontU8g2 f(u8g2_font_open_iconic_arrow_8x_t);
        uint16_t c =
            _dir == DIR_UP      ? 'G' :
            _dir == DIR_DOWN    ? 'D' :
            _dir == DIR_LEFT    ? 'E' :
            _dir == DIR_RIGHT   ? 'F' : ' ';
        gfx.symb(480 - 120, 190, f, c);
    }
}

void init_motor() {
    motor::resume();
    proc::add(_proc);
    dspl::add(_draw);
}

namespace motor {
    dir_t isrun(code_t _m) {
        auto m = mot(_m);
        if (!m)
            return OFF;

        auto in1 = HAL_GPIO_ReadPin(m->in1.gpiox, m->in1.pin);
        auto in2 = HAL_GPIO_ReadPin(m->in2.gpiox, m->in2.pin);

        return
            (in1 == GPIO_PIN_RESET) && (in2 == GPIO_PIN_SET) ?
                (m->rev ? FWD : BAC) :
            (in1 == GPIO_PIN_SET) && (in2 == GPIO_PIN_RESET) ?
                (m->rev ? BAC : FWD) :
            (in1 == GPIO_PIN_SET) && (in2 == GPIO_PIN_SET) ?
                BRK :
                OFF;
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

    void straight(bool rev) {
        run(L_A, rev ? BAC : FWD);
        run(L_B, rev ? BAC : FWD);
        run(R_A, rev ? BAC : FWD);
        run(R_B, rev ? BAC : FWD);
        _dir = rev ? DIR_DOWN : DIR_UP;
    }

    void fstturnl() {
        run(L_A, BAC);
        run(L_B, BAC);
        run(R_A, FWD);
        run(R_B, FWD);
        _dir = DIR_LEFT;
    }

    void fstturnr() {
        run(L_A, FWD);
        run(L_B, FWD);
        run(R_A, BAC);
        run(R_B, BAC);
        _dir = DIR_RIGHT;
    }

    void stop(bool brk) {
        run(L_A, brk ? BRK : OFF);
        run(L_B, brk ? BRK : OFF);
        run(R_A, brk ? BRK : OFF);
        run(R_B, brk ? BRK : OFF);
        _dir = DIR_STOP;
    }

    void sleep() {
        HAL_GPIO_WritePin(MOT_PIN_SLEEP, GPIO_PIN_RESET);
    }
    void resume() {
        HAL_GPIO_WritePin(MOT_PIN_SLEEP, GPIO_PIN_SET);
    }
}; // namespace motor
