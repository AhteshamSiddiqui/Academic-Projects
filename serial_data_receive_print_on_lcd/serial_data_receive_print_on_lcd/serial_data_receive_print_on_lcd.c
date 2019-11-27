#define F_CPU 16000000
#include <avr/io.h>
#include "usart.h"
#include "lcd.h"
#include <compat/deprecated.h>
#include <avr/interrupt.h>
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
	
	while(1)
	{
		lcd_goto(1,1);
		lcd_printc(x);
	}
}
void ctrlz()
{
	
	loop_until_bit_is_set(UCSRA,UDRE);
	UDR=26;
}