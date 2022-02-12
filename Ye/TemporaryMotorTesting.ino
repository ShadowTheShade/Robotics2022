#include <CrcLib.h>  //CrcLib program requirement

//Rename IOs with a meaningful name (good practice)
#define ELEVATOR_SERVO_5 CRC_PWM_5 
#define ELEVATOR_SERVO_6 CRC_PWM_6 
#define ELEVATOR_SERVO_7 CRC_PWM_7 
#define POTENT_TEST_1 CRC_ANA_1 

using namespace Crc; //CrcLib program requirement
//**************************************************************************************************************************
void setup() {
  // put your setup code here, to run once at the beginning:
  CrcLib::Initialize(); //Sets up the CrcDuino
  Serial.begin(2000000);
  CrcLib::GetAnalogInput(POTENT_TEST_1);
  CrcLib::InitializePwmOutput(ELEVATOR_SERVO_5);
  CrcLib::InitializePwmOutput(ELEVATOR_SERVO_6);
  CrcLib::InitializePwmOutput(ELEVATOR_SERVO_7);
 
}
//**************************************************************************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  CrcLib::Update(); //Refreshes the CrcDuino+
  Serial.print(analogRead(POTENT_TEST_1));
  Serial.print('\n');
  if (analogRead(POTENT_TEST_1) <= 255 ){
    CrcLib::SetPwmOutput(ELEVATOR_SERVO_5, 127);
    CrcLib::SetPwmOutput(ELEVATOR_SERVO_6, -127);
    CrcLib::SetPwmOutput(ELEVATOR_SERVO_7, 127);
  }
  else if (analogRead(POTENT_TEST_1) >= 380 ){
    CrcLib::SetPwmOutput(ELEVATOR_SERVO_5, -127);
    CrcLib::SetPwmOutput(ELEVATOR_SERVO_6, 127);
    CrcLib::SetPwmOutput(ELEVATOR_SERVO_7, -127);
  }
  else {
    CrcLib::SetPwmOutput(ELEVATOR_SERVO_5, -10);
    CrcLib::SetPwmOutput(ELEVATOR_SERVO_6, -10);
    CrcLib::SetPwmOutput(ELEVATOR_SERVO_7, -10);
  }
}
