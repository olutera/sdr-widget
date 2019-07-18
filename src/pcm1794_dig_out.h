#ifndef PCM1794_DIG_OUT_H_
#define PCM1794_DIG_OUT_H_

#define RELAY  AVR32_PIN_PA14
#define LED44  AVR32_PIN_PX29
#define LED48  AVR32_PIN_PX33
#define LED88  AVR32_PIN_PX30
#define LED96  AVR32_PIN_PX31
#define LED176 AVR32_PIN_PC00
#define LED192 AVR32_PIN_PC01  

#include "gpio.h"
#include "board.h"
#include "compiler.h"
#include "FreeRTOS.h"
#include "task.h"
#include "device_audio_task.h"

void pcm1794_init(void);
void pcm1794_sampleLed_set(U32 samplerate); 
void pcm1794_mute_set(U8 set);
void pcm1794_sample_check(U32 sample);

#endif