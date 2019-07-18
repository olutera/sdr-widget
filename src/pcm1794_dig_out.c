#include "pcm1794_dig_out.h"
#include "cycle_counter.h"

U8 sampleRate;

#define LED_STEP_DELAY	100
#define LED_FULL_DELAY	200

inline void pcm1794_init(void)
{
	gpio_set_gpio_pin(RELAY);
	
	gpio_set_gpio_pin(LED44);
  	gpio_clr_gpio_pin(LED48);
  	gpio_clr_gpio_pin(LED88);
  	gpio_clr_gpio_pin(LED96);
  	gpio_clr_gpio_pin(LED176);
  	gpio_clr_gpio_pin(LED192);

  	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
  	gpio_set_gpio_pin(LED48);
	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
	gpio_set_gpio_pin(LED88);
	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
	gpio_set_gpio_pin(LED96);
	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
	gpio_set_gpio_pin(LED176);
	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
	gpio_set_gpio_pin(LED192);
	cpu_delay_ms(LED_FULL_DELAY, FCPU_HZ);
	gpio_clr_gpio_pin(LED192);
	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
	gpio_clr_gpio_pin(LED176);
	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
	gpio_clr_gpio_pin(LED96);
	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
	gpio_clr_gpio_pin(LED88);
	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
	gpio_clr_gpio_pin(LED48);
	cpu_delay_ms(LED_STEP_DELAY, FCPU_HZ);
	gpio_clr_gpio_pin(LED44);
}

void pcm1794_sampleLed_set(U32 samplerate)
{
	
  static U32 rate = 0;

  if (rate != samplerate) {
	  gpio_clr_gpio_pin(LED44);
	  gpio_clr_gpio_pin(LED48);
	  gpio_clr_gpio_pin(LED88);
	  gpio_clr_gpio_pin(LED96);
	  gpio_clr_gpio_pin(LED176);
	  gpio_clr_gpio_pin(LED192);

		switch (samplerate)
		{
		case 44100:	
			gpio_set_gpio_pin(LED44);
			break;
		case 48000:
			gpio_set_gpio_pin(LED48);
			break;
		case 88200:
		  gpio_set_gpio_pin(LED88);
			break;
		case 96000:
		  gpio_set_gpio_pin(LED96); 
			break;
		case 176400:
			gpio_set_gpio_pin(LED176);
			break;
		case 192000:
			gpio_set_gpio_pin(LED192);
			break;
		}
		rate = samplerate;
	}
}

void pcm1794_sample_check(U32 sample){

}