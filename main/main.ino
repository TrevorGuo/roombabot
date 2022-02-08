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

  // pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  // pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  // pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
  
  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
