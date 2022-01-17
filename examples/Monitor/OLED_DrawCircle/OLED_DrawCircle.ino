#include <EM_OLED.h>
EM_OLED u8g2(U8G2_R0, U8X8_PIN_NONE);           // 初始化

void setup(){
  u8g2.begin();
  u8g2.enableUTF8Print();
}

void loop(){
  u8g2.firstPage();
  do
  {
    u8g2.drawDisc(30,30,20,U8G2_DRAW_ALL);      // 圆心坐标(30, 30) 半径20 实心整圆  U8G2_DRAW_ALL: 整圆  U8G2_DRAW_UPPER_RIGHT: 1/4右上圆 U8G2_DRAW_UPPER_LEFT: 1/4左上圆
	                                            // U8G2_DRAW_LOWER_RIGHT: 1/4右下圆    U8G2_DRAW_LOWER_LEFT: 1/4左下圆
	// u8g2.drawCircle(30,30,20,U8G2_DRAW_ALL);      // 圆心坐标(30, 30) 半径20 空心整圆
  }while(u8g2.nextPage());

}