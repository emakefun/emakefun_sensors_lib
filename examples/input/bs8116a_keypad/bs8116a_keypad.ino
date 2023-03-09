#include "bs8116a_keypad.h"

Bs8116aKeyPad key_pad;

void setup() {
  Serial.begin(115200);
  key_pad.Init();
}

void loop() {
  auto key = key_pad.TouchedKey();
  if (key != Bs8116aKeyPad::kKeyNone) {
    Serial.println(key);
  }
  delay(100);
}