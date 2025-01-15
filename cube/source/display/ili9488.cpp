#include "ili9488.h"
#include "../sys/stm32drv.h"

// ---------------------------------------------------------

#define ILI9488_NOP           0x00
#define ILI9488_SWRESET       0x01
#define ILI9488_RDDID         0x04
#define ILI9488_RDDST         0x09

#define ILI9488_SLPIN         0x10
#define ILI9488_SLPOUT        0x11
#define ILI9488_PTLON         0x12
#define ILI9488_NORON         0x13

#define ILI9488_RDMODE        0x0A
#define ILI9488_RDMADCTL      0x0B
#define ILI9488_RDPIXFMT      0x0C
#define ILI9488_RDIMGFMT      0x0D
#define ILI9488_RDSELFDIAG    0x0F

#define ILI9488_INVOFF        0x20
#define ILI9488_INVON         0x21
#define ILI9488_GAMMASET      0x26
#define ILI9488_DISPOFF       0x28
#define ILI9488_DISPON        0x29

#define ILI9488_CASET         0x2A
#define ILI9488_PASET         0x2B
#define ILI9488_RAMWR         0x2C
#define ILI9488_RAMRD         0x2E

#define ILI9488_PTLAR         0x30
#define ILI9488_VSCRDEF       0x33
#define ILI9488_MADCTL        0x36
#define ILI9488_VSCRSADD      0x37
#define ILI9488_PIXFMT        0x3A
#define ILI9488_RAMWRCONT     0x3C
#define ILI9488_RAMRDCONT     0x3E

#define ILI9488_IMCTR         0xB0
#define ILI9488_FRMCTR1       0xB1
#define ILI9488_FRMCTR2       0xB2
#define ILI9488_FRMCTR3       0xB3
#define ILI9488_INVCTR        0xB4
#define ILI9488_DFUNCTR       0xB6

#define ILI9488_PWCTR1        0xC0
#define ILI9488_PWCTR2        0xC1
#define ILI9488_PWCTR3        0xC2
#define ILI9488_PWCTR4        0xC3
#define ILI9488_PWCTR5        0xC4
#define ILI9488_VMCTR1        0xC5
#define ILI9488_VMCTR2        0xC7

#define ILI9488_RDID1         0xDA
#define ILI9488_RDID2         0xDB
#define ILI9488_RDID3         0xDC
#define ILI9488_RDID4         0xDD

#define ILI9488_GMCTRP1       0xE0
#define ILI9488_GMCTRN1       0xE1
#define ILI9488_IMGFUNCT      0xE9

#define ILI9488_ADJCTR3       0xF7

#define ILI9488_MAD_RGB       0x08
#define ILI9488_MAD_BGR       0x00

#define ILI9488_MAD_VERTICAL  0x20
#define ILI9488_MAD_X_LEFT    0x00
#define ILI9488_MAD_X_RIGHT   0x40
#define ILI9488_MAD_Y_UP      0x80
#define ILI9488_MAD_Y_DOWN    0x00

// ---------------------------------------------------------

extern SPI_HandleTypeDef hspi1;

// ---------------------------------------------------------

static void _cmd8(uint8_t cmd8) {
    HAL_GPIO_WritePin(DSPL_PIN_DC, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, &cmd8, 1, 100);
    HAL_GPIO_WritePin(DSPL_PIN_DC, GPIO_PIN_SET);
}
static void _cmd8(uint8_t cmd8, const uint8_t *data, size_t sz) {
    _cmd8(cmd8);
    HAL_SPI_Transmit(&hspi1, data, sz, 10*sz);
}

// ---------------------------------------------------------

class _CS {
    public:
        static inline void beg() {
            HAL_GPIO_WritePin(DSPL_PIN_CS, GPIO_PIN_RESET);
        }
        static inline void end() {
            HAL_GPIO_WritePin(DSPL_PIN_CS, GPIO_PIN_SET);
        }
        _CS()   { beg(); }
        ~_CS()  { end(); }
};

class _SPI16 {
    public:
        static inline void beg() {
            if (hspi1.Init.DataSize != SPI_DATASIZE_16BIT) {
                hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
                SET_BIT(hspi1.Instance->CR1, hspi1.Init.DataSize & SPI_CR1_DFF);
            }
        }
        static inline void end() {
            hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
            CLEAR_BIT(hspi1.Instance->CR1, SPI_DATASIZE_16BIT & SPI_CR1_DFF);
        }
        _SPI16()    { beg(); }
        ~_SPI16()   { end(); }
};

// ---------------------------------------------------------


static void _init(uint8_t cmd8) {
    _CS cs;
    _cmd8(cmd8);
}
static void _init(uint8_t cmd8, uint8_t arg) {
    _CS cs;
    _cmd8(cmd8, &arg, 1);
}
static void _init(uint8_t cmd8, const char *data, size_t sz) {
    _CS cs;
    _cmd8(cmd8, reinterpret_cast<const uint8_t *>(data), sz);
}



