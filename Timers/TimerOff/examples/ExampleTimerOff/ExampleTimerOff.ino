#include <IOHandler.h>
#include <TimerOff.h>
bool selectTest = false;
bool selectTest_OLD = false;
bool statusOfTestInput = false;
bool showFirstCycleTimeWhenEquals = false;
bool wasShown = false;

int myOutput = 7;
int inputForSelectTest = 5;
int myInputForTest = 10;
int selectWhatIWantTest = 0;
int selectWhatIWantTest_OLD = 0;

IOHandler myTools;
TimerOff timersOff[1];

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  myTools.defThisPinAsInput(inputForSelectTest);
  myTools.defThisPinAsInput(myInputForTest);
}

void loop()
{
  selectTest = myTools.getStatusInput(inputForSelectTest);
  statusOfTestInput = myTools.getStatusInput(myInputForTest);

  // put your main code here, to run repeatedly:
  if ((selectTest != selectTest_OLD) & (selectTest == true))
  {
    if (selectWhatIWantTest >= 1)
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
  {
    if (!wasShown)
    {
      wasShown = true;
      Serial.println("Testing function .timerOff");
    }
    if (timersOff[0].outputTimerOff(statusOfTestInput,1000))
    {
      Serial.println("Timer Off triggered");
    }
    break;
  }
  default:
    if (!wasShown)
    {
      wasShown = true;
      Serial.println("Choose one number on variable selectWhatIWantTest");
    }
  }
}