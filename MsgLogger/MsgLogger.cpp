//Definição das funcionalidades da classe Log

#include "MsgLogger.h"

//Construtor
MsgLogger::MsgLogger() {
}

//Funcionalidade da função startMsgLogger
void MsgLogger::startMsgLogger(){
	Serial.begin(9600);
}
//Funcionalidade da função startMsgLogger
void MsgLogger::startMsgLogger(unsigned long speedOfSerial){
	Serial.begin(speedOfSerial);
}
//Funcionalidade da função setupInitialDateAndTimeOfMsgLogger 
void MsgLogger::setupInitialDateAndTimeOfMsgLogger(unsigned int year,byte month,byte day,byte hour,byte minute,byte second){
	MsgLoggerDateAndTime.setupDateAndTime(year,month,day,hour,minute,second);
}
// Funcionalidade da função runMsgLogger
void MsgLogger::runMsgLogger(){
	MsgLoggerDateAndTime.generateAsyncClok();
}


//Funcionalidade da função generateMessage
void MsgLogger::generateMessage(const char* shownThisMessage, bool status){
	MsgLogger::generateHeaderOfMessage();
	Serial.print(shownThisMessage);
	Serial.println(status);
}
//Funcionalidade da função generateMessage
void MsgLogger::generateMessage(const char* shownThisMessage, byte status){
	MsgLogger::generateHeaderOfMessage();
	Serial.print(shownThisMessage);
	Serial.println(status);
}
//Funcionalidade da função generateMessage
void MsgLogger::generateMessage(const char* shownThisMessage, int status){
	MsgLogger::generateHeaderOfMessage();
	Serial.print(shownThisMessage);
	Serial.println(status);
}
//Funcionalidade da função generateMessage
void MsgLogger::generateMessage(const char* shownThisMessage, unsigned int status){
	MsgLogger::generateHeaderOfMessage();
	Serial.print(shownThisMessage);
	Serial.println(status);
}
//Funcionalidade da função generateMessage
void MsgLogger::generateMessage(const char* shownThisMessage, long status){
	MsgLogger::generateHeaderOfMessage();
	Serial.print(shownThisMessage);
	Serial.println(status);
}
//Funcionalidade da função generateMessage
void MsgLogger::generateMessage(const char* shownThisMessage, double status){
	MsgLogger::generateHeaderOfMessage();
	Serial.print(shownThisMessage);
	Serial.println(status);
}
//Funcionalidade da função generateMessage
void MsgLogger::generateMessage(const char* shownThisMessage, float status){
	MsgLogger::generateHeaderOfMessage();
	Serial.print(shownThisMessage);
	Serial.println(status);
}

//Métodos Privados
//Funcionalidade da função generateHeaderOfMessage
void MsgLogger::generateHeaderOfMessage(){
	Serial.print(MsgLoggerDateAndTime.getDateAndTime());;
	Serial.print(" | ");
}
