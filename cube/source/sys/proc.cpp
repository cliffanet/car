
#include "proc.h"
#include "stm32drv.h"
#include "log.h"

#include <list>

static std::list<proc::el_t> _proc;

void init_display();
void init_touch();

void init_testbox();
void init_testtouch();

extern "C"
void init() {
    init_display();
    init_touch();
    init_testtouch();
    init_testbox();

    while (1) {
        for (auto p: _proc)
            p();
    }
}



/*
extern "C"
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    uint8_t l = HAL_GPIO_ReadPin(TOUCH_PIN_IRQ);
        CONSOLE("touch: %d", l);

    if ((GPIO_Pin == GPIO_PIN_10) && !l) {
        tcupd = true;
    }
}

extern "C"
void HardFault_Handler(void) {
    while (1) {
        for (int n = 0; n < 3000000; n++)
            asm("");
        HAL_GPIO_TogglePin(GPIOA, led_red_Pin);
    }
}

extern "C"
void MemManage_Handler(void) {
    while (1) {
        for (int i =0; i < 10; i++) {
            for (int n = 0; n < 3000000; n++)
                asm("");
            HAL_GPIO_TogglePin(GPIOA, led_red_Pin);
        }
        for (int n = 0; n < 30000000; n++)
            asm("");
    }
}
*/

namespace proc {
    void add(el_t p) {
        for (const auto e: _proc)
            if (p == e)
                return;
        _proc.push_back(p);
    }

    void del(el_t p) {
        for (auto i = _proc.cbegin(); i != _proc.cend(); i++)
            if (*i == p) {
                _proc.erase(i);
                return;
            }
    }
};
