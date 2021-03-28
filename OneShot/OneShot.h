//Diretivas para a criação da biblioteca
#ifndef ONESHOT_H
#define ONESHOT_H

//Inclusão da biblioteca do arduino
#include <Arduino.h>

//Definindo a classe
class OneShot
{
public:
	//Construtor da classe
	OneShot();
	//Métodos da classe
	bool oneShotRisingEdge(bool statusOfInput);
	bool oneShotFallingEdge(bool statusOfInput);

private:
	//Variáveis utilizadas na classe
	bool _statusOfInput_OneShotRisingEdge = false;
	bool _statusOfInput_OneShotFallingEdge = false;
	
};

#endif