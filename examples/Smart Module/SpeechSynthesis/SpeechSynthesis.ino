#include "EM_TTS.h"

TTS tts;

void setup() {
  Serial.begin(9600);
}

void loop() {
  uint8_t ret;
//  tts.Start("[v10]小爱同学", strlen("[v10]小爱同学"));    // 直接发送数据并播放  
  tts.TextCacheCmd("[v10]小爱同学", strlen("[v10]小爱同学"));  //  文本缓存后播放
  tts.Cplay(1);  // 播放缓存内容次数0~15
  ret = tts.RetStatus();    //  返回状态查询 
  Serial.println(ret, HEX);
  delay(2000);
}
