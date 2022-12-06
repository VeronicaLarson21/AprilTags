
#include "TankDrive.h"
//This includes our header files so all of our definitions carry over to this file

//This is the constructor where we intitialize the motor objects
Tankdrive::Tankdrive():
//The guide for initializing motor objects is motorClassInitializedName(Port Number, Type of Motor)
//For the NEO motors we use in the drivetrain the type is Brushless
LeftF(5, rev::CANSparkMax::MotorType::kBrushless),
LeftB(4, rev::CANSparkMax::MotorType::kBrushless),
LeftT(6, rev::CANSparkMax::MotorType::kBrushless),
RightF(8, rev::CANSparkMax::MotorType::kBrushless),
RightB(7, rev::CANSparkMax::MotorType::kBrushless),
RightT(9, rev::CANSparkMax::MotorType::kBrushless)
{}

//This defines what our Drive function actually does when we call it
void Tankdrive::Drive(float left, float right){

	//This if statement takes the joystick inputs and limits them to between -1 and 1, as thats the input the motor controllers take.
	if(left > 1.0)
		left = 1.0;
	else if(left < -1.0)
		left = -1.0;
	if(right > 1)
		right = 1.0;
	else if(right < -1.0)
		right = -1.0;
	//This sets the motors to the thresholded speed given, like this motorClassInitializedName.Set(Speed)
	//The left side is flipped in direction because when positive is defined as clockwise, when you turn the motor sidewase clockwise only goes foward for the right side, and goes backward for the left side, thus the inversion
	LeftF.Set(left * throttle  * -1.0);
	LeftB.Set(left * throttle  * -1.0);		
	LeftT.Set(left * throttle  * -1.0);
	RightF.Set(right * throttle);
	RightB.Set(right * throttle);
	RightT.Set(right * throttle);
}


//DirectDrive looks very similar to Drive but notice there is no throttle multiplyer attached to the speed
//This is used when the speed is predetermined and has no need to change, as often we will make throttle a variable value
void Tankdrive::DirectDrive(float left, float right)
{
	if(left > 1.0)
		left = 1.0;
	else if(left < -1.0)
		left = -1.0;
	if(right > 1.0)
		right = 1.0;
	else if(right < -1.0)
		right = -1.0;

	LeftF.Set(left);
	LeftB.Set(left);		
	LeftT.Set(left);

	RightF.Set(right*-1.0);
	RightB.Set(right*-1.0);
	RightT.Set(right*-1.0);
}
