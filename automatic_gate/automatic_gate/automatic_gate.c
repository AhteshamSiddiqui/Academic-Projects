#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h> //COM15
int main(void)
{
	DDRC=0b00000000;
	DDRB=0b11111111;
	PORTC=0XFF;
	while(1)
	{
		if(bit_is_clear(PINC,0)) 
		{
			PORTB=0b00000010;
			_delay_ms(20) ;
			PORTB=0b00000000;
			_delay_ms(4000) ;
		
			
		}
		else if(bit_is_clear(PINC,1)) 
		{
		PORTB=0b00000010;
		_delay_ms(20) ;
		PORTB=0b00000000;
		_delay_ms(4000) ;
		}
		
		
		else if(bit_is_clear(PINC,2))
		{
		PORTB=0b00000001;
		_delay_ms(40) ;
		PORTB=0b00000000;
		_delay_ms(4000) ;
		}
		
		else if((bit_is_set(PINC,0)) && (bit_is_set(PINC,1)) && (bit_is_set(PINC,2)))
		PORTB=0x00;
	}
	
}


