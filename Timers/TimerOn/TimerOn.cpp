//Definição das funcionalidades da classe TimerOn

#include "TimerOn.h"

//Construtor
TimerOn::TimerOn() {}

//Funcionalidade da função activateAfter
bool TimerOn::outputTimerOn(bool statusOfInput, long valueOfTime)
{
	bool _local_stateOfOutput = false;

	if ((statusOfInput != _statusOfInput_outputTimerOn) && (statusOfInput))
	{
		_valueOfFirstHit_outputTimerOn = millis();
	}
	else if (!statusOfInput)
	{
		_valueOfFirstHit_outputTimerOn = 0;
	}

	if (statusOfInput && (millis() >= (_valueOfFirstHit_outputTimerOn + valueOfTime)))
	{
		_local_stateOfOutput = true;
	}
	else if (!statusOfInput)
	{
		_local_stateOfOutput = false;
	}

	_statusOfInput_outputTimerOn = statusOfInput;
	return _local_stateOfOutput;
}
