/*
 * lantern.h
 *
 *  Created on: 2013.07.18
 *      Author: gravi_
 */

#ifndef LANTERN_H_
#define LANTERN_H_

#include "pwm.h"
#ifndef F_CPU
#define F_CPU 1000000
#endif
#include <util/delay.h>

#define ON				1
#define OFF				0
#define THRESHOLD		1000
#define HIT_THRESHOLD	40

struct lantern {
	void (*lanternPowerStatus[2])(void);
	uint8_t (*getStatus)(void);
	void (*setPower[2])(void);
	
	uint8_t power;
};

extern struct lantern lantern_t;

/*!
*	Description:
*		Turns on power for lantern light-bulb.
*
*	Arguments:
*		None.
*	
*	Return:
*		None.
*/

void lanternPowerOn(void);

/*!
 *	Description:
 *		Turns off power for lantern light-bulb.
 *
 *	Arguments:
 *		None.
 *
 *	Return:
 *		None.
 */

void lanternPowerOff(void);

/*!
 *	Description:
 *		Reads a variable "power" of type unsigned int 8bit 
 *		from lantern structure and returns it.
 *
 *	Arguments:
 *		None.
 *
 *	Return:
 *		Power indicator status.
 */

uint8_t getPowerStatus(void);

/*
 *	Description:	
 *		Sets power status as 'power source established'
 *		in lantern structure variable "power".
 *	
 *	Arguments:
 *		None.
 *
 *	Return:
 *		None.
 */

void setPowerOn(void);

/*
 *	Description:	
 *		Sets power status as 'power source disabled'
 *		in lantern structure variable "power".
 *	
 *	Arguments:
 *		None.
 *
 *	Return:
 *		None.
 */

void setPowerOff(void);

#endif /* LANTERN_H_ */
