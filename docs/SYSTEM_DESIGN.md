
# System Design

## 1. Input Layer
An 8-channel infrared sensor array is planned to detect
the black line against a white surface.

## 2. Processing Layer
The Arduino Uno will process sensor readings and
calculate corrections for line tracking.

## 3. Motor Control Layer
A motor driver will control the two DC motors.
PWM signals will be used to regulate motor speed.

## 4. Navigation Layer
The robot will detect intersections and make
navigation decisions such as:

- Left
- Right
- Straight
- Backtrack

## 5. Learning and Optimization Layer
The robot will record navigation decisions during
its exploration run.

The recorded route will be simplified to eliminate
unnecessary dead-end detours.

## 6. Adaptive Speed Control
The proposed system will use lower speed around
turns and higher speed on suitable straight sections.

## 7. Future Enhancement
A reward-based learning mechanism may be explored
as a future reinforcement-learning extension.

