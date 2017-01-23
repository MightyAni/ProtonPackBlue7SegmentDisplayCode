// We always have to include the library
#include "LedControl.h"

/*
Now we need an LedControl to work with.
Adafruit Pro Trinket 5 V, 16 MHz
pin 11 is connected to the DataIn/MOSI/SDI/Din
pin 13 is connected to the SCK/CLK
pin 10 is connected to LOAD/CS/SS
pin 12 is connected to DataOut/MISO/SDO/Dout
We have only a single MAX7219.
*/

int csPin = 10;
int mosiPin = 11;
int misoPin = 12;
int clkPin = 13;
int numDevices = 1;
int displayAddr = 0;	//We only have 1 MAX7219 chip controlling one display

int brightness = 15;	//Brightness intensity between 0 and 15

LedControl lc = LedControl(mosiPin, clkPin, csPin, numDevices);

/* we always wait a bit between updates of the display */
//unsigned long delayval = 500;	//This is the delay in milliseconds between updates of the number displayed
unsigned long delayval;
int low = 0;	//The bottom of the number range
int high = 9;	//The top of the number range

void setup() {
//// This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
//#if defined (__AVR_ATtiny85__)
//	if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
//#endif
//// End of trinket special code

	/*
	The MAX72XX is in power-saving mode on startup;
	we have to do a wakeup call
	*/
	lc.shutdown(displayAddr, false);
	/* Set the brightness to a medium value */
	lc.setIntensity(displayAddr, brightness);
	/* and clear the display */
	lc.clearDisplay(displayAddr);

}

void randomDigit0() {
	static int digit0;
	//Have the Pro Trinket randomly display digit 0 between low and high
	digit0 = random(low, high);	//Pick a random number between 0 and 9, inclusive
	lc.setDigit(displayAddr, 0, digit0, false);
	delay(10 + random(0, 2500));
}

void randomDigit1() {
	static int digit1;
	//Have the Pro Trinket randomly display digit 1 between low and high
	digit1 = random(low, high);
	lc.setDigit(displayAddr, 1, digit1, false);
	delay(10 + random(0, 1000));
}

void randomDigit2() {
	static int digit2;
	//Have the Pro Trinket randomly display digit 2 between low and high
	digit2 = random(low, high);
	lc.setDigit(displayAddr, 2, digit2, false);
	delay(10 + random(0, 3000));
}

void randomDigit3() {
	static int digit3;
	//Have the Pro Trinket randomly display digit 3 between low and high
	digit3 = random(low, high);
	lc.setDigit(displayAddr, 3, digit3, false);
	delay(10 + random(0, 250));
}

void displayNum() {
}

void loop() {
	randomDigit3();
	randomDigit2();
	randomDigit1();
	randomDigit0();
}

/*
This method will display the characters for the
word "Arduino" one after the other on digit 0.
*/
//void writeArduinoOn7Segment() {
//	lc.setChar(0, 0, 'a', false);
//	delay(delayval);
//	lc.setRow(0, 0, 0x05);
//	delay(delayval);
//	lc.setChar(0, 0, 'd', false);
//	delay(delayval);
//	lc.setRow(0, 0, 0x1c);
//	delay(delayval);
//	lc.setRow(0, 0, B00010000);
//	delay(delayval);
//	lc.setRow(0, 0, 0x15);
//	delay(delayval);
//	lc.setRow(0, 0, 0x1D);
//	delay(delayval);
//	lc.clearDisplay(0);
//	delay(delayval);
//}

///*
//This method will scroll all the hexa-decimal
//numbers and letters on the display. You will need at least
//four 7-Segment digits. otherwise it won't really look that good.
//*/
//void scrollDigits() {
//	for (int i = 0; i < 7; i++) {
//		lc.setDigit(displayAddr, 0, i, false);
//		lc.setDigit(displayAddr, 1, i + 1, false);
//		lc.setDigit(displayAddr, 2, i + 2, false);
//		lc.setDigit(displayAddr, 3, i + 3, false);
//		delay(delayval);
//	}
//	lc.clearDisplay(displayAddr);
//	delay(delayval);
//}

//void loop() {
//	//writeArduinoOn7Segment();
//	//scrollDigits();
//}


//// Arduino Pin 7 to DIN, 6 to Clk, 5 to CS, no.of devices is 1
//
//const int nDevices = 1;
//LedControl lc = LedControl(7, 6, 5, nDevices);
//void setup() {
//	// Initialize the MAX7219 device
//	for (int deviceID = 0; deviceID<nDevices; deviceID++) {
//		lc.shutdown(deviceID, false);   // Enable display
//		lc.setIntensity(deviceID, 15);  // Set brightness level (0 is min, 15 is max)
//		lc.clearDisplay(deviceID);
//	}
//}
//
//void loop() {
//	for (int deviceID = 0; deviceID<nDevices; deviceID++) {
//		for (int i = 0; i<9; i++) {
//			lc.setDigit(deviceID, i, i + 1, false);
//			delay(500);
//		}
//		lc.clearDisplay(deviceID);
//	}
//	delay(1000);
//}