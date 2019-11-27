
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <compat/deprecated.h>
#include "lcd.h"
float hr;
int j,h,speed;
void timer();
int x=0,s=0,h=0,m=0,check_a=1;
int main(void)
{
	lcd_init();
	DDRD=0x00;
	PORTD=0xFF;

		lcd_clrscr();	
	

    while(1)
    {
		{
			x++;
			if (x==1600)
			{
				timer();
			}
		}
 //////////////////////////////////////////////////////////////////     
	  {
		   if(bit_is_set(PIND,0) && check_a==1)
	   {
		 j=j+1;

		check_a=0;   
	   }
	   if(bit_is_clear(PIND,0) && check_a==0)
	   check_a=1;
	  }	 
		if(m==2)
			{
				speed=j;	
				lcd_clrscr();	
				lcd_goto(0,1);
				lcd_prints("Speed=");
				lcd_printi(speed);
				lcd_prints("km/hr");
				j=0;
				m=0;
				check_a=1;
			}
    }
}
void timer()
{
	x=0;
	s++;
	if (s>150)
	{
		s=0;
		m++;
	}

	if (m>2)
	{
		m=0;
	}

}