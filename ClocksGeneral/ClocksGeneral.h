//Diretivas para a criação da biblioteca
#ifndef CLOCKSGENERAL_H
#define CLOCKSGENERAL_H

//Inclusão da biblioteca do arduino
#include <Arduino.h>

//Definindo a classe
class ClocksGeneral
{
public:
	//Construtor da classe
	ClocksGeneral();
	//Métodos da classe
	long getLastCycleTime(long startCycleTime);
	bool getClockInThisTime(long baseTime);
	
	
private:
	//Variáveis utilizadas na classe
	long _actualTimeInMs = 0;
	long _lastTimeTriggered = 0;
	long _offsetForWrongTime = 0;
};


#endif