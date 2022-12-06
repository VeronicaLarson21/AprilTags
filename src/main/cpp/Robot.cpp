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
//this code is simple right left adjustment based on yaw
  if (stick1.GetTrigger() && result.HasTargets()) {

      SmartDashboard::PutNumber("targets?",1);
    // Vision-alignment mode

    // Query the latest result from PhotonVision

    
      // Rotation speed is the output of the PID controller

      rotationSpeed = -controllerSideSide.Calculate(result.GetBestTarget().GetYaw(), 0);
      tankdrive.Drive(basespeed-rotationSpeed,basespeed+rotationSpeed);
    
       units::meter_t range = photonlib::PhotonUtils::CalculateDistanceToTarget(
          CAMERA_HEIGHT, TARGET_HEIGHT, CAMERA_PITCH,
          units::degree_t{result.GetBestTarget().GetPitch()});
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
