#include <RgbUltrasonic.h>

RgbUltrasonic myRGBUltrasonic(6, 5);

void setup(){
  Serial.begin(9600);
}

void loop(){
  myRGBUltrasonic.SetRgbEffect(E_RGB_ALL, RGB_RED, E_EFFECT_NONE);
  Serial.println(myRGBUltrasonic.GetUltrasonicDistance());
  delay(1000);
}