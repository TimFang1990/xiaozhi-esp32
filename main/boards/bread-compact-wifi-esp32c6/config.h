#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 16000

// 如果使用 Duplex I2S 模式，请注释下面一行
// ESP32C6 has only 1 I2S
// Duplex mode reference : https://ccnphfhqs21z.feishu.cn/wiki/EH6wwrgvNiU7aykr7HgclP09nCh
// #define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX
//Microphone
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_22 //Updated for ESP32C6-WROOM-1 (4->22)
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_3  //Updated for ESP32C6-WROOM-1 (5->3)
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_2  //Updated for ESP32C6-WROOM-1 (6->2), SD for microphone
//Speaker -- Bypassed in ESP32c6
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_7 //GPIO_NUM_7 //speaker amplifier DIN
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_0 //GPIO_NUM_15  
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_1 //GPIO_NUM_16 

#else

#define AUDIO_I2S_GPIO_WS   GPIO_NUM_4       // WS for MIC, LRC for SPK
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5       // SCK for MIC, BCLK for SPK
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_6       // SD for MIC
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_7       // DIN for SPK

#endif


#define BUILTIN_LED_GPIO        GPIO_NUM_8 //Updated for ESP32C6-WROOM-1 (48->8), Build-in LED
#define BOOT_BUTTON_GPIO        GPIO_NUM_9 //Updated for ESP32C6-WROOM-1 (0->9), Build-in Boot Button
#define TOUCH_BUTTON_GPIO       GPIO_NUM_21 //Updated for ESP32C6-WROOM-1 (47->21), NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_20 //Updated for ESP32C6-WROOM-1 (40->20)
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_19 //Updated for ESP32C6-WROOM-1 (39->19)

#define DISPLAY_SDA_PIN GPIO_NUM_10 //Updated for ESP32C6-WROOM-1 (41->10)
#define DISPLAY_SCL_PIN GPIO_NUM_11 //Updated for ESP32C6-WROOM-1 (42->11)
#define DISPLAY_WIDTH   128

#if CONFIG_OLED_SSD1306_128X32
#define DISPLAY_HEIGHT  32
#elif CONFIG_OLED_SSD1306_128X64
#define DISPLAY_HEIGHT  64
#else
#error "未选择 OLED 屏幕类型"
#endif

#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y true

#endif // _BOARD_CONFIG_H_
