#include <Buzzer.h>
#include <EM_Piano.h>

Buzzer buzzer_3(3);
Piano mPiano_56;

void setup(){
  mPiano_56.initPiano(5, 6);
}

void loop(){
  if (mPiano_56.PressBsButton(EM_PIANO_KEYCODE_1)) {
    buzzer_3.tone(3, 262, 200);
  } else if (mPiano_56.PressBsButton(EM_PIANO_KEYCODE_2)) {
    buzzer_3.tone(3, 294, 200);
  } else if (mPiano_56.PressBsButton(EM_PIANO_KEYCODE_3)) {
    buzzer_3.tone(3, 330, 200);
  } else if (mPiano_56.PressBsButton(EM_PIANO_KEYCODE_4)) {
    buzzer_3.tone(3, 349, 200);
  } else if (mPiano_56.PressBsButton(EM_PIANO_KEYCODE_5)) {
    buzzer_3.tone(3, 392, 200);
  } else if (mPiano_56.PressBsButton(EM_PIANO_KEYCODE_6)) {
    buzzer_3.tone(3, 440, 200);
  } else if (mPiano_56.PressBsButton(EM_PIANO_KEYCODE_7)) {
    buzzer_3.tone(3, 494, 200);
  } else if (mPiano_56.PressBsButton(EM_PIANO_KEYCODE_8)) {
    buzzer_3.tone(3, 523, 200);
  }
}