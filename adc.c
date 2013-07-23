#include "adc.h"

struct adcMeas adcMeas_t = {initADC,
							initPins,
							getMeasDistance,
							setMeasDistance,
							startChecking,
							stopChecking,
							0};

void initPins(void) {
	DDRB |= 1<<PB1;
}

void initADC(void) {

	// Voltage reference selection
	// internal 2,56V with external cap at AREF
	ADMUX = (ADMUX & ~ADMUX_MASK) | ADMUX_CH_3;

	// ADC enabled
	ADCSRA |= 1<<ADEN;

	// Interrupt enabled
	ADCSRA |= 1<<ADIE;

	// ADC pre-scaler Fclk/8
	ADCSRA |= 1<<ADPS1 | 1<<ADPS0;

	// Disable digital input buffer
	DIDR0 |= 1<<ADC3D;
	
	adcMeas_t.initPinout();
}



void startChecking(void) {
	
	uint16_t timeout = 0;
	uint16_t adcValue;
	
	// enable adc
	ADCSRA |= 1<<ADEN;
	
	// some delay for C_s/h discharge
	_delay_ms(1);
	
	// start conversion
	ADCSRA |= 1<<ADSC;
	
	while (ADCSRA & 1<<ADSC) {
		timeout++;
		if (timeout > 2000)
			return;
	}
	adcValue = ADC;
	adcMeas_t.setMeasDist(&adcValue);
}

void stopChecking(void) {
	// disable adc
	ADCSRA &= ~1<<ADEN;
}

uint16_t getMeasDistance(void) { return adcMeas_t.pathMeasured; }

void setMeasDistance(uint16_t *value) {
	adcMeas_t.pathMeasured = *value;
}
