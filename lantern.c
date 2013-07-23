#include "lantern.h"

struct lantern lantern_t = { {lanternPowerOff, lanternPowerOn},
		  	     getPowerStatus,
			     {setPowerOff, setPowerOn},
			     0};

void lanternPowerOn(void) {
	uint8_t step;
//	TCCR0B |= 1<<CS00;
	while( !lantern_t.getStatus() ) {
		for(step = 0; step != MAX_PWM; step++){
//			OCR0B = step;
			_delay_ms(4);
		}
		lantern_t.setPower[1]();
	}
	
}

void lanternPowerOff(void) {
	uint8_t step;

	while( lantern_t.getStatus() ) {
		for(step = MAX_PWM; step != 0; step--){
//			OCR0B = step;
			_delay_ms(4);
		}		
		lantern_t.setPower[0]();
//		OCR0B = 0x00;
//		TCCR0B &= ~1<<CS00;
	}
}

uint8_t getPowerStatus(void) { return lantern_t.power; }

void setPowerOn(void) { lantern_t.power = ON; }

void setPowerOff(void) { lantern_t.power = OFF; }
