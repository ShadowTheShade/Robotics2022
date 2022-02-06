#include <CrcLib.h>  //CrcLib program requirement

//Rename IOs with a meaningful name (good practice)
#define BASE_WHEEL_1 CRC_PWM_1
#define BASE_WHEEL_2 CRC_PWM_2
#define BASE_WHEEL_3 CRC_PWM_3
#define BASE_WHEEL_4 CRC_PWM_4
#define BASE_WHEEL_5 CRC_PWM_5
#define SET_WHEEL_1 CRC_DIG_1
#define SET_WHEEL_2 CRC_DIG_2
#define SET_WHEEL_3 CRC_DIG_3
#define SET_WHEEL_4 CRC_DIG_4

using namespace Crc; //CrcLib program requirement
//**************************************************************************************************************************
void setup() {
  // put your setup code here, to run once at the beginning:
  CrcLib::Initialize(); //Sets up the CrcDuino
  Serial.begin(2000000);
  CrcLib::InitializePwmOutput(BASE_WHEEL_1);
  CrcLib::InitializePwmOutput(BASE_WHEEL_2);
  CrcLib::InitializePwmOutput(BASE_WHEEL_3);
  CrcLib::InitializePwmOutput(BASE_WHEEL_4);
  CrcLib::InitializePwmOutput(BASE_WHEEL_5);
  CrcLib::SetDigitalPinMode(SET_WHEEL_1, LOW);
  CrcLib::SetDigitalPinMode(SET_WHEEL_2, LOW);
  CrcLib::SetDigitalPinMode(SET_WHEEL_3, LOW);
  CrcLib::SetDigitalPinMode(SET_WHEEL_4, LOW);//Sets up the motor output

}
//**************************************************************************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  CrcLib::Update(); //Refreshes the CrcDuino+
  leftJoystick();
  if (CrcLib::IsCommValid())
  {
    Serial.print(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y));
    Serial.print('\n');
    Serial.print(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));
    Serial.print('\n');
    Serial.print(CrcLib::ReadDigitalChannel(BUTTON::COLORS_LEFT));
    Serial.print('\n');
    Serial.print(CrcLib::ReadDigitalChannel(BUTTON::COLORS_UP));
    Serial.print('\n');
    Serial.print(CrcLib::ReadDigitalChannel(BUTTON::COLORS_RIGHT));
    Serial.print('\n');
    Serial.print(CrcLib::ReadDigitalChannel(BUTTON::COLORS_DOWN));
    Serial.print('\n');
  }
  else{
    Serial.print("No remote controller successfully communicates with the CrcDuino");
  }
}
  
  




void leftJoystick (){
  if (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) < -10 or CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) > 10 or CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X) < -10 or CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X) > 10){
    if (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) > 10 and CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X) > 10){
      CrcLib::SetPwmOutput(BASE_WHEEL_1, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) - CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));
      CrcLib::SetPwmOutput(BASE_WHEEL_2, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));
      CrcLib::SetPwmOutput(BASE_WHEEL_3, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) - CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));
      CrcLib::SetPwmOutput(BASE_WHEEL_4, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));//127=Full speed
    }
    else if (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) > 10 and CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X) < -10){
      CrcLib::SetPwmOutput(BASE_WHEEL_1, (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) - CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X))e);
      CrcLib::SetPwmOutput(BASE_WHEEL_2, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));
      CrcLib::SetPwmOutput(BASE_WHEEL_3, (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) - CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X))/2);
      CrcLib::SetPwmOutput(BASE_WHEEL_4, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));//127=Full speed
    }
    else if (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) < -10 and CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X) < -10){
      CrcLib::SetPwmOutput(BASE_WHEEL_1, (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) - CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X)));
      CrcLib::SetPwmOutput(BASE_WHEEL_2, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));
      CrcLib::SetPwmOutput(BASE_WHEEL_3, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) - CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));
      CrcLib::SetPwmOutput(BASE_WHEEL_4, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));//127=Full speed
    }
    else if (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) < -10 and CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X) > 10){
      CrcLib::SetPwmOutput(BASE_WHEEL_1, (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) - CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X)));
      CrcLib::SetPwmOutput(BASE_WHEEL_2, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));
      CrcLib::SetPwmOutput(BASE_WHEEL_3, (CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) - CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X))/2);
      CrcLib::SetPwmOutput(BASE_WHEEL_4, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X));//127=Full speed
    }
  }
  
}

void colourButton (){
  if (CrcLib::ReadDigitalChannel(BUTTON::COLORS_LEFT) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_1, 20);
    Serial.print("yoooooooooooooooooooooooooooooooooooooooooooooooooooooo");
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::COLORS_UP) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_1, 40);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::COLORS_RIGHT) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_1, 60);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::COLORS_DOWN) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_1, 80);
  }
  if (CrcLib::ReadDigitalChannel(BUTTON::COLORS_LEFT) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_2, 20);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::COLORS_UP) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_2, 40);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::COLORS_RIGHT) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_2, 60);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::COLORS_DOWN) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_2, 80);
  }
}

void arrowButton (){
  if (CrcLib::ReadDigitalChannel(BUTTON::ARROW_LEFT) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_1, -20);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::ARROW_UP) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_1, -40);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::ARROW_RIGHT) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_1, -60);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::ARROW_DOWN) == 1) {
    CrcLib::SetPwmOutput(BASE_WHEEL_1, -80);
  }
  if (CrcLib::ReadDigitalChannel(BUTTON::ARROW_LEFT) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_2, -20);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::ARROW_UP) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_2, -40);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::ARROW_RIGHT) == 1){
    CrcLib::SetPwmOutput(BASE_WHEEL_2, -60);
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::ARROW_DOWN) == 1) {
    CrcLib::SetPwmOutput(BASE_WHEEL_2, -80);
  }
}
