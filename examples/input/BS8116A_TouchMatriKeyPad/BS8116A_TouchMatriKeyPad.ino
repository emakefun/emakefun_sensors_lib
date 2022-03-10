#include "bs8116a.h"

BS8116A_KeyPad keypad;

char str[128];
void setup()
{
  keypad.init();
  Serial.begin(9600);   //Set the serial port baud rate to 9600
  Serial.println("Touch MatriKeyPad Test");
  
}

void loop()
{
  uint16_t keycode = keypad.GetKey();
  if (keycode != 0) {      //Determine whether the button is pressed
    sprintf(str, "Get keycode:0x%x", keycode);  
    //Convert the value of the key to a string
    Serial.println(str);    //Print the characters corresponding to the keys
  }

  delay(100);
}