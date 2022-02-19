#include <CrcLib.h>  //CrcLib program requirement

#include <math.h>

//Rename IOs with a meaningful name (good practice)
#define ELEVATOR_1 CRC_PWM_5 //Variable for the top-left serv0 for pwm pin 5(DC motor) on the CrcDuino
#define ELEVATOR_2 CRC_PWM_6 //Variable for the top-right wheel for pwm pin 6(DC motor) on the CrcDuino
#define ELEVATOR_3 CRC_PWM_7 //Variable for the bottom-right wheel for pwm pin 7(DC motor) on the CrcDuino
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
  CrcLib::SetDigitalPinMode(SET_DIGPIN_1, OUTPUT); //Set the digital pin used for the top-left wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_2, OUTPUT); //Set the digital pin used for the top-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_3, OUTPUT); //Set the digital pin used for the bottom-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_4, OUTPUT); //Set the digital pin used for the bottom-left wheel as an output

}
//**************************************************************************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  CrcLib::Update(); //Refreshes the CrcDuino
  leftJoystick(); //Function specifying what moving the left joystick accomplishes
  if (CrcLib::IsCommValid()) //CrcDuino specific command which checks if the board is in contact with the bluetooth module CrcConnect
  { //All values are printed on the serial monitor when the controller is connected
    Serial.println(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y)); //Reads the position of the left joystick of the connected controller ( -127(full up) to 127(full down) )
    Serial.println(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X)); //Reads the position of the left joystick of the connected controller ( -127(full left) to 127(full right) )
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::COLORS_LEFT)); //Reads if the left button on the right side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::COLORS_UP)); //Reads if the top button on the right side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::COLORS_RIGHT)); //Reads if the right button on the right side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::COLORS_DOWN)); //Reads if the bottom button on the right side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
  }
  else
  { //Will display on the serial monitor for a no connection situation
    Serial.print("No remote controller successfully communicates with the CrcDuino"); //This will desplay if the controller is not plugged in, if the CrcConnect is off or if thee remote is not compatible
  }
}

//based code
//



void leftJoystick ()
{ //Function for the use of the left side controller joystick
  CrcLib::SetPwmOutput(ELEVATOR_1, -CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y)); //
  CrcLib::SetPwmOutput(ELEVATOR_2, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y)); //
  CrcLib::SetPwmOutput(ELEVATOR_3, -CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y));
  
}
