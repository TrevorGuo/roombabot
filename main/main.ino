#include "variables.h"
#include "movement.h"
#include "sensors.h"
#include <MPU6050.h>

// MPU6050 accelgyro;

void setup() {
  Serial.begin(115200);
  Serial.println("Setting up");

  for (int i = 0; i < 3; i++) {
    pinMode(ultrasonicSensors[i][0], INPUT);  //echo
    pinMode(ultrasonicSensors[i][1], OUTPUT); //trig
  }
  pinMode(servo, OUTPUT);

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
  Serial.println("Pins set");

  while(!accelgyro.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }

  accelgyro.calibrateGyro();
  //Serial.println("Gyro calibrated");
  accelgyro.setThreshold(1); //Fiddle with this more
  Serial.println("Finished setup");
}

void loop() {
  // put your main code here, to run repeatedly:
  getYaw();
  Serial.print(" Yaw: ");
  Serial.println(yaw);
}
