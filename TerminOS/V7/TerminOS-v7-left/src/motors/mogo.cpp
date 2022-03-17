#include "vex.h"

using namespace vex;
using namespace robotty;


//new bumper code -fixed March 2022

void mogo::mogoUp(){
  while (Controller1.ButtonR1.pressing()&& !mogoStop.pressing()){
    mogoMotor.spin(forward);
  wait(10, msec);
  }
 mogoMotor.stop();
}

void mogo::mogoDown(){
  while(Controller1.ButtonR2.pressing()){
    mogoMotor.spin(reverse);
  wait(10, msec);
  }
  mogoMotor.stop();
}

/*
void mogo::mogoUp(){
  while(Controller1.ButtonR1.pressing()){
    if(!mogoStop.pressing()){
      mogoMotor.spin(forward);
      wait(10, msec);
    }
    mogoMotor.stop();
  }
}

  void mogo::mogoDown(){
    while(Controller1.ButtonR1.pressing()){
      mogoMotor.spin(reverse);
    }
    mogoMotor.stop();
}
*/
// Drive code
/*
void mogo::mogo() {
  while(function::trueYetFalse(Controller1.ButtonR1.pressing(), Controller1.ButtonR2.pressing()) && !mogoStop.pressing()) {
    mogoMotor.spin(function::driveDir(Controller1.ButtonR1.pressing(), Controller1.ButtonR2.pressing(), forward, reverse), mogoSpeed, percent);
  wait(10, msec);
  }
  mogoMotor.stop();
}
*/