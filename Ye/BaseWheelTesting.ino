#include <CrcLib.h>  //CrcLib program requirement

#define BASE_WHEEL_1 CRC_PWM_1 
#define BASE_WHEEL_2 CRC_PWM_2 
#define BASE_WHEEL_3 CRC_PWM_3 
#define BASE_WHEEL_4 CRC_PWM_4 
#define POTENT_TEST_1 CRC_ANA_1 

using namespace Crc; //CrcLib program requirement
//**************************************************************************************************************************
void setup()
{ // put your setup code here, to run once at the beginning:
  CrcLib::Initialize(); //Sets up the CrcDuino
  Serial.begin(2000000);
  CrcLib::GetAnalogInput(POTENT_TEST_1);
  CrcLib::InitializePwmOutput(BASE_WHEEL_1);
  CrcLib::InitializePwmOutput(BASE_WHEEL_2);
  CrcLib::InitializePwmOutput(BASE_WHEEL_3);
  CrcLib::InitializePwmOutput(BASE_WHEEL_4);
 
}

//**************************************************************************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  CrcLib::Update(); //Refreshes the CrcDuino+
  Serial.print(analogRead(POTENT_TEST_1));
  Serial.print('\n');
  if (analogRead(POTENT_TEST_1) <= 255 )
  {
    CrcLib::SetPwmOutput(BASE_WHEEL_1, 127);
    CrcLib::SetPwmOutput(BASE_WHEEL_2, -127);
    CrcLib::SetPwmOutput(BASE_WHEEL_3, 127);
    CrcLib::SetPwmOutput(BASE_WHEEL_4, 127);
  }
  else if (analogRead(POTENT_TEST_1) >= 380 )
  {
    CrcLib::SetPwmOutput(BASE_WHEEL_1, -127);
    CrcLib::SetPwmOutput(BASE_WHEEL_2, 127);
    CrcLib::SetPwmOutput(BASE_WHEEL_3, -127);
    CrcLib::SetPwmOutput(BASE_WHEEL_4, -127);
  }
  else
  {
    CrcLib::SetPwmOutput(BASE_WHEEL_1, -10);
    CrcLib::SetPwmOutput(BASE_WHEEL_2, -10);
    CrcLib::SetPwmOutput(BASE_WHEEL_3, -10);
    CrcLib::SetPwmOutput(BASE_WHEEL_4, -10);
  }
}
