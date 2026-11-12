
/*
  PROJECT: Autonomous Maze-Solving Robot
  MODULE: Experience-Based Route Learning Demo
  BOARD: Arduino Uno

  PURPOSE:
  Demonstrates how a robot can record its first
  exploration route and simplify dead-end detours.

  L = Left
  R = Right
  S = Straight
  B = Backtrack

  STATUS:
  Software demonstration only.
  Hardware integration and physical testing are pending.
*/

#define MAX_PATH 100

char learnedPath[MAX_PATH];
int pathLength = 0;

// Record the robot's navigation decision
void recordDecision(char decision) {
  if (pathLength < MAX_PATH - 1) {
    learnedPath[pathLength++] = decision;
    learnedPath[pathLength] = '\0';
  }
}

// Simplify a three-decision pattern: X B Y
char simplifyPattern(char first, char last) {

  if (first == 'L' && last == 'L') return 'S';
  if (first == 'L' && last == 'S') return 'R';
  if (first == 'L' && last == 'R') return 'B';

  if (first == 'S' && last == 'L') return 'R';
  if (first == 'S' && last == 'S') return 'B';
  if (first == 'S' && last == 'R') return 'L';

  if (first == 'R' && last == 'L') return 'B';
  if (first == 'R' && last == 'S') return 'L';
  if (first == 'R' && last == 'R') return 'S';

  return '?';
}

// Optimize the recorded route
void optimizeRoute() {

  bool changed = true;

  while (changed) {
    changed = false;

    for (int i = 0; i <= pathLength - 3; i++) {

      if (learnedPath[i + 1] == 'B') {

        char replacement =
          simplifyPattern(learnedPath[i],
                          learnedPath[i + 2]);

        if (replacement != '?') {

          learnedPath[i] = replacement;

          for (int j = i + 3; j < pathLength; j++) {
            learnedPath[j - 2] = learnedPath[j];
          }

          pathLength -= 2;
          learnedPath[pathLength] = '\0';

          changed = true;
          break;
        }
      }
    }
  }
}

// Suggest motor speed based on the next movement
int adaptiveSpeed(char decision) {

  if (decision == 'L' || decision == 'R')
    return 90;

  if (decision == 'S')
    return 150;

  return 80;
}

void setup() {

  Serial.begin(9600);

  Serial.println("EXPERIENCE-BASED MAZE LEARNING");
  Serial.println("--------------------------------");

  // SAMPLE DATA: simulated first exploration
  recordDecision('L');
  recordDecision('B');
  recordDecision('L');
  recordDecision('S');
  recordDecision('B');
  recordDecision('R');
  recordDecision('R');

  Serial.print("First-run route: ");
  Serial.println(learnedPath);

  Serial.println("Analyzing recorded route...");

  optimizeRoute();

  Serial.print("Optimized route: ");
  Serial.println(learnedPath);

  Serial.println("Second-run speed suggestions:");

  for (int i = 0; i < pathLength; i++) {

    Serial.print("Movement: ");
    Serial.print(learnedPath[i]);

    Serial.print(" | Suggested speed: ");
    Serial.println(adaptiveSpeed(learnedPath[i]));
  }

  Serial.println("--------------------------------");
  Serial.println("DEMONSTRATION COMPLETE");
}

void loop() {
  // This software demonstration runs once.
}

