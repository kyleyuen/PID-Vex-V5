//Motor1 to Motor 6 are the standard motors given in Vex V5
//Intertial is the inertial sensor used for rotation that is built within the Vex V5 system
//VEXcode libraries are assumed to be included at the top of this file 
//#include "vex.h"

#include <cmath>

void turnP(float angle) {
    float speed = 55;       // Max turning speed
    float minSpeed = 10;    // Minimum speed to ensure movement
    float kP = 0.65;        // Proportional gain constant
    float threshold = 2.0;  // Angle tolerance to stop

    while (true) {
        // Recalculate error inside the loop
        float error = angle - Inertial.rotation(deg);

        // Exit condition: if within threshold, stop loop
        if (fabs(error) <= threshold) {
            break;
        }

        // Calculate turn speed
        float turnSpeed = error * kP;

        // Limit speed to prevent excessive values
        if (turnSpeed > speed) {
            turnSpeed = speed;
        } else if (turnSpeed < -speed) {
            turnSpeed = -speed;
        }

        // Ensure a minimum turn speed to avoid getting stuck
        if (fabs(turnSpeed) < minSpeed) {
            turnSpeed = (turnSpeed > 0) ? minSpeed : -minSpeed;
        }

        // Apply motor control
        Motor1.spin(fwd, turnSpeed, velocityUnits::pct);
        Motor2.spin(fwd, turnSpeed, velocityUnits::pct);
        Motor3.spin(fwd, turnSpeed, velocityUnits::pct);
        Motor4.spin(fwd, -turnSpeed, velocityUnits::pct);
        Motor5.spin(fwd, -turnSpeed, velocityUnits::pct);
        Motor6.spin(fwd, -turnSpeed, velocityUnits::pct);

        vex::task::sleep(20);  // Small delay for smoother operation
    }

    // Stop all motors once the turn is complete
    Motor1.stop(hold);
    Motor2.stop(hold);
    Motor3.stop(hold);
    Motor4.stop(hold);
    Motor5.stop(hold);
    Motor6.stop(hold);
}