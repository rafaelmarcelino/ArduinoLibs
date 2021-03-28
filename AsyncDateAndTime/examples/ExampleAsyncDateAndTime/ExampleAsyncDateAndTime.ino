#include <IOHandler.h>
#include <OneShot.h>
#include <AsyncDateAndTime.h>

bool selectTest = false;
bool selectTest_OLD = false;
bool statusOfTestInput = false;
bool wasShown = false;

int inputForSelectTest = 13;
int myInputForTest = 12;
int selectWhatIWantTest = 0;
int selectWhatIWantTest_OLD = 0;

IOHandler IOHandler;
OneShot oneShots[1];
AsyncDateAndTime DateAndTime;

void setup()
{
	// put your setup code here, to run once:
	IOHandler.defThisPinAsInput(inputForSelectTest);
	IOHandler.defThisPinAsInput(myInputForTest);
	DateAndTime.setupDateAndTime(2018, 1, 1, 0, 0, 0);
	Serial.begin(9600);
}

void loop()
{
	DateAndTime.generateAsyncClok();
	selectTest = IOHandler.getStatusInput(inputForSelectTest);
	statusOfTestInput = IOHandler.getStatusInput(myInputForTest);

	// put your main code here, to run repeatedly:
	if ((selectTest != selectTest_OLD) & (selectTest == true))
	{
		if (selectWhatIWantTest >= 11)
		{
			selectWhatIWantTest = 0;
		}
		selectWhatIWantTest = selectWhatIWantTest + 1;
		selectTest_OLD = selectTest;
	}
	else
	{
		selectTest_OLD = selectTest;
	}

	//Definition for shown on serial monitor the log
	if (selectWhatIWantTest != selectWhatIWantTest_OLD)
	{
		wasShown = false;
		selectWhatIWantTest_OLD = selectWhatIWantTest;
	}

	switch (selectWhatIWantTest)
	{
	case 1:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getYear");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getYear = ");
			Serial.println(DateAndTime.getYear());
		}
		break;
	case 2:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getMonth");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getMonth = ");
			Serial.println(DateAndTime.getMonth());
		}
		break;
	case 3:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getDay");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getDay = ");
			Serial.println(DateAndTime.getDay());
		}
		break;
	case 4:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getHour");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getHour = ");
			Serial.println(DateAndTime.getHour());
		}
		break;
	case 5:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getMinute");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getMinute = ");
			Serial.println(DateAndTime.getMinute());
		}
	case 6:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getSecond");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getSecond = ");
			Serial.println(DateAndTime.getSecond());
		}
	case 7:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getMilisecond");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getMilisecond = ");
			Serial.println(DateAndTime.getMilisecond());
		}
		break;
	case 8:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getDate");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getDate = ");
			Serial.println(DateAndTime.getDate());
		}
		break;
	case 9:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getTime");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getTime = ");
			Serial.println(DateAndTime.getTime());
		}
		break;
	case 10:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Testing function .getDateAndTime");
		}

		if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
		{
			Serial.print("Value of getDateAndTime = ");
			Serial.println(DateAndTime.getDateAndTime());
		}
		break;
	default:
		if (!wasShown)
		{
			wasShown = true;
			Serial.println("Choose one number on variable selectWhatIWantTest");
		}
	}
}