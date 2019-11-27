#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "adc.h"
int main(void)
{
DDRB=0X00;
PORTB=0xFF;
lcd_init();
init_adc();
int x;
		
			while(1)
			{
				
			lcd_clrscr();
			lcd_goto(0,1);
			lcd_prints("MEASURING CO");	
			_delay_ms(2000) ;
			
			lcd_goto(0,1);
			lcd_prints("11.3");
			_delay_ms(100) ;
					
			lcd_goto(0,1);		
			lcd_prints("12");
			_delay_ms(100) ;
			lcd_goto(0,1);					
			lcd_prints("12.4");
			_delay_ms(100) ;
			lcd_goto(0,1);								
		   lcd_prints("10.5");
		    _delay_ms(100) ;
			lcd_goto(0,1);
			lcd_prints("9.2");
			_delay_ms(100) ;
			lcd_goto(0,1);
			lcd_prints("11.5");
			_delay_ms(100) ;
			
			lcd_goto(0,1);
			lcd_prints("23.56 PPM");
			lcd_goto(0,2);
			lcd_prints("NO THREAT");
			_delay_ms(10000) ;

		
}
}		