#include "I2CExpansionBoard.h"

byte level, i;
I2CExpansionBoard i2c_ex_board;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    i2c_ex_board.ConfigFunMode(E0_CONFIG_REG, EXTERN_FUN_OUT_MODE);
    delay(1000);
}

void loop()
{
  if (i%2 == 0) {
      digitalWrite(LED_BUILTIN, HIGH);         
      level = 1;
  } else {
      digitalWrite(LED_BUILTIN, LOW);
      level = 0;
  }
  i2c_ex_board.SetExGpioLevel(I2C_E0, level);
  i++;
  delay(1000);
  Serial.println("i2c gpio test:");
}
