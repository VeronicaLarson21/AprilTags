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

  double forwardSpeed = -xboxController.GetRightY();
  double rotationSpeed;
  
  if (xboxController.GetAButton()) {

    // Vision-alignment mode

    // Query the latest result from PhotonVision

    photonlib::PhotonPipelineResult result = camera.GetLatestResult();


    if (result.HasTargets()) {

      // Rotation speed is the output of the PID controller

      rotationSpeed = -controller.Calculate(result.GetBestTarget().GetYaw(), 0);

    } else {

      // If we have no targets, stay still.

      rotationSpeed = 0;

    }

  } else {

    // Manual Driver Mode

    rotationSpeed = xboxController.GetLeftX();

  }


  // Use our forward/turn speeds to control the drivetrain

  drive.ArcadeDrive(forwardSpeed, rotationSpeed);
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
