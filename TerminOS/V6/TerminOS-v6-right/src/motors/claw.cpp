#include "vex.h"
#include "constants.h"

using namespace vex;
using namespace robotty;


void claw::clawLift() {
  while (function::trueYetFalse(Controller1.ButtonUp.pressing(), Controller1.ButtonDown.pressing())) {
    clawElev.spin(function::driveDir(Controller1.ButtonUp.pressing(), Controller1.ButtonDown.pressing(), forward, reverse), clawLiftSpeed, percent);
  wait(100, msec);
  }

  clawElev.stop();
}


void claw::clawMove() {
  // Potentially change to function::buttonPressing
  while (function::trueYetFalse(Controller1.ButtonLeft.pressing(), Controller1.ButtonRight.pressing())) {
    clawMotor.spin(function::driveDir(Controller1.ButtonLeft.pressing(), Controller1.ButtonRight.pressing(), forward, reverse), clawSpeed, percent);
  wait(100, msec);
  }

  clawMotor.stop();
}

/*
void claw::clawMove() {
  bool gear = function::driveOrNot(Controller1.ButtonLeft.pressing(), Controller1.ButtonRight.pressing(), );
}*/


/* Future implementation pending bugfix, use of clutch-style logic instead of simple while-done
void claw::clawLift() {
  switch (function::driveOrNot(Controller1.ButtonUp.pressing(), Controller1.ButtonDown.pressing(), 'D', 'N')) {
    case 'D':
      clawMotor.spin(function::driveDir(Controller1.ButtonUp.pressing(), Controller1.ButtonDown.pressing(), forward, reverse), 10, percent);
      break;
    case 'N':
      clawMotor.stop();
      break;
  }
}   
*/