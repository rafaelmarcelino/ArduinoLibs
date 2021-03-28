//Diretivas para a criação da biblioteca
#ifndef IOHANDLER_H
#define IOHANDLER_H

//Inclusão da biblioteca do arduino
#include <Arduino.h>

//Definindo a classe
class IOHandler
{
public:
	//Construtor da classe
	IOHandler();
	//Métodos da classe
	void defThisPinAsInput(int inputPin);
	int defThesePinsAsInputs(int inputPins[],int sizeOfArray);
	bool getStatusInput(int inputPin);

	void defThisPinAsOutput(int outputPin);
	int defThesePinsAsOutputs(int outputPins[],int sizeOfArray);
	void setEnergized(int outputPin);
	void setDeEnergized(int outputPin);
	void changeStateOutput(int outputPin);
	void writeStatusOnOutput(bool status, int outputPin);

private:
	//Variáveis utilizadas na classe
};


#endif