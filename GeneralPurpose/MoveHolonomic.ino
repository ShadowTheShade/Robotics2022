int in_min = -128;
int in_max = 127;
int out_min = -128;
int out_max = 127;



void moveHolonomic()
{ //Built-in Crc function to command the movement of a base with 4 omni-wheels

  CrcLib::MoveHolonomic(
    scaleNum(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X)), //Adjusted to the controller left joystick drift
    scaleNum(-CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y)), //Adjusted to the controller left joystick drift
    scaleNum(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_X)), 
    BASE_WHEEL_1, //Top-left wheel
    BASE_WHEEL_4, //Bottom-left wheel
    BASE_WHEEL_2, //Top-right wheel
    BASE_WHEEL_3 //Bottom-right wheel
  ); //Maps the controller to produce omni wheel movement basd on two joysticks
}


int scaleNum(int num){
  return (num - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
