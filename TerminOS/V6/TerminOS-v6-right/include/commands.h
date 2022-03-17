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