#include "I2CExpansionBoard.h"


I2CExpansionBoard::I2CExpansionBoard()
{
    Wire.begin();
    BOARD_ADDR = EXPANSION_BOARD_ADDR;
}

I2CExpansionBoard::I2CExpansionBoard(uint8_t addr)
{
    Wire.begin();
    BOARD_ADDR = addr;
}

boolean I2CExpansionBoard::WireWriteByte(uint8_t val)
{
    Wire.beginTransmission(BOARD_ADDR);
    Wire.write(val);
    if( Wire.endTransmission() != 0 ) {
        return false;
    }
    return true;
}

boolean I2CExpansionBoard::WireWriteDataArray(uint8_t reg, uint8_t *val, unsigned int len)
{
    unsigned int i;
    Wire.beginTransmission(BOARD_ADDR);
    Wire.write(reg);
    for(i = 0; i < len; i++) {
        Wire.write(val[i]);
    }
    if( Wire.endTransmission() != 0 ) {
        return false;
    }
    return true;
}

int I2CExpansionBoard::WireReadDataArray(uint8_t reg, uint8_t *val, unsigned int len)
{
    unsigned char i = 0;  
    /* Indicate which register we want to read from */
    if (!WireWriteByte(reg)) {
        return -1;
    }
    Wire.requestFrom(BOARD_ADDR, len);
    while (Wire.available()) {
        if (i >= len) {
            return -1;
        }
        val[i] = Wire.read();
        i++;
    }
    /* Read block data */    
    return i;
}

uint8_t I2CExpansionBoard::ReadByte(uint8_t reg)
{
    byte d[1];
    WireReadDataArray(reg, d, 1);
    return d[0];
}

void I2CExpansionBoard::ConfigFunMode(uint8_t ex_gpio_pin, uint8_t mode)
{
	  uint8_t value[1];
    value[0] = mode;	 
    WireWriteDataArray(ex_gpio_pin, value, 1);
}

uint8_t I2CExpansionBoard::SetExGpioLevel(uint8_t ex_gpio_pin, uint8_t level)
{
	uint8_t value[1];
    value[0] = level;	 
    WireWriteDataArray(ex_gpio_pin + EX_IO_REG, value, 1);
}

uint8_t I2CExpansionBoard::GetExGpioLevel(uint8_t ex_gpio_pin)
{
	uint8_t value[1];
	WireReadDataArray(ex_gpio_pin + EX_IO_REG, value, 1);
	return value[0];
}


I2CExpansionBoard::~I2CExpansionBoard()
{

}
