#include "xpt2046.h"
#include "../sys/stm32drv.h"

// ---------------------------------------------------------

extern SPI_HandleTypeDef hspi1;

#define MSR_OP          0x80
#define MSR_X           0x90
#define MSR_Y           0xD0
#define MSR_Z1          0xB0
#define MSR_Z2          0xC0

// надо ли оставлять включённым измерятель
#define MSR_ON          0x01
// только при выключенном измерятеле активируется пин IRQ
// после всех измерений надо выключить измерятель
#define MSR_OFF         0x00
#define MSR_WAIT()      HAL_Delay(3)

// ---------------------------------------------------------

class _CS {
    public:
        static inline void beg() {
    while (SPI1->SR & SPI_SR_BSY_Msk);
            HAL_GPIO_WritePin(TOUCH_PIN_CS, GPIO_PIN_RESET);
        }
        static inline void end() {
            HAL_GPIO_WritePin(TOUCH_PIN_CS, GPIO_PIN_SET);
        }
        _CS()   { beg(); }
        ~_CS()  { end(); }
};

class _SPILOW {
    uint32_t _prescaller = 0;
    public:
        _SPILOW()   {
            _prescaller = hspi1.Init.BaudRatePrescaler;
            if (hspi1.Init.BaudRatePrescaler < SPI_BAUDRATEPRESCALER_64) {
                while (SPI1->SR & SPI_SR_BSY_Msk);
                hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
                SET_BIT(hspi1.Instance->CR1, hspi1.Init.BaudRatePrescaler & SPI_CR1_BR_Msk);
                while (SPI1->SR & SPI_SR_BSY_Msk);
            }
        }
        ~_SPILOW()  {
            if (hspi1.Init.BaudRatePrescaler != _prescaller) {
                while (SPI1->SR & SPI_SR_BSY_Msk);
                hspi1.Init.BaudRatePrescaler = _prescaller;
                CLEAR_BIT(hspi1.Instance->CR1, SPI_CR1_BR_Msk);
                SET_BIT(hspi1.Instance->CR1, hspi1.Init.BaudRatePrescaler & SPI_CR1_BR_Msk);
                while (SPI1->SR & SPI_SR_BSY_Msk);
            }
        }
};

static void _cmd(uint8_t c) {
    HAL_SPI_Transmit(&hspi1, &c, 1, 10);
}
static uint16_t _cmdr(uint8_t c = 0) {
    //MSR_WAIT();
    uint8_t tx[] = { 0x00, c };
    uint8_t rx[sizeof(tx)];
    HAL_SPI_TransmitReceive(&hspi1, tx, rx, sizeof(tx), 10);
    return (rx[0] << 8) | rx[1];
}

void TouchXPT2046::init() {
    _CS cs;
    _cmd(MSR_OP | MSR_OFF);
}

#include "../sys/log.h"
TouchXPT2046::val_t TouchXPT2046::get() {
    _CS cs;
    _SPILOW lo;

    // особенности XPT2046
    // 1. он требует минимум 1.6мс от начала замера (отправка команды) до сбора результата
    // 2. позволяет отправить команду на следующий замер, получая второй байт результатов:
    //  т.е. следующая команда отправляется в накладку с получением данных о предыдущей

    // Т.е. действовать будем по следующему алгоритму:
    // 1. Отправляем первую команду через _cmd - только отправка одного байта
    // 2. Ждём 2мс
    // 3. Командой _cmdr выполняем отправку двух байт: 0x00 и следующую команду на измерение
    // 4. Возвращённые в п.3 данные будут результатом измерения п.1
    // 5. Ждём 2мс
    // 6. Аналогично п.3 отправляем следующую команду или просто два нулевых байта, если больше не надо
    // 7. Полученные в п.6 данные будут результатом замеров п.3

    // Позже выяснилось, что паузу после старта замера можно не делать,
    // но нужно обязательно понижать скорость spi

    uint16_t z1 = 0, z2 = 0, x = 0, y = 0, n;
    for (n = 0; n < 5; n++) {
                _cmd (MSR_Z1 | MSR_ON);
        z1 +=   _cmdr(MSR_Z2 | MSR_ON) >> 3;
        z2 +=   _cmdr(MSR_X  | MSR_ON) >> 3;
                        // Везде говорят, что первый замер всегда с шумами, его надо пропускать
                        //_cmdr(MSR_X  | MSR_ON);
        x +=    _cmdr(MSR_Y  | MSR_ON) >> 3;
        y +=    _cmdr(MSR_OFF) >> 3;
    }

    //CONSOLE("x: 0x%04x; y: 0x%04x, z: 0x%04x", x, y, z1 + 0xfff - z2);

    return { x/n, y/n, z1/n + 0xfff - z2/n };
}
