//Definição das funcionalidades da classe OneShot

#include "OneShot.h"

//Construtor
OneShot::OneShot() {}

//Funcionalidade da função oneShotRisingEdge
bool OneShot::oneShotRisingEdge(bool statusOfInput)
{
	bool _local_stateOfOneShot = false;

	if ((statusOfInput != _statusOfInput_OneShotRisingEdge) && (statusOfInput))
	{
		_local_stateOfOneShot = true;
	}
	else
	{
		_local_stateOfOneShot = false;
	}

	_statusOfInput_OneShotRisingEdge = statusOfInput;
	return _local_stateOfOneShot;
}

//Funcionalidade da função oneShotFallingEdge
bool OneShot::oneShotFallingEdge(bool statusOfInput)
{
	bool _local_stateOfOneShot = false;

	if ((statusOfInput != _statusOfInput_OneShotFallingEdge) && (!statusOfInput))
	{
		_local_stateOfOneShot = true;
	}
	else
	{
		_local_stateOfOneShot = false;
	}

	_statusOfInput_OneShotFallingEdge = statusOfInput;
	return _local_stateOfOneShot;
}