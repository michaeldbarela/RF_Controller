#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte address[6] = "00001";

class RF_Transmitter{
private:
	// pins to be set after calling parameterized constructor
	uint8_t CE;
	uint8_t CSN;
	// default constructed RF24 object
	RF24 radio;

public:
	// default constructor
	RF_Transmitter(void);
	// parameterized constructor
	RF_Transmitter(uint8_t CE, uint8_t CSN);
	// update function for use in loop
	void update(uint8_t data);

	// getter functions
	RF24 get_radio(void);

	// print for debugging
	void print_dbg(void);
};