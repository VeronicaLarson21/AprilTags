#pragma once
#include <photonlib/PhotonCamera.h>
#include <frc/TimedRobot.h>
#include <frc/controller/PIDController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <units/angle.h>
#include <units/length.h>
#include <frc/TimedRobot.h>
#include "TankDrive.h"
#include <frc/Joystick.h>

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

  //will need to be tuned yay *sarcastic*
  frc2::PIDController controller{.1, 0, 0};
  //need to figure out what LL camera would be called
  photonlib::PhotonCamera camera{"photonvision"};
  Tankdrive tankdrive;
  Joystick stick1{0}; 
};
