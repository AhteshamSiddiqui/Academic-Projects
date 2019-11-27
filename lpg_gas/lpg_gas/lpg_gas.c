#define F_CPU 16000000 //crystal definitation
#include<util/delay.h>
#include <avr/io.h> 
#include "usart.h"
#include "lcd.h"
#include "adc.h"
#include <compat/deprecated.h> //bit level operation 
#include <avr/interrupt.h> //interrupt activation 
void ctrlz(void);

int main(void)
{	
	init_adc();// initialization of adc
	int x;
	init_usart(103); // serial communication initialization 
	sei();
	lcd_init();//  initialization of lcd
	while(1) //continous operation
	{
			{
				lcd_init();
				x=read_adc(2); //read the adc value
				lcd_goto(0,1); // set cursor position
				lcd_printi(x); //print acd value
				lcd_goto(0,2); // set cursor position
				lcd_prints(" LPG Reading"); //comment print
			}
     if(x>500) 
	 {
		transmit_string("AT+CMGF=1\r\n");
		_delay_ms(1000);
		transmit_string("AT+CMGS=");
		_delay_ms(1000);
		transmit_char('"');
		_delay_ms(1000);
		transmit_string("8149438930");
		_delay_ms(1000);
		transmit_char('"');
		_delay_ms(1000);
		transmit_string("\r\n");
		_delay_ms(1000);
        transmit_string("LPG Gas Leakage");
		_delay_ms(1000);
		ctrlz();
		_delay_ms(1000);
		ctrlz();
	 }		
		
	}
}
void ctrlz()
{
	loop_until_bit_is_set(UCSRA,UDRE);
	UDR=26;
}

