//Diretivas para a criação da biblioteca
#ifndef BLINKPATTERN_H
#define BLINKPATTERN_H

//Inclusão da biblioteca do arduino
#include <Arduino.h>
#include <ClocksGeneral.h>

//Definindo a classe
class BlinkPattern
{
public:
	//Construtor da classe
	BlinkPattern();
	//Métodos da classe
	bool blink_inThisTime(long timeWishBlink);
	
	
private:
	//Variáveis utilizadas na classe
	ClocksGeneral _clocksCustom;
	bool _actualStatusOutput = false;
	bool _actualStatusClock = false;

};



#endif