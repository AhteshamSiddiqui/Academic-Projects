#define F_CPU 16000000
#include <avr/io.h>
#include "usart.h"
#include "lcd.h"
#include <compat/deprecated.h>
#include <avr/interrupt.h>
char x[13];
int a=0,i=0;
void ctrlz(void);
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
	DDRB=0x0f;
	PORTB=0xf0;
	while(1)
	{
		_delay_ms(20000);
			{

				lcd_goto(1,1);
				for (a=1;a<=13;a++)
				{
					lcd_printc(x[a]);
				}
				lcd_goto(0,2);
				lcd_prints(" SYS  DIA  PULSE");
			}

		transmit_string("AT+CMGF=1\r\n");
		_delay_ms(1000);
		transmit_string("AT+CMGS=");
		_delay_ms(1000);
		transmit_char('"');
		_delay_ms(1000);
		transmit_string("9096360288");
		_delay_ms(1000);
		transmit_char('"');
		_delay_ms(1000);
		transmit_string("\r\n");
		_delay_ms(1000);
				for(a=0;a<=13;a++)
				{
					transmit_char(x[a]);
				}

		_delay_ms(1000);
		ctrlz();
		_delay_ms(1000);
		ctrlz();
	
}	
}
void ctrlz()
{
	loop_until_bit_is_set(UCSRA,UDRE);
	UDR=26;
}