/*! \mainpage Week-1 Experiment-4: LCD Interfacing
 *
 * @author     e-Yantra Team
 * @date       2020/01/31
 *
 * \subsection Aim
 * To display moving/scrolling and static text/string on LCD.
 *
 * \subsection Connections
 * LCD Connections:								<br>
 *		 LCD Pins	  Micro-controller Pins     <br>
 *			  RS  --> PC0						<br>
 *			  RW  --> PC1						<br>
 *			  EN  --> PC2						<br>
 *			  DB7 --> PC7						<br>
 *			  DB6 --> PC6						<br>
 *			  DB5 --> PC5						<br>
 *			  DB4 --> PC4						<br>
 *
 */


//---------------------------------- HEADER FILES -----------------------------------------------------
#include "firebird_simulation.h"		// Header file included that contains macro definitions essential for Firebird V robot
#include <util/delay.h>					// Standard AVR Delay Library
#include "lcd.h"						// LCD Header file included that contains function definitions essential to deal with LCD


//------------------------------------- MACROS -----------------------------------------------------
// If any

//---------------------------------- GLOBAL VARIABLES ---------------------------------------------------
// If any

//---------------------------------- FUNCTIONS ----------------------------------------------------------
// << TODO >> : Complete all the functions as per the instructions given in form of comments


/**
 * @brief      Code to display scrolling message on LCD
 */
void scrolling_loop() {
	char text[] = "Crash Course - Embedded Systems"; //Embedded Systems";
	
	/* 
	<< TODO >> : 
	1. Write your Logic to display the scrolling message as shown in the expected output video
	2. Display text "Crash Course - Embedded Systems" starting from 1st row and 1st column of the LCD
	*/
	int i;
	char row_num = 1;// col_num = 1;
	
	lcd_string(row_num,1,text);
	_delay_ms(100);
	for(i=0;i<=24;i++)
	{
		lcd_wr_command(0x18);
		_delay_ms(100);
	}
}


/**
 * @brief      Code to display static message on LCD
 */
void static_loop() {
	/* 
	<< TODO >> : 
	1. Code to display static message as shown in the expected output video
	2. Display text "e-Yantra Academy" starting from 2nd row and 1st column of the LCD
	*/
	
	char row_num = 2, col_num = 1;
	char message[16] = "e-Yantra Academy";
	lcd_string(row_num,col_num,message); 
}


//---------------------------------- MAIN ----------------------------------------------------------------
/**
 * @brief      Main Function
 *
 * @details    First Initializes LCD and displays static and scrolling message on LCD
 */
int main(void) {
	
	// << NOTE >> : You are not allowed to modify or change anything inside this function
	lcd_port_config();					// Initialize the LCD port
	lcd_init();							// Initialize the LCD
	
	while(1)
	{
		lcd_clear();					// Clears LCD
		lcd_home();						// Sets the cursor's to home i.e. 1st row, 1st column
		
		static_loop();					// Display static text
		_delay_ms(2000);				// Delay of 2 seconds
		
		lcd_clear();					// Clears LCD
		lcd_home();						// Sets the cursor's to home i.e. 1st row, 1st column
		
		scrolling_loop();				// Display scrolling text
		_delay_ms(2000);				// Delay of 2 seconds
	}
}
//---------------------------------- END ------------------------------------------------------------------