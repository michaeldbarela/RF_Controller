#include <Arduino.h>
#include <Wire.h>
#include "RF_Transmitter.h"
#include "RF_Receiver.h"
#include "Joystick.h"

// arduino functions
void setup(void);
void loop(void);

// global variables
uint8_t count;
uint8_t prev_count;
Joystick joystick_left = Joystick(A0, A1, 2);

// main function
int main(void){
	init(); // required
	setup();

	// forever loop
	for(;;){
		loop();
	}

	return 0;
}

// Initial setup of program
void setup(void){
  Serial.begin(9600);
}

// Main logic of the program
void loop(void){
	joystick_left.update();
	joystick_left.print_dbg();
	delay(100);
}
