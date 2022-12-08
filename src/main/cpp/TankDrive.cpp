
#include "TankDrive.h"

//Need to def variables for throttle based on the constants file
// Convencion: Teleob gets joystick vals, AUTO: feed positive vals

Tankdrive::Tankdrive():
//defines the motors

//some reason this struct is being finkicky about passing a variable to the port nums. dont know why but it works this way i think its a issue with a constant vs a inst ill look later
LeftF(5, rev::CANSparkMax::MotorType::kBrushless),
LeftB(4, rev::CANSparkMax::MotorType::kBrushless),
LeftT(6, rev::CANSparkMax::MotorType::kBrushless),
RightF(8, rev::CANSparkMax::MotorType::kBrushless),
RightB(7, rev::CANSparkMax::MotorType::kBrushless),
RightT(9, rev::CANSparkMax::MotorType::kBrushless)
{}

void Tankdrive::Drive(double left, double right){

	// Limit left and right inputs to between -1 and 1
	if(left > 1.0)
		left = 1.0;
	else if(left < -1.0)
		left = -1.0;
	if(right > 1)
		right = 1.0;
	else if(right < -1.0)
		right = -1.0;
	LeftF.Set(left * throttle  * -1.0);
	LeftB.Set(left * throttle  * -1.0);		// becuase joystick values of inversed!!!!
	LeftT.Set(left * throttle  * -1.0);
	RightF.Set(right * throttle);
	RightB.Set(right * throttle);
	RightT.Set(right * throttle);
}


//directly drives no joystick input, can be used by a computer
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
	LeftB.Set(left);		// becuase joystick values of inversed!!!!
	LeftT.Set(left);

	RightF.Set(right*-1.0);
	RightB.Set(right*-1.0);
	RightT.Set(right*-1.0);
}
