#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "adc.h"
int main(void)
{
	lcd_init();
	init_adc();
	int x;
	while(1)
	{
		
		x=read_adc(2);
		lcd_goto(0,1);
		lcd_printi(x);
		lcd_goto(3,1);
		lcd_prints("% REFLECTION");
		
	}
}