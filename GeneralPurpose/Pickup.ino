uint8_t dropoffInterval = 300;
enum class DROPOFF { NIL, ONCE, MANY };
DROPOFF dropoff_state = DROPOFF::NIL;

void balls ()
{ //Function for activating ball pickup
  if(CrcLib::ReadDigitalChannel(BUTTON::L1) == 1){
    CrcLib::SetPwmOutput(PICKUP_1, 127); //
  }
  else if(CrcLib::ReadDigitalChannel(BUTTON::R1) == 1){
    CrcLib::SetPwmOutput(PICKUP_1, -127); //
  }
  else if (CrcLib::ReadDigitalChannel(BUTTON::COLORS_UP) == 1){
    CrcLib::SetPwmOutput(PICKUP_1, 0); //
  }
  if(CrcLib::ReadDigitalChannel(BUTTON::COLORS_LEFT) == 1){
    previousTime = currentTime;
    dropoff_state = DROPOFF::MANY;
    CrcLib::SetPwmOutput(DROPOFF_1, -35);
  }
  else if(CrcLib::ReadDigitalChannel(BUTTON::COLORS_RIGHT) == 1){
    previousTime = currentTime;
    dropoff_state = DROPOFF::MANY;
    CrcLib::SetPwmOutput(DROPOFF_1, 35);
  }
  else if(CrcLib::ReadDigitalChannel(BUTTON::COLORS_DOWN) == 1){
    previousTime = currentTime;
    dropoff_state = DROPOFF::ONCE;
    CrcLib::SetPwmOutput(DROPOFF_1, 35);
  }
  if (dropoff_state == DROPOFF::MANY) {
    if (currentTime - previousTime >= eventInterval) {
      dropoff_state = DROPOFF::NIL;
      CrcLib::SetPwmOutput(DROPOFF_1, 0);
    }
  }
  else if (dropoff_state == DROPOFF::ONCE) {
    if (currentTime - previousTime >= pickupInterval) {
      CrcLib::SetPwmOutput(DROPOFF_1, -35);
    }
    else if (currentTime - previousTime >= pickupInterval * 2) {
      dropoff_state = DROPOFF::NIL;
       CrcLib::SetPwmOutput(DROPOFF_1, 0);
    }
  }
}
