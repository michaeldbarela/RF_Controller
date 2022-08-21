#pragma once
#include <Arduino.h>

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
	// default constructor
	Joystick(void);
	// constructor
	Joystick(uint8_t VRx, uint8_t VRy, uint8_t SW);
	void update(void);

	// getter functions
	uint16_t get_xPosition(void);
	uint16_t get_yPosition(void);
	uint8_t get_SW_state(void);
	uint16_t get_mapX(void);
	uint16_t get_mapY(void);

	// print for debugging
	void print_dbg(void);
};