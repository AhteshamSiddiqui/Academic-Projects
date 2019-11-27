#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "adc.h"
int main(void)
{
	
	init_adc();
	DDRC=0xff;//port c as output for motors
	int x,y;
	while(1)
	{
		lcd_init();
		x=read_adc(2);
		lcd_goto(0,1);
		lcd_printi(x);
		lcd_prints(" ->X");
		y=read_adc(3);
		lcd_goto(0,2);
		lcd_printi(y);
		lcd_prints(" ->Y");
	
	if (y>370)
	{
	PORTC=0b00000101;//right
	_delay_ms(100);	
	PORTC=0b00000000;
	_delay_ms(10);
	}
	else if (y<300)
	{
	PORTC=0b00001010;//left
	_delay_ms(100);
	PORTC=0b00000000;
	_delay_ms(10);
	}
	else if (x<300)
	{
	PORTC=0b00001001;//rev
	_delay_ms(100);
	PORTC=0b00000000;
	_delay_ms(10);
	}
    else if (x>350)
	{
	PORTC=0b00000110;//fw
	_delay_ms(100);
	PORTC=0b00000000;
	_delay_ms(10);
	}
	else
	PORTC=0b00000000;
	
	}
}