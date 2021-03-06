
#include <Servo.h>

// max and min signal that can be output to the motors
const int MAX_SIGNAL = 2000;
const int MIN_SIGNAL = 1000;
const int MOTOR1 = 8;
const int DELAY = 1000;
const int POTENTIOMETER_PIN = A0;

Servo motor1;

void setup() {
  Serial.begin(9600);
  calibrateMotors();
}

void calibrateMotors() {
  motor1.attach(MOTOR1);

  // calibrating the motor signal
  motor1.writeMicroseconds(MAX_SIGNAL);

  // delay for 3 seconds to finish max signal calibration
  delay(2000);

  motor1.writeMicroseconds(MIN_SIGNAL);

  delay(2000);
}

void loop() {
  int potentiometerVal = analogRead(POTENTIOMETER_PIN);
  int motorVal = map(potentiometerVal, 0, 1023, MIN_SIGNAL, MAX_SIGNAL);

  // write data to port
  Serial.print(potentiometerVal);
  Serial.print(" ");
  Serial.println(motorVal);
  
  motor1.writeMicroseconds(motorVal);
}
