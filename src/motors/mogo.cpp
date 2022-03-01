#include "vex.h"

using namespace vex;
using namespace robotty;

// Yes this is inefficient
// Yes every single motor commands works this way
// No I don't know how to make it better
// Yes I'm gonna brute force it
 
// Debug-Test Mode

/*
void mogo::mogoUp() {
  while (Controller1.ButtonR1.pressing() && !mogoStop.pressing()){
    mogoMotor.spin(forward);
  wait(10, msec);
  } 
  mogoMotor.stop();
}

void mogo::mogoDown() {
  while (Controller1.ButtonR2.pressing()) {
    mogoMotor.spin(reverse);
  wait(10, msec);
  }
  mogoMotor.stop();
}
*/

// Drive code

void mogo::mogo() {
  while(function::trueYetFalse(Controller1.ButtonR1.pressing(), Controller1.ButtonR2.pressing()) && !mogoStop.pressing()) {
    mogoMotor.spin(function::driveDir(Controller1.ButtonR1.pressing(), Controller1.ButtonR2.pressing(), forward, reverse), mogoSpeed, percent);
  wait(10, msec);
  }
  mogoMotor.stop();
}