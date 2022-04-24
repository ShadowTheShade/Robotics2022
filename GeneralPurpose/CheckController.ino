void checkController()
{ //Function verifying the connection to the CrcConnect and displays the values of each sensor on the serial monitor
  if (CrcLib::IsCommValid()) //CrcDuino specific command which checks if the board is in contact with the bluetooth module CrcConnect
  { //All values are printed on the serial monitor when the controller is connected
    Serial.print("Left-Side Joystick y-axis: ");
    Serial.println(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y)); //Reads the y-position of the left joystick of the connected controller ( -127(full up) to 127(full down) )
    Serial.print("Left-Side Joystick x-axis: ");
    Serial.println(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X)); //Reads the x-position of the left joystick of the connected controller ( -127(full left) to 127(full right) )
    Serial.print("Left-Side Joystick press: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::HATL)); //Reads if the left joystick is pressed ( 0(not pressed) or 1(pressed) )
    
    Serial.print("Arrow Left: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::ARROW_LEFT)); //Reads if the left button on the left side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.print("Arrow Up: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::ARROW_UP)); //Reads if the top button on the left side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.print("Arrow Right: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::ARROW_RIGHT)); //Reads if the right button on the left side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.print("Arrow Down: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::ARROW_DOWN)); //Reads if the bottom button on the left side of the remote is pressed ( 0(not pressed)  or 1(pressed) )

    Serial.print("LeftGachette: "); 
    Serial.println(CrcLib::ReadAnalogChannel(ANALOG::GACHETTE_L)); //Reads if the right trigger is pressed ( -128(unpressed) to 127(fully pressed) ) for xbox and ps ( 0(not pressed)  or 1(pressed) ) for other
    Serial.print("L1: "); 
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::L1)); //Reads if the left shoulder button is pressed ( 0(not pressed)  or 1(pressed) )

    
    Serial.print("Right-Side Joystick y-axis: ");
    Serial.println(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_Y)); //Reads the y-position of the right joystick of the connected controller ( -127(full up) to 127(full down) )
    Serial.print("Right-Side Joystick x-axis: ");
    Serial.println(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_X)); //Reads the x-position of the right joystick of the connected controller ( -127(full left) to 127(full right) )
    Serial.print("Right-Side Joystick press: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::HATR)); //Reads if the right joystick is pressed ( 0(not pressed) or 1(pressed) )

    Serial.print("Colour Left: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::COLORS_LEFT)); //Reads if the left button on the right side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.print("Colour Up: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::COLORS_UP)); //Reads if the top button on the right side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.print("Colour Right: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::COLORS_RIGHT)); //Reads if the right button on the right side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.print("Colour Down: ");
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::COLORS_DOWN)); //Reads if the bottom button on the right side of the remote is pressed ( 0(not pressed)  or 1(pressed) )
    
    Serial.print("RightGachette: "); 
    Serial.println(CrcLib::ReadAnalogChannel(ANALOG::GACHETTE_R)); //Reads if the right trigger is pressed ( -128(unpressed) to 127(fully pressed) ) for xbox and ps ( 0(not pressed)  or 1(pressed) ) for other
    Serial.print("R1: "); 
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::R1)); //Reads if the right shoulder button is pressed ( 0(not pressed)  or 1(pressed) )
  
    Serial.print("Select: "); 
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::SELECT)); //Reads if the select button is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.print("Start: "); 
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::START)); //Reads if the start button is pressed ( 0(not pressed)  or 1(pressed) )
    Serial.print("Icon: "); 
    Serial.println(CrcLib::ReadDigitalChannel(BUTTON::LOGO)); //Reads if the controller icon is pressed ( 0(not pressed)  or 1(pressed) )

}

  else
  { //Will display on the serial monitor for a no connection situation
    Serial.println("No remote controller successfully communicates with the CrcDuino"); //This will desplay if the controller is not plugged in, if the CrcConnect is off or if thee remote is not compatible
  }
}
