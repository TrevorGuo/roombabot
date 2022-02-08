#include <Wire.h>

#include "variables.h"

const int MPU = 0x68; // MPU6050 I2C address

float yaw = 0;
float gyroZ, gyroAngleZ, gyroErrorZ;
int c = 0;

float getYaw() {    // what file should this be in lol
    currTime = millis();
    elapsedTime = currTime - previousTime; 
    // figure out how to read angular velocity
    yaw += gyroAngleZ * elapsedTime;    // hello what is gyroAngleZ the angular displacement or velocity?? im tired now bye
    previousTime = currTime;
    return yaw;
}

void forward() {  // move forward until an object is detected within a certain threshold distance
    digitalWrite(ultrasonicSensors[1][1], LOW); // just front ultrasonic sensor, let's just say it's second one in array
    delayMicroseconds(2); 
    digitalWrite(ultrasonicSensors[1][1], HIGH); 
    distanceFront = pulseIn(ultrasonicSensors[1][0], HIGH) * 343 * pow(10,-4) / 2;   // in cm

    if (distanceFront >= 15) {   // if we check sensors before calling forward(), we can just start off with the digitalWrites
        digitalWrite(ENA, HIGH);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(ENB, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }

    while (distanceFront >= 15) {
        digitalWrite(ultrasonicSensors[1][1], LOW); 
        delayMicroseconds(2); 
        digitalWrite(ultrasonicSensors[1][1], HIGH); 
        distance = pulseIn(ultrasonicSensors[1][0], HIGH) * 343 * pow(10,-4) / 2;
    }

    analogWrite(ENA, LOW);
    analogWrite(ENB, LOW);

    }
}

void rotate(float degree) {

}

void aroundObstacle() {
    
}
