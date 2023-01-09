#pragma once
#include <rev/CANSparkMax.h>
#include <GyroFunctions.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <units/velocity.h>
#include <units/angular_acceleration.h>
#include <units/angular_velocity.h>
#include <units/acceleration.h>

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
	void Drive(double left, double right);
	void DirectDrive(float left, float right);
	double GetRightFrontEncoder();
	double GetLeftFrontEncoder();
	void ResetEncoders();
	units::meter_t RightDistance();
	units::meter_t LeftDistance();
	units::meter_t GetAverageDistance();
	frc::Pose2d GetOdometryPose();
	void UpdateOdometry();
	void ResetOdometry(frc::Pose2d pose);
	GyroFunctions gyro;
	
private:
	float throttle=0.1;
	//these might need to be public?
	int LeftBackNeo = 4;
	int LeftFrontNeo = 5;
	int LeftTopNeo = 6;
	int RightBackNeo = 7;
	int RightFrontNeo = 8;
	int RightTopNeo = 9;
	rev::SparkMaxRelativeEncoder leftFrontEncoder = LeftF.GetEncoder();
	rev::SparkMaxRelativeEncoder rightFrontEncoder = RightF.GetEncoder();
	double rEncoderOffset = 0.0;
	double lEncoderOffset = 0.0;
	double pulsePerMinute = 0.0;
	double wheelRadius = 0.0;
	double pi = 3.142;
	frc::DifferentialDriveKinematics kinematics{17_in};
	frc::Rotation2d gyroRot2d = gyro.GetHeadingRotation2dRIOGryo();
	frc::DifferentialDriveOdometry odometry;
	double distanceConversionFactor = ((2*pi)*wheelRadius);
};