#include<avr/io.h>
#include<util/delay.h>

#define MS_DELAY 3000

int main()
{
    DDRB |= _BV(DDB5);//out pin 13
    DDRB |= _BV(DDB4);//out pin 12
    DDRB |= _BV(DDB3);//out pin 11
    DDRB |= _BV(DDB2);//out pin 10
    DDRB |= _BV(DDB1);//out pin 09
    DDRB |= _BV(DDB0);//out pin 08
    DDRD |= _BV(DDD7);//out pin 07
    DDRD |= _BV(DDD6);//out pin 06

    while(1)
    {
        PORTB &= ~_BV(PORTB5);//pin 13 Low led a
        PORTB &= ~_BV(PORTB4);//pin 12 Low led b
        PORTB &= ~_BV(PORTB3);//pin 11 Low led c
        PORTB &= ~_BV(PORTB2);//pin 10 Low led d
        PORTB &= ~_BV(PORTB1);//pin 09 Low led e
        PORTB &= ~_BV(PORTB0);//pin 08 Low led f
        PORTD &= ~_BV(PORTD7);//pin 07 Low led g
        PORTD |= _BV(PORTD6);//pin 06 High led dp
        _delay_ms(MS_DELAY);

        // 0
        PORTB |= _BV(PORTB5);//pin 13 High led a
        PORTB |= _BV(PORTB4);//pin 12 High led b
        PORTB |= _BV(PORTB3);//pin 11 High led c
        PORTB |= _BV(PORTB2);//pin 10 High led d
        PORTB |= _BV(PORTB1);//pin 09 High led e
        PORTB |= _BV(PORTB0);//pin 08 High led f
        PORTD &= ~_BV(PORTD7);//pin 07 Low led g
        _delay_ms(MS_DELAY);

        // 1
        PORTB &= ~_BV(PORTB5);//pin 13 Low led a
        PORTB |= _BV(PORTB4);//pin 12 High led b
        PORTB |= _BV(PORTB3);//pin 11 High led c
        PORTB &= ~_BV(PORTB2);//pin 10 Low led d
        PORTB &= ~_BV(PORTB1);//pin 09 Low led e
        PORTB &= ~_BV(PORTB0);//pin 08 Low led f
        PORTD &= ~_BV(PORTD7);//pin 07 Low led g
        _delay_ms(MS_DELAY);

        // 2
        PORTB |= _BV(PORTB5);//pin 13 High led a
        PORTB |= _BV(PORTB4);//pin 12 High led b
        PORTB &= ~_BV(PORTB3);//pin 11 Low led c
        PORTB |= _BV(PORTB2);//pin 10 High led d
        PORTB |= _BV(PORTB1);//pin 09 High led e
        PORTB &= ~_BV(PORTB0);//pin 08 Low led f
        PORTD |= _BV(PORTD7);//pin 07 High led g
        _delay_ms(MS_DELAY);

        // 3
        PORTB |= _BV(PORTB5);//pin 13 High led a
        PORTB |= _BV(PORTB4);//pin 12 High led b
        PORTB |= _BV(PORTB3);//pin 11 High led c
        PORTB |= _BV(PORTB2);//pin 10 High led d
        PORTB &= ~_BV(PORTB1);//pin 09 Low led e
        PORTB &= ~_BV(PORTB0);//pin 08 Low led f
        PORTD |= _BV(PORTD7);//pin 07 High led g
        _delay_ms(MS_DELAY);

        // 4
        PORTB &= ~_BV(PORTB5);//pin 13 Low led a
        PORTB |= _BV(PORTB4);//pin 12 High led b
        PORTB |= _BV(PORTB3);//pin 11 High led c
        PORTB &= ~_BV(PORTB2);//pin 10 Low led d
        PORTB &= ~_BV(PORTB1);//pin 09 Low led e
        PORTB |= _BV(PORTB0);//pin 08 High led f
        PORTD |= _BV(PORTD7);//pin 07 High led g
        _delay_ms(MS_DELAY);

        // 5
        PORTB |= _BV(PORTB5);//pin 13 High led a
        PORTB &= ~_BV(PORTB4);//pin 12 Low led b
        PORTB |= _BV(PORTB3);//pin 11 High led c
        PORTB |= _BV(PORTB2);//pin 10 High led d
        PORTB &= ~_BV(PORTB1);//pin 09 Low led e
        PORTB |= _BV(PORTB0);//pin 08 High led f
        PORTD |= _BV(PORTD7);//pin 07 High led g
        _delay_ms(MS_DELAY);

        // 6
        PORTB |= _BV(PORTB5);//pin 13 High led a
        PORTB &= ~_BV(PORTB4);//pin 12 Low led b
        PORTB |= _BV(PORTB3);//pin 11 High led c
        PORTB |= _BV(PORTB2);//pin 10 High led d
        PORTB |= _BV(PORTB1);//pin 09 High led e
        PORTB |= _BV(PORTB0);//pin 08 High led f
        PORTD |= _BV(PORTD7);//pin 07 High led g
        _delay_ms(MS_DELAY);

        // 7
        PORTB |= _BV(PORTB5);//pin 13 High led a
        PORTB |= _BV(PORTB4);//pin 12 High led b
        PORTB |= _BV(PORTB3);//pin 11 High led c
        PORTB &= ~_BV(PORTB2);//pin 10 Low led d
        PORTB &= ~_BV(PORTB1);//pin 09 Low led e
        PORTB &= ~_BV(PORTB0);//pin 08 Low led f
        PORTD &= ~_BV(PORTD7);//pin 07 Low led g
        _delay_ms(MS_DELAY);

        // 8
        PORTB |= _BV(PORTB5);//pin 13 High led a
        PORTB |= _BV(PORTB4);//pin 12 High led b
        PORTB |= _BV(PORTB3);//pin 11 High led c
        PORTB |= _BV(PORTB2);//pin 10 High led d
        PORTB |= _BV(PORTB1);//pin 09 High led e
        PORTB |= _BV(PORTB0);//pin 08 High led f
        PORTD |= _BV(PORTD7);//pin 07 High led g
        _delay_ms(MS_DELAY);

        // 9
        PORTB |= _BV(PORTB5);//pin 13 High led a
        PORTB |= _BV(PORTB4);//pin 12 High led b
        PORTB |= _BV(PORTB3);//pin 11 High led c
        PORTB |= _BV(PORTB2);//pin 10 High led d
        PORTB &= ~_BV(PORTB1);//pin 09 Low led e
        PORTB |= _BV(PORTB0);//pin 08 High led f
        PORTD |= _BV(PORTD7);//pin 07 High led g
        _delay_ms(MS_DELAY);
    }
    return 0;
}