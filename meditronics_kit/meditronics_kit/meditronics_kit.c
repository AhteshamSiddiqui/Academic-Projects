#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <compat/deprecated.h>
#include "lcd.h"
#include "usart.h"
#include <avr/interrupt.h>
void timer();
void heart_rate();
void bp();
int x=0,s=0,m=0,h=10,j=0,bpm=0;
float hr;
int j;
char p[13];
int a=0,i=0;
void ctrlz(void);

int main(void)
{
	lcd_init();
	DDRB=0x00;
	while(1)
	{
		PORTB=0XFF;
		if (bit_is_clear(PINB,0))
		heart_rate();
		else if (bit_is_clear(PINB,1))
		bp();
		else
		{ 
		 lcd_goto(0,1);
		 lcd_prints("MEDITRONICS");
		 lcd_goto(0,2);
		 lcd_prints("HR(S1) BP(S2)");
		}
	}
}

void heart_rate()
{

	lcd_init();
	DDRD=0x00;
	PORTD=0xFF;
	int check=1;

    while(bit_is_clear(PINB,0))
    {
		   x++;
       	   if (x==1600)
       	   {
	       	   timer();
       	   }
	   if(bit_is_set(PIND,7) && check==1)
	   {
		 j=j+1;
		check=0;   
	   }
	   else if(bit_is_clear(PIND,7) && check==0)
	   {
		   check=1;   
	   }   
		   
	  
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

SIGNAL(USART_RXC_vect)
{
	p[i]=UDR;
	if (i==13)
	{
		i=0;
	}
	else
	{
		i++;
	}
}
void bp()
{

	init_usart(103);
	sei();
	lcd_init();
	while(bit_is_clear(PINB,1))
	{
		lcd_init();
		lcd_goto(1,1);
		lcd_prints("BP_Measuring...");
		_delay_ms(40000);	
		{
			lcd_goto(1,1);
			for (a=1;a<=13;a++)
			{
				lcd_printc(p[a]);
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
		transmit_string("BP Reading of a patient is");
		_delay_ms(1000);
		for(a=0;a<=13;a++)
		{
			transmit_char(p[a]);
		}
		_delay_ms(1000);
		transmit_string(" which is SYS DIA PULSE Respectively");
		_delay_ms(1000);
		ctrlz();
		_delay_ms(1000);
		ctrlz();
		_delay_ms(10000);
		
	}
}
void ctrlz()
{
	loop_until_bit_is_set(UCSRA,UDRE);
	UDR=26;
}