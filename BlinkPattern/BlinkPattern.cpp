//Definição das funcionalidades da classe ClocksGeneral

#include "BlinkPattern.h"

//Construtor
BlinkPattern::BlinkPattern() {
}

//Funcionalidade da função blink_inThisTime
bool BlinkPattern::blink_inThisTime(long timeWishBlink)
{
	_actualStatusClock = _clocksCustom.getClockInThisTime(timeWishBlink);
	if (_actualStatusClock)
	{
		_actualStatusOutput = !_actualStatusOutput;
	}
	return _actualStatusOutput;
}