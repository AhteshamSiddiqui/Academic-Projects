/*
 * GccApplication1.c
 *
 * Created: 1/31/2015 8:00:48 PM
 *  Author: admin
 */ 




#define  F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include <compat/deprecated.h>

#define s0 bit_is_set(PINA,0)
#define s1 bit_is_set(PINA,1)
#define s2 bit_is_set(PINA,2)
#define s3 bit_is_set(PINA,3)
#define c0 bit_is_clear(PINA,0)
#define c1 bit_is_clear(PINA,1)
#define c2 bit_is_clear(PINA,2)
#define c3 bit_is_clear(PINA,3) 
int main(void)
{
	DDRA=0x00; // PORT A INPUT
	DDRD=0xff; // PORT D OUTPUT


	
	while(1)
	{
		if (c3 && c2 && c1 && s0) //2
		{
			PORTD=0b00000001;
		}
		else if	(c3 && c2 && s1 && c0) // 8
		{
			PORTD=0b00000010;
		}
				else if	(c3 && s2 && c1 && c0) // 4
				{
					PORTD=0b00000100;
				}
				
				else if	(s3 && c2 && c1 && c0) // 6
			{
				PORTD=0b00001000;
			}
								
					else if	(c3 && s2 && c1 && s0) // 5
					{
					PORTD=0x00;
					}

	}
}	
	
