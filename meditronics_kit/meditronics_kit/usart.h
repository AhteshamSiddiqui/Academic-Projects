

#include <avr/io.h>    							// The necessary header file required for avr atmega 16/32
#include <util/delay.h>							// Header file required for Delay
#include<compat/deprecated.h>					// Used for the commands like sbi,cbi,bit_is_clear etc..
#include<stdlib.h>

#ifndef __USART_H__
#define __USART_H__

#if defined (__AVR_ATmega16__) || (__AVR_ATmega32__) || (__AVR_ATmega16A__) || (__AVR_ATmega8__)

void init_usart(char);
void transmit_char(char);
void transmit_string(char *);

//USART
void init_usart(char baud)
{
	//Communication protocol set
	//with 1 stop bit & 8 data bits
	UCSRC=(1<<UCSZ1)|(1<<UCSZ0)|(1<<URSEL);
	
	//Reception & transmission is enabled
	//Reception of data will occur on interrupt
	UCSRB=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	
	//Baud rate = 9600
	UBRRH=0x00;
	UBRRL=baud;
}

void transmit_char(char data)
{
	loop_until_bit_is_set(UCSRA,UDRE);
	UDR=data;
}

void transmit_string(char *data)
{
	while(*data)
	{
		transmit_char(*data);
		data++;
	}
		
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}
#else
#error Invalid MCU
#endif
#endif
