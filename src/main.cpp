#include <Arduino.h>
#include "RF_Transmitter.h"
#include "RF_Receiver.h"
#include "Joystick.h"

// arduino functions
void setup(void);
void loop(void);

// global variables
uint8_t count;
uint8_t prev_count;

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
  count = 0;
  prev_count = 0;
}

// Main logic of the program
void loop(void){
	count = millis()/1000;
	if((millis()%1000 == 0) && (count != prev_count)){
		Serial.println(count);
	}
	prev_count = count;
}
