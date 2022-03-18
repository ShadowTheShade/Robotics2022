#include <CrcLib.h>  //CrcLib program requirement

//Rename IOs with a meaningful name (good practice)
#define ELEVATOR_1 CRC_PWM_5 //Variable for the top-left servo for pwm pin 5 on the CrcDuino
#define ELEVATOR_2 CRC_PWM_6 //Variable for the top-right servo for pwm pin 6 on the CrcDuino
#define ELEVATOR_3 CRC_PWM_7 //Variable for the bottom-right wheel for pwm pin 7 on the CrcDuino
#define ELEVATOR_4 CRC_PWM_8 //Variable for the bottom-right wheel for pwm pin 8 on the CrcDuino
#define SET_DIGPIN_1 CRC_DIG_1 //Variable for digital pin 1 on the CrcDuino
#define SET_DIGPIN_2 CRC_DIG_2 //Variable for digital pin 2 on the CrcDuino
#define SET_DIGPIN_3 CRC_DIG_3 //Variable for digital pin 3 on the CrcDuino
#define SET_DIGPIN_4 CRC_DIG_4 //Variable for digital pin 4 on the CrcDuino

using namespace Crc; //CrcLib program requirement
//**************************************************************************************************************************
void setup() {
  //Runs once before everything else
  CrcLib::Initialize(); //Sets up the CrcDuino
  Serial.begin(2000000); //Initializes the serial monitor bandwith (higher number == higher frequency)
  CrcLib::InitializePwmOutput(ELEVATOR_1); //Sets the pwm pin used for the top-left elevator servo as an output
  CrcLib::InitializePwmOutput(ELEVATOR_2); //Sets the pwm pin used for the top-right elevator servo as an output
  CrcLib::InitializePwmOutput(ELEVATOR_3); //Sets the pwm pin used for the bottom-right elevator servo as an output
  CrcLib::InitializePwmOutput(ELEVATOR_4); //Sets the pwm pin used for the bottom-right elevator servo as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_1, OUTPUT); //Set the digital pin used for the top-left wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_2, OUTPUT); //Set the digital pin used for the top-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_3, OUTPUT); //Set the digital pin used for the bottom-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_4, OUTPUT); //Set the digital pin used for the bottom-left wheel as an output

}
//**************************************************************************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  CrcLib::Update(); //Refreshes the CrcDuino
  rightJoystick(); //Function specifying what moving the left joystick accomplishes
}

//based code
//



void rightJoystick ()
{ //Function for the use of the right side controller joystick
  CrcLib::SetPwmOutput(ELEVATOR_1, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y)); //
  CrcLib::SetPwmOutput(ELEVATOR_2, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y)); //
  CrcLib::SetPwmOutput(ELEVATOR_3, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y));
  CrcLib::SetPwmOutput(ELEVATOR_4, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y));
  
}
