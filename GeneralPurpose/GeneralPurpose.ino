 #include <CrcLib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

//Rename IOs with a meaningful name (good practice)
#define BASE_WHEEL_1 CRC_PWM_1 //Variable for the top-left wheel for pwm pin 1(DC motor) on the CrcDuino
#define BASE_WHEEL_2 CRC_PWM_2 //Variable for the top-right wheel for pwm pin 2(DC motor) on the CrcDuino
#define BASE_WHEEL_3 CRC_PWM_3 //Variable for the bottom-right wheel for pwm pin 3(DC motor) on the CrcDuino
#define BASE_WHEEL_4 CRC_PWM_4 //Variable for the bottom-left wheel for pwm pin 4(DC motor) on the CrcDuino
#define ELEVATOR_1 CRC_PWM_5 //Variable for pwm pin 5(servo) on the CrcDuino
#define ELEVATOR_2 CRC_PWM_6 //Variable for pwm pin 6(servo) on the CrcDuino
#define ELEVATOR_3 CRC_PWM_7 //Variable for pwm pin 7(servo) on the CrcDuino
#define ELEVATOR_4 CRC_PWM_8 //Variable for pwm pin 8(servo) on the CrcDuino
#define SET_DIGPIN_1 CRC_DIG_1 //Variable for digital pin 1 on the CrcDuino
#define SET_DIGPIN_2 CRC_DIG_2 //Variable for digital pin 2 on the CrcDuino
#define SET_DIGPIN_3 CRC_DIG_3 //Variable for digital pin 3 on the CrcDuino
#define SET_DIGPIN_4 CRC_DIG_4 //Variable for digital pin 4 on the CrcDuino
  
using namespace Crc;

void initialize();
void checkController();
void moveHolonomic();
void elevatorMovement();

//**************************************************************************************************************************
void setup() {
  initialize();
  
}

//**************************************************************************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  CrcLib::Update(); //Refreshes the CrcDuino
  checkController(); //Displays whether or not the controller is connected to the arduino and displays its values
  moveHolonomic();
  elevatorMovement();
}
