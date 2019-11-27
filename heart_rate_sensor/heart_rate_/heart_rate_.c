 /*
 * LINEFOLLOWER.c
 *
 * Created: 2/11/2015 3:59:15 AM
 *  Author: PIYUSH
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <compat/deprecated.h>
#include "lcd.h"
void timer();
	int x=0,s=0,m=0,h=10,j=0,bpm=0;
	float hr;
	int j;

int main(void)
{

	lcd_init();
	DDRD=0x00;
	PORTD=0xFF;
	int check=1;

    while(1)
    {
		   x++;
       	   if (x==1600)
       	   {
	       	   timer();
       	   }
	   if(bit_is_set(PIND,0) && check==1)
	   {
		 j=j+1;
		check=0;   
	   }
	   else if(bit_is_clear(PIND,0) && check==0)
	   {
		   check=1;   
	   }   
		   
						
///////////////////////////////////////////////////////////////////////////////////////////////
	  
    }
}
void timer()
{
	x=0;
	s=s+1;
	if (s>60)
	{
		s=0;
		m++;	
		 	 
	}

	   if (m>6)
	   {
		   m=0;
		   h--;
		  		 lcd_goto(0,2);
				 lcd_prints("Please Wait...");
		  		 lcd_printi(h);
	   }
	   	   
	   if (h==0)
	   {
	  bpm=j*6;
	  lcd_clrscr();
      lcd_goto(0,1);
      lcd_printi(bpm);
	  lcd_goto(4,1);
	  lcd_prints("BPM");
	  h=10;
	  j=0;
	   }
	
}