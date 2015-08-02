/*HUB-ee BMD Arduino Lib
Provides an object for a single motor using the BMD motor driver, includes optional standby control.
Designed for the BMD or BMD-S motor driver which uses the Toshiba TB6593FNG motor driver IC
Created by Creative Robotics Ltd in 2012.
Released into the public domain.
*/
#ifndef HUBeeBMDWheel_H
#define HUBeeBMDWheel_H
#include "Arduino.h"
//#define Debug

class HUBeeBMDWheel
{
	public:

		HUBeeBMDWheel();
		HUBeeBMDWheel(int In1Pin, int In2Pin, int PWMPin);
		HUBeeBMDWheel(int In1Pin, int In2Pin, int PWMPin, int STBYPin);
		void setupPins(int In1Pin, int In2Pin, int PWMPin);
		void setupPins(int In1Pin, int In2Pin, int PWMPin, int STBYPin);
		void setBrakeMode(boolean brakeMode);
		void stopMotor();
		void setStandbyMode(boolean standbyMode);
		void setDirectionMode(boolean direction);
		boolean getDirectionMode();
		void setMotorPower(int MPower);
		int getMotorPower();
		void setQPin(int Q1PinA1, int Q1PinB2);
		void HUBW_readQ();
		int HUB_steps();
		int getQPins ();
	
	private:
		void initialise();
		void setMotor();
		int motorPower;
		int rawPower;
		long int steps;
		boolean motorDirection;
		boolean motorBrakeMode;
		boolean motorStandbyMode;
		boolean motorDirectionMode;
		//pin assignments
		int IN1;
		int IN2;
		int PWM;
		int STBY;
		int Q1PinA;
		int Q1PinB;
};
#endif

