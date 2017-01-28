
#ifndef __BQ25892_H__
#define __BQ25892_H__

// Includes
#include "mbed.h"

// Define Registers
#define EN_HIZ_REG 0x00
#define EN_HIZ_BIT 0x80 //7
#define EN_ILIM_REG 0x00
#define EN_ILIM_BIT 0x40 //6
#define IINLIM_REG 0x00
#define IINLIM_BIT 0x3F //0-5

#define BHOT_REG 0x01
#define BHOT_BIT 0xC0 //6-7
#define BCOLD_REG 0x01
#define BCOLD_BIT 0x20 //5
#define VINDPM_OS_REG 0x01
#define VINDPM_OS_BIT 0x1F //0-4

#define CONV_START_REG 0x02
#define CONV_START_BIT 0x80 //7
#define CONV_RATE_REG 0x02
#define CONV_RATE_BIT 0x40 //6
#define BOOST_FREQ_REG 0x02
#define BOOST_FREQ_BIT 0x20 //5
#define ICO_EN_REG 0x02
#define ICO_EN_BIT 0x10 //4
#define HVDCP_EN_REG 0x02
#define HVDCP_EN_BIT 0x08 //3
#define MAXC_EN_REG 0x02
#define MAXC_EN_BIT 0x04 //2
#define FORCE_DPDM_REG 0x02
#define FORCE_DPDM_BIT 0x02 //1
#define AUTO_DPDM_EN_REG 0x02
#define AUTO_DPDM_EN_BIT 0x01 //0

#define BAT_LOADEN_REG 0x03
#define BAT_LOADEN_BIT 0x80 //7
#define WD_RESET_REG 0x03
#define WD_RESET_BIT 0x40 //6
#define OTG_CONFIG_REG 0x03
#define OTG_CONFIG_BIT 0x20 //5
#define CHG_CONFIG_REG 0x03
#define CHG_CONFIG_BIT 0x10 //4
#define SYS_MIN_REG 0x03
#define SYS_MIN_BIT 0x0E //1-3
// Bit 0, Reg 0x03 Reserved = 0

#define EN_PUMPX_REG 0x04
#define EN_PUMPX_BIT 0x80 //7
#define ICHG_REG 0x04
#define ICHG_BIT 0x7F //0-6

#define IPRECHG_REG 0x05
#define IPRECHG_BIT 0xF0 //4-7
#define ITERM_REG 0x05
#define ITERM_BIT 0x0F //0-4

#define VREG_REG 0x06
#define VREG_BIT 0xFC //2-7
#define BATLOWV_REG 0x06
#define BATLOWV_BIT 0x02 //1
#define VRECHG_REG 0x06
#define VRECHG_BIT 0x01 //0

#define EN_TERM_REG 0x07
#define EN_TERM_BIT 0x80 //7
#define STAT_DIS_REG 0x07
#define STAT_DIS_BIT 0x40 //6
#define WATCHDOG_REG 0x07
#define WATCHDOG_BIT 0x30 //4-5
#define EN_TIMER_REG 0x07
#define EN_TIMER_BIT 0x08 //3
#define CHG_TIMER_REG 0x07
#define CHG_TIMER_BIT 0x06 //1-2
#define JEITA_ISET_REG 0x07
#define JEITA_ISET_BIT 0x01 //0

#define BAT_COMP_REG 0x08
#define BAT_COMP_BIT 0xE0 //5-7
#define VCLAMP_REG 0x08
#define VCLAMP_BIT 0x38 //2-4
#define TREG_REG 0x08
#define TREG_BIT 0x03 //0-1

#define FORCE_ICO_REG 0x09
#define FORCE_ICO_BIT 0x80 //7
#define TMR2X_EN_REG 0x09
#define TMR2X_EN_BIT 0x40 //6
#define BATFET_DIS_REG 0x09
#define BATFET_DIS_BIT 0x20 //5
#define JEITA_VSET_REG 0x09
#define JEITA_VSET_BIT 0x10 //4
#define BATFET_DLY_REG 0x09
#define BATFET_DLY_BIT 0x08 //3
#define BATFET_RST_EN_REG 0x09
#define BATFET_RST_EN_BIT 0x04 //2
#define PUMPX_UP_REG 0x09
#define PUMPX_UP_BIT 0x02 //1
#define PUMPX_DN_REG 0x09
#define PUMPX_DN_BIT 0x01 //0

