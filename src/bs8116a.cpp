#include "bs8116a.h"

/* BS8116A引脚对应keycode */
static uint16_t key_array[KEYBOARD_SIZE] = {
    0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080,
    0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000
};

boolean BS8116A_KeyPad::_WireWriteByte(uint8_t val)
{
    Wire.beginTransmission(BS8116A_ADDR);
    Wire.write(val);
    if (Wire.endTransmission() != 0) {
        return false;
    }
    return true;
}

boolean BS8116A_KeyPad::_WireWriteDataArray(uint8_t reg, uint8_t *val, unsigned int len)
{
   unsigned int i;
    Wire.beginTransmission(BS8116A_ADDR);
    Wire.write(reg);
    for(i = 0; i < len; i++) {
        Wire.write(val[i]);
    }
    if( Wire.endTransmission() != 0 ) {
        return false;
    }
    return true;
}

int BS8116A_KeyPad::_WireReadDataArray(uint8_t reg, uint8_t *val, unsigned int len)
{
    unsigned char i = 0;  
    /* Indicate which register we want to read from */
    if (!_WireWriteByte(reg)) {
        return -1;
    }
    Wire.requestFrom(BS8116A_ADDR, len);
    while (Wire.available()) {
        if (i >= len) {
            return -1;
        }
        val[i] = Wire.read();
        i++;
    }
    /* Read block data */    
    return i;
}

BS8116A_KeyPad::BS8116A_KeyPad() {
    Wire.begin();
}


/* 对BS8116A芯片进行初始化配置，需要在上电后的8秒内调用 */
void BS8116A_KeyPad::init(void) {
    uint8_t touch_key_init_buff[22] = {
        0x00,                           /* 触发模式 */
        0x00, 0x83, 0xF3,               /* 固定协议 */
        0x98,                           /* 省电模式 */
        0x20, 0x20, 0x20, 0x20, 0x20,   /* 触摸阈值 */
        0x20, 0x20, 0x20, 0x20, 0x20,   /* 触摸阈值 */
        0x20, 0x20, 0x20, 0x20, 0x20,   /* 触摸阈值 */
        0x20,                           /* 按键模式 */
        0x2E                            /* SUM校验和 */
    };
    _WireWriteDataArray(SET_ATTR_ADDR, touch_key_init_buff, INIT_BUF_SIZE-1);
}

/* 使用i2c获取触摸按键的key */
uint16_t BS8116A_KeyPad::GetKey(void) {

    byte d[2];
    _WireReadDataArray(GET_DATA_ADDR, d, 2);
    return (d[1]<<8 | d[0]);
}
