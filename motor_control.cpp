#include "motor_control.h"
#include <Servo.h>

Servo servoPan;   
Servo servoTilt;  

void motors_init() {
    servoPan.attach(9);   
    servoTilt.attach(10);
}

void set_angles(int pan, int tilt) {
    servoPan.write(pan);
    servoTilt.write(tilt);
}
