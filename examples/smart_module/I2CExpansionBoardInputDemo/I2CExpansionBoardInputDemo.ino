#include "I2CExpansionBoard.h"

I2CExpansionBoard i2c_ex_board;
unsigned long OledTimer = 0;
void setup()
{
  Serial.begin(9600);
  i2c_ex_board.ConfigFunMode(I2C_E1, EXTERN_FUN_ADC_MODE);
  delay(10);
  OledTimer = millis();
}

void loop()
{
    if (millis() - OledTimer < 10000) {
      i2c_ex_board.ConfigFunMode(I2C_E1, EXTERN_FUN_ADC_MODE);
      Serial.print("Get E0 ADC Level: ");
      Serial.println(i2c_ex_board.GetExAdcValue(I2C_E1));    
    } else if (millis() - OledTimer > 10000 && millis() - OledTimer < 20000) {
      i2c_ex_board.ConfigFunMode(I2C_E1, EXTERN_FUN_INPUT_FLOATING_MODE);
      Serial.print("Get E0 Level: ");
      Serial.println(i2c_ex_board.GetExGpioLevel(I2C_E1));
    }else if(millis() - OledTimer > 20000 && millis() - OledTimer < 30000){
      i2c_ex_board.ConfigFunMode(I2C_E1, EXTERN_FUN_OUT_MODE);
      i2c_ex_board.SetExGpioLevel(I2C_E1, 1);
      delay(20);
      i2c_ex_board.SetExGpioLevel(I2C_E1, 0);
      delay(20);
    }else{
      OledTimer = millis();
    }
    
    
}
