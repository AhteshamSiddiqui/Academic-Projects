#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h> //COM13
int main(void)
{
	DDRA=0b00000000;
	DDRC=0b11111111;
	PORTA=0XFF;
	PORTD=0X00;
	while(1)
	{
		if((bit_is_clear(PINA,0)) && (bit_is_clear(PIND,0)))
		{
			PORTC=0b00000011;
			_delay_ms(100) ;
			PORTC=0b00000110;
			_delay_ms(100) ;
			PORTC=0b00001100;
			_delay_ms(100) ;
			PORTC=0b00001001;
			_delay_ms(100) ;
			PORTC=0b00000011;
			_delay_ms(100) ;
			PORTC=0b00000110;
			_delay_ms(100) ;
			PORTC=0b00001100;
			_delay_ms(100) ;
			PORTC=0b00001001;
			_delay_ms(100) ;
			PORTD=0B00000001;
			_delay_ms(1000) ;
		
		}
		else if((bit_is_clear(PINA,1)) && (bit_is_set(PIND,0)) && (bit_is_clear(PIND,1)))
		{
			PORTC=0b00000011;
			_delay_ms(100) ;
			PORTC=0b00000110;
			_delay_ms(100) ;
			PORTC=0b00001100;
			_delay_ms(100) ;
			PORTC=0b00001001;
			_delay_ms(100) ;
			PORTC=0b00000011;
			_delay_ms(100) ;
			PORTC=0b00000110;
			_delay_ms(100) ;
			PORTC=0b00001100;
			_delay_ms(100) ;
			PORTC=0b00001001;
			_delay_ms(100) ;
		    PORTD=0B00000011;
			_delay_ms(1000) ;
		}
		
		
		else if((bit_is_clear(PINA,2)) && (bit_is_set(PIND,0)) && (bit_is_set(PIND,1)) && (bit_is_clear(PIND,2)))
		{
			PORTC=0b00001001;
			_delay_ms(100) ;
			PORTC=0b00001100;
			_delay_ms(100) ;
			PORTC=0b00000110;
			_delay_ms(100) ;
			PORTC=0b00000011;
			_delay_ms(100) ;
			PORTD=0b11111000;
			_delay_ms(1000) ;
			PORTC=0b00001001;
			_delay_ms(100) ;
			PORTC=0b00001100;
			_delay_ms(100) ;
			PORTC=0b00000110;
			_delay_ms(100) ;
			PORTC=0b00000011;
			_delay_ms(100) ;
			PORTD=0b11111000;
			_delay_ms(1000) ;
			PORTC=0b00001001;
			_delay_ms(100) ;
			PORTC=0b00001100;
			_delay_ms(100) ;
			PORTC=0b00000110;
			_delay_ms(100) ;
			PORTC=0b00000011;
			_delay_ms(100) ;
			PORTC=0b00001001;
			_delay_ms(100) ;
			PORTC=0b00001100;
			_delay_ms(100) ;
			PORTC=0b00000110;
			_delay_ms(100) ;
			PORTC=0b00000011;
			_delay_ms(100) ;
			PORTD=0b00000111;
			_delay_ms(1000) ;
		}
		
		else if((bit_is_set(PINA,0)) && (bit_is_set(PINA,1)) && (bit_is_set(PINA,2)))
		PORTC=0x00;
	}
	
}


