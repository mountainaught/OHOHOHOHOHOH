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
  mogoMotor.setVelocity(90.0, percent);

  // Go forward and grab goal
  // 500 for termina, 500 for t4p
  mogoMotor.spinFor(reverse, 500.0, degrees);
  // wait(0.29, seconds);
  autoDrive(42.5);
  mogoMotor.setVelocity(70.0, percent);
  mogoMotor.spinFor(forward, 500.0, degrees, true);

  // Left
  autoTurn(-90.0);
  autoDrive(23.0);

  // Right
  autoTurn(-90.0);

  // Go forward and grab things
  liftMotor.spin(forward);
  intakeMotor.spin(forward);
  leftDrive.setVelocity(15.0, percent);
  rightDrive.setVelocity(15.0, percent);
  autoDrive(-75.0);

  // Go back
  leftDrive.setVelocity(40.0, percent);
  rightDrive.setVelocity(40.0, percent);
  autoDrive(90.0);

  // Place goal down
  mogoMotor.spinFor(reverse, 500.0, degrees);
  autoDrive(-10.0);
  liftMotor.stop();
  intakeMotor.stop();
 
}