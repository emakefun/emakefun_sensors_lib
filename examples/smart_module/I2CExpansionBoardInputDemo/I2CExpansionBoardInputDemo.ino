#include "I2CExpansionBoard.h"

I2CExpansionBoard i2c_ex_board;
unsigned long OledTimer = 0;
void setup()
{
  Serial.begin(9600);
  i2c_ex_board.ConfigFunMode(I2C_E7, EXTERN_FUN_ADC_MODE);  // config mode
  delay(10);
  OledTimer = millis();
}

void loop()
{
    if (millis() - OledTimer < 10000) {
      i2c_ex_board.ConfigFunMode(I2C_E7, EXTERN_FUN_ADC_MODE);
      Serial.print("Get E7 ADC Level: ");
      Serial.println(i2c_ex_board.GetExAdcValue(I2C_E7));       // get adc value 
    } else if (millis() - OledTimer > 10000 && millis() - OledTimer < 20000) {
      i2c_ex_board.ConfigFunMode(I2C_E7, EXTERN_FUN_INPUT_FLOATING_MODE);  // config input mode
      Serial.print("Get E7 Level: ");
      Serial.println(i2c_ex_board.GetExGpioLevel(I2C_E7));   // get digital value
    }else if(millis() - OledTimer > 20000 && millis() - OledTimer < 30000){
      i2c_ex_board.ConfigFunMode(I2C_E7, EXTERN_FUN_OUT_MODE); // config output mode
      i2c_ex_board.SetExGpioLevel(I2C_E7, 1);    // set port HIGH
      delay(20);
      i2c_ex_board.SetExGpioLevel(I2C_E7, 0);    // set port LOW
      delay(20);
    }else{
      OledTimer = millis();
    }
    
    
}
