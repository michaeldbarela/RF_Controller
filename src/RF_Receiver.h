#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

class RF_Receiver{
private:
	// pins to be set after calling parameterized constructor
	uint8_t CE;
	uint8_t CSN;
	// default constructed RF24 object
	RF24 radio;
	// data
	uint8_t rx_data;

public:
	// default constructor
	RF_Receiver(void);
	// parameterized constructor
	RF_Receiver(uint8_t CE, uint8_t CSN);
	// update function for use in loop
	void update(void);

	// getter functions
	RF24 get_radio(void);

	// print for debugging
	void print_dbg(void);
};