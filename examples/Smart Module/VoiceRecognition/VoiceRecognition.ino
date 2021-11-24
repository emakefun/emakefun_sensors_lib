#include "asr_ld3320.h"

void setup()
{
  E_WORK_MODE asr_mode = LOOP_MODE;      // LOOP_MODE：循环识别模式  KEYWORDS_MODE：口令模式，以第一个词条为口令  BUTTON_MODE：按键模式，按下开始识别
  Wire.begin();
  Serial.begin(9600);
  ld3320_reset();
  ld3320_config_mode(asr_mode);  // 循环模式
//  ld3320_config_keywords("xiao du xiao du");
//  ld3320_config_time(10);    // wake up time 10s
  ld3320_add_words(1, "ni hao");  // 你好
  ld3320_add_words(2,"kai deng");          // 开灯
  ld3320_add_words(3, "xiao yi tong xue");              
  ld3320_add_words(4, "guan deng");        // 关灯
  ld3320_add_words(5, "yi chuang kong jian");    // 易创空间
  ld3320_add_words(6, "xiao yi xiao yi");  // 小易小易
  ld3320_asr_start();
  Serial.println("ld3320 start ");
}

void loop()
{
  unsigned char result;
  result = ld3320_get_result();
  if (result != 0xFF) {
    Serial.print("asr result is:");
    Serial.println(result);   //返回识别结果，即识别到的词条编号
    delay(20);
  }

}