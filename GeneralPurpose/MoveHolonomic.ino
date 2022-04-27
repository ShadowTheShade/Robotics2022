int in_min = -128;
int in_max = 127;
int out_min = -128;
int out_max = 127;

void moveHolonomic()
{ //Built-in Crc function to command the movement of a base with 4 omni-wheels

  CrcLib::MoveHolonomic(
    scaleNum(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_X) - 10), //Adjusted to the controller left joystick drift
    scaleNum(-(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK1_Y) + 7)), //Adjusted to the controller left joystick drift
    scaleNum(CrcLib::ReadAnalogChannel(ANALOG::JOYSTICK2_X) - 8), 
    BASE_WHEEL_4, //Bottom-left wheel, 2 => 1
    BASE_WHEEL_1, //Top-left wheel, 1 => 2
    BASE_WHEEL_2, //Top-right wheel
    BASE_WHEEL_3 //Bottom-right wheel
  ); //Maps the controller to produce omni wheel movement basd on two joysticks
}

template <typename T, typename F>
T lerp(F f, T a, T b) {
    return a + static_cast<double>(f) * (b - a);
}

template <typename T, typename F>
T clamp_lerp(F f, T a, T b) {
    return lerp<T, F>(MIN(MAX(f, 0), 1), a, b);
}

template <typename T, typename F>
T lerp_range(F f, F x, F y, T a, T b) {
    return lerp<T, double>(static_cast<double>(f - x) / static_cast<double>(y - x), a, b);
}

template <typename T, typename F>
T clamp_lerp_range(F f, F x, F y, T a, T b) {
    return clamp_lerp<T, double>(static_cast<double>(f - x) / static_cast<double>(y - x), a, b);
}

int scaleNum(int num){
  return SGN(num)*lerp_range<double, double>(pow(clamp_lerp_range<double, double>(num, in_min, in_max, -1.0, 1.0), 2), -1.0, 1.0, out_min, out_max);
}
