#include "BQ25892.h"
#include "mbed.h"

BQ25892::BQ25892(sda_pin, scl_pin)
{
        I2C bq(sda_pin, scl_pin);
}

bool BQ25892::ChgEnable()
{
    uint8_t reg = bqReadByte(0x03);
    bool CHG_CONFIG = ((reg >> 4)  & 0x01); //check bit 4 CHG_CONFIG


    return CHG_CONFIG;
}

uint8_t BQ25892::bqReadByte(uint8_t regAddr)
{
    bq.write(addr, regAddr, 1);
    return bq.read(addr, regAddr, 1);
}