#define BOOSTV_REG 0x0A
#define BOOSTV_BIT 0xF0 //4-7
// Reg 0x0A, Bit 3 Reserved
#define BOOST_LIM_REG 0x0A
#define BOOST_LIM_BIT 0x07 //0-2

#define VBUS_STAT_REG 0x0B
#define VBUS_STAT_BIT 0xE0 //5-7
#define CHRG_STAT_REG 0x0B
#define CHRG_STAT_BIT 0x0C //3-4
#define PG_STAT_REG 0x0B
#define PG_STAT_BIT 0x04 //2
// Reg 0x0B Bit 1 Reserved
#define VSYS_STAT_REG 0x0B
#define VSYS_STAT_BIT 0x01 //0

#define WATCHDOG_FAULT_REG 0x0C
#define WATCHDOG_FAULT_BIT 0x80
#define BOOST_FAULT_REG 0x0C
#define BOOST_FAULT_BIT 0x40
#define CHRG_FAULT_REG 0x0C
#define CHRG_FAULT_BIT 0x30 //4-5
#define BAT_FAULT_REG 0x0C
#define BAT_FAULT_BIT 0x08 //3
#define NTC_FAULT_REG 0x0C
#define NTC_FAULT_BIT 0x07 //0-2

#define FORCE_VINDPM_REG 0x0D
#define FORCE_VINDPM_BIT 0x80 //7
#define VINDPM_REG 0x0D
#define VINDPM_BIT 0x7F //0-6

#define THERM_STAT_REG 0x0E
#define THERM_STAT_BIT 0x80 //7
#define BATV_REG 0x0E
#define BATV_BIT 0x7F //0-6

// Reg 0x0F Bit 7, Reserved
#define SYSV_REG 0x0F
#define SYSV_BIT 0x7F //0-6

// Reg 0x10 Bit 7 Reserved
#define TSPCT_REG 0x10
#define TSPCCT_BIT 0x7F //0-6

#define VBUS_GD_REG 0x11
#define VBUS_GD_BIT 0x80 //7
#define VBUSV_REG 0x11
#define VBUSV_BIT 0x7F //0-6

// Reg 0x12 Bit7 Unused = 0
#define ICHGR_REG 0x12
#define ICHGR_BIT 0x7F //0-6

#define VDPM_STAT_REG 0x13
#define VDPM_STAT_BIT 0x80 //7
#define IDPM_STAT_REG 0x13
#define IDPM_STAT_BIT 0x40 //6
#define IDPM_LIM_REG 0x13
#define IDPM_LIM_BIT 0x3F //0-5

#define REG_RST_REG 0x14
#define REG_RST_BIT 0x80 //7
#define ICO_OPTIMIZED_REG 0x14
#define ICO_OPTIMIZED_BIT 0x40 //6
#define PN_REG 0x14
#define PN_BIT 0x38 //3-5
#define TS_PROFILE_REG 0x14
#define TS_PROFILE_BIT 0x04 //4
#define DEV_REV_REG 0x14
#define DEV_REV_BIT 0x03 //0-1

// Define other, modes etc.
#define ADDR 0x6B << 1

class BQ25892 {

public:
    // Constrcutor
    BQ25892(PinName sda, PinName scl); //TODO add other pins here eg. for INT, CE, STAT etc

    ~BQ25892();

    char rev;
    char pnc;
    char* pn[8];

    bool reset();

    int ChgEnable();
    int ChgDisable();

private:
    I2C i2c_;
    char ReadByte(char regAddr);
    int WriteByte(char regAddr, char data);
    int setBit(char regAddr, int bit);
    int clearBit(char regAddr, int bit);
    bool checkBit(char regAddr, int bit);
};

#endif /* __BQ25892_H__ */
