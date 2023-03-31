#include "i2c_expansion_board.h"

#include <Wire.h>
#include <arduino.h>

#define EXTERN_FUN_ADC_MODE (0x00)
#define EXTERN_FUN_INPUT_UP_MODE (0x48)
#define EXTERN_FUN_INPUT_DOWN_MODE (0x28)
#define EXTERN_FUN_INPUT_FLOATING_MODE (0x04)
#define EXTERN_FUN_OUT_MODE (0x10)

#define REGISTER_CONFIG_GPIO_MODE (0x40)
#define REGISTER_READ_GPIO_RAW_DATA (0x10)
#define REGISTER_READ_WRITE_GPIO_LEVEL (0x50)

I2cExpansionBoard::I2cExpansionBoard(uint8_t device_i2c_address)
    : device_i2c_address_(device_i2c_address) {
  Wire.begin();
  Wire.setWireTimeout(3000, true);
}

bool I2cExpansionBoard::SetGpioMode(I2cExpansionBoard::GpioPin gpio_pin,
                                    I2cExpansionBoard::GpioMode mode) {
  uint8_t buffer[2] = {0};
  buffer[0] = REGISTER_CONFIG_GPIO_MODE + gpio_pin;
  switch (mode) {
    case kGpioModeAdc:
      buffer[1] = EXTERN_FUN_ADC_MODE;
      break;
    case kGpioModeInputPullUp:
      buffer[1] = EXTERN_FUN_INPUT_UP_MODE;
      break;
    case kGpioModeInputPullDown:
      buffer[1] = EXTERN_FUN_INPUT_DOWN_MODE;
      break;
    case kGpioModeOutput:
      buffer[1] = EXTERN_FUN_OUT_MODE;
      break;
    default:
      return false;
  }

  Wire.beginTransmission(device_i2c_address_);
  Wire.write(buffer, sizeof(buffer));
  auto ret = Wire.endTransmission();
  if (ret != 0) {
    Serial.print("Error occured when i2c writing: ");
    Serial.println(ret);
    return false;
  }

  return true;
}

bool I2cExpansionBoard::SetGpioLevel(I2cExpansionBoard::GpioPin gpio_pin,
                                     uint8_t level) {
  uint8_t buffer[] = {gpio_pin + REGISTER_READ_WRITE_GPIO_LEVEL, level};

  Wire.beginTransmission(device_i2c_address_);
  Wire.write(buffer, sizeof(buffer));
  if (0 != Wire.endTransmission()) {
    return false;
  }
  return true;
}

uint8_t I2cExpansionBoard::GetGpioLevel(I2cExpansionBoard::GpioPin gpio_pin) {
  Wire.beginTransmission(device_i2c_address_);
  Wire.write(gpio_pin + REGISTER_READ_WRITE_GPIO_LEVEL);
  if (0 != Wire.endTransmission()) {
    return 0;
  }

  Wire.requestFrom(device_i2c_address_, (uint8_t)1);
  if (Wire.available()) {
    return Wire.read();
  }

  return 0;
}

uint16_t I2cExpansionBoard::GetGpioAdcValue(
    I2cExpansionBoard::GpioPin gpio_pin) {
  Wire.beginTransmission(device_i2c_address_);
  Wire.write(gpio_pin + REGISTER_READ_GPIO_RAW_DATA);
  if (0 != Wire.endTransmission()) {
    return 0;
  }

  uint8_t value[2] = {0};
  uint8_t index = 0;
  Wire.requestFrom(device_i2c_address_, (uint8_t)2);
  while (Wire.available() && index < sizeof(value)) {
    value[index++] = Wire.read();
  }

  return (((uint16_t)value[1]) << 8) | value[0];
}
