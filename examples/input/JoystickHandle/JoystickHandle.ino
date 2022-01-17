#include <JoystickHandle.h>

JoystickHandle myJoystickHandle(JOYSTICK_I2C_ADDR);

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.print("value_X:");
  Serial.print(myJoystickHandle.AnalogRead_X());
  Serial.print(" value_Y:");
  Serial.println(myJoystickHandle.AnalogRead_Y());
  if (myJoystickHandle.Get_Button_Status(BUTOON_UP)==PRESS_DOWN) {
    Serial.println("A BUTTON IS PRESS DOWN");
  } else if (myJoystickHandle.Get_Button_Status(BUTOON_UP)==PRESS_UP) {
    Serial.println("A BUTTON IS PRESS UP");
  } else if (myJoystickHandle.Get_Button_Status(BUTOON_UP)==SINGLE_CLICK) {
    Serial.println("A BUTTON IS SINGLE CLICK");
  } else if (myJoystickHandle.Get_Button_Status(BUTOON_UP)==DOUBLE_CLICK) {
    Serial.println("A BUTTON IS DOUBLE CLICK");
  } else if (myJoystickHandle.Get_Button_Status(BUTOON_UP)==LONG_PRESS_HOLD) {
    Serial.println("A BUTTON IS LONG PRESS HOLD");
  } else if (myJoystickHandle.Get_Button_Status(BUTOON_UP)==NONE_PRESS) {
    Serial.println("A BUTTON IS NONE PRESS");
  }
  delay(100);

}