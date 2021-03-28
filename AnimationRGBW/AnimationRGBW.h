//Diretivas para a criação da biblioteca
#ifndef ANIMATIONRGBW_H
#define ANIMATIONRGBW_H

//Inclusão da biblioteca do arduino
#include <Arduino.h>

//Definindo a classe
class AnimationRGBW
{
  public:
	//Construtor da classe
	AnimationRGBW();
	//Métodos da classe
	byte getDinamycRangeOfBrigh(long maxSeconds, long actualSeconds, byte maxValueForThisColor);
	byte pulseColor(long maxSeconds, long actualSeconds, byte maxValueForThisColor);
	byte incrementPixelByTime(long maxSeconds,long actualSeconds,byte maxNumberOfPixels);
	

  private:
	//Variáveis utilizadas na classe
	bool _invertDirectionPC = false;	
	long _memActualSecondsPC = 0;
		
};

#endif