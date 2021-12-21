//注意本文文件保存格式必须是UTF8编码格式

#include "EM_OLED.h"

/**************************************
*** GetFontData 输入单个中文字符UTF8编码
*** 将得到的字符点阵放在 buff_fifo 中
***************************************/
uint8_t EM_OLED::GetFontData(uint8_t * data, uint8_t dat_len)
{
    uint8_t num = 0;
    Wire.beginTransmission(FONTADDR); 
    for (int i = 0; i < dat_len; i++) {
        Wire.write(data[i]);
        //Serial.print(data[i],HEX);   
    }   
    //Serial.println(); 
    byte error = Wire.endTransmission();
    if (error == 0) {
        Wire.requestFrom(FONTADDR, 32);
        while (Wire.available()) {
            if (num >= 32) {
                //Serial.println("error");
                return -1;
            }
            buff_fifo[num++] = Wire.read();
       }
    }
    return num;
}

/**************************************
*** GetUtf8ByteNum 
*** 获取一个中文 UTF8 编码长度
***************************************/
uint8_t EM_OLED::GetUtf8ByteNum(uint8_t data)
{
  if (data >= 0x20 && data <= 0x7E) { //单字符
    return 0xFF;
  } 
  if (data >= 0xFC && data < 0xFE) {
    return 6;
  } else if (data >= 0xF8) {
    return 5;
  } else if (data >= 0xF0) {
    return 4;
  } else if (data >= 0xE0) {
    return 3;
  } else if (data >= 0xC0) {
    return 2;
  } else if ((data & 0x80) == 0) {
    return 1;
  }
  return 0;  
}

/**************************************
*** ShowFont 
*** 显示汉字 坐标（x,y） str：显示汉字数据
***************************************/
uint8_t EM_OLED::ShowFont(uint8_t x, uint8_t y, uint8_t *str)
{
    uint8_t str_len = 0, len = 0, num = 0;
    uint8_t *ptr = str, font_size = 0;
    if (str == NULL) return 0;
    str_len = strlen(str);
    while (*ptr != '\0' && len <= str_len) {
        num = GetUtf8ByteNum(*ptr); //一个汉字的UTF8编码长度
        if (num == 0) return 0;
        if (num != 0xFF) {
            memset(buff_fifo, 0, sizeof(buff_fifo));
            GetFontData(ptr, num);
            font_size = 16;
        }
        if (num == 0xFF) { //字母或者数字
            memset(buff_fifo, 0, sizeof(buff_fifo));
            GetFontData(ptr, 1);
            num = 1;
            font_size = 8;
        }
        switch(font_size) {
            case 0x08: EM_OLED::drawXBM(x, y, 8, 16, buff_fifo);break;
            case 0x10: EM_OLED::drawXBM(x, y, 16, 16, buff_fifo);break;
            default: break;
        }
        if ((x + font_size) >  127) {
            x = 0;
            if ((y + 16) > 63) {
                return 0;
            } else {
                y += 16;
            }
        } else {
            x += font_size;
        }
        ptr += num;
        len++;
    }
}

/**************************************
*** ShowFont 
*** 显示汉字 坐标（x,y） str：显示汉字数据
**************************************
uint8_t EM_OLED::ShowFont(uint8_t x, uint8_t y, String s)
{
//  uint8_t array[0x100];
//  strcpy(array, );
  ShowFont(x, y, s.c_str());
}*/

