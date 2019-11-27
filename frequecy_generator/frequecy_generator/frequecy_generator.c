#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h> //COM13
int main(void)
{
	DDRB=0b11111111;
	while(1)
	{
		PORTB=0X00;
		_delay_us(100);
		PORTB=0B00000111;
		_delay_us(100);
	}
}
