#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h> //COM13
int main(void)
{
	DDRD=0b11111111;
	while(1)
	{
				PORTD=0X00;
				_delay_ms(500);
				PORTD=0XFF;
				_delay_ms(500);
				
	}
}
