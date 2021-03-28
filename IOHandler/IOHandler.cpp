//Definição das funcionalidades da classe IOHandler

#include "IOHandler.h"

//Construtor
IOHandler::IOHandler() {}

//Funcionalidade da função defThisPinsAsInput
void IOHandler::defThisPinAsInput(int inputPin)
{
	int _inputPin = inputPin;
	pinMode(_inputPin, INPUT_PULLUP);
	inputPin = _inputPin;
}

//Funcionalidade da função defThesePinsAsinputs
int IOHandler::defThesePinsAsInputs(int inputPins[], int sizeOfArray)
{
	int _sizeOfArray = sizeOfArray;

	if (_sizeOfArray > 0)
	{
		for (int i = 0; i < _sizeOfArray; i++)
		{
			pinMode(inputPins[i], INPUT_PULLUP);
		}
		return _sizeOfArray;
	}
	else
	{
		return -1; 
	}
}

//Funcionalidade da função getStatusInput
bool IOHandler::getStatusInput(int inputPin)
{
	int _inputPin = inputPin;
	inputPin = digitalRead(_inputPin);
	if (inputPin == HIGH)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Funcionalidade da função defThisPinsAsOutput
void IOHandler::defThisPinAsOutput(int outputPin)
{
	int _outputPin = outputPin;
	pinMode(_outputPin, OUTPUT);
	outputPin = _outputPin;
}

//Funcionalidade da função defThesePinsAsOutputs
int IOHandler::defThesePinsAsOutputs(int outputPins[], int sizeOfArray)
{
	int _sizeOfArray = sizeOfArray;

	if (_sizeOfArray > 0)
	{
		for (int i = 0; i < _sizeOfArray; i++)
		{
			pinMode(outputPins[i], OUTPUT);
		}
		return _sizeOfArray;
	}
	else
	{
		return -1; 
	}
}

//Funcionalidade da função setEnergized
void IOHandler::setEnergized(int outputPin)
{
	int _outputPin = outputPin;
	digitalWrite(_outputPin, HIGH);
	outputPin = _outputPin;
}

//Funcionalidade da função setDeEnergized
void IOHandler::setDeEnergized(int outputPin)
{
	int _outputPin = outputPin;
	digitalWrite(_outputPin, LOW);
	outputPin = _outputPin;
}

//Funcionalidade da função changeStateOutput
void IOHandler::changeStateOutput(int outputPin)
{
	int _outputPin = outputPin;
	digitalWrite(_outputPin, !digitalRead(_outputPin));
	outputPin = _outputPin;
}
//Funcionalidade da função changeStateOutput
void IOHandler::writeStatusOnOutput(bool status,int outputPin)
{
	bool _status = status;
	int _outputPin = outputPin;
	if (status)	{
		digitalWrite(_outputPin, HIGH);
	}else{
		digitalWrite(_outputPin, LOW);		
	}
	outputPin = _outputPin;
}