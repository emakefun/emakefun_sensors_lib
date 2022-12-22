# Emakefun传感器库
emakefun 传感器Arduino库



### I2C GPIO扩展板库文件介绍

```
void I2CExpansionBoard(void); // 构造函数，默认I2C地址为0x24
#define EXTERN_FUN_ADC_MODE 0x00   //ADC功能
#define EXTERN_FUN_INPUT_MODE 0x01 //输入功能
#define EXTERN_FUN_OUT_MODE 0x02   //输出功能

void ConfigFunMode(uint8_t ex_gpio_pin, uint8_t mode);
// 配置I2C扩展板IO的功能模式，0：ADC模式 1：输出模式 2：输出模式
uint8_t GetExGpioLevel(uint8_t ex_gpio_pin); //获取I2C扩展板对应IO口的高低电平值
uint8_t SetExGpioLevel(uint8_t ex_gpio_pin, uint8_t level);//设置I2C扩展板对应IO口的高低电平值
uint16_t GetExAdcValue(uint8_t ex_gpio_pin); //获取I2C扩展板对应IO口的ADC值 adc精度为10bit
```