#include <HUBeeBMDWheel.h>

//-----zona de variabile globale
//start
int HUBW1_Q1APin = 2; // atasat intreruperii int.0
int HUBW1_Q1BPin = 7;

int HUBW2_Q1APin = 3; // atasat intreruperii int.1
int HUBW2_Q1BPin = 4;

int HUBW1_IN1 = 8;
int HUBW1_IN2 = 11;
int HUBW1_PWM = 9;

int HUBW2_IN1 = 12;
int HUBW2_IN2 = 13;
int HUBW2_PWM = 10;
// end

//-----initializare obiecte
//start
HUBeeBMDWheel HUBWheel1(HUBW1_IN1,HUBW1_IN2,HUBW1_PWM);    // .setupPins(INT1,INT2,PWM);
HUBeeBMDWheel HUBWheel2(HUBW2_IN1,HUBW2_IN2,HUBW2_PWM);   // .setupPins(INT1,INT2,PWM);
// end

void setup() {

	#ifdef Debug
	Serial.begin(115200);
	Serial.println("Starting connection. Please wait...");
	delay(100);
	Serial.println("Data from the MCU:");
	#endif
	
	//-----zona de initializare pini
	//start
	pinMode(HUBW1_Q1APin, INPUT_PULLUP);
	pinMode(HUBW1_Q1BPin, INPUT_PULLUP);
	pinMode(HUBW2_Q1APin, INPUT_PULLUP);
	pinMode(HUBW2_Q1BPin, INPUT_PULLUP);

	HUBWheel1.setQPin(HUBW1_Q1APin, HUBW1_Q1BPin);
	HUBWheel2.setQPin(HUBW2_Q1APin, HUBW2_Q1BPin);
	//end

	//-----atasare intreruperi pentru quadraturi
	//start
	attachInterrupt(0, read_HUBW1Q, CHANGE);
	attachInterrupt(1, read_HUBW2Q, CHANGE);
	//end
};

void loop() {
};

//-----small hack to accept objects in attachInterrupt function
//start
void read_HUBW1Q()
{
	HUBWheel1.HUBW_readQ();
};

void read_HUBW2Q()
{
	HUBWheel2.HUBW_readQ();
};
//end