#include "Joystick.h"

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

int Joystick::get_xPosition(void){
	return xPosition;
}

int Joystick::get_yPosition(void){
	return yPosition;
}

int Joystick::get_SW_state(void){
	return SW_state;
}

int Joystick::get_mapX(void){
	return mapX;
}

int Joystick::get_mapY(void){
	return mapY;
}

void Joystick::print_dbg(){
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