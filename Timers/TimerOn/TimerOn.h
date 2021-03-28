//Diretivas para a criação da biblioteca
#ifndef TIMERON_H
#define TIMERON_H

//Inclusão da biblioteca do arduino
#include <Arduino.h>

//Definindo a classe
class TimerOn
{
public:
	//Construtor da classe
	TimerOn();
	//Métodos da classe
	bool outputTimerOn(bool statusOfInput, long valueOfTime);

private:
	//Variáveis utilizadas na classe
	bool _statusOfInput_outputTimerOn = false;
	
	long _valueOfFirstHit_outputTimerOn = 0;
};


#endif