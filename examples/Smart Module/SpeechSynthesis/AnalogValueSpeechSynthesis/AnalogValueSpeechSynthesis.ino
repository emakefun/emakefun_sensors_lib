volatile int item;

#include <EM_TTS.h>

TTS tts;
char str[200];

void setup(){
  item = 0;
}

void loop(){
  item = analogRead(A0);
  String res = String("[v10][s10]") + String(String("我爱创客") + String(item));
  char cArr[res.length() + 1];
  res.toCharArray(cArr,res.length() + 1);
  tts.Start(cArr, strlen(cArr));
  delay(3000);

}