// blinking of the led connected at pin 13 PORTB5

#include <avr/io.h>
#include <util/delay.h>

#define MS_DELAY 1000

int main (void) 
{
    
    DDRB |= _BV(DDB5);

    while(1) 
	{
        
        	PORTB |= _BV(PORTB5);

	        
        	_delay_ms(MS_DELAY);

	        
        	PORTB &= ~_BV(PORTB5);

	        
        	_delay_ms(MS_DELAY);
	}
	return(0);
	
}