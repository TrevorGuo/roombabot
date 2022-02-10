#include "variables.h"
#include "movement.h"
#include "sensors.h"

// MPU6050 accelgyro;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 3; i++) {
    pinMode(ultrasonicSensors[i][0], INPUT);  //echo
    pinMode(ultrasonicSensors[i][1], OUTPUT); //trig
  }
  pinMode(servo, OUTPUT);

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
}
