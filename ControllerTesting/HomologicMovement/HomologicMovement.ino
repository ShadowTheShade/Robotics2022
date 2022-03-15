#include <CrcLib.h>  //CrcLib program requirement

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
//Rename IOs with a meaningful name (good practice)
#define BASE_WHEEL_1 CRC_PWM_1 //Variable for the top-left wheel for pwm pin 1(DC motor) on the CrcDuino
#define BASE_WHEEL_2 CRC_PWM_2 //Variable for the top-right wheel for pwm pin 2(DC motor) on the CrcDuino
#define BASE_WHEEL_3 CRC_PWM_3 //Variable for the bottom-right wheel for pwm pin 3(DC motor) on the CrcDuino
#define BASE_WHEEL_4 CRC_PWM_4 //Variable for the bottom-left wheel for pwm pin 4(DC motor) on the CrcDuino
#define BASE_WHEEL_5 CRC_PWM_5 //Variable for a servo mot wheel for pwm pin 5(Servo motor) on the CrcDuino
#define SET_DIGPIN_1 CRC_DIG_1 //Variable for digital pin 1 on the CrcDuino
#define SET_DIGPIN_2 CRC_DIG_2 //Variable for digital pin 2 on the CrcDuino
#define SET_DIGPIN_3 CRC_DIG_3 //Variable for digital pin 3 on the CrcDuino
#define SET_DIGPIN_4 CRC_DIG_4 //Variable for digital pin 4 on the CrcDuino

namespace Crc{ //CrcLib program requirement

void checkController();
void MoveHomologic();
//**************************************************************************************************************************
void setup() {
  //Runs once before everything else
  CrcLib::Initialize(); //Sets up the CrcDuino
  Serial.begin(2000000); //Initializes the serial monitor bandwith (higher number == higher frequency)
  CrcLib::InitializePwmOutput(BASE_WHEEL_1); //Sets the pwm pin used for the top-left wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_2); //Sets the pwm pin used for the top-right wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_3); //Sets the pwm pin used for the bottom-right wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_4); //Sets the pwm pin used for the bottom-left wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_5); //Sets the pwm pin used for a servo motor as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_1, OUTPUT); //Set the digital pin used for the top-left wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_2, OUTPUT); //Set the digital pin used for the top-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_3, OUTPUT); //Set the digital pin used for the bottom-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_4, OUTPUT); //Set the digital pin used for the bottom-left wheel as an output

}

//**************************************************************************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  CrcLib::Update(); //Refreshes the CrcDuino
  checkController(); //Displays whether or not the controller is connected to the arduino and displays its values
  moveHomologic();
  
}
void checkController()
{ //Function verifying the connection to the CrcConnect and displays the values of each sensor on the serial monitor
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

void moveHomologic()
{ //Built-in Crc function to command the movement of a base with 4 omni-wheels
  CrcLib::MoveHolonomic(
    MIN(127, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + 5), //Adjusted to the controller left joystick drift
    MAX(-127, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X) - 13), //Adjusted to the controller left joystick drift
    CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_X), 
    BASE_WHEEL_1, //Top-left wheel
    BASE_WHEEL_4, //Bottom-left wheel
    BASE_WHEEL_2, //Top-right wheel
    BASE_WHEEL_3 //Bottom-right wheel
  ); //Maps the controller to produce omni wheel movement basd on two joysticks
}
}
