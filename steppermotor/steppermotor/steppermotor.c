#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h> 
int main(void)
{
	DDRC=0b11111111;
	
	while(1)
	{
		
			PORTC=0b00001001;
			_delay_ms(10) ;
			PORTC=0b00001100;
			_delay_ms(10) ;
			PORTC=0b00000110;
			_delay_ms(10) ;
			PORTC=0b00000011;
			_delay_ms(10) ;
		

	}
}
