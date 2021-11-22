#include "TouchMatriKeyPad.h"

int SCLPin = A5, SDOPin = A4;   //Define SCL clock and SDO data port

TouchMatriKeyPad mKeyPad(SCLPin, SDOPin);
char str[128];
void setup()
{
  Serial.begin(9600);   //Set the serial port baud rate to 9600
  Serial.println("Touch MatriKeyPad Test");
}

void loop()
{
  uint16_t keycode = mKeyPad.GetKeyCode();
  if (keycode != 0xFFFF) {      //Determine whether the button is pressed
    String key_name = mKeyPad.GetKeyMap();
    sprintf(str, "Get keycode: 0x%x\r\nkey name: %s \r\n", keycode, (char *)key_name.c_str()); 
    //Convert the value of the key to a string
    Serial.println(str);    //Print the characters corresponding to the keys
  }
  if (mKeyPad.KeyPressed(KEYPAD_KEYCODE_5)) {
    Serial.println("KEYPAD_KEYCODE_5 pressed");
  }
  delay(100);
}
