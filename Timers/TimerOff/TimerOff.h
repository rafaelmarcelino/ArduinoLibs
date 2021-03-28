//Diretivas para a criação da biblioteca
#ifndef TIMEROFF_H
#define TIMEROFF_H

//Inclusão da biblioteca do arduino
#include <Arduino.h>

//Definindo a classe
class TimerOff
{
public:
	//Construtor da classe
	TimerOff();
	//Métodos da classe
	bool outputTimerOff(bool statusOfInput, long valueOfTime);

private:
	//Variáveis utilizadas na classe
	bool _statusOfInput_TimerOff = false;
	bool _activateFirst = false;
	bool _stateOfOutput = false;
	
	long _valueOfFirstHit_TimerOff = 0;
};


#endif