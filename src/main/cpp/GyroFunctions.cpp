#include "GyroFunctions.h"

GyroFunctions::GyroFunctions(){
    pigeonGyro = new ctre::phoenix::sensors::PigeonIMU(pigeonCanPort);
}

void GyroFunctions::ResetAnglePigeon(){
    pigeonGyro->SetYaw(0.0);
}

void GyroFunctions::BootCalibratePigeon(){
    pigeonGyro->EnterCalibrationMode(ctre::phoenix::sensors::PigeonIMU::CalibrationMode::BootTareGyroAccel, 6000);
}

double GyroFunctions::GetYawPigeon(){
    double ypr[3];
    pigeonGyro->GetYawPitchRoll(ypr);
        return ypr[0];
}

double GyroFunctions::GetPitchPigeon(){
    double ypr[3];
    pigeonGyro->GetYawPitchRoll(ypr);
        return ypr[1];
}

double GyroFunctions::GetRollPigeon(){
    double ypr[3];
    pigeonGyro->GetYawPitchRoll(ypr);
        return ypr[2];
}
double GyroFunctions::GetHeadingRIOGyro(){
   return gyro.GetAngle();
}
void GyroFunctions::CalibrateRIOGyro(){
    gyro.Calibrate();
}
frc::Rotation2d GyroFunctions::GetHeadingRotation2dRIOGryo(){
    return gyro.GetRotation2d();
}
void GyroFunctions::ResetRIOGyro(){
    return gyro.Reset();
}