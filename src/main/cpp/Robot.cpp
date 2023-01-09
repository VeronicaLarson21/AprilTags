// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
   
 photonlib::PhotonPipelineResult result = camera.GetLatestResult();
 //m_odometry.Update(gyro.GetHeadingRIOGyro());
  if (stick1.GetTrigger() && result.HasTargets()) {
      units::meter_t range = photonlib::PhotonUtils::CalculateDistanceToTarget(CAMERA_HEIGHT, TARGET_HEIGHT, CAMERA_PITCH,units::degree_t{result.GetBestTarget().GetPitch()});
      SmartDashboard::PutNumber("targets?",1);

      fowardSpeed = -controllerFrontBack.Calculate(range.value(),GOAL_RANGE_METERS.value());
      rotationSpeed = -controllerSideSide.Calculate(result.GetBestTarget().GetYaw(), 0);

      //frc::ChassisSpeeds chassisSpeeds(fowardSpeed,0,rotationSpeed);
      //tankdrive.Drive(basespeed-rotationSpeed,basespeed+rotationSpeed);
      //tankdrive.DirectDrive(-fowardSpeed,-fowardSpeed);
      units::velocity::meters_per_second_t fowardSpeedmps{fowardSpeed};
      units::angular_velocity::radians_per_second_t rotationSpeedmps{fowardSpeed};
      //auto fowardSpeedmps = fowardSpeed_mps;
      
      //for kinematics testing just going to use left right to test the correct movement
      //ChassisSpeeds chassisSpeeds{0_mps,0_mps,rotationSpeedmps};
      //auto [left, right] = kinematics.ToWheelSpeeds(chassisSpeeds);
      //tankdrive.Drive(left.value(), right.value());
      
      SmartDashboard::PutNumber("Range Total",range.value());
      SmartDashboard::PutNumber("Diffrence between desired and total",range.value()-GOAL_RANGE_METERS.value());
      
    } else if(stick1.GetTrigger()) {
      SmartDashboard::PutNumber("targets?",0);
      // If we have no targets just manual drive
      tankdrive.Drive(stick1.GetY(), stick2.GetY());

    }

  } 


  

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}
#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
