// Fun fact! Headers are meant to make code smaller and use less resources, since you don't need to link stuff to other stuff you don't need
// Fun fact! the intake.cpp links to literally everything else, as does mogo.cpp and leftarm

// y o u a r e m o t h e r f u c k e r ?

namespace robotty
{  
  namespace intake {
    void gameIn(), gameOut();
  }

  namespace mogo {
    void mogoUp();
    void mogoDown();
    
    void mogo();
  }

  namespace leftarm {
    void armSwitch();
  }

  namespace powertrain {
    void driveFlip();
  }

  namespace function {
    int cast();
    const char * castBool(bool AAAAA, const char * trueop, const char * falseop);

    const enum vex::directionType driveDir(bool variable12345678, bool variable223142712653, const enum vex::directionType bokuwasekkusudaisuki, const enum vex::directionType itsumosekkusumainichi);
    char driveOrNot(bool variable12345678, bool variable223142712653, char helo, char chinese, char im);
    int cast (double KILLME);

    bool buttonPressing(const char * subsystem);

    bool trueYetFalse(bool yeap, bool sad);  
    }

  namespace peaceOS {
    void display();
    void incrementScreen(), main();

    void debugMode();
  }

  namespace claw {
    void clawMove();
    void clawLift();
  }
  
}