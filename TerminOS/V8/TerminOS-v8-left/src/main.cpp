/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\rexilius && C:\Users\bagel                       */
/*    Created:      Fri Dec 17 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/**

********** BUTTON-PORT ASSIGNMENT **********
CLAWMOTOR   PORT 10   BUTTONS LEFT-RIGHT
CLAWLIFT    PORT 9    BUTTONS UP-DOWN

**/

#include "vex.h"

using namespace vex;
competition Competition;

using namespace robotty;

void paramConfig() {
  intakeMotor.setVelocity(intakeSpeed, percent);
  liftMotor.setVelocity(liftSpeed, percent);

  clawElev.setBrake(hold);
  clawMotor.setBrake(hold);

}

void autonomous() {
  autoCode();
}

void usercontrol() {
  // Consider implementing two-way switch, where entering debug is achieved by way of the main while loop ending
  // As main() repeats infinitely, usercontrol() is called infinitely
  // Would be dangerous if it were to start during a match, however, so need easy functionality to disable prior to tournament

  while (1) {
    Controller1.ButtonL1.pressed(intake::gameIn);
    Controller1.ButtonL2.pressed(intake::gameOut);

    //Controller1.ButtonR1.pressed(mogo::mogo);
    //Controller1.ButtonR2.pressed(mogo::mogo);           //Commented as in Mogo Stop Function Debug Test Done

    Controller1.ButtonB.pressed(powertrain::driveFlip);

    peaceOS::display();

    Controller1.ButtonA.pressed(peaceOS::incrementScreen);
    Controller1.ButtonX.pressed(peaceOS::main);

    // for terminus robot

    // Call same function following implementation of functions
    Controller1.ButtonUp.pressed(claw::clawLift);
    Controller1.ButtonDown.pressed(claw::clawLift);

    Controller1.ButtonRight.pressed(claw::clawMove);
    Controller1.ButtonLeft.pressed(claw::clawMove);

    wait(20, msec);
  }
  
}

int main() {
  vexcodeInit();

  paramConfig();

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  wait(100, msec);

  
}
