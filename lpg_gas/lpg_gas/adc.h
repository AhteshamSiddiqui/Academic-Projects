#include <avr/io.h>    							// The necessary header file required for avr atmega 16/32
#include <util/delay.h>							// Header file required for Delay
#include<compat/deprecated.h>					// Used for the commands like sbi,cbi,bit_is_clear etc..
#include<stdlib.h>

#if defined (__AVR_ATmega8__) || (__AVR_ATmega16__) || (__AVR_ATmega32__) || (__AVR_ATmega16A__)

#ifndef __ADC_H__
#define __ADC_H__

void init_adc(void);
int read_adc(char adc);

void init_adc(void)
{
	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2)|(1<<ADEN);
}

int read_adc(char adc)
{
	ADMUX&=(0b11100000);
	ADMUX|=(adc);
	//`ADMUX=0b01
	
	ADCSRA|=(1<<ADEN)|(1<<ADSC);
	while((ADCSRA&(1<<ADIF))==0);
	return ADC;
}

#endif
#else
#error Invalid MCU
#endif
