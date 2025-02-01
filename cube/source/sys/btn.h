/*
    Button processor
*/

#ifndef _sys_btn_H
#define _sys_btn_H

#include "../def.h"
#include <stdint.h>
#include <stddef.h>


// минимальное время между изменениями состояния кнопки
#define BTN_FILTER_TIME     10
// время длинного нажатия
#define BTN_LONG_TIME       1000
// кол-во тиков без любых нажатий, после которого считается, что нет активности по кнопкам
#define BTN_ACTIVE_LONG     300
// кол-во тиков без любых нажатий, при которых устройство будет оставаться
// в power-active режиме, чтобы верно отрабатывал HAL_GetTick
#define BTN_ACTIVE_SHORT    30

#ifdef __cplusplus

namespace btn {

    // Коды кнопок
    typedef enum {
        SEL = 1,
        UP,
        DN,
        LT,
        RT
    } code_t;

    typedef void (*hnd_t)();

    void set(code_t code, hnd_t hndsmpl, hnd_t hndlong = NULL);
    void hold(hnd_t hnd);
    void sleep();

    bool isactive(uint32_t tickcnt = BTN_ACTIVE_SHORT);
    bool ispushed();
}; // namespace Btn

    extern "C"
#endif // __cplusplus
    void btn_byexti(uint16_t pin);

#endif // _sys_btn_H
