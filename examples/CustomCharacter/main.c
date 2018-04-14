/*
  LiquidCrystal Library - Custom Characters

 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "I <heart> ARM!" and a little dancing man
 to the LCD.

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

 library originated from Arduino, Adafruit and ported 12 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)
 example originated from Arduino, Adafruit and ported 13 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)
 
 Based on Adafruit's example at
 https://github.com/adafruit/SPI_VFD/blob/master/examples/createChar/createChar.pde

 This example code is in the public domain.
 https://github.com/SayidHosseini/LiquidCrystal/tree/master/examples/CustomeCharacter
 
 Also useful:
 http://icontexto.com/charactercreator/

*/

/* This example and createChar function are not working yet */

#include "stm32f3xx_hal.h" // change this here and inside LiquidCrystal library accordingly
#include "LiquidCrystal.h"

//this should be checked to see if this is the way
typedef unsigned char byte;

// make some custom characters:
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

// ISR Required by the library (for HAL_Delay)
void SysTick_Handler(void);

int main(void)
{
  // Initializing SysTick - required by the library
	HAL_Init();

	// initialize the library by associating any needed LCD interface pin
	LiquidCrystal(GPIOD, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14);
	
  // create a new character
  createChar(0, heart);
  // create a new character
  createChar(1, smiley);
  // create a new character
  createChar(2, frownie);
  // create a new character
  createChar(3, armsDown);
  // create a new character
  createChar(4, armsUp);

  // Print a message to the lcd.
  print("I ");
  write((0)); // when calling lcd.write() '0' must be cast as a byte
  print(" ARM! ");
  write((byte)1);

	
	while(1)
	{
		setCursor(4, 1);
		// draw the little man, arms down:
		write(3);
		HAL_Delay(500);
		setCursor(4, 1);
		// draw him arms up:
		write(4);
		HAL_Delay(500);
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}
