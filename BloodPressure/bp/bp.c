#define F_CPU 16000000
#include <avr/io.h>
#include "usart.h"
#include "lcd.h"
#include <compat/deprecated.h>
#include <avr/interrupt.h>
char x[13];
int a=0,i=0;
SIGNAL(USART_RXC_vect)
{
	x[i]=UDR;
	if (i==13)
	{
		i=0;
	}
	else
	{
		i++;
	}
}
int main(void)
{

	init_usart(103);
	sei();
	lcd_init();
	
	while(1)
	{

		lcd_goto(1,1);
		for (a=1;a<=13;a++)
		{
			lcd_printc(x[a]);
		}
			lcd_goto(0,2);
			lcd_prints(" SYS  DIA  PULSE");
	}
}
void ctrlz()
{
	
	loop_until_bit_is_set(UCSRA,UDRE);
	UDR=26;
}