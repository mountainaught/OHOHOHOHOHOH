#include "vex.h"

using namespace vex;
using namespace robotty;

// inb4 might move to functions

void powertrain::driveFlip() {
  if(driveAhead) {
    driveAhead = false;
  } else if (!driveAhead) {
    driveAhead = true;
  }

  waitUntil(!Controller1.ButtonB.pressing());
}