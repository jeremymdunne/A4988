#include "Arduino.h"
#include "A4988.h"
A4988::A4988(int stepsPerRev, int stpPin, int dirPin) {
  this->stpPin = stpPin;
  this->dirPin = dirPin;
  this->stepsPerRev = stepsPerRev;
  pinMode(stpPin, OUTPUT);
  pinMode(dirPin, OUTPUT); 
}
void A4988::setStepperSpeed(int speed) {
  this->delayTime = 60 * 1000000 / stepsPerRev / speed;
}
void A4988::stepStepper(int steps) {
  if (steps > 0) {
    digitalWrite(dirPin, HIGH);
  }
  else {
    digitalWrite(dirPin, LOW);
  }
  for (int c = 0; c < abs(steps); c ++) {
    digitalWrite(stpPin, HIGH);
    delayMicroseconds((delayTime / 2));
    digitalWrite(stpPin, LOW);
    delayMicroseconds((delayTime / 2));
  }
}
