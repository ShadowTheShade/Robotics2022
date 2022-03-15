void initialize() {
  CrcLib::Initialize(); //Sets up the CrcDuino
  Serial.begin(2000000); //Initializes the serial monitor bandwith (higher number == higher frequency)
  CrcLib::InitializePwmOutput(BASE_WHEEL_1); //Sets the pwm pin used for the top-left wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_2); //Sets the pwm pin used for the top-right wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_3); //Sets the pwm pin used for the bottom-right wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_4); //Sets the pwm pin used for the bottom-left wheel as an output
  CrcLib::InitializePwmOutput(ELEVATOR_1); //Sets the pwm pin used for the top-left elevator servo as an output
  CrcLib::InitializePwmOutput(ELEVATOR_2); //Sets the pwm pin used for the top-right elevator servo as an output
  CrcLib::InitializePwmOutput(ELEVATOR_3); //Sets the pwm pin used for the bottom-right elevator servo as an output
  CrcLib::InitializePwmOutput(ELEVATOR_4); //Sets the pwm pin used for the bottom-right elevator servo as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_1, OUTPUT); //Set the digital pin used for the top-left wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_2, OUTPUT); //Set the digital pin used for the top-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_3, OUTPUT); //Set the digital pin used for the bottom-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_4, OUTPUT); //Set the digital pin used for the bottom-left wheel as an output
}
