#include  <MechaQMC5883.h>

MechaQMC5883 myCompass;
int x, y, z;
int azimuth, result;

void setup(){
  Wire.begin();
  myCompass.init();
  Serial.begin(9600);
}

void loop(){
  myCompass.read(&x, &y, &z, &azimuth);
  Serial.print("X direction: ");
  Serial.println(x);
  Serial.print("Y direction: ");
  Serial.println(y);
  Serial.print("Z direction: ");
  Serial.println(z);
  Serial.print("azimuth: ");
  Serial.println(azimuth);
  delay(1000);
}