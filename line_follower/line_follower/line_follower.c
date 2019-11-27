

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <compat/deprecated.h>
#include "lcd.h"

int main(void)
{

	DDRD=0x00;
	DDRC=0XFF;
	PORTD=0xff;
	lcd_init();
	lcd_prints("ENTRIX 8.0");
    while(1)
    {
      
		    if (bit_is_set(PIND,1))
        {
			PORTC=0b00000101;
        } 
        else
        {
			if (bit_is_set(PIND,0))
			{
				PORTC=0b00001001;
			} 
			else
			{
				if (bit_is_set(PIND,2))
				{
					PORTC=0b00000110;
				}
				else
				{
					PORTC=0b00001010;
					_delay_ms(300);
					PORTC=0b00001001;
					_delay_ms(400);
				}
			}
        }			
    }
}

