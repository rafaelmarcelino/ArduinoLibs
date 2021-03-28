//Definição das funcionalidades da classe AsyncDateAndTime

#include "AsyncDateAndTime.h"

//Construtor
AsyncDateAndTime::AsyncDateAndTime() {}

//Funcionalidade da função generateAsyncClock
void AsyncDateAndTime::generateAsyncClok()
{
	_timeInMs = millis();

	if (_timeInMs != _memTimeInMs)
	{
		//Verifica se houve estouro da função millis()
		if (_timeInMs < _memTimeInMs)
		{
			_auxOverflowLong = ((OVERFLOW_LONG - _memTimeInMs) + _timeInMs);
			_flagOverflowLong = true;
		}
		//Contando os milisegundos e o offset de segundos para atualização dos milisegundos
		if (AsyncDateAndTime::getMilisecond() < MAX_MILISECOND)
		{
			if (!_flagOverflowLong)
			{
				AsyncDateAndTime::setMilisecond(_timeInMs - _offsetForTimeInMs);
			}
			else
			{
				_auxUnsignedInt = AsyncDateAndTime::getMilisecond() + _auxOverflowLong;
				AsyncDateAndTime::setMilisecond(_auxUnsignedInt);
				_auxUnsignedInt = 0;
				_flagOverflowLong = false;
			}
		}
		//Contando os milisegundos e o offset de milisegundos para atualização dos segundos
		if (AsyncDateAndTime::getMilisecond() >= MAX_MILISECOND)
		{
			_offsetForTimeInMs += MAX_MILISECOND;
			AsyncDateAndTime::setMilisecond(_timeInMs - _offsetForTimeInMs);
			_auxByte = AsyncDateAndTime::getSecond();
			_auxByte++;
			AsyncDateAndTime::setSecond(_auxByte);

			// Atualização das flags de minutos, segundos e dia
			if (AsyncDateAndTime::getSecond() == MAX_SECOND)
			{
				_flagChangedMinute = true;
			}
			if ((AsyncDateAndTime::getMinute() == MAX_MINUTE) && _flagChangedMinute)
			{
				_flagChangedHour = true;
			}
			if ((AsyncDateAndTime::getHour() == MAX_HOUR) && (_flagChangedHour) && (_flagChangedMinute))
			{
				_flagChangedDay = true;
			}

			_auxByte = 0;
		}
		//Contando os minutos e redefinindo os segundos
		if ((AsyncDateAndTime::getSecond() == DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND) && _flagChangedMinute)
		{
			_auxByte = AsyncDateAndTime::getMinute();
			_auxByte++;
			AsyncDateAndTime::setMinute(_auxByte);
			_auxByte = 0;
			_flagChangedMinute = false;
		}
		//Contando as horas e redefinindo os minutos
		if ((AsyncDateAndTime::getMinute() == DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND) && _flagChangedHour)
		{
			_auxByte = AsyncDateAndTime::getHour();
			_auxByte++;
			AsyncDateAndTime::setHour(_auxByte);
			_auxByte = 0;
			_flagChangedHour = false;
		}
		_memTimeInMs = _timeInMs;
	}

	//Definindo mudança do dia
	if ((AsyncDateAndTime::getHour() == DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND) && _flagChangedDay)
	{
		if (AsyncDateAndTime::getDay() < MAX_DAY)
		{
			_auxByte = AsyncDateAndTime::getDay();
			_auxByte++;
			AsyncDateAndTime::setDay(_auxByte);
			_auxByte = 0;
		}
		else
		{
			AsyncDateAndTime::setDay(DEFAULT_MIN_MONTH_DAY);
			_flagChangedMonth = true;
		}
		_flagChangedDay = false;
	}

	//Definindo mudança do mês
	if (_flagChangedMonth)
	{
		if (AsyncDateAndTime::getMonth() < MAX_MONTH)
		{
			_auxByte = AsyncDateAndTime::getMonth();
			_auxByte++;
			AsyncDateAndTime::setMonth(_auxByte);
			_auxByte = 0;
		}
		else
		{
			AsyncDateAndTime::setMonth(DEFAULT_MIN_MONTH_DAY);
			_flagChangedYear = true;
		}
		_flagChangedMonth = false;
	}

	//Definindo mudança do ano
	if (_flagChangedYear)
	{
		_auxUnsignedInt = AsyncDateAndTime::getYear();
		_auxUnsignedInt++;
		AsyncDateAndTime::setYear(_auxUnsignedInt);
		_auxUnsignedInt = 0;
		_flagChangedYear = false;
	}
}

