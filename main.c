/*
 *	Author:
 *		Graþvidas Balèius
 *	
 *	Email:
 *		grazvidas@elektromotus.lt
 *
 *	Date created:
 *		2013 July 18
 *
 *	Version:
 *		v1.0
 */

#include "main.h"

struct checkTab checkTab_t = {checkHandMovement,
							  0};

int main(void) {
	
	pwmTab_t.initPwm();
	adcMeas_t.initAdc();
	
	while (TRUE) {
		adcMeas_t.startCheck();
		checkTab_t.chechHandMov(&lantern_t);
	}

	return ERR;
}

void checkHandMovement(struct lantern* lantern_t) {

	uint8_t status;
	
	if (adcMeas_t.getMeasDist() < THRESHOLD) {
		checkTab_t.hitCount++;
		
	}
	else {
		checkTab_t.hitCount = 0;
	}
		if (checkTab_t.hitCount > HIT_THRESHOLD) {
			// get current power status
			status = lantern_t->getStatus();
			
			// toggle power status
			lantern_t->lanternPowerStatus[!status]();
			
			// loops while same state applied
			while (adcMeas_t.getMeasDist() < THRESHOLD) {
				adcMeas_t.startCheck();			
			 }
			checkTab_t.hitCount = 0;
		}
}
