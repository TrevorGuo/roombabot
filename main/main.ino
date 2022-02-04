#include <MPU6050.h>

#include "variables.h"

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 3; i++) {
    pinMode(ultrasonicSensors[i][0], INPUT);  //echo
    pinMode(ultrasonicSensors[i][1], OUTPUT); //trig
  }
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);
  pinMode(servo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
