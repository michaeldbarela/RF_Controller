#include "RF_Receiver.h"

const uint8_t address[6] = "00001";

RF_Receiver::RF_Receiver(void){

}

RF_Receiver::RF_Receiver(uint8_t CE, uint8_t CSN){
	this->CE = CE;
	this->CSN = CSN;
	RF24 radio(this->CE, this->CSN);
	radio.begin();
	radio.openReadingPipe(0, address);
	radio.setPALevel(RF24_PA_MIN);
	radio.startListening();
}

uint8_t RF_Receiver::update(void){
	uint8_t data;
	if(radio.available()){
		radio.read(&data, sizeof(data));
	}
	return data;
}

RF24 RF_Receiver::get_radio(void){
	return radio;
}

void RF_Receiver::print_dbg(void){
	Serial.print("Received Data = ");
	Serial.println(rx_data);
}