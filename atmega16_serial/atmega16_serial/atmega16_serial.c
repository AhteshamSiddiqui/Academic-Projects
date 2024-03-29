#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h>
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1
void main( void )
{
	
	USART_Init ( MYUBRR );
	
}
void USART_Init( unsigned int ubrr)
{
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}