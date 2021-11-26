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
    u8g2.ShowFont(10,0,"hello World!!!");    // first row
    u8g2.ShowFont(10,16,"我爱创客");         // sencond
    u8g2.ShowFont(10,32,"EMAKEFUN");         // third
    u8g2.ShowFont(10,48,"I love STEAM");     // fourth
  }while(u8g2.nextPage());

}