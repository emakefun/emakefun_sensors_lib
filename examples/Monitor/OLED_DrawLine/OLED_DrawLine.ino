#include "EM_OLED.h"
EM_OLED u8g2(U8G2_R0, U8X8_PIN_NONE);

void setup(){
  u8g2.begin();
  u8g2.enableUTF8Print();
}

void loop(){
  u8g2.firstPage();
  do
  {
    u8g2.drawLine(1,1,60,50);       // 画线  开始坐标(1, 1) 终点坐标(60, 50)
  }while(u8g2.nextPage());
}