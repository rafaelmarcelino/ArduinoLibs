
//Definição das funcionalidades da classe TimerOff

#include "TimerOff.h"

//Construtor
TimerOff::TimerOff() {}

//Funcionalidade da função outputTimerOff
bool TimerOff::outputTimerOff(bool statusOfInput, long valueOfTime)
{

	if ((statusOfInput != _statusOfInput_TimerOff) && (statusOfInput))
	{
		_activateFirst  =true;
		_stateOfOutput = false;
	}
	
	
	if ((statusOfInput != _statusOfInput_TimerOff) && (!statusOfInput))
	{
		_valueOfFirstHit_TimerOff = millis();
	}

	if (!statusOfInput && _activateFirst && (millis() >= (_valueOfFirstHit_TimerOff + valueOfTime)))
	{
		_stateOfOutput = true;
		_activateFirst = false;
	}

	_statusOfInput_TimerOff = statusOfInput;
	return _stateOfOutput;
}
