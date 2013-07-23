#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "lantern.h"
#include "pwm.h"
#include "adc.h"

#define TRUE		1
#define FALSE		0
#define ERR			1
#define WIN			0

struct checkTab {
	void (*chechHandMov)(struct lantern* lantern_t);
	uint16_t hitCount;
};

extern struct checkTab checkTab_t;

/*
 *	Description:	
 *		Measures ADC for checking a hand position over the IR sensor.
 *		Calculates hit count of successful hand position detection over time.
 *		Keeps the same power status even if hand is over sensor for long time.
 *	
 *	Arguments:
 *		Object "lantern_t" of structure lantern.
 *
 *	Return:
 *		None.
 */

void checkHandMovement(struct lantern* lantern_t);

#endif
