
# Autonomous Maze-Solving Robot with PID-Based Line Tracking

## Project Overview

This project aims to develop an autonomous mobile robot
capable of navigating a black-line maze on a white surface.

The robot is planned to use an array of infrared sensors
for line detection and a PID-based control approach for
stable line tracking.

An additional proposed feature is experience-based route
learning and optimization, allowing the robot to record
its navigation decisions during an exploration run and
simplify its route for subsequent runs.

## Project Objectives

- Develop an autonomous line-following robot.
- Implement PID-based line tracking.
- Detect intersections and dead ends.
- Record navigation decisions during exploration.
- Optimize the recorded route by reducing unnecessary
  backtracking.
- Explore adaptive motor speed control.
- Investigate reinforcement learning as a future extension.

## Planned Hardware

- Arduino Uno R3
- 8-channel digital IR sensor array
- Two DC geared motors
- Motor driver module
- Two wheels
- Caster wheel
- Robot chassis
- Battery and voltage regulation circuit

## Planned Software

- Arduino IDE
- Embedded C/C++
- PID-based line tracking
- Experience-based route optimization
- Adaptive speed control

## System Development Stages

1. Hardware assembly and wiring.
2. IR sensor testing and calibration.
3. Motor driver testing.
4. Basic line-following implementation.
5. PID tuning.
6. Intersection and dead-end detection.
7. Route recording and optimization.
8. Adaptive speed control.
9. Integrated testing and performance evaluation.

## Current Development Status

The project repository and initial software
demonstration have been prepared.

The route-learning demonstration uses sample navigation
data to illustrate route recording and simplification.

Physical hardware integration, sensor calibration,
motor control integration, and full maze testing
are still pending.

## Future Scope

- EEPROM-based route storage.
- Improved maze mapping.
- Reward-based learning.
- Reinforcement learning exploration.
- Performance comparison between first and
  subsequent runs.

## Repository Structure

- `hardware/` - Hardware information and connections.
- `code/` - Arduino source code.
- `docs/` - Project documentation and design.
- `media/` - Images and demonstration videos.
- `tests/` - Testing procedures and results.

## Project Status

Initial planning and software demonstration stage.
