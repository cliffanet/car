/*
    Ultrasonic HC-SR04
*/

#include "sr04.h"
#include "motor.h"
#include "../sys/proc.h"
#include "../sys/display.h"
#include "../sys/log.h"
#include "../sys/stm32drv.h"
#include "../display/u8g2_fonts.h"

#include "stdio.h"

static bool _eok = false, _erun = false;
static uint32_t _ebeg = 0, _eus = 0;
static uint16_t _eback = 0;

static void _proc() {
    if (_eback == 0) {
        if (!_eok || !_erun)
            return;
        if (
                (motor::isrun(motor::L_A) != motor::FWD) ||
                (motor::isrun(motor::L_B) != motor::FWD) ||
                (motor::isrun(motor::R_A) != motor::FWD) ||
                (motor::isrun(motor::R_B) != motor::FWD)
            )
            return;
        
        if (sr04::distmm() < 150) {
            _eback = 20;
            motor::straight(true);
        }
        return;
    }

    _eback --;
    if (_eback == 10)
        motor::fstturnl();
    else
    if (_eback == 0) {
        motor::straight(false);
    }
}

static void _draw(DsplGfx &gfx) {
    if (!_eok || !_erun)
        return;
    
    double mm = sr04::distmm();
    
    DsplFontU8g2 f(u8g2_font_fub20_tr);
    gfx.color(mm > 300 ? COLOR_GREEN : mm > 200 ? COLOR_YELLOW : COLOR_RED);
    char s[32];
    if (mm > 200)
        snprintf(s, sizeof(s), "%0.1f m", mm/1000);
    else
    if (mm > 10)
        snprintf(s, sizeof(s), "%0.1f cm", mm/10);
    else
        snprintf(s, sizeof(s), "%0.0f mm", mm);
    gfx.text(480-f.width(s), f.ascent(), f, s);

    if (_eback > 0) {
        snprintf(s, sizeof(s), "%d", _eback);
        gfx.text(480-f.width(s), f.ascent()*2, f, s);
    }
}

void init_sr04() {
}


extern TIM_HandleTypeDef htim2;

#ifdef __cplusplus
    extern "C"
#endif
void sr04_byexti(uint16_t pin) {
    if (pin != GPIO_PIN_3)
        return;
    uint32_t cnt = __HAL_TIM_GET_COUNTER(&htim2);
    auto v = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
    if (v) {
        if (_eus > 0)
            _eok = false;
        _ebeg = cnt;
    }
    else
    if (cnt > _ebeg) {
        _eok = true;
        _eus = cnt - _ebeg;
    }
    else
        _eok = false;
}

namespace sr04 {

    void start() {
        _erun = true;
        HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
        proc::add(_proc);
        dspl::add(_draw);
    }

    void stop() {
        _erun = false;
        _eback = false;
        HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
        proc::del(_proc);
        dspl::del(_draw);
    }

    uint16_t distmm() {
        return _eus * 10 / 56;
    }

    bool isback() {
        return _eback > 0;
    }

}; // namespace sr04
