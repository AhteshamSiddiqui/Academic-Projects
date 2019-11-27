
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <compat/deprecated.h>
#include "lcd.h"


#include "usart.h"
#include <avr/interrupt.h>
void line_follower();
char x;

SIGNAL(USART_RXC_vect)
{
	x=UDR;
}

int main(void)
{
	init_usart(103);
	sei();
	lcd_init();
	DDRD=0x00;
	PORTD=0xff;
		DDRB=0x00;
		PORTB=0xff;
	DDRC=0xff;
	
    while(1)
    {

	{
		lcd_goto(1,1);
		lcd_printc(x);
	}	
/////////////////////////////////////////////////////////////
        if(bit_is_set(PINB,0))
		{
			if(x=='4')   
			PORTC=0b00000000;
			else
		    line_follower();
		}
/////////////////////////////////////////////////////////////	
/////////////////////////////////////////////////////////////
if(bit_is_set(PINB,1))
{
	if(x=='5')
	PORTC=0b00000000;
	else
	line_follower();
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
if(bit_is_set(PINB,2))
{
	if(x=='8')
	PORTC=0b00000000;
	else
	line_follower();
}
/////////////////////////////////////////////////////////////

    }
}

void line_follower()
{
	 if (bit_is_set(PIND,6))
	 {
		 PORTC=0b00000101;
	 }
	 else
	 {
		 if (bit_is_set(PIND,7))
		 {
			 PORTC=0b00001001;
		 }
		 else
		 {
			 if (bit_is_set(PIND,5))
			 {
				 PORTC=0b00000110;
			 }
}	
}
}

void ctrlz()
{
	
	loop_until_bit_is_set(UCSRA,UDRE);
	UDR=26;
}
