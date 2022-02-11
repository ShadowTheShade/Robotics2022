#include <CrcLib.h>

#define BASE_WHEEL_1 CRC_PWM_1 //Counts the pulses per rotation of the 5202-0002-0188

#define POTENT_TEST_1 CRC_ANA_1

#define MOTOR_ENCODER_1 CRC_PWM_2

volatile long encoderValue = 0;

int interval = 1000;

long previousMillis = 0;
long currentMillis = 0;

int rpm = 0;

int motorPWM = 0;

bool motorRotating = LOW;

const int STOP_POSITION = 5281;
const int MOTOR_SPEED = 13;

using namespace Crc;

void setup() {
  CrcLib::Initialize();
  Serial.begin(2000000);
  CrcLib::GetAnalogInput(POTENT_TEST_1);
  CrcLib::InitializePwmOutput(MOTOR_ENCODER_1, INPUT_PULLUP);
  CrcLib::InitializePwmOutput(BASE_WHEEL_1, motorPWM);

  attachInterrupt(digitalPinToInterrupt(MOTOR_ENCODER_1), updateEncoder, RISING);
}

void loop() {
  CrcLib::Update();  
  motorPWM = map(analogRead(POTENT_TEST_1), 0, 1023, 0, 127);
  
  Serial.println(analogRead(POTENT_TEST_1));

  

  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;


    // Calculate RPM
    rpm = (float)(encoderValue * 60 / STOP_POSITION);

    // Only update display when there is a reading
    if (motorPWM > 0 || rpm > 0) {
      Serial.print("PWM VALUE: ");
      Serial.print(motorPWM);
      Serial.print('\t');
      Serial.print(" PULSES: ");
      Serial.print(encoderValue);
      Serial.print('\t');
      Serial.print(" SPEED: ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }
    
    encoderValue = 0;
  }

}

void updateEncoder()
{
  // Increment value for each pulse from encoder
  encoderValue++;
}
