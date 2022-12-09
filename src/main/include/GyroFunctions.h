#pragma once
#include <ctre/Phoenix.h>
#include <frc/ADXRS450_Gyro.h>
#include <frc/geometry/Rotation2d.h>

class GyroFunctions{
    public:
        GyroFunctions();
        void ResetAnglePigeon();
        void BootCalibratePigeon();
        double GetYawPigeon();
        double GetPitchPigeon();
        double GetRollPigeon();
        double GetHeadingRIOGyro();
        void CalibrateRIOGyro();
        frc::Rotation2d GetHeadingRotation2dRIOGryo();
        void ResetRIOGyro();
        frc::ADXRS450_Gyro gyro;
    private:
        int pigeonCanPort = 3;
        ctre::phoenix::sensors::PigeonIMU *pigeonGyro;   
};