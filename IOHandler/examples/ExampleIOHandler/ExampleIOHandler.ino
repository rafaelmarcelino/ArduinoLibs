#include <IOHandler.h>
#include <ClocksGeneral.h>

bool selectTest = false;
bool selectTest_OLD = false;
bool statusOfTestInput = false;
bool showFirstCycleTimeWhenEquals = false;
bool wasShown = false;

int myOutput = 14;
int inputForSelectTest = 13;
int myInputForTest = 12;
int selectWhatIWantTest = 0;
int selectWhatIWantTest_OLD = 0;

long startCycleTime = 0;
long lastCycleTime_OLD = 0;
long lastCycleTime = 0;
long auxChangeOutput = 0;

IOHandler myTools;
ClocksGeneral myClocks;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  myTools.defThisPinAsOutput(myOutput);
  myTools.defThisPinAsInput(inputForSelectTest);
  myTools.defThisPinAsInput(myInputForTest);
}

void loop()
{
  startCycleTime = millis();
  selectTest = myTools.getStatusInput(inputForSelectTest);
  statusOfTestInput = myTools.getStatusInput(myInputForTest);

  // put your main code here, to run repeatedly:
  if ((selectTest != selectTest_OLD) & (selectTest))
  {
    if (selectWhatIWantTest >= 4)
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
      Serial.println("Testing function .setEnergized");
    }
    myTools.setEnergized(myOutput);
    break;
  case 2:
    if (!wasShown)
    {
      wasShown = true;
      Serial.println("Testing function .setDeEnergized");
    }
    myTools.setDeEnergized(myOutput);
    break;
  case 3:
    if (!wasShown)
    {
      wasShown = true;
      Serial.println("Testing function .changeStateOutput");
    }
    if (millis() >= (auxChangeOutput + 1000))
    {
      myTools.changeStateOutput(myOutput);
      auxChangeOutput = millis();
      Serial.println("Output changed state");
    }
    break;
  case 4:
    if (!wasShown)
    {
      wasShown = true;
      Serial.println("Testing function .getLastCycleTime");
    }
    lastCycleTime = myClocks.getLastCycleTime(startCycleTime);
    if ((lastCycleTime != lastCycleTime_OLD) || (lastCycleTime == lastCycleTime_OLD && !showFirstCycleTimeWhenEquals))
    {
      Serial.print("Last cycle time in: ");
      Serial.print(lastCycleTime);
      Serial.println(" ms.");

      lastCycleTime_OLD = lastCycleTime;
      showFirstCycleTimeWhenEquals = true;
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
