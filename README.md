# VEX V5 Proportional Turn Function --> PID (`turnP`)

## Overview

This project contains a proportional control function `turnP(float angle)` for turning a VEX V5 robot to a specified angle using the built-in inertial sensor. The function uses a simple proportional controller (P-controller) to rotate the robot smoothly and accurately.

## Features

- Uses the VEX V5 inertial sensor to measure the robot's current heading.
- Proportional control to calculate motor speeds based on the angle error.
- Limits maximum and minimum motor speeds for smooth and reliable turning.
- Stops motors with a hold brake once the target angle is reached within a tolerance.
- Compatible with 6 standard VEX V5 motors configured for tank drive or similar drivetrain.

## Requirements

- VEX V5 Robot Brain and Controller
- 6 standard VEX V5 motors connected to ports 1 through 6 (or configured accordingly)
- VEX V5 inertial sensor connected and named `Inertial`
- VEXcode V5 Pro development environment

## How It Works

1. The function takes a target angle in degrees as input.  
2. It continuously reads the current rotation from the inertial sensor.  
3. Calculates the error between the target angle and current angle.  
4. Computes a turn speed proportional to the error (`turnSpeed = error * kP`).  
5. Clamps the turn speed between a minimum and maximum speed to avoid stalling or jerky movement.  
6. Commands the left motors to spin forward at `turnSpeed` and the right motors to spin backward at `turnSpeed` (or vice versa) to turn the robot.  
7. Once the error is within a small threshold (2 degrees), the motors stop and hold position.

## Parameters

- `angle` (float): Target heading angle in degrees to turn to.

## Constants (modifiable inside `turnP`)

| Constant   | Description                     | Default Value |
|------------|---------------------------------|---------------|
| `speed`    | Maximum motor speed (percent)   | 55            |
| `minSpeed` | Minimum motor speed (percent)   | 10            |
| `kP`       | Proportional gain constant      | 0.65          |
| `threshold`| Angle error tolerance (degrees)| 2.0           |


## Challenges faced 
Throughout the development of this turning function, I went through many iterations and explored various source codes and control strategies. The main challenge was to find a solution that was not only simple and effective but also accurate and, most importantly, repeatable in real-world robot operation. After extensive testing and refinement, I created my own proportional control function that balances responsiveness with stability, ensuring consistent and reliable turns every time. This approach avoids unnecessary complexity while delivering precise control, making it well-suited for VEX V5 robotics applications.
