#include <IOHandler.h>
#include <BlinkPattern.h>
IOHandler bp_IOHandler;
BlinkPattern myBlinkPattern[3];

int myInputs[] = {13};
int myOutputs[] = {14,15,16};
int selectWhatIWantTest = 0;
int selectWhatIWantTest_OLD = 0;

bool selectTest = false;
bool selectTest_OLD = false;
bool wasShown = false;
bool aux_Blink_1s = false;
bool bp_Blink_1s = false;
bool bp_Blink_500ms = false;
bool bp_Blink_250ms = false;

long startCycleTime = 0;
long endCycleTime = 0;
long lastCycleTime = 0;
long baseTime = 1000;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  bp_IOHandler.defThisPinAsInput(myInputs[0]);
  
  bp_IOHandler.defThisPinAsOutput(myOutputs[0]);
  bp_IOHandler.defThisPinAsOutput(myOutputs[1]);
  bp_IOHandler.defThisPinAsOutput(myOutputs[2]);
}

void loop()
{
  selectTest = bp_IOHandler.getStatusInput(myInputs[0]);

  bp_Blink_1s = myBlinkPattern[0].blink_inThisTime(1000);
  bp_Blink_500ms = myBlinkPattern[1].blink_inThisTime(500);
  bp_Blink_250ms = myBlinkPattern[2].blink_inThisTime(250);

  // put your main code here, to run repeatedly:
  if ((selectTest != selectTest_OLD) & (selectTest))
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
      Serial.println("Testing all functions of BlinkPattern");
    }
    bp_IOHandler.writeStatusOnOutput(bp_Blink_1s, myOutputs[0]);
    bp_IOHandler.writeStatusOnOutput(bp_Blink_500ms, myOutputs[1]);
    bp_IOHandler.writeStatusOnOutput(bp_Blink_250ms, myOutputs[2]);

    break;
  default:
    if (!wasShown)
    {
      wasShown = true;
      Serial.println("Choose one number on variable selectWhatIWantTest");
    }
  }
}