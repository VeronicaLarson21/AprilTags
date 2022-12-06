#pragma once
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/DigitalInput.h>
#include <rev/CANSparkMax.h>
//Our includees here provide the needed functions for motor control
using namespace frc;
class Tankdrive
{
public: 
	//This creates a constructor to initalize objects in, here it is just used for motor objects but we use it for other things on occasion
	Tankdrive();
	//This is creating instances of the motor controller class for the motor contrllers we use for each motor in our drivetrain
	rev::CANSparkMax LeftF;
	rev::CANSparkMax LeftB;
	rev::CANSparkMax LeftT;
	rev::CANSparkMax RightF;
	rev::CANSparkMax RightB;
	rev::CANSparkMax RightT;
	//This initialzies our two driving functions, one that takes a drive input and multiplys it by the throttle and one that just imparts a number
	//Void is the type of a function
	//Functions are declared like so void nameOfFunc(argument type argument)
	//Both our drive functions take two arguments as they are tankdrive style with two independent sides of wheels
	void Drive(float left, float right);
	void DirectDrive(float left, float right);
private:
	//This double defines the speed of the robot that is applyed to the joystick inputs
	double throttle=0.1;
};