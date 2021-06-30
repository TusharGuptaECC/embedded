// 4-bit counter

#include<avr/io.h>
#include<util/delay.h>

#define MS_DELAY 2000

int main()
{
    DDRB |= _BV(DDB4);
    DDRB |= _BV(DDB2);
    DDRB |= _BV(DDB5);
    DDRB |= _BV(DDB3);

    
    while (1)
    {
        PORTB &= ~_BV(PORTB2);
        PORTB &= ~_BV(PORTB3);
        PORTB &= ~_BV(PORTB4);
        PORTB &= ~_BV(PORTB5);
        _delay_ms(MS_DELAY);        //0000

        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB3);
        PORTB &= ~_BV(PORTB4);
        PORTB &= ~_BV(PORTB5);
        _delay_ms(MS_DELAY);        //0001

        PORTB &= ~_BV(PORTB2);
        PORTB |= _BV(PORTB3);
        PORTB &= ~_BV(PORTB4);
        PORTB &= ~_BV(PORTB5);
        _delay_ms(MS_DELAY);        //0010

        PORTB |= _BV(PORTB2);
        PORTB |= _BV(PORTB3);
        PORTB &= ~_BV(PORTB4);
        PORTB &= ~_BV(PORTB5);
        _delay_ms(MS_DELAY);        //0011

        PORTB &= ~_BV(PORTB2);
        PORTB &= ~_BV(PORTB3);
        PORTB |= _BV(PORTB4);
        PORTB &= ~_BV(PORTB5);
        _delay_ms(MS_DELAY);        //0100

        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB3);
        PORTB |= _BV(PORTB4);
        PORTB &= ~_BV(PORTB5);
        _delay_ms(MS_DELAY);        //0101

        PORTB &= ~_BV(PORTB2);
        PORTB |= _BV(PORTB3);
        PORTB |= _BV(PORTB4);
        PORTB &= ~_BV(PORTB5);
        _delay_ms(MS_DELAY);        //0110

        PORTB |= _BV(PORTB2);
        PORTB |= _BV(PORTB3);
        PORTB |= _BV(PORTB4);
        PORTB &= ~_BV(PORTB5);
        _delay_ms(MS_DELAY);        //0111

        PORTB &= ~_BV(PORTB2);
        PORTB &= ~_BV(PORTB3);
        PORTB &= ~_BV(PORTB4);
        PORTB |= _BV(PORTB5);
        _delay_ms(MS_DELAY);        //1000

        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB3);
        PORTB &= ~_BV(PORTB4);
        PORTB |= _BV(PORTB5);
        _delay_ms(MS_DELAY);        //1001

        PORTB &= ~_BV(PORTB2);
        PORTB |= _BV(PORTB3);
        PORTB &= ~_BV(PORTB4);
        PORTB |= _BV(PORTB5);
        _delay_ms(MS_DELAY);        //1010

        PORTB |= _BV(PORTB2);
        PORTB |= _BV(PORTB3);
        PORTB &= ~_BV(PORTB4);
        PORTB |= _BV(PORTB5);
        _delay_ms(MS_DELAY);        //1011

        PORTB &= ~_BV(PORTB2);
        PORTB &= ~_BV(PORTB3);
        PORTB |= _BV(PORTB4);
        PORTB |= _BV(PORTB5);
        _delay_ms(MS_DELAY);        //1100

        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB3);
        PORTB |= _BV(PORTB4);
        PORTB |= _BV(PORTB5);
        _delay_ms(MS_DELAY);        //1101
        
        PORTB &= ~_BV(PORTB2);
        PORTB |= _BV(PORTB3);
        PORTB |= _BV(PORTB4);
        PORTB |= _BV(PORTB5);
        _delay_ms(MS_DELAY);        //1110
        
        PORTB |= _BV(PORTB2);
        PORTB |= _BV(PORTB3);
        PORTB |= _BV(PORTB4);
        PORTB |= _BV(PORTB5);  
        _delay_ms(MS_DELAY);        //1111
    }
    return 0;
}