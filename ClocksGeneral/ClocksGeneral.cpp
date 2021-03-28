//Definição das funcionalidades da classe ClocksGeneral

#include "ClocksGeneral.h"

//Construtor
ClocksGeneral::ClocksGeneral(){}

//Funcionalidade da função getLastCycleTime
long ClocksGeneral::getLastCycleTime(long startCycletime){
	long _startCycleTime = startCycletime;
	long _endCycleTime = millis();
	if ((_endCycleTime - _startCycleTime)< 0){
		return -1;
	}else{
		return (_endCycleTime - _startCycleTime);
	}
}

//Funcionalidade da função getClockInThisTime
bool ClocksGeneral::getClockInThisTime(long baseTime){
	_actualTimeInMs = millis();
	if(_lastTimeTriggered <= 0){
		_lastTimeTriggered = _actualTimeInMs;
	}
	if((_actualTimeInMs - (_lastTimeTriggered - _offsetForWrongTime)) >= baseTime){
		if (_offsetForWrongTime <= 0){
			_offsetForWrongTime = _actualTimeInMs - (_lastTimeTriggered + baseTime);			
		}else{
			_offsetForWrongTime = _actualTimeInMs - ((_lastTimeTriggered - _offsetForWrongTime) + baseTime);						
		}
		_lastTimeTriggered = _actualTimeInMs;
		return  true;
	}else{
		return false;
	}
}