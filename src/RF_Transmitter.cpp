#include "RF_Transmitter.h"

RF_Transmitter::RF_Transmitter(void){
	
}

RF_Transmitter::RF_Transmitter(uint8_t CE, uint8_t CSN){
	this->CE = CE;
	this->CSN = CSN;
	RF24 radio(this->CE, this->CSN);
	radio.begin();
	radio.openWritingPipe(address);
	radio.setPALevel(RF24_PA_MIN);
	radio.stopListening();
}

void RF_Transmitter::update(uint8_t data){
	radio.write(&data, sizeof(data));
}

RF24 RF_Transmitter::get_radio(void){
	return radio;
}

void RF_Transmitter::print_dbg(void){

}