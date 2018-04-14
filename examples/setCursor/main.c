/*
  LiquidCrystal Library - setCursor

 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints to all the positions of the LCD using the
 setCursor() method:

 The circuit:
 * LCD RS pin to PD8
 * LCD R/W pin to PD9
 * LCD En pin to PD10
 * LCD D4 pin to PD11
 * LCD D5 pin to PD12
 * LCD D6 pin to PD13
 * LCD D7 pin to PD14
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 library forked from Arduino, Adafruit and modified 12 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)
 example forked from Arduino, Adafruit and modified 13 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)


 This example code is in the public domain.

 https://github.com/SayidHosseini/LiquidCrystal/tree/master/examples/setCursor

*/
#include "stm32f3xx_hal.h" // change this here and inside LiquidCrystal library accordingly
#include "LiquidCrystal.h"

const int numRows = 2;
const int numCols = 16;

int main(void)
{
	// initialize the library by associating any needed LCD interface pin
	LiquidCrystal(GPIOD, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14);
	
	while(1)
	{
		// loop from ASCII 'a' to ASCII 'z':
		for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {
			// loop over the columns:
			for (int  thisRow = 0; thisRow < numRows; thisRow++) {
				// loop over the rows:
				for (int thisCol = 0; thisCol < numCols; thisCol++) {
					// set the cursor position:
					setCursor(thisCol, thisRow);
					// print the letter:
					write(thisLetter);
					HAL_Delay(200);
				}
			}
		}
	}
}
