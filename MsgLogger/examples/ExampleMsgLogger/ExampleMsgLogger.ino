#include <IOHandler.h>
#include <OneShot.h>
#include <MsgLogger.h>

bool selectTest = false;
bool selectTest_OLD = false;
bool statusOfTestInput = false;
bool statusOneShot = false;
bool wasShown = false;

int inputForSelectTest = 13;
int myInputForTest = 12;
int selectWhatIWantTest = 0;
int selectWhatIWantTest_OLD = 0;

IOHandler IOHandler;
OneShot oneShots[1];
MsgLogger Logger;

void setup()
{
  // put your setup code here, to run once:
  IOHandler.defThisPinAsInput(inputForSelectTest);
  IOHandler.defThisPinAsInput(myInputForTest);
  Logger.startMsgLogger();
  Logger.setupInitialDateAndTimeOfMsgLogger(2018,1,18,13,43,0);

}

void loop()
{
  Logger.runMsgLogger();
  selectTest = IOHandler.getStatusInput(inputForSelectTest);
  statusOfTestInput = IOHandler.getStatusInput(myInputForTest);
  statusOneShot = oneShots[0].oneShotRisingEdge(statusOfTestInput);

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
      Serial.println("Testing function .generateMessageWithBoolValue");
    }

    if (statusOneShot)
    {
      Logger.generateMessage("Value of bool variable now =",statusOneShot);
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