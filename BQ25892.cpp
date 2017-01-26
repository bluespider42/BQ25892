
// Includes
#include "BQ25892.h"
//#include "mbed.h"

BQ25892::BQ25892(PinName sda, PinName scl) : i2c_(sda, scl)
{
    // Setup
    rev = ReadByte(DEV_REV_REG) & DEV_REV_BIT;
    char pnc = ReadByte(PN_REG) & PN_BIT;
    //pnc = pnc << 3;
    switch (pnc) {
        case 0x18:
            pn[8] = "BQ25890";
            break;
        case 0x00:
            pn[8] = "BQ25892";
            break;
        default:
            pn[8] = "NOT_DEF";
            break;
    }
}

BQ25892::~BQ25892()
{

}

char BQ25892::ReadByte(char regAddr)
{
    char tx = regAddr;
    char output;
    i2c_.write(ADDR, &tx, 1);
    i2c_.read(ADDR, &output, 1);
    return output;
}

int BQ25892::WriteByte(char regAddr, char data)
{
    int ack = 0;
    char tx[2];
    tx[0] = regAddr;
    tx[1] = data;
    return ack | i2c_.write(ADDR, tx, 2);
}

int BQ25892::setBit(char regAddr, int bit)
{
    char reg = ReadByte(regAddr);
    reg |= 1 << bit;
    return WriteByte(regAddr, reg);
}

int BQ25892::clearBit(char regAddr, int bit)
{
    char reg = ReadByte(regAddr);
    reg &= ~(1 << bit);
    return WriteByte(regAddr, reg);
}

bool BQ25892::checkBit(char regAddr, int bit)
{
    char reg = ReadByte(regAddr);
    bool set = (reg >> bit) & 1;
    return set;
}

int BQ25892::ChgEnable()
{
    char regAddr = 0x03;
    return setBit(regAddr, 4);
}

int BQ25892::ChgDisable()
{
    char regAddr = 0x03;
    return clearBit(regAddr, 4);
}