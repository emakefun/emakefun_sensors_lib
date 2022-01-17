#include <asr_ld3320.h>

LD3320 myVoiceRecognition(VOICE_IIC_ADDR);   // 初始化

void setup(){
  myVoiceRecognition.ld3320_reset();    // 复位
  delay(200);
  myVoiceRecognition.ld3320_config_mode(LOOP_MODE);     // 0：循环识别模式  1：口令模式，以第一个词条为口令  2、按键模式，按下开始识别
  myVoiceRecognition.ld3320_add_words(1, "xiao yi xiao yi");    // 小易小易
  delay(200);
  myVoiceRecognition.ld3320_add_words(2, "chang jiang chang jiang");   // 长江长江
  delay(200);
  myVoiceRecognition.ld3320_add_words(3, "huang he huang he");     // 黄河黄河
  delay(200);
  myVoiceRecognition.ld3320_asr_start();    // 开始识别
  Serial.begin(9600);
}

void loop(){
  unsigned char item;
  item = myVoiceRecognition.ld3320_get_result();   // 获取识别结果
  if (item != 255) {
    Serial.println(item);      // 返回识别结果，即识别到的词条编号
    delay(20);
  }
}