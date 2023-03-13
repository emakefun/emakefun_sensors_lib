#include "i2c_expansion_board.h"

I2cExpansionBoard i2c_expansion_board;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  i2c_expansion_board.SetGpioMode(I2cExpansionBoard::kGpioPinE7,
                                  I2cExpansionBoard::kGpioModeOutput);
  i2c_expansion_board.SetGpioLevel(I2cExpansionBoard::kGpioPinE7, 1);

  i2c_expansion_board.SetGpioMode(I2cExpansionBoard::kGpioPinE0,
                                  I2cExpansionBoard::kGpioModeInputPullDown);
  Serial.println(
      i2c_expansion_board.GetGpioLevel(I2cExpansionBoard::kGpioPinE0));
  delay(100);
}
