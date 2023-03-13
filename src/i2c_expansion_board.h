#pragma once

#include <stdint.h>

class I2cExpansionBoard {
 public:
  enum GpioMode {
    kGpioModeAdc = 0,
    kGpioModeInputPullUp,
    kGpioModeInputPullDown,
    kGpioModeOutput,
  };

  enum GpioPin {
    kGpioPinE0 = 0,
    kGpioPinE1 = 1,
    kGpioPinE2 = 2,
    kGpioPinE3 = 3,
    kGpioPinE4 = 4,
    kGpioPinE5 = 5,
    kGpioPinE6 = 6,
    kGpioPinE7 = 7,
  };

  enum { kDeviceI2cAddressDefault = 0x24 };

  I2cExpansionBoard(uint8_t device_i2c_address = kDeviceI2cAddressDefault);
  bool SetGpioMode(GpioPin gpio_pin, GpioMode mode);
  bool SetGpioLevel(GpioPin gpio_pin, uint8_t level);
  uint8_t GetGpioLevel(GpioPin gpio_pin);
  uint16_t GetGpioAdcValue(GpioPin gpio_pin);

 private:
  uint8_t device_i2c_address_;
};