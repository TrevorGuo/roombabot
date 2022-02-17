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
    if (frontDist >= 15 || leftDist >= 15 || rightDist >= 15) {   // arbitrary for now
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
    float initYaw = getYaw();
    float finalYaw = initYaw + degree;
    if (degree > 0) {
        while (finalYaw - getYaw() > 2) { // threshold 0.5º difference
            analogWrite(ENA, motorSpeed);
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            analogWrite(ENB, motorSpeed);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);

            getYaw();
            Serial.print("Yaw: ");
            Serial.println(yaw);
        }
        analogWrite(ENA, LOW);
        analogWrite(ENB, LOW);
    }
    else {
        while (getYaw() - finalYaw > 2) { 
            analogWrite(ENA, motorSpeed);
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            analogWrite(ENB, motorSpeed);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);

            getYaw();
            Serial.print("Yaw: ");
            Serial.println(yaw);
        }
        analogWrite(ENA, LOW);
        analogWrite(ENB, LOW);
    }
}

// call when obstacle detected, assume leftDist != rightDist?
void aroundObstacle() {
    readUltrasonicSensors();
    float deg = 0.0;
    if (leftDist > rightDist) {
        deg = 45; // change later
    }
    else {
        deg = -45;
    }
    rotate(deg);
    forward();
    rotate(-deg); 
}
