
#include "TankDrive.h"

//Need to def variables for throttle based on the constants file
// Convencion: Teleob gets joystick vals, AUTO: feed positive vals

Tankdrive::Tankdrive():
//defines the motors

LeftF(LeftFrontNeo, rev::CANSparkMax::MotorType::kBrushless),
LeftB(LeftBackNeo, rev::CANSparkMax::MotorType::kBrushless),
LeftT(LeftTopNeo, rev::CANSparkMax::MotorType::kBrushless),
RightF(RightFrontNeo, rev::CANSparkMax::MotorType::kBrushless),
RightB(RightBackNeo, rev::CANSparkMax::MotorType::kBrushless),
RightT(RightTopNeo, rev::CANSparkMax::MotorType::kBrushless),

void Tankdrive::Drive(float left, float right){

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
