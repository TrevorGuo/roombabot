#include "variables.h"
#include "sensors.h"
#include "movement.h"

/* const int MPU = 0x68; // MPU6050 I2C address

float yaw = 0;
float gyroZ, gyroAngleZ, gyroErrorZ;
int c = 0; */

float getYaw() {    // what file should this be in lol
    currTime = millis();
    elapsedTime = currTime - previousTime; 
    // figure out how to read angular velocity
    yaw += gyroAngleZ * elapsedTime;    // hello what is gyroAngleZ the angular displacement or velocity?? im tired now bye
    previousTime = currTime;
    return yaw;
}

void forward() {  // move forward until an object is detected within a certain threshold distance
    readUltrasonicSensors();
    if (frontDist >= 15 || leftDist >= 15 || rightDist >= 15) {   // arbitrary for now
        analogWrite(ENA, motorSpeed);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENB, motorSpeed);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
    while (frontDist >= 15 || leftDist >= 15 || rightDist >= 15) {
        readUltrasonicSensors();
    }
    
    analogWrite(ENA, LOW);
    analogWrite(ENB, LOW);
}

void rotate(float degree) {

}

void aroundObstacle() {

}
