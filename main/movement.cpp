#include "variables.h"
#include "sensors.h"
#include "movement.h"

/* const int MPU = 0x68; // MPU6050 I2C address

float yaw = 0;
float gyroZ, gyroAngleZ, gyroErrorZ;
int c = 0; */

void forward() {  // move forward until an object is detected within a certain threshold distance
    //readUltrasonicSensors();
    frontDist = 15;
    leftDist = 15;
    rightDist = 15;
    if (frontDist >= 15 && leftDist >= 15 && rightDist >= 15) {   // arbitrary for now
        analogWrite(ENA, motorSpeed);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENB, motorSpeed);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
    Serial.println(frontDist);
    Serial.println(leftDist);
    Serial.println(rightDist);
    Serial.println();
    // while (frontDist >= 15 && leftDist >= 15 && rightDist >= 15) {
    //     readUltrasonicSensors();
    // }
    delay(5000);
    
    analogWrite(ENA, LOW);
    analogWrite(ENB, LOW);
}

void rotate(float degree) {
    analogWrite(ENA, motorSpeed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENB, motorSpeed);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    delay(5000);
    analogWrite(ENA, LOW);
    analogWrite(ENB, LOW);
}

void aroundObstacle() {

}
