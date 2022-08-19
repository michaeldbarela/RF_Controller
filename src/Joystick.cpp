#include "Joystick.h"

Joystick::Joystick(void){
	xPosition = 0;
	yPosition = 0;
	SW_state = 0;
	mapX = 0;
	mapY = 0;
	VRx = 0;
	VRy = 0;
	SW = 0;
}

Joystick::Joystick(uint8_t VRx, uint8_t VRy, uint8_t SW){
	xPosition = 0;
	yPosition = 0;
	SW_state = 0;
	mapX = 0;
	mapY = 0;
	this->VRx = VRx;
	this->VRy = VRy;
	this->SW = SW;
	pinMode(this->VRx, INPUT);
  	pinMode(this->VRy, INPUT);
  	pinMode(this->SW, INPUT_PULLUP); 
}

void Joystick::update(void) {
	xPosition = analogRead(VRx);
	yPosition = analogRead(VRy);
	SW_state = digitalRead(SW);
	SW_state = !SW_state;
	mapX = map(xPosition, 0, 1023, -512, 512);
	mapY = map(yPosition, 0, 1023, -512, 512);
}

uint16_t Joystick::get_xPosition(void){
	return xPosition;
}

uint16_t Joystick::get_yPosition(void){
	return yPosition;
}

uint8_t Joystick::get_SW_state(void){
	return SW_state;
}

uint16_t Joystick::get_mapX(void){
	return mapX;
}

uint16_t Joystick::get_mapY(void){
	return mapY;
}

void Joystick::print_dbg(void){
	Serial.print("X: ");
	Serial.print(mapX);
	Serial.print(" | X Analog: ");
	Serial.print(xPosition);
	Serial.print(" | Y: ");
	Serial.print(mapY);
	Serial.print(" | Y Analog: ");
	Serial.print(yPosition);
	Serial.print(" | Button: ");
	Serial.println(SW_state);
}