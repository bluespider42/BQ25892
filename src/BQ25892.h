
#ifndef __BQ25892_h__
#define __BQ25892_h__

#include "mbed.h"

class BQ25892
{
public:
    BQ25892(PinName sda_pin, PinName scl_pin);
    bool ChgEnable();

private:
    I2C bq_;
    const uint8_t addr 0x6B << 1;
    uint8_t bqReadByte(uint8_t regAddr);
};

#endif
