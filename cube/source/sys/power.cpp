/*
    Power
*/

#include "stm32drv.h"
#include "power.h"
#include "proc.h"
#include "log.h"
#include "btn.h"
#include "display.h"
#include "touch.h"
#include "../chassis/motor.h"

/* ------  spi on/off  --------- */

extern SPI_HandleTypeDef hspi1;

static void _spi_off() {
    // spi даёт 0.22 mA
    HAL_SPI_DeInit(&hspi1);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

static void _spi_on() {
    HAL_SPI_Init(&hspi1);
}

/* ------  power on/off  --------- */

#include "usbd_cdc_if.h"
extern USBD_HandleTypeDef hUsbDeviceFS;
extern "C" void MX_USB_DEVICE_Init(void);

static void _off() {
    btn::sleep();
    dspl::sleep();
    ts::sleep();
    _spi_off();
    motor::stop();
    motor::sleep();

    // отключение usb и adc даёт не более 20 мкА
    //HAL_ADC_DeInit(&hadc1);
    USBD_Stop(&hUsbDeviceFS);
    USBD_DeInit(&hUsbDeviceFS);
}

static void _on() {
    //HAL_ADC_Init(&hadc1);
    MX_USB_DEVICE_Init();

    CONSOLE("init");
    _spi_on();
    btn::resume();
    dspl::resume();
    ts::resume();
    motor::resume();
}

extern "C"
void SystemClock_Config(void);
static void _stop() {
    HAL_SuspendTick();
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
    HAL_ResumeTick();
    SystemClock_Config();
}

/* ------  -------  --------- */

static uint32_t _active = 0;

void _proc() {
    auto tm = HAL_GetTick();

    if ((tm - _active) > 40000) {
        _off();
        _stop();
        _on();
        pwr::active();
    }
}

void init_power() {
    pwr::active();
    proc::add(_proc);
}

namespace pwr {

    void active() {
        _active = HAL_GetTick();
    }
};
