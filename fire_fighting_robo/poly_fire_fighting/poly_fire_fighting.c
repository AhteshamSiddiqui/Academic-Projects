
#define F_CPU 16000000
#include <avr/io.h>
#include <compat/deprecated.h>
int main(void)
{
	DDRC=0xff;
	DDRB=0x00;
	PORTB=0xff;
	while(1)
	{
		PORTB=0xff;
		if (bit_is_clear(PINB,0))
		PORTC=0b00001001;
		else if (bit_is_clear(PINB,1))
		PORTC=0b00001010;
		else if (bit_is_clear(PINB,2))
		PORTC=0b00000101;
	    else if (bit_is_clear(PINB,3))
		PORTC=0b00000110;
		else if (bit_is_clear(PINB,4))
		PORTC=0b00010000;
		else
		PORTC=0b00000000;	
	}
}