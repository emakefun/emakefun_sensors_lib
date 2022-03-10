#ifndef __BS8116A_H_
#define __BS8116A_H_

#include <Arduino.h>
#include <Wire.h>

/* BS8116A总线地址 */
#define BS8116A_ADDR  0x50
/* BS8116A 获取键值地址 */
#define GET_DATA_ADDR 0x08
/* BS8116A 参数配置地址 */
#define SET_ATTR_ADDR 0xB0
/* BS8116A 触摸引脚数量 */
#define KEYBOARD_SIZE 16
/* BS8116A 初始化数组的大小 */
#define INIT_BUF_SIZE 0x16

class BS8116A_KeyPad {
  private:
    boolean _WireWriteByte(uint8_t val);
    boolean _WireWriteDataArray(uint8_t reg, uint8_t *val, unsigned int len);
    int _WireReadDataArray(uint8_t reg, uint8_t *val, unsigned int len);
    uint16_t KeyCode;
  public:
    BS8116A_KeyPad();
    void init(void);
   // uint16_t GetKeyCode(void);
   // String GetKeyMap(void);
   uint16_t GetKey(void);
   // bool KeyPressed(E_EM_KEYCODE key);
};

#endif  /* __BS8116A_H_ */
