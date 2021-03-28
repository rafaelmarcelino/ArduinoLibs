#include <IOHandler.h>
#include <OneShot.h>

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

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  IOHandler.defThisPinAsInput(inputForSelectTest);
  IOHandler.defThisPinAsInput(myInputForTest);
}

void loop()
{
  selectTest = IOHandler.getStatusInput(inputForSelectTest);
  statusOfTestInput = IOHandler.getStatusInput(myInputForTest);

  // put your main code here, to run repeatedly:
  if ((selectTest != selectTest_OLD) & (selectTest == true))
  {
    if (selectWhatIWantTest >= 2)
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
      Serial.println("Testing function .oneShotRisingEdge");
    }

    if (oneShots[0].oneShotRisingEdge(statusOfTestInput))
    {
       Serial.println("oneShotRisingEdge triggered");
    }
    break;
  case 2:
    if (!wasShown)
    {
      wasShown = true;
      Serial.println("Testing function .oneShotFallingEdge");
    }

    if (oneShots[0].oneShotFallingEdge(statusOfTestInput))
    {
      Serial.println("oneShotFallingEdge triggered");
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