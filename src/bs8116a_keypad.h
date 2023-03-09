#pragma once

#include <stdint.h>

class Bs8116aKeyPad {
 public:
  enum Key {
    kKey1,
    kKey2,
    kKey3,
    kKeyA,
    kKey4,
    kKey5,
    kKey6,
    kKeyB,
    kKey7,
    kKey8,
    kKey9,
    kKeyC,
    kKeyAsterisk,
    kKey0,
    kKeyPound,
    kKeyD,
    kKeyNone,
  };

  enum { kDeviceI2cAddressDefault = 0x50 };

  Bs8116aKeyPad(const uint8_t device_i2c_address = kDeviceI2cAddressDefault);
  virtual ~Bs8116aKeyPad() = default;
  bool Init();
  Key TouchedKey();

 private:
  uint8_t device_i2c_address_;
};
