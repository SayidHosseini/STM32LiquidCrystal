/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

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


 This example code is in the public domain.

 https://github.com/SayidHosseini/LiquidCrystal/tree/master/examples/Display

*/
#include "stm32f3xx_hal.h" // change this here and inside LiquidCrystal library accordingly
#include "LiquidCrystal.h"

// ISR Required by the library (for HAL_Delay)
void SysTick_Handler(void);

int main(void)
{
    // Initializing SysTick - required by the library
	HAL_Init();

	// initialize the library by associating any needed LCD interface pin
	LiquidCrystal(GPIOD, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14);
	
	print("Hello, World!");
	
	while(1)
	{
    // Turn off the display:
    noDisplay();
    HAL_Delay(500);
    // Turn on the display:
    display();
    HAL_Delay(500);
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}
