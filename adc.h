#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 1000000UL
#endif
#include <util/delay.h>

#define ADMUX_MASK	0xF
#define ADMUX_CH_0	0x00
#define ADMUX_CH_1	0x01
#define ADMUX_CH_2	0x02
#define ADMUX_CH_3	0x03

#define ADC_CH		PB3

struct adcMeas {
	void (*initAdc)(void);
	void (*initPinout)(void);
	uint16_t (*getMeasDist)(void);
	void (*setMeasDist)(uint16_t*);
	void (*startCheck)(void);
	void (*stopCheck)(void);
	uint16_t pathMeasured;
};

extern struct adcMeas adcMeas_t;

/*
 *	Description:	
 *		Initialize ADC parameters.
 *	
 *	Arguments:
 *		None.
 *
 *	Return:
 *		None.
 */

void initADC(void);

/*
 *	Description:	
 *		Initialize Pins for ADC.
 *	
 *	Arguments:
 *		None.
 *
 *	Return:
 *		None.
 */

void initPins(void);

/*
 *	Description:	
 *		Enables A2D conversion .
 *	
 *	Arguments:
 *		None.
 *
 *	Return:
 *		None.
 */

void startChecking(void);

/*
 *	Description:	
 *		Disables A2D conversion
 *	
 *	Arguments:
 *		None.
 *
 *	Return:
 *		None.
 */

void stopChecking(void);

/*
 *	Description:	
 *		Returns measured distance between sensor and hand
 *		as ADC value.
 *	
 *	Arguments:
 *		None.
 *
 *	Return:
 *		Measured distance as ADC value.
 */

uint16_t getMeasDistance(void);
/*
 *	Description:	
 *		Sets measured ADC value to "pathMeasured" variable in 
 *		adcMeas structure.
 *	
 *	Arguments:
 *		Measured ADC value passed by reference.
 *
 *	Return:
 *		None.
 */
void setMeasDistance(uint16_t *value);


#endif
