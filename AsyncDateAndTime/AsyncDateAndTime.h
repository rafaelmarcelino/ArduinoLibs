//Diretivas para a criação da biblioteca
#ifndef ASYNCDATEANDTIME_H
#define ASYNCDATEANDTIME_H

//Inclusão da biblioteca do arduino
#include <Arduino.h>

//Definindo a classe
class AsyncDateAndTime
{
public:
	//Construtor da classe
	AsyncDateAndTime();
	//Métodos da classe
	void setupDateAndTime(unsigned int year,byte month,byte day,
					byte hour,byte minute,byte second);
	void generateAsyncClok();
	void setYear(unsigned int year);
	unsigned int getYear();
	void setMonth(byte month);
	byte getMonth();
	void setDay(byte day);
	byte getDay();	
	String getDate();
	void setHour(byte hour);
	byte getHour();
	void setMinute(byte minute);
	byte getMinute();
	void setSecond(byte second);
	byte getSecond();
	void setMilisecond(unsigned int milisecond);
	unsigned int getMilisecond();
	String getTime();
	String getDateAndTime();
		
private:
	//Constantes utilizadas na classe
	const unsigned int DEFAULT_YEAR = 2018;
	const byte DEFAULT_MIN_MONTH_DAY = 1;
	const byte MAX_MONTH = 12;
	const byte MAX_DAY = 31;

	const byte DEFAULT_MIN_HOUR_MINUTE_SECOND_MILISECOND = 0;
	const byte MAX_HOUR = 23;
	const byte MAX_MINUTE = 59;
	const byte MAX_SECOND = 59;
	const unsigned int MAX_MILISECOND = 1000;
	const unsigned long OVERFLOW_LONG = 4294967295;
	

	//Variáveis utilizadas na classe
	unsigned int _actualYear;
	unsigned int _actualMonth;
	unsigned int _actualDay;
	unsigned int _index;
	byte _actualHour;
	byte _actualMinute;
	byte _actualSecond;
	byte _auxByte;
	unsigned int _actualMiliSecond;
	unsigned int _auxUnsignedInt;


	unsigned long _timeInMs = 0;
	unsigned long _memTimeInMs = 0;
	unsigned long _offsetForTimeInMs = 0;
	unsigned long _auxOverflowLong = 0;
	bool _flagOverflowLong = false;
	bool _flagChangedDay = false;
	bool _flagChangedMonth = false;
	bool _flagChangedYear = false;
	bool _flagChangedHour = false;
	bool _flagChangedMinute = false;
	bool _flagChangedSecond = false;
	String _milisecond;
	String _second;
	String _minute;
	String _hour;
	String _year;
	String _month;
	String _day;
};


#endif