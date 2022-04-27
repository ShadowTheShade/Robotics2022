

void balls ()
{ //Function for activating ball pickup
  if(CrcLib::ReadDigitalChannel(BUTTON::COLORS_UP) == 1){
    CrcLib::SetPwmOutput(PICKUP_1, 100); //
  }
  else{
    CrcLib::SetPwmOutput(PICKUP_1, 0); //
  }
  if(CrcLib::ReadDigitalChannel(BUTTON::COLORS_LEFT) == 1){
    previousTime = currentTime;
    CrcLib::SetPwmOutput(DROPOFF_1, -70);
  }
  else if(CrcLib::ReadDigitalChannel(BUTTON::COLORS_RIGHT) == 1){
    previousTime = currentTime;
    CrcLib::SetPwmOutput(DROPOFF_1, 100);
  }
  else if(CrcLib::ReadDigitalChannel(BUTTON::COLORS_DOWN) == 1){
    previousTime = currentTime;
    CrcLib::SetPwmOutput(DROPOFF_1, 100);
  }
  if (currentTime - previousTime >= eventInterval) {
    CrcLib::SetPwmOutput(DROPOFF_1, 0);
  }
}
