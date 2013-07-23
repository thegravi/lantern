#ifndef PWM_H_
#define PWM_H_

#define MAX_PWM		0xFF

#include <avr/io.h>

struct pwmTab {
	void (*initPwm)(void);
};

/*
 *	Description:	
 *		Initialize Pulse width modulation parameters.
 *	
 *	Arguments:
 *		None.
 *
 *	Return:
 *		None.
 */

void initPWM(void);

extern struct pwmTab pwmTab_t;

#endif