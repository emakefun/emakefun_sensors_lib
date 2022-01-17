#include <EM_InfraredTracking.h>

InfraredTracking _5line_track(INFRARED_I2C_ADDR);

void setup() {
    Serial.begin(9600);
/*******************************************
*** Sensitivity 设置五路循迹模块的检测灵敏度(高于此值模块上对应的灯亮)
*** 阈值范围（0~1000）
*******************************************/
    _5line_track.Sensitivity(500);
}

void loop() {
/*******************************************
*** 读取全部数据前需要调用 GetRawDat() 刷新数据
*** ir_track X：分别对应 1-5 路红外循迹管脚的模拟值(0~1023)
*** Threshold： 为红外管脚的临界值，高于此值红外对应的灯亮
*** state： 五路循迹模块状态的数字值（0bit ~ 4bit 对应 1 ~ 5 个红外循迹）
*******************************************/
  _5line_track.GetRawDat();
  Serial.print("line_1: ");
  Serial.print(_5line_track.ir_track1);
  Serial.print(" ");
  Serial.print("line_2: ");
  Serial.print(_5line_track.ir_track2);
  Serial.print(" ");
  Serial.print("line_3: ");
  Serial.print(_5line_track.ir_track3);
  Serial.print(" ");
  Serial.print("line_4: ");
  Serial.print(_5line_track.ir_track4);
  Serial.print(" ");
  Serial.print("line_5: ");
  Serial.println(_5line_track.ir_track5);
//  Serial.print(_5line_track.state);
//  Serial.println();
//  Serial.println();


/*******************************************
*** GetState 获取循迹模块状态的数字值(高于设置的阈值对应位置读取的值为1)
***     bit0  bit1  bit2  bit3  bit4
***     inf1  inf2  inf3  inf4  inf5
***    参数默认是INFRARED_ALL 读取5路循迹状态 
*******************************************/ 
  uint8_t state = _5line_track.GetState();
  Serial.println(state); 
}
