void initialize() {
  CrcLib::Initialize(); //Sets up the CrcDuino
#ifdef __SERIAL_DEBUG
  Serial.begin(2000000); //Initializes the serial monitor bandwith (higher number == higher frequency)
#endif
  CrcLib::InitializePwmOutput(BASE_WHEEL_1); //Sets the pwm pin used for the top-left wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_2); //Sets the pwm pin used for the top-right wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_3); //Sets the pwm pin used for the bottom-right wheel as an output
  CrcLib::InitializePwmOutput(BASE_WHEEL_4); //Sets the pwm pin used for the bottom-left wheel as an output
  CrcLib::InitializePwmOutput(ELEVATOR_1); //Sets the pwm pin used for the top-left elevator servo as an output
  CrcLib::InitializePwmOutput(ELEVATOR_2); //Sets the pwm pin used for the top-right elevator servo as an output
  CrcLib::InitializePwmOutput(ELEVATOR_3); //Sets the pwm pin used for the bottom-right elevator servo as an output
  CrcLib::InitializePwmOutput(ELEVATOR_4); //Sets the pwm pin used for the bottom-right elevator servo as an output
  CrcLib::InitializePwmOutput(PICKUP_1); //Sets the pwm pin used for the pickup motor as an output
  CrcLib::InitializePwmOutput(DROPOFF_1); //Sets the pwm pin used for the dropoff servo as an output
  CrcLib::InitializePwmOutput(SUSPICIOUS_ADDITION_1); //Sets the pwm pin used for the dropoff servo as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_1, OUTPUT); //Set the digital pin used for the top-left wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_2, OUTPUT); //Set the digital pin used for the top-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_3, OUTPUT); //Set the digital pin used for the bottom-right wheel as an output
  CrcLib::SetDigitalPinMode(SET_DIGPIN_4, OUTPUT); //Set the digital pin used for the bottom-left wheel as an output
  CrcLib::SetPwmOutput(BASE_WHEEL_1, 0);
  CrcLib::SetPwmOutput(BASE_WHEEL_2, 0);
  CrcLib::SetPwmOutput(BASE_WHEEL_3, 0);
  CrcLib::SetPwmOutput(BASE_WHEEL_4, 0);
}
