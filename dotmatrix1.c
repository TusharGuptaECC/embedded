#include<avr/io.h>
#include<util/delay.h>

# define MS_DELAY 1
//# define MS_DELAY1 100

void fillLsrZeroOrOne(int);
void fillRsrZeroOrOne(int);
void fillRegister(int,int,int,int,int,int,int,int,int);
void resetRegister(void);
void representRegister(void);
void displayS(void);
void displayO(void);
void displayN(void);
void displayA(void);
void displayL(void);
void displayK(void);
void displayU(void);
void displayJ(void);
void displayB(void);
void displayC(void);
void displayD(void);
void displayE(void);
void displayF(void);
void displayG(void);
void displayH(void);
void displayI(void);
void displayP(void);
//void displayQ(void);
void displayR(void);
void displayT(void);

int main()
{
    DDRB |= _BV(DDB4);  //pin 12 as output
    DDRB |= _BV(DDB3);  //pin 11 as output
    DDRB |= _BV(DDB2);  //pin 10 as output
    DDRB |= _BV(DDB1);  //pin 9  as output
    DDRB |= _BV(DDB0);  //pin 8  as output
    DDRD |= _BV(DDD7);  //pin 7  as output
    DDRD |= _BV(DDD6);  //pin 6  as output
    DDRD |= _BV(DDD5);  //pin 5  as output

    while(1)
    {
        displayS();
        displayO();
        displayN();
        displayA();
        displayL();
        displayK();
        displayU();
        displayN();
        displayJ();
        displayA();
        displayB();
        displayC();
        displayD();
        displayE();
        displayF();
        displayG();
        displayH();
        displayI();
        displayJ();
        displayK();
        displayL();
        displayN();
        displayO();
        displayP();
        displayR();
        displayS();
        displayT();
        displayU();
    }

    return 0;
}

void fillLsrZeroOrOne(int x)
{
    int x1 = x;
    if(x1==0)
    {
        PORTB &= ~_BV(PORTB4);   //datapin = 0 lsr
        PORTB |= _BV(PORTB3);   //clockpin = 1 lsr
        PORTB &= ~_BV(PORTB3);  //clockpin = 0 lsr
    }
    else 
    {
        PORTB |= _BV(PORTB4);   //datapin = 1 lsr
        PORTB |= _BV(PORTB3);   //clockpin = 1 lsr
        PORTB &= ~_BV(PORTB3);  //clockpin = 0 lsr
    }
}

void fillRsrZeroOrOne(int y)
{
    int y1 = y;
    if(y1==0)
    {
        PORTB &= ~_BV(PORTB1);   //datapin = 0 rsr
        PORTB |= _BV(PORTB0);   //clockpin = 1 rsr
        PORTB &= ~_BV(PORTB0);  //clockpin = 0 rsr
    }
    else 
    {
        PORTB |= _BV(PORTB1);   //datapin = 1 rsr
        PORTB |= _BV(PORTB0);   //clockpin = 1 rsr
        PORTB &= ~_BV(PORTB0);  //clockpin = 0 rsr
    }
}





void fillRegister(int a, int b, int c, int d, int e, int f, int g, int h, int r)
{
    int a1=a,b1=b,c1=c,d1=d,e1=e,f1=f,g1=g,h1=h,r1=r;
    if(r1==0)
    {
        // filling LSR
        fillLsrZeroOrOne(h1);
        fillLsrZeroOrOne(g1);
        fillLsrZeroOrOne(f1);
        fillLsrZeroOrOne(e1);
        fillLsrZeroOrOne(d1);
        fillLsrZeroOrOne(c1);
        fillLsrZeroOrOne(b1);
        fillLsrZeroOrOne(a1);
    }
    else if(r1==1)
    {
        // filling RSR
        fillRsrZeroOrOne(h1);
        fillRsrZeroOrOne(g1);
        fillRsrZeroOrOne(f1);
        fillRsrZeroOrOne(e1);
        fillRsrZeroOrOne(d1);
        fillRsrZeroOrOne(c1);
        fillRsrZeroOrOne(b1);
        fillRsrZeroOrOne(a1);
    }
    else{}
}

