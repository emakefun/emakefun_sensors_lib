#include "bs8116a_keypad.h"

#include <Wire.h>
#include <arduino.h>

#include "utils/log/Log.h"

#define SETTING_REGISTER_START_BYTE (0xB0)
#define TOUCH_KEY_STATUS_DATA_REGISTER (0x08)
#define KEY_TRIGGER_THRESHOLD_VALUE (0x3F)
#define KEY_STATUS_STRUCTURE_SIZE (2)

#define WIRE_TIMEOUT_US (3000)

#define LOG(...) (void(0))  // for debug

Bs8116aKeyPad::Bs8116aKeyPad(const uint8_t device_i2c_address)
    : device_i2c_address_(device_i2c_address) {}

bool Bs8116aKeyPad::Init() {
  const uint8_t setting_bytes[] = {
      0x00,  // Option1
      0x00,  // Reserve
      0x83,  // Reserve
      0xF3,  // Reserve
      0x98,  // Option2

      KEY_TRIGGER_THRESHOLD_VALUE,  // Key1 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key2 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key3 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key4 Trigger threshold value

      KEY_TRIGGER_THRESHOLD_VALUE,  // Key5 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key6 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key7 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key8 Trigger threshold value

      KEY_TRIGGER_THRESHOLD_VALUE,  // Key9 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key10 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key11 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key12 Trigger threshold value

      KEY_TRIGGER_THRESHOLD_VALUE,  // Key13 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key14 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key15 Trigger threshold value
      KEY_TRIGGER_THRESHOLD_VALUE,  // Key16 Trigger threshold value
  };

  Wire.beginTransmission(device_i2c_address_);
  Wire.write(SETTING_REGISTER_START_BYTE);
  uint8_t checksum = 0;
  for (auto i = 0; i < sizeof(setting_bytes); i++) {
    checksum += setting_bytes[i];
    if (1 != Wire.write(setting_bytes[i])) {
      LOG("Wire.write failed");
      return false;
    }
    delay(20);
  }

  if (1 != Wire.write(checksum)) {
    LOG("Wire.write failed");
    return false;
  }

  if (0 != Wire.endTransmission()) {
    LOG("Wire.endTransmission failed");
    return false;
  }

  return true;
}

Bs8116aKeyPad::Key Bs8116aKeyPad::TouchedKey() {
  Wire.setWireTimeout(WIRE_TIMEOUT_US, true);
  Wire.clearWireTimeoutFlag();
  Wire.beginTransmission(device_i2c_address_);
  if (1 != Wire.write(TOUCH_KEY_STATUS_DATA_REGISTER)) {
    LOG("Wire.write failed.");
    return Bs8116aKeyPad::kKeyNone;
  }

  if (0 != Wire.endTransmission()) {
    LOG("Wire.endTransmission failed");
    return Bs8116aKeyPad::kKeyNone;
  }

  if (0 == Wire.requestFrom(device_i2c_address_,
                            (uint8_t)KEY_STATUS_STRUCTURE_SIZE,
                            (uint8_t) false)) {
    return Bs8116aKeyPad::kKeyNone;
  }

  uint8_t key_status = 0;
  uint8_t key = 0;

  while (Wire.available()) {
    key_status = Wire.read();
    if (key_status != 0) {

      while ((key_status & 0x1) == 0) {
        key_status >>= 1;
        key++;
      }
      return static_cast<Bs8116aKeyPad::Key>(key);
    }

    key += 8;
  }

  return Bs8116aKeyPad::kKeyNone;
}