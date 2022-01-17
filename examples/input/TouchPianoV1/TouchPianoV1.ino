#include <BS818A.h>
#include <Buzzer.h>

Buzzer buzzer_3(3);
BS818A BS_56;

void setup(){
  BS_56.InitBS818A(6, 5);
}

void loop(){
  if (BS_56.PressBsButton(BS_KEYCODE_1)) {
    buzzer_3.tone(3, 262, 200);
  } else if (BS_56.PressBsButton(BS_KEYCODE_2)) {
    buzzer_3.tone(3, 294, 200);
  } else if (BS_56.PressBsButton(BS_KEYCODE_3)) {
    buzzer_3.tone(3, 330, 200);
  } else if (BS_56.PressBsButton(BS_KEYCODE_4)) {
    buzzer_3.tone(3, 349, 200);
  } else if (BS_56.PressBsButton(BS_KEYCODE_5)) {
    buzzer_3.tone(3, 392, 200);
  } else if (BS_56.PressBsButton(BS_KEYCODE_6)) {
    buzzer_3.tone(3, 440, 200);
  } else if (BS_56.PressBsButton(BS_KEYCODE_7)) {
    buzzer_3.tone(3, 494, 200);
  } else if (BS_56.PressBsButton(BS_KEYCODE_8)) {
    buzzer_3.tone(3, 523, 200);
  }
}