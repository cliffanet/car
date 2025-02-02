/*
    Batt
*/

#include "stm32drv.h"
#include "batt.h"
#include "proc.h"
#include "display.h"
#include "../display/u8g2_fonts.h"
#include "../chassis/led.h"


#define BATT_PIN_INFO       GPIOC, GPIO_PIN_0
#define BATT_PIN_CHRG_STB   GPIOB, GPIO_PIN_8
#define BATT_PIN_CHRG_ACT   GPIOB, GPIO_PIN_9

extern ADC_HandleTypeDef hadc1;

static uint32_t _raw = 0;
static bool _chg_stb = false, _chg_act = false;
static uint8_t _blink = 0;

static void _proc() {
    HAL_ADC_Start(&hadc1);
    _raw =
        HAL_ADC_PollForConversion(&hadc1, 1000) == HAL_OK ?
            HAL_ADC_GetValue(&hadc1) :
            0;
    HAL_ADC_Stop(&hadc1);

    bool
        _stb = HAL_GPIO_ReadPin(BATT_PIN_CHRG_STB) == GPIO_PIN_RESET,
        _act = HAL_GPIO_ReadPin(BATT_PIN_CHRG_ACT) == GPIO_PIN_RESET;
    
    if (_chg_stb != _stb) {
        _chg_stb = _stb;
    }
    if (_chg_act != _act) {
        _chg_act = _act;
        if (_act)
            led::on(led::INTB);
        else
            led::off(led::INTB);
    }

    _blink++;
}

static void _draw(DsplGfx &gfx) {
    auto v05 = batt::val05();

    if ((v05 > 0) || (_blink%10 > 4)) {
        if (v05 >= 4)
            gfx.color(COLOR_GREEN);
        else
        if (v05 <= 1)
            gfx.color(COLOR_RED);
        else
            gfx.color(COLOR_YELLOW);
        
        static DsplFontU8g2 f(u8g2_font_battery24_tr);
        gfx.symb(0, 25, f, '0' + (v05 > 0 ? v05-1 : 0));
    }

    if (_chg_act) {
        gfx.color(COLOR_RED);
        static DsplFontU8g2 f(u8g2_font_open_iconic_embedded_2x_t);
        gfx.symb(3, 22, f, 'C');
    }
    else
    if (_chg_stb) {
        gfx.color(COLOR_BLUE);
        static DsplFontU8g2 f(u8g2_font_open_iconic_embedded_2x_t);
        gfx.symb(3, 22, f, 'C');
    }
}

void init_batt() {
    proc::add(_proc);
    dspl::add(_draw);
}


namespace batt {

    uint16_t raw() {
        return _raw;
    }

    uint8_t val05() {
        // 4.3 = 3945
        // 4.2 = 3850
        // 4.1 = 3757
        // 4.0 = 3665
        // 3.9 = 3572
        // 3.8 = 3480
        // 3.7 = 3385
        // 3.6 = 3290
        // 3.5 = 3197
        // 3.4 = 3105
        // 3.35 = 3060
        // 3.3 = 3040
        // 3.2 = 3040 - уже явно ошибка
        // где-то на 3.33 останавливается снижение показаний
        // и ниже всегда: 3030-3040
        // ниже - работает очень нестабильно
        // причём, проблемы только с дисплеем,
        // дисплёй:
        // - 3.14-3.15 на акк: работает стабильно
        // - 3.12-3.13 на акк: артефакты
        // - 3.10-3.11 на акк: гарантированно отключается
        // сам cpu работает примерно до 2.6-2.7в на акк
        // отключать надо где-то на 3100
        return
            _raw > 3700 ? 5 :
            _raw > 3580 ? 4 :
            _raw > 3450 ? 3 :
            _raw > 3350 ? 2 :
            _raw > 3200 ? 1 :
            0;
    }

    bool charge() {
        return _chg_act;
    }

} // namespace batt 


