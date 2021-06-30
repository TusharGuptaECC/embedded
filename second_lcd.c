/*
    RS-----pin12
    RW-----pin11
    E -----pin10
    D0-----pin9     D7  pin2
    D1-----pin8     D6  pin3
    D2-----pin7     D5  pin4
    D3-----pin6     D4  pin5
    D4-----pin5     D3  pin6
    D5-----pin4     D2  pin7
    D6-----pin3     D1  pin8
    D7-----pin2     D0  pin9
*/

#include<avr/io.h>
#include<util/delay.h>

# define MS_DELAY 1000

void clearDisplay(void);
void allowDisplay(void);
void returnHome(void);
void allowTwoLineDisplay(void);
void displayCharacter(int);
void startOfRow(int);
void incrementMode(void);
void rightShiftUperRow(void);
void rightShiftLowerRow(void);

int main()
{
    //int i,sum=0;
    DDRB = 0x3F;    // setting pin 13,12,11,10,9,8 as output
    DDRD = 0xFC;    // setting pin 7,6,5,4,3,2 as output
    
    PORTB |= _BV(PORTB5);
    
    clearDisplay();
    returnHome();
    allowDisplay();
    allowTwoLineDisplay();
    /*displayCharacter('S');
    displayCharacter('O');
    displayCharacter('N');
    displayCharacter('A');
    displayCharacter('L');
    displayCharacter('K');
    displayCharacter('U');
    displayCharacter('N');
    displayCharacter('J');
    displayCharacter();*/
    /*for(i=1;i<=26;i++)
    {
        sum = 64+i;
        if(i!=17)
        {
            displayCharacter(sum);
        }
        else
        {
            startOfRow('L');
            displayCharacter(sum);
        }
    }*/
    displayCharacter('H');
    displayCharacter('E');
    displayCharacter('L');
    displayCharacter('L');
    displayCharacter('O');
    rightShiftUperRow();
    displayCharacter('W');
    displayCharacter('O');
    displayCharacter('R');
    displayCharacter('L');
    displayCharacter('D');    

    return 0;
}

void clearDisplay(void)
{
    _delay_ms(MS_DELAY);
    PORTB = 0x22;
    PORTD = 0x00;
    // E edge
    PORTB |= _BV(PORTB2);
    PORTB &= ~_BV(PORTB2);
}

void allowDisplay(void)
{
    _delay_ms(MS_DELAY);
    PORTB = 0x20;
    PORTD = 0xC0;
    // E edge
    PORTB |= _BV(PORTB2);
    PORTB &= ~_BV(PORTB2);
}

void returnHome(void)
{
    _delay_ms(MS_DELAY);
    PORTB = 0x21;
    PORTD = 0x00;
    // E edge
    PORTB |= _BV(PORTB2);
    PORTB &= ~_BV(PORTB2);
}

void allowTwoLineDisplay(void)
{
    _delay_ms(MS_DELAY);
    PORTB = 0x20;
    PORTD = 0x70;

    // E edge
    PORTB |= _BV(PORTB2);
    PORTB &= ~_BV(PORTB2);
}

void displayCharacter(int c)
{
    int x;
    x=c;
    if(x=='A')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x32;
        PORTD = 0x08;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }
    
    else if(x=='B')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x31;
        PORTD = 0x08;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='C')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x33;
        PORTD = 0x08;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='D')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x30;
        PORTD = 0x88;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='E')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x32;
        PORTD = 0x88;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='F')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x31;
        PORTD = 0x88;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='G')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x33;
        PORTD = 0x88;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='H')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x30;
        PORTD = 0x48;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='I')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x32;
        PORTD = 0x48;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='J')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x31;
        PORTD = 0x48;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='K')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x33;
        PORTD = 0x48;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='L')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x30;
        PORTD = 0xC8;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='M')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x32;
        PORTD = 0xC8;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='N')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x31;
        PORTD = 0xC8;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='O')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x33;
        PORTD = 0xC8;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='P')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x30;
        PORTD = 0x28;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='Q')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x32;
        PORTD = 0x28;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='R')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x31;
        PORTD = 0x28;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='S')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x33;
        PORTD = 0x28;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='T')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x30;
        PORTD = 0xA8;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='U')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x32;
        PORTD = 0xA8;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='V')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x31;
        PORTD = 0xA8;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='W')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x33;
        PORTD = 0xA8;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='X')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x30;
        PORTD = 0x68;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='Y')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x32;
        PORTD = 0x68;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else if(x=='Z')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x31;
        PORTD = 0x68;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }

    else{}
}

void incrementMode(void)
{
    _delay_ms(MS_DELAY);
    PORTB = 0x21;
    PORTD = 0x80;

    // E edge
    PORTB |= _BV(PORTB2);
    PORTB &= ~_BV(PORTB2);
}

void startOfRow(int x)
{
    int c;
    c = x;
    if(c=='L')
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x20;
        PORTD = 0x0C;    

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }
    else
    {
        _delay_ms(MS_DELAY);
        PORTB = 0x20;
        PORTD = 0x04;

        // E edge
        PORTB |= _BV(PORTB2);
        PORTB &= ~_BV(PORTB2);
    }
}

void rightShiftUperRow(void)
{
    //int k;
    _delay_ms(MS_DELAY);
    PORTB = 0x21;
    PORTD = 0x84;

    // E edge
    PORTB |= _BV(PORTB2);
    PORTB &= ~_BV(PORTB2);
}

void rightShiftLowerRow(void)
{
    //int k;
    _delay_ms(MS_DELAY);
    PORTB = 0x20;
    PORTD = 0x0C;

    // E edge
    PORTB |= _BV(PORTB2);
    PORTB &= ~_BV(PORTB2);
}
