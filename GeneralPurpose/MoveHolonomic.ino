void moveHolonomic()
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
