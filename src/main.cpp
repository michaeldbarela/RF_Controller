#include <Arduino.h>
#include <Wire.h>
#include "RF_Transmitter.h"
#include "RF_Receiver.h"
#include "Joystick.h"

// for use with functions to designate setup or loop logic
#define SETUP	1
#define LOOP 2
// Enable objects by setting constants to 1
#define JOYSTICKS_EN 0
#define RF_TX_EN 0
#define RF_RX_EN 1

// arduino functions
void setup(void);
void loop(void);
// enable object and setup or loop logic
void joysticks_en(uint8_t setup_loop, uint8_t enable);
void rf_tx_en(uint8_t setup_loop, uint8_t enable);
void rf_rx_en(uint8_t setup_loop, uint8_t enable);

// global objects
Joystick joystick_left;
Joystick joystick_right;
RF_Transmitter rf_tx;
RF_Receiver rf_rx;
// global variables
uint8_t tx_data;

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
  joysticks_en(SETUP, JOYSTICKS_EN);
  rf_tx_en(SETUP, RF_TX_EN);
  rf_rx_en(SETUP, RF_RX_EN);
}

// Main logic of the program
void loop(void){
	joysticks_en(LOOP, JOYSTICKS_EN);
	rf_tx_en(LOOP, RF_TX_EN);
	rf_rx_en(LOOP, RF_RX_EN);
	delay(1000);
}

void joysticks_en(uint8_t setup_loop, uint8_t enable){
	if(enable & setup_loop == 1){
		joystick_left = Joystick(A0, A1, 2);
 		joystick_right = Joystick(A2, A3, 3);
	}else if(enable & setup_loop == 2){
		joystick_left.update();
		// joystick_right.update();
		joystick_left.print_dbg();
		// joystick_right.print_dbg();
	}
}

void rf_tx_en(uint8_t setup_loop, uint8_t enable){
	if(enable & setup_loop == 1){
		rf_tx = RF_Transmitter(9, 10);
	}else if(enable & setup_loop == 2){
		rf_tx.update('t');
		rf_tx.print_dbg();
	}
}

void rf_rx_en(uint8_t setup_loop, uint8_t enable){
	if(enable & setup_loop == 1){
		rf_rx = RF_Receiver(9, 10);
	}else if(enable & setup_loop == 2){
		rf_rx.update();
		rf_rx.print_dbg();
	}
}
