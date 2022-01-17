#include <SparkFun_APDS9960.h>

SparkFun_APDS9960 myHandleSensor = SparkFun_APDS9960();
int myHandleSensor_gestureStatus;

void setup(){
  myHandleSensor.init();
  myHandleSensor.enableGestureSensor(true);
  Serial.begin(9600);
}

void loop(){
	myHandleSensor_gestureStatus = myHandleSensor.readGesture();
    if (myHandleSensor.isGestureAvailable()) {
    if (myHandleSensor_gestureStatus == DIR_UP) {
      Serial.println("UP");
    } else if (myHandleSensor_gestureStatus == DIR_DOWN) {
      Serial.println("DOWN");
    } else if (myHandleSensor_gestureStatus == DIR_LEFT) {
      Serial.println("LEFT");
    } else if (myHandleSensor_gestureStatus == DIR_RIGHT) {
      Serial.println("RIGHT");
    } else if (myHandleSensor_gestureStatus == DIR_NEAR) {
      Serial.println("NEAR");
    } else if (myHandleSensor_gestureStatus == DIR_FAR) {
      Serial.println("FLY");
    }
  }
  delay(200);
}