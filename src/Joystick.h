#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>

class Joystick{
private:
	uint8_t VRx;
	uint8_t VRy;
	uint8_t SW;
	// these analog positions can range from 0 to 1023
	uint16_t xPosition;
	uint16_t yPosition;
	uint8_t SW_state;
	// these will map the positition values to a range of -512 to 512
	int16_t mapX;
	int16_t mapY;

public:
	// constructor
	Joystick(uint8_t VRx, uint8_t VRy, uint8_t SW);
	void update(void);

	// getter functions
	int get_xPosition(void);
	int get_yPosition(void);
	int get_SW_state(void);
	int get_mapX(void);
	int get_mapY(void);

	// print for debugging
	void print_dbg();
};