void elevatorMovement ()
{ //Function for the use of the right side controller joystick
  CrcLib::SetPwmOutput(ELEVATOR_1, -CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y)); //
  CrcLib::SetPwmOutput(ELEVATOR_2, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y)); //
  CrcLib::SetPwmOutput(ELEVATOR_3, -CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y)); 
  CrcLib::SetPwmOutput(ELEVATOR_4, CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y)); 
}
