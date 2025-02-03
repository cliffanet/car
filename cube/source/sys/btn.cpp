/*
    Button processor
*/

#include "btn.h"
#include "proc.h"
#include "power.h"
#include "stm32drv.h"
#include "../path.h"


#define BTN_PIN_SEL     GPIOB, GPIO_PIN_7
#define BTN_PIN_UP      GPIOB, GPIO_PIN_3
#define BTN_PIN_DN      GPIOB, GPIO_PIN_4
#define BTN_PIN_LT      GPIOB, GPIO_PIN_5
#define BTN_PIN_RT      GPIOB, GPIO_PIN_6

#define BSTATE(btn)     HAL_GPIO_ReadPin(btn.gpiox, btn.pin)
#define PUSHED(state)   ((state) == GPIO_PIN_RESET)

namespace btn {

    static bool     _sleep = false;         // в sleep-режиме в прерываниях мы не делаем обработку
                                            // на нажатия. Прерывание тут нужно только для пробуждения.
    static uint32_t _tickact = 0;           // кол-во тиков после крайней активности
    static hnd_t    _hold = NULL;           // обработчик зажатой кнопки
                                            // его нужно устанавливать при обычном onclick
                                            // при любом другом push/release он будет сброшен

    typedef struct {
        code_t          code;               // Код кнопки
        GPIO_TypeDef *  gpiox;              // группа пинов
        uint16_t        pin;                // пин
        GPIO_PinState   state;              // текущее состояние пина кнопки
        uint32_t        tmpsh, tmrls;       // время предыдущего нажатия на кнопку и отпускания (для антидребезга)
        uint8_t         cntsmpl, cntlong;   // счётчик сработавших событий simple и long
        bool            evtok;              // указывает на то, что hnd уже сработало при текущем удержании
        hnd_t           hndsmpl, hndlong;   // обработчики событий simple и long
    } el_t;

    static el_t _all[] = {
        { SEL,  BTN_PIN_SEL },
        { UP,   BTN_PIN_UP },
        { DN,   BTN_PIN_DN },
        { LT,   BTN_PIN_LT },
        { RT,   BTN_PIN_RT },
    };

    static void _initpin(el_t &b) {
        b.state = BSTATE(b);
        b.tmrls = HAL_GetTick();
        if (PUSHED(b.state)) {
            // pushed
            b.tmpsh = b.tmrls;
            b.evtok = true;
        }
        else {
            b.tmpsh = 0;
            b.evtok = false;
        }
    }

    static void _read(el_t &b) {
        auto st = BSTATE(b);
        bool pushed = PUSHED(st);
        bool chg = st != b.state;
        auto tm = HAL_GetTick();

        if (chg) {
            pwr::active();

            _hold = NULL;
            _tickact = 0;
            if (pushed && ((tm-b.tmrls) > BTN_FILTER_TIME)) {
                // отфильтрованное нажатие
                b.tmpsh = tm;
                if (!b.evtok && (b.hndsmpl != NULL) && (b.hndlong == NULL)) {
                    // hndsmpl при отсутствующем hndlong
                    // срабатывает при нажатии
                    b.cntsmpl ++;
                    b.evtok = true;
                }
            }
            b.tmrls = tm;
            b.state = st;
        }
        else
        if (!pushed && (b.tmpsh > 0) && ((tm-b.tmrls) > BTN_FILTER_TIME)) {
            // отфильтрованное отпускание
            if (!b.evtok && (b.hndsmpl != NULL) && (b.hndlong != NULL)) {
                // hndsmpl при наличии hndlong
                // срабатывает при отпускании
                b.cntsmpl ++;
            }
            b.tmpsh = 0;
            b.evtok = false;
        }

        if (!b.evtok && (b.hndlong != NULL) && pushed && (b.tmpsh > 0) && ((tm-b.tmpsh) > BTN_LONG_TIME)) {
            b.cntlong ++;
            b.evtok = true;
        }
    }

    static void _proc() {
        if (_hold != NULL)
            _hold();
        else
            _tickact ++;
        
        for (auto &b: _all) {
            _read(b);

            if (b.hndsmpl != NULL)
                for (; b.cntsmpl > 0; b.cntsmpl--)
                    b.hndsmpl();
            else
            if (b.cntsmpl > 0)
                b.cntsmpl = 0;
            if (b.hndlong != NULL)
                for (; b.cntlong > 0; b.cntlong--)
                    b.hndlong();
            else
            if (b.cntlong > 0)
                b.cntlong = 0;
        }
    }

    // ------------------------------------

    void set(code_t code, hnd_t hndsmpl, hnd_t hndlong) {
        for (auto &b: _all)
            if (b.code == code) {
                b.hndsmpl = hndsmpl;
                b.hndlong = hndlong;
                return;
            }
    }

    void hold(hnd_t hnd) {
        if (!ispushed())
            return;
        _hold = hnd;
    }

    void sleep() {
        _sleep = true;
        while (ispushed())
            asm("");
    }

    void resume() {
        while (ispushed())
            asm("");
        
        _sleep = false;
        _tickact = 0;

        for (auto &b: _all)
            _initpin(b);
    }

    bool isactive(uint32_t tickcnt) {
        return _tickact <= tickcnt;
    }

    bool ispushed() {
        for (const auto &b: _all)
            if (PUSHED(BSTATE(b)))
                return true;
        return false;
    }

}; // namespace btn


#include "log.h"
#include "../chassis/motor.h"

void init_btn() {
    btn::resume();
    proc::add(btn::_proc);

    btn::set(btn::SEL, [] () {
        CONSOLE("btn SEL");
        path::stop();
        motor::stop();
    });
    btn::set(btn::UP,  [] () {
        CONSOLE("btn UP");
        path::stop();
        motor::straight(false);
    });
    btn::set(btn::DN,  [] () {
        CONSOLE("btn DN");
        path::stop();
        motor::straight(true);
    });
    btn::set(btn::LT,  [] () {
        CONSOLE("btn LT");
        path::stop();
        motor::fstturnl();
    });
    btn::set(btn::RT,  [] () {
        CONSOLE("btn RT");
        path::stop();
        motor::fstturnr();
    });
}

#ifdef __cplusplus
    extern "C"
#endif
void btn_byexti(uint16_t pin) {
    if (btn::_sleep)
        return;
    for (auto &b: btn::_all)
        if ((b.gpiox != NULL) && (b.pin == pin))
            btn::_read(b);
}
