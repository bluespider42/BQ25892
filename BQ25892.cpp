
// Includes
#include "BQ25892.h"
//#include "mbed.h"

BQ25892::BQ25892(PinName sda, PinName scl) : i2c_(sda, scl)
{
    // Setup
    //i2c_.frequency(100000);
    pn[0]='B';
    pn[1]='Q';
    pn[2]='2';
    pn[3]='5';
    pn[4]='8';
    pn[5]='9';
    pn[6]='X';
    // Get dev info
    rev = (ReadByte(DEV_REV_REG) & DEV_REV_BIT); // Revision Number
    pnc = (ReadByte(PN_REG) & PN_BIT);
    // Extract Part Number
     switch (pnc) {
        case 0x18:
            pn[6] = '0';
            break;
        case 0x00:
            pn[6] = '2';
            break;
        default:
            pn[6] = 'X';
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
    i2c_.write(ADDR, &tx, 1, 1);
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

int BQ25892::setBit(char regAddr, char bitmask)
{
    char reg = ReadByte(regAddr);
    reg |= bitmask;
    return WriteByte(regAddr, reg);
}

int BQ25892::clearBit(char regAddr, char bitmask)
{
    char reg = ReadByte(regAddr);
    reg &= ~(bitmask);
    return WriteByte(regAddr, reg);
}

char BQ25892::checkBit(char regAddr, char bitmask)
{
    char reg = ReadByte(regAddr);
    bool set = reg & bitmask;
    return set;
}

bool BQ25892::reset()
{
    char reg = ReadByte(REG_RST_REG);
    reg |= REG_RST_BIT;
    return WriteByte(REG_RST_REG, reg);
}

bool BQ25892::powerOff()
{
    setBit(BATFET_DLY_REG, BATFET_DLY_BIT);
    return (setBit(BATFET_DIS_REG, BATFET_DIS_BIT) == 0);
}

int BQ25892::ChgEnable()
{
    return setBit(CHG_CONFIG_REG, CHG_CONFIG_BIT);
}

int BQ25892::ChgDisable()
{
    return clearBit(CHG_CONFIG_REG, CHG_CONFIG_BIT);
}
