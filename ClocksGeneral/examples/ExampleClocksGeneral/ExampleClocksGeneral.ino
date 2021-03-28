#include <IOHandler.h>
#include <ClocksGeneral.h>

IOHandler myTools;
ClocksGeneral myClocks;

int myInputs[] = {13};
int selectWhatIWantTest = 0;
int selectWhatIWantTest_OLD = 0;

bool selectTest = false;
bool selectTest_OLD = false;
bool wasShown = false;

long startCycleTime = 0;
long endCycleTime = 0;
long lastCycleTime = 0;
long baseTime = 1000;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	myTools.defThisPinAsInput(myInputs[0]);
}

void loop() {
	startCycleTime = millis();
	getStatusOfMyInputs();
	// put your main code here, to run repeatedly:
	if ((selectTest != selectTest_OLD)&(selectTest)){
		if (selectWhatIWantTest >= 2 ){
			selectWhatIWantTest = 0;
		}
		selectWhatIWantTest = selectWhatIWantTest +1;
		selectTest_OLD = selectTest;
	}
	else{
		selectTest_OLD = selectTest;
	}
	
	//Definition for shown on serial monitor the log
	if (selectWhatIWantTest != selectWhatIWantTest_OLD){
		wasShown = false;
		selectWhatIWantTest_OLD = selectWhatIWantTest;
	}
	
	switch (selectWhatIWantTest) {
		case 1:
		if (!wasShown) {
			wasShown = true;
			Serial.println("Testing function .getClockInThisTime");
		}
		if(myClocks.getClockInThisTime(baseTime)){
			Serial.print("Triggered at ");			
			Serial.println(millis());
		}
		break;
		case 2:
		if (!wasShown) {
			wasShown = true;
			Serial.println("Testing function .getLastCycleTime");
		}
		Serial.print("Last cycle time in ms: ");
		delay(200);
		Serial.println(myClocks.getLastCycleTime(startCycleTime));
		break;
		default:
		if (!wasShown){
				wasShown = true;
				Serial.println("Choose one number on variable selectWhatIWantTest");
			}
			
		}
	}
	
	//Funções gerais
	void getStatusOfMyInputs(){
		selectTest = myTools.getStatusInput(myInputs[0]);	
	}
	
