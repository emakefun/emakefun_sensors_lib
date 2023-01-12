#include "I2CExpansionBoard.h"

I2CExpansionBoard i2c_ex_board;

void setup()
{
  Serial.begin(9600);
  i2c_ex_board.ConfigFunMode(I2C_E0, EXTERN_FUN_INPUT_FLOATING_MODE);
  delay(10);
}

void loop()
{

    Serial.print("Get E0 Level: ");
    Serial.println(i2c_ex_board.GetExGpioLevel(I2C_E0));
}
