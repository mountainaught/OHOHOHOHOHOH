#include "vex.h"
#include <sstream>


using namespace vex;
using namespace robotty;

int screenTab = 1;
const int screenMax = 3;

// void errorMotor ( void );

void peaceOS::incrementScreen() {
  switch (screenTab) {
    case screenMax:
      screenTab = 1;
    break;

    default:
      screenTab = screenTab + 1;
  }

  Controller1.Screen.clearScreen();
}

void peaceOS::main() {
  Controller1.Screen.clearScreen();
  screenTab = 1;
}

void peaceOS::display() {
  switch (screenTab) {
    case 1:
      Controller1.Screen.setCursor(0, 1);
      Controller1.Screen.print("Batt. %d", Brain.Battery.capacity());

      Controller1.Screen.setCursor(2, 1);
      Controller1.Screen.print("mStop %s", function::castBool(mogoStop.pressing(), "locked", "free"));

      Controller1.Screen.setCursor(4, 1);
      Controller1.Screen.print("drive %s", function::castBool(driveAhead, "fwd", "rev"));
      break;

    case 2:
      Controller1.Screen.setCursor(0, 1);
      Controller1.Screen.print("Mogo %d", function::cast(mogoMotor.temperature(celsius)));

      Controller1.Screen.setCursor(2, 1);
      Controller1.Screen.print("left %d", function::cast(leftDrive.temperature(celsius)));

      Controller1.Screen.setCursor(4, 1);
      Controller1.Screen.print("right %d", function::cast(rightDrive.temperature(celsius)));

      break;
    
    case screenMax:
      Controller1.Screen.setCursor(0, 2);
      Controller1.Screen.print("----System Errors----");

      // Section for Motor Errors
      // errorMotor();

      /*
      Controller1.Screen.setCursor(2, 1);
      Controller1.Screen.print( (rightDrive.temperature(celsius) > 30) || (leftDrive.temperature(celsius) > 55) ? "Drivetrain Overheat" : "");
      */

      // Section for General Errors
      Controller1.Screen.setCursor(4, 1);
      Controller1.Screen.print( (Brain.Battery.capacity() < 35) ? "Batt. Low" : "");

      break;
  }

}


// -- DEBUG FEATURE --
/*********************
Will disable all regular bindings

Consider implementing the main logic into the usercontrol() loop in main.cpp, as doing it under this loop will cause multithread issues
This can act as general watchdog

*/
void peaceOS::debugMode() {
  bool debugActive = true; // Move to constants to allow finer control of motors in subsystem logic
  bool debugConfirm = false; // Used once when entering debug mode

  while(debugActive) {
    // display thingy here
    if (Controller1.ButtonY.pressing()) {
      debugConfirm = true;
    } else if ( Controller1.ButtonB.pressing() ) {
      debugActive = false;
      return;
    }

    while( debugActive && debugConfirm ) {

    }
  }
}


// Motor error page

/*
void errorMotor() {
  if ( rightDrive.temperature(celsius) || leftDrive.temperature(celsius) > 30) {
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.clearLine(2);

    Controller1.Screen.print("Drivetrain Overheat");
    wait(4, sec);
  }
  if ( mogoMotor.temperature(celsius) > 10 ) {
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.clearLine(2);

    Controller1.Screen.print("Mogo Overheat");
    wait(4, sec);
  }
}
*/

// Print image onto V5 screen via sd card
// Current code is for printing a GIF that has been divided into a million images lmao

// GOD I HATE C++!
// AHAHAHAHAHAHAHAH WHY IS THIS SO HORRIBLE? SO MUCH INLINE BULLSHIT!

/*
void peaceOS::brainDisplay() {
  while(true) {

    for (int frame = 0; frame <= 26; frame++) {
    std::string lmao = static_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << frame ) ).str();

    std::string printFrame = "frame_" + lmao +  "_delay-0.02s.png";

    Brain.Screen.drawImageFromFile(printFrame.c_str(), 1, 1); 
    wait(0.02, sec);    
    }

    wait(10, msec);
  }
}
*/
