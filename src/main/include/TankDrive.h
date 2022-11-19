#pragma once
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/DigitalInput.h>
#include <rev/CANSparkMax.h>

using namespace frc;
class Tankdrive
{
public: 
	Tankdrive();
	rev::CANSparkMax LeftF;
	rev::CANSparkMax LeftB;
	rev::CANSparkMax LeftT;
	rev::CANSparkMax RightF;
	rev::CANSparkMax RightB;
	rev::CANSparkMax RightT;
	void Drive(float left, float right);
	void DirectDrive(float left, float right);
private:
	float throttle;
};