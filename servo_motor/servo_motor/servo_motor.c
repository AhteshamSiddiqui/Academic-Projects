#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRD=0xff;
	DDRA=0x00;
	while(1)
	{
				while(bit_is_set(PINA,0))
				{
					PORTD=0b00000000;
					_delay_ms(18);
					PORTD=0b11111111;
					_delay_ms(2);
					
				}
					while(bit_is_set(PINA,1))
					{
						PORTD=0b00000000;
						_delay_ms(19);
						PORTD=0b11111111;
						_delay_ms(1);
						
					}
	}
}
