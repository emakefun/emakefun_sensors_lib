#include "asr_ld3320.h"
LD3320 ld3320;
void setup()
{
  E_WORK_MODE asr_mode = LOOP_MODE;      // 0：循环识别模式  1：口令模式，以第一个词条为口令  2、按键模式，按下开始识别
  Wire.begin();
  Serial.begin(9600);
  ld3320.ld3320_reset();
  ld3320.ld3320_config_mode(asr_mode);  // 循环模式
  ld3320.ld3320_add_words(1, "xiao yi xiao yi");  // 小易小易
  Serial.println("xiao yi xiao yi");
  ld3320.ld3320_add_words(5, "shen zhen shi");    // 深圳市
  Serial.println("shen zhen shi");
  ld3320.ld3320_add_words(2,"kai deng");          // 开灯
  Serial.println("kai deng");
  ld3320.ld3320_add_words(3, "xiao yi tong xue");              
  Serial.println("xiao yi tong xue");
  ld3320.ld3320_add_words(4, "guan deng");        // 关灯
  Serial.println("guan deng");
  ld3320.ld3320_add_words(8, "chang jiang chang jiang");         // 长江长江
  Serial.println("chang jiang chang jiang");
  ld3320.ld3320_add_words(9, "huang he huang he");         // 黄河黄河
  Serial.println("huang he huang he");
  ld3320.ld3320_asr_start();
  Serial.println("ld3320 start ");

  
}

void loop()
{
  unsigned char result;
  result = ld3320.ld3320_get_result();
  if (result != 0xFF) {
    Serial.print("asr result is:");
    Serial.println(result);   //返回识别结果，即识别到的词条编号
    delay(20);
  }

}
