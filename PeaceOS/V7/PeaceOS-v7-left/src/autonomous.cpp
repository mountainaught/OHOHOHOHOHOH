#include "vex.h"
using namespace vex;

// using namespace robotty;

void autoDrive(double dist) {
  leftDrive.spinFor(forward, (dist / 43.2), turns, false);
  rightDrive.spinFor(forward, (dist / 43.2), turns, true);
}

void autoTurn(double head) {
  leftDrive.spinFor(forward, (head * 0.00739), turns, false);
  rightDrive.spinFor(reverse, (head * 0.00739), turns, true);
}

void autoCode() {
  leftDrive.setVelocity(40.0, percent);
  rightDrive.setVelocity(40.0, percent);

  intakeMotor.setVelocity(90.0, percent);
  liftMotor.setVelocity(80.0, percent);
  mogoMotor.setVelocity(120.0, percent);

 // Go forward and grab things
  leftDrive.setVelocity(66.05, percent);
  rightDrive.setVelocity(66.0, percent);
  mogoMotor.spinFor(reverse, 510.0, degrees);
  autoDrive(126.5);

  // Go back
  mogoMotor.spinFor(forward, 500.0, degrees);
  leftDrive.setVelocity(40.0, percent);
  rightDrive.setVelocity(40.0, percent);
  autoDrive(-95.0);

  // Place goal down
  mogoMotor.spinFor(reverse, 500.0, degrees);
  autoDrive(-20.0);
  liftMotor.stop();
  intakeMotor.stop();
 
}