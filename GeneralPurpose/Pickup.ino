void balls ()
{ //Function for activating ball pickup
  if(CrcLib::ReadDigitalChannel(BUTTON::COLORS_UP) == 1){
    CrcLib::SetPwmOutput(PICKUP_1, 100); //
  }
  else{
    CrcLib::SetPwmOutput(PICKUP_1, 0); //
  }
  if(CrcLib::ReadDigitalChannel(BUTTON::COLORS_UP) == 1){
    
    CrcLib::SetPwmOutput(DROPOFF_1, 100);
  }
}
