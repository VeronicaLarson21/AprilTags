#pragma once
#include <frc/TimedRobot.h>
#include "TankDrive.h"
#include <frc/Joystick.h>
//Here are the includes, these are files the code refrences in order to add additional functions in a more organized manor
//Timed robot is needed for the main robot file of any robot software using it as their primary file
//TankDrive is where our movement code is
//Joystick is a library that interfaces with the joysticks we use to drive the robot


class Robot : public frc::TimedRobot {
 public:
 //These are the base functions of the timed robot structure, and when you run the robot each is run at specific times
 //Init functions are ran once at the beginning of their respective stages
 //Periodic functions are ran every few milliseconds during the period they are in
 //Robot: The whole of the robots time on
 //Autonomous: The period where no driver input is given and the robot moves independently
 //Teleop: The bulk of the match, where drivers have control of the robot
 //Disabled: When the robot is disabled by the field software
 //Test: When the robot is a specific test period
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
 //As we learned last week when you use a class in a function you have to define it. 
 //This is what we are doing here with the tankdrive class
  Tankdrive tankdrive;
//And here we create two class instances defined at diffrent ports
  Joystick stick1{0}; 
  Joystick stick2{1};
};