void DsplILI9488::init() {
    HAL_GPIO_WritePin(DSPL_PIN_BL, GPIO_PIN_SET);

    HAL_GPIO_WritePin(DSPL_PIN_RST, GPIO_PIN_SET);

    HAL_GPIO_WritePin(DSPL_PIN_DC, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DSPL_PIN_CS, GPIO_PIN_SET);
    
    HAL_Delay(10);
    HAL_GPIO_WritePin(DSPL_PIN_RST, GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(DSPL_PIN_RST, GPIO_PIN_SET);
    HAL_Delay(10);

    HAL_Delay(150);
    _init(ILI9488_SWRESET);
    HAL_Delay(150);

    
    // positive gamma control
    _init(ILI9488_GMCTRP1,      "\x00\x03\x09\x08\x16\x0A\x3F\x78\x4C\x09\x0A\x08\x16\x1A\x0F", 15);
    // negative gamma control
    _init(ILI9488_GMCTRN1,      "\x00\x16\x19\x03\x0F\x05\x32\x45\x46\x04\x0E\x0D\x35\x37\x0F", 15);
    // Power Control 1 (Vreg1out, Verg2out)
    _init(ILI9488_PWCTR1,       "\x17\x15", 2);
    // Power Control 2 (VGH,VGL)
    _init(ILI9488_PWCTR2,       "\x41", 1);
    // Power Control 3 (Vcom)
    _init(ILI9488_VMCTR1,       "\x00\x12\x80", 3);
    // Interface Pixel Format (18 bit)
    // этот дисплей в spi-режиме не поддерживает 16-битную передачу
    _init(ILI9488_PIXFMT,       "\x66", 1);
    // Memory Access
    _init(ILI9488_MADCTL,       ILI9488_MAD_RGB | ILI9488_MAD_X_LEFT | ILI9488_MAD_Y_DOWN | ILI9488_MAD_VERTICAL);
    // Interface Mode Control (SDO NOT USE)
    _init(ILI9488_IMCTR,        "\x80", 1);
    // Frame rate (60Hz)
    _init(ILI9488_FRMCTR1,      "\xA0", 1);
    // Display Inversion Control (2-dot)
    _init(ILI9488_INVCTR,       "\x02", 1);
    // Display Function Control RGB/MCU Interface Control (MCU + Source,Gate scan direction)
    _init(ILI9488_DFUNCTR,      "\x02\x02", 2);
    // Set Image Functio (Disable 24 bit data)
    _init(ILI9488_IMGFUNCT,     "\x00", 1);
    // Adjust Control (D7 stream, loose)
    _init(ILI9488_ADJCTR3,      "\xA9\x51\x2C\x82", 4);
    // Exit Sleep
    _init(ILI9488_SLPOUT);
    HAL_Delay(150);
    // Display on
    _init(ILI9488_DISPON);
    HAL_Delay(50);
}

// ---------------------------------------------------------

void DsplBufILI9488DMA::write() {
    if (data() == NULL)
        return;
    
    while (SPI1->SR & SPI_SR_BSY_Msk);
    //_SPI16::end();

    auto a = area();
    auto x2 = a.x + a.w - 1;
    uint8_t x[4] = {
        static_cast<uint8_t>(a.x>>8),   static_cast<uint8_t>(a.x&0xff),
        static_cast<uint8_t>(x2>>8),    static_cast<uint8_t>(x2&0xff)
    };
    _cmd8(ILI9488_CASET, x, 4);
    auto y2 = a.y + a.h - 1;
    uint8_t y[4] = {
        static_cast<uint8_t>(a.y>>8),   static_cast<uint8_t>(a.y&0xff),
        static_cast<uint8_t>(y2>>8),    static_cast<uint8_t>(y2&0xff)
    };
    _cmd8(ILI9488_PASET, y, 4);

    _cmd8(ILI9488_RAMWR);
    //_SPI16::beg(); // почему-то в 16-битном режиме коцаются цвета
    // возможно, надо свапать байты в парах, а это гемор,
    // выигрыша от 16 бит в DMA режиме всё равно не наблюдается,
    // не будем использовать
    HAL_SPI_Transmit_DMA(&hspi1, data(), sz());///2);
    while (SPI1->SR & SPI_SR_BSY_Msk);
}

void DsplBufILI9488DMA::begin() {
    DsplBuf24::begin();
    _CS::beg();
}

bool DsplBufILI9488DMA::next() {
    // отправляем текущий буфер на дисплей
    write();

    if (DsplBuf24::next())
        return true;
    
    //while (SPI1->SR & SPI_SR_BSY_Msk) ;
    //_SPI16::end();
    _CS::end();
    return false;
}
