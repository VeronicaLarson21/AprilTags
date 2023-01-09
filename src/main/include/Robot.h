#pragma once
#include <photonlib/PhotonCamera.h>
#include <photonlib/PhotonUtils.h>
#include <frc/controller/PIDController.h>
#include <frc/drive/DifferentialDrive.h>
#include <units/angle.h>
#include <units/length.h>
#include <frc/TimedRobot.h>
#include "TankDrive.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "GyroFunctions.h"



class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  //will need to be tuned yay *sarcastic*
  frc2::PIDController controllerSideSide{.1, 0, 0};
  //semi easy to just yknow see but these are hight of cam and hight of what the cams looking at
  const units::meter_t CAMERA_HEIGHT = 23_in;
  const units::meter_t TARGET_HEIGHT = 6.25_ft;
  //angle of camera from horizontal, i assume horizontal at the hight its at
  const units::radian_t CAMERA_PITCH = 43.2_deg;
  //how far from target we want
  const units::meter_t GOAL_RANGE_METERS = 4_ft;
  //more tuning! 
  //i want to get left and right working first before i do drive ups so this pid will sit for a hot sec
  //why does the front back need P and D? 
  //wait D is zero lol why did it need to be consted?
  //ig tuning we will figure out
  const double P_GAIN = 0.1;
  const double D_GAIN = 0.0;
  frc2::PIDController controllerFrontBack{P_GAIN, 0.0, D_GAIN};
  //need to figure out what LL camera would be called
  photonlib::PhotonCamera camera{"gloworm"};
  Tankdrive tankdrive;
  GyroFunctions gyro;
  Joystick stick1{0}; 
  Joystick stick2{1};
  double basespeed = 0.01;
  double rotationSpeed; 
  double fowardSpeed; 
  //Change to real distance between wheel vals
};
