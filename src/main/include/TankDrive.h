#pragma once
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/DigitalInput.h>
#include <rev/CANSparkMax.h>

using namespace frc;
class Tankdrive
{
public: 
	Tankdrive();
	void Drive(float left, float right);
	void DirectDrive(float left, float right);
	rev::CANSparkMax LeftF;
	rev::CANSparkMax LeftB;
	rev::CANSparkMax LeftT;
	rev::CANSparkMax RightF;
	rev::CANSparkMax RightB;
	rev::CANSparkMax RightT;
private:
	float throttle;
	int LeftBackNeo = 4;
	int LeftFrontNeo = 5;
	int LeftTopNeo = 6;
	int RightBackNeo = 7;
	int RightFrontNeo = 8;
	int RightTopNeo = 9;
};