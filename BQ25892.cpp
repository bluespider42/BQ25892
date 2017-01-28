
// Includes
#include "BQ25892.h"
//#include "mbed.h"

BQ25892::BQ25892(PinName sda, PinName scl) : i2c_(sda, scl)
{
    // Setup
    rev = ReadByte(DEV_REV_REG) & DEV_REV_BIT; // Revision Number
    char pnc = ReadByte(PN_REG) & PN_BIT;
    // Extract Part Number
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

bool BQ25892::reset()
{
    return (setBit(REG_RST_REG, REG_RST_BIT) == 0);
}

int BQ25892::ChgEnable()
{
    return setBit(CHG_CONFIG_REG, CHG_CONFIG_BIT);
}

int BQ25892::ChgDisable()
{
    return clearBit(CHG_CONFIG_REG, CHG_CONFIG_BIT);
}
