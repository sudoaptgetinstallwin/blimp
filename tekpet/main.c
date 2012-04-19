/**
 This is the code for the tekpet, which uses an AT90USB646
 Currently we are testing to make sure servo control works
 */

/** Includes */
#include <avr/io.h>
#include <util/delay.h>

/** Constants */
#define F_CPU 1000000U

/** Global Variables */

/** Functions */

void initialize (void) {
	/*
	 * We are using port B here for PWM outputs on Timer/Counter1.
	 * Bits 5:7 are PWM outputs A:C, so those are the ones we enable
	 * as outputs.
	 */
	DDRB = 0b11100000;

	/*
	 * Set PWM A:C to clear at OCR match and set at TOP
	 * Set mode to high-resolution fast-PWM
	 */
	TCCR1A = 0b10101010;

	/*
	 * Set PWM top to be ICR1
	 * Set clock to be system clock, prescaled to 1/256
	 */
	TCCR1B = 0b00011100;

	/* Set TOP (high byte, then low byte) */
	ICR1 = 0xFF;
	ICR1 = 0xFF;

}


void update_pwm( char a, char b, char c ) {
	/* Set high and low bytes for PWM A */
	OCR1A = 16 | ( a >> 4 );
	OCR1A = a << 4;

	/* Implement the others after we check that this works */

}
	

int main( void ) {
	initialize();
	

	char i = 0;
	while( 1 ) {
		update_pwm( i, 0, 255);
		i += 1;
		_delay_ms( 16 );
	}
	return 0;
}