#include <Arduino.h>
#include <Wire.h>

#define EXPANSION_BOARD_ADDR 0x24  //扩展板地址

#define EXPANSION_BOARD_RAW_BASE_REG 0x10  //  read ADC raw data
#define EXPANSION_BOARD_VOLTAGE_BASE_REG 0x20   // read voltage 
#define EXPANSION_BOARDR_PERCENTAGE_BASE_REG 0x30  // Read the ratio of input voltage to output voltage Input voltage / output voltage

#define EX_CONFIG_REG 0x40  
#define E0_CONFIG_REG 0x40
#define E1_CONFIG_REG 0x41
#define E2_CONFIG_REG 0x42
#define E3_CONFIG_REG 0x43
#define E4_CONFIG_REG 0x44
#define E5_CONFIG_REG 0x45
#define E6_CONFIG_REG 0x46
#define E7_CONFIG_REG 0x47

#define EX_IO_REG 0x50
#define E0_IO_REG 0x50
#define E1_IO_REG 0x51
#define E2_IO_REG 0x52
#define E3_IO_REG 0x53
#define E4_IO_REG 0x54
#define E5_IO_REG 0x55
#define E6_IO_REG 0x56
#define E7_IO_REG 0x57

#define EXTERN_FUN_ADC_MODE 0x00    // Default ADC
#define EXTERN_FUN_INPUT_UP_MODE 0x48 // Input Up
#define EXTERN_FUN_INPUT_DOWN_MODE 0x28
#define EXTERN_FUN_INPUT_FLOATING_MODE 0x04
#define EXTERN_FUN_OUT_MODE 0x10    // Output

#define I2C_E0 0
#define I2C_E1 1
#define I2C_E2 2
#define I2C_E3 3
#define I2C_E4 4
#define I2C_E5 5
#define I2C_E6 6
#define I2C_E7 7

class I2CExpansionBoard
{
  private:
    uint8_t ReadByte(uint8_t reg);
    boolean WireWriteByte(uint8_t val);
    boolean WireWriteDataArray(uint8_t reg, uint8_t *val, unsigned int len);
    int WireReadDataArray(uint8_t reg, uint8_t *val, unsigned int len);
  public:
    uint8_t BOARD_ADDR;
    
    I2CExpansionBoard(void);
    I2CExpansionBoard(uint8_t addr);

	void ConfigFunMode(uint8_t ex_gpio_pin, uint8_t mode);
	uint8_t SetExGpioLevel(uint8_t ex_gpio_pin, uint8_t level);
	uint8_t GetExGpioLevel(uint8_t ex_gpio_pin);
  uint16_t GetExAdcValue(uint8_t ex_gpio_pin);
    ~I2CExpansionBoard();
};