//Funcionalidade da função setupDateAndTime
void AsyncDateAndTime::setupDateAndTime(unsigned int year, byte month, byte day,
										byte hour, byte minute, byte second)
{
	// Definindo o ano
	AsyncDateAndTime::setYear(year);
	//Definindo o mês
	AsyncDateAndTime::setMonth(month);
	//Definindo o dia
	AsyncDateAndTime::setDay(day);
	// Definindo hora
	AsyncDateAndTime::setHour(hour);
	//Definindo o minuto
	AsyncDateAndTime::setMinute(minute);
	//Definindo o segundo
	AsyncDateAndTime::setSecond(second);
	//Definindo milisegundos
	AsyncDateAndTime::setMilisecond(DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND);
}

//Funcionalidade da função setYear
void AsyncDateAndTime::setYear(unsigned int year)
{
	if (year >= DEFAULT_YEAR)
	{
		_actualYear = year;
	}
	else
	{
		_actualYear = DEFAULT_YEAR;
	}
}
//Funcionalidade da função getYear
unsigned int AsyncDateAndTime::getYear()
{
	return _actualYear;
}
//Funcionalidade da função setMonth
void AsyncDateAndTime::setMonth(byte month)
{
	if ((month >= DEFAULT_MIN_MONTH_DAY) && (month <= MAX_MONTH))
	{
		_actualMonth = month;
	}
	else
	{
		_actualMonth = DEFAULT_MIN_MONTH_DAY;
	}
}
//Funcionalidade da função getMonth
byte AsyncDateAndTime::getMonth()
{
	return _actualMonth;
}
//Funcionalidade da função setDay
void AsyncDateAndTime::setDay(byte day)
{
	if ((day >= DEFAULT_MIN_MONTH_DAY) && (day <= MAX_DAY))
	{
		_actualDay = day;
	}
	else
	{
		_actualDay = DEFAULT_MIN_MONTH_DAY;
	}
}
//Funcionalidade da função getDay
byte AsyncDateAndTime::getDay()
{
	return _actualDay;
}
//Funcionalidade da função getDate
String AsyncDateAndTime::getDate()
{
	_year = String(AsyncDateAndTime::getYear());
	_month = String(AsyncDateAndTime::getMonth());
	_day = String(AsyncDateAndTime::getDay());

	return _year + '-' + _month + '-' + _day;
}
//Funcionalidade da função setHour
void AsyncDateAndTime::setHour(byte hour)
{
	if ((hour >= DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND) && (hour <= MAX_HOUR))
	{
		_actualHour = hour;
	}
	else
	{
		_actualHour = DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND;
	}
}
//Funcionalidade da função getHour
byte AsyncDateAndTime::getHour()
{
	return _actualHour;
}
//Funcionalidade da função setMinute
void AsyncDateAndTime::setMinute(byte minute)
{
	if ((minute >= DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND) && (minute <= MAX_MINUTE))
	{
		_actualMinute = minute;
	}
	else
	{
		_actualMinute = DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND;
	}
}
//Funcionalidade da função getminute
byte AsyncDateAndTime::getMinute()
{
	return _actualMinute;
}
//Funcionalidade da função setSecond
void AsyncDateAndTime::setSecond(byte second)
{
	if ((second >= DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND) && (second <= MAX_SECOND))
	{
		_actualSecond = second;
	}
	else
	{
		_actualSecond = DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND;
	}
}
//Funcionalidade da função getSecond
byte AsyncDateAndTime::getSecond()
{
	return _actualSecond;
}
//Funcionalidade da função setSecond
void AsyncDateAndTime::setMilisecond(unsigned int milisecond)
{
	_actualMiliSecond = milisecond;
}
//Funcionalidade da função getMilisecond
unsigned int AsyncDateAndTime::getMilisecond()
{
	return _actualMiliSecond;
}
//Funcionalidade da função getTime
String AsyncDateAndTime::getTime()
{

	_hour = String(AsyncDateAndTime::getHour());
	_minute = String(AsyncDateAndTime::getMinute());
	_second = String(AsyncDateAndTime::getSecond());
	_milisecond = String(AsyncDateAndTime::getMilisecond());

	return _hour + ':' + _minute + ':' + _second + ':' + _milisecond;
}
//Funcionalidade da função getDateAndTime
String AsyncDateAndTime::getDateAndTime()
{
	return AsyncDateAndTime::getDate() + '|' + AsyncDateAndTime::getTime();
}
