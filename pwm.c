#include "pwm.h"

struct pwmTab pwmTab_t = {initPWM};

void initPWM(void) {

	// PWM 8-bit, Fast PWM
	TCCR0A |= 1<<WGM00;
	TCCR0A |= 1<<WGM01;

	// compare output mode
	TCCR0A |= 1<<COM0B1;

	// Clock select with no pre-scaler
	TCCR0B |= 1<<CS00;
	
	// Interrupt mask
	TIMSK |= 1<<OCIE0B;
}
