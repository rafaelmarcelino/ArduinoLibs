//Diretivas para a criação da biblioteca
#ifndef MSGLOGGER_H
#define MSGLOGGER_H

//Inclusão da biblioteca do arduino
#include <Arduino.h>
#include <AsyncDateAndTime.h>

//Definindo a classe
class MsgLogger
{
public:
	//Construtor da classe
	MsgLogger();
	//Métodos da classe
	void startMsgLogger();
	void startMsgLogger(unsigned long speedOfSerial);
	void setupInitialDateAndTimeOfMsgLogger(unsigned int year,byte month,byte day,byte hour,byte minute,byte second);
	void runMsgLogger();
	void generateMessage(const char* shownThisMessage,bool status);
	void generateMessage(const char* shownThisMessage,byte status);
	void generateMessage(const char* shownThisMessage,int status);
	void generateMessage(const char* shownThisMessage,unsigned int status);
	void generateMessage(const char* shownThisMessage,long status);
	void generateMessage(const char* shownThisMessage,double status);
	void generateMessage(const char* shownThisMessage,float status);

private:
	//Variáveis utilizadas na classe
	AsyncDateAndTime MsgLoggerDateAndTime;
	//Métodos privados da classe
	void generateHeaderOfMessage();
};

#endif