void resetRegister(void)
{
    _delay_ms(MS_DELAY);

    PORTB &= ~_BV(PORTB2);   //latchpin = 0 lsr
    PORTD &= ~_BV(PORTD7);   //latchpin = 0 rsr
    
    //reseting the left and right shift register
    PORTD &= ~_BV(PORTD5);   //MR' low
    PORTD |= _BV(PORTD5);    //MR' high

    PORTD &= ~_BV(PORTD6);   //MR' low
    PORTD |= _BV(PORTD6);    //MR' high
}

void representRegister(void)
{
    PORTB |= _BV(PORTB2);   //latchpin = 1 lsr
    PORTD |= _BV(PORTD7);   //latchpin = 1 rsr
}

void displayS(void)
{
    int i=0;
    while(i<=100)
    {
        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();
        
        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

         // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,0,1,1,1,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayO(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();
        
        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();

         // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayN(void)
{
    int i=0;
    while(i<=100)
    {   
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 7,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,1,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 6,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 4,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();
        
        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();
        
        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayA(void)
{   
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 5,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,0,1,1,1,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayL(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayK(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 6,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 7,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();

        // 4,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,1,1);
        representRegister();

        // 3,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayU(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayJ(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();

        // 7,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,1,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 4,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayB(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 5,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,0,1,1,1,0,1,0,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayC(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayD(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayE(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 5,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,0,1,1,1,0,1,0,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayF(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 5,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,0,1,1,1,0,1,0,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayG(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayH(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 5,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,0,1,1,1,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayI(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();

        // 7,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,1,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 4,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

/*void displayM(void)
{

}*/

void displayP(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 5,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,0,1,1,1,0,1,0,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

/*void displayQ(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();
        
        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();

         // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,1,0,0,1,0,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,4
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,0,1);
        representRegister();

        // 3,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();
        

        _delay_ms(MS_DELAY);
        i++;
    }
}*/

void displayR(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,3
        resetRegister();
        fillRegister(0,1,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 5,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,1,0,0);
        fillRegister(0,0,1,1,1,0,1,0,1);
        representRegister();

        // 6,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,1,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();

        // 7,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,1,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 4,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(0,0,1,0,1,0,1,1,1);
        representRegister();

        // 3,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 2,6
        resetRegister();
        fillRegister(0,1,1,1,0,1,0,0,0);
        fillRegister(0,1,0,0,1,0,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

void displayT(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        

        // 2,5
        resetRegister();
        fillRegister(0,1,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        
        // 8,4
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,0,1,0,1,0,1,0,1);
        representRegister();

        // 8,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 8,6
        resetRegister();
        fillRegister(0,0,1,1,0,1,0,0,0);
        fillRegister(1,1,0,0,1,0,1,1,1);
        representRegister();

        // 7,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,1,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 5,5
        resetRegister();
        fillRegister(1,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,1,1,0,1,0,1);
        representRegister();

        // 4,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();

        // 3,5
        resetRegister();
        fillRegister(0,0,1,1,0,0,1,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}

/*void displayV(void)
{
    int i=0;
    while(i<=100)
    {
        // 8,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(1,1,1,0,1,0,1,0,1);
        representRegister();

        // 7,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,1,1,0,1);
        representRegister();

        // 6,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,1,0);
        fillRegister(0,1,1,0,1,0,1,1,1);
        representRegister();

        // 5,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,1,0,0);
        fillRegister(0,1,1,1,0,0,1,0,1);
        representRegister();

        // 4,3
        resetRegister();
        fillRegister(0,0,1,0,0,1,0,0,0);
        fillRegister(0,1,1,0,1,0,1,0,1);
        representRegister();
        
        _delay_ms(MS_DELAY);
        i++;
    }
}*/