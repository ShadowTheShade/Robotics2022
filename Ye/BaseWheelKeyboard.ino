                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     #include <CrcLib.h>  //CrcLib program requirement

#define BASE_WHEEL_1 CRC_PWM_1 
#define BASE_WHEEL_2 CRC_PWM_2 
#define BASE_WHEEL_3 CRC_PWM_3 
#define BASE_WHEEL_4 CRC_PWM_4 
int motorSpeed = 90;

using namespace Crc; //CrcLib program requirement
//**************************************************************************************************************************
void setup()
{ // put your setup code here, to run once at the beginning:
  CrcLib::Initialize(); //Sets up the CrcDuino
  Serial.begin(2000000);
  CrcLib::InitializePwmOutput(BASE_WHEEL_1);
  CrcLib::InitializePwmOutput(BASE_WHEEL_2);
  CrcLib::InitializePwmOutput(BASE_WHEEL_3);
  CrcLib::InitializePwmOutput(BASE_WHEEL_4);
 
}

//**************************************************************************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  CrcLib::Update(); //Refreshes the CrcDuino+
  Serial.println(motorSpeed);
  CrcLib::SetPwmOutput(BASE_WHEEL_1, motorSpeed);
  
}
