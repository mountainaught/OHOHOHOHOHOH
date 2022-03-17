#include "vex.h"

using namespace vex;
using namespace robotty;

// WILL PORT TO FUNCTION-BASED
// CONSIDER UTILISING JAVA-LIKE INTERFACE FOR MOTOR-CONTROLLER LOGIC

void intake::gameIn() {

  // Need to simultaneously call motors as with other motors.
  // Issue arises with vexcode's lack of multithreading
  while (Controller1.ButtonL1.pressing()) {
    liftMotor.spin(forward);
    intakeMotor.spin(forward);
  wait(10, msec);
  }
  intakeMotor.stop();
  liftMotor.stop();
}

void intake::gameOut() {
  while (Controller1.ButtonL2.pressing()) {
    liftMotor.spin(reverse);
    intakeMotor.spin(reverse);
  wait(10, msec);
  }
  intakeMotor.stop();
  liftMotor.stop();
}