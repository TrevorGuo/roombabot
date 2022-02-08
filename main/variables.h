#include <MPU6050.h>

#ifndef VARIABLES_H
#define VARIABLES_H

float yaw, leftDist, frontDist, rightDist = 0.0;
float currTime, previousTime = 0.0;
const float turnDegree = 0.0;
const float timeForward = 0.0;
const float captureDist = 0.0;

//left, middle, right
const int ultrasonicSensors[3][2] = {{1,2},{3,4},{5,6}};
const int motorLeft = 7;
const int motorRight = 8;
const int servo = 9;

MPU6050 accelgyro;
#endif //VARIABLES_H
