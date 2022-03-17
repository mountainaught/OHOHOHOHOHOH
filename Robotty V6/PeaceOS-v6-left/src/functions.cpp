#include "vex.h"
using namespace robotty;

// NOTE: CONSIDER REMOVING FROM vex.h AS UNLINKING FROM UNNECESARRY LIBS

const char * function::castBool (bool AAAAA, const char * trueop, const char * falseop) {
  return AAAAA ? trueop : falseop;
}

int function::cast (double SHENZHENGUANGDONG) {
  return static_cast < int > (SHENZHENGUANGDONG);
}

const enum vex::directionType function::driveDir(bool variable12345678, bool variable223142712653, const enum vex::directionType bokuwasekkusudaisuki, const enum vex::directionType itsumosekkusumainichi) {
  if(variable12345678 && !variable223142712653) {
    return bokuwasekkusudaisuki;
  } else if (!variable12345678 && variable223142712653) {
      return itsumosekkusumainichi;
  } else {
      return itsumosekkusumainichi;
  }
}

/*
char function::driveOrNot(bool variable12345678, bool variable223142712653, char helo, char chinese, char im) {
  if(variable12345678 && !variable223142712653) {
    return helo;
  } else if (!variable12345678 && variable223142712653) {
      return chinese;
  } else {
      return im;
  }
}*/


bool function::trueYetFalse(bool yeap, bool sad) {
    if(yeap && !sad) {
    return true;
  } else if (!yeap && sad) {
      return true;
  } else {
      return false;
  }
}

/*
bool function::buttonPressing(const char * subsystem) {
  if (subsystem == "mogo") {
    if ( Controller1.ButtonL1.pressing() || Controller1.ButtonL2.pressing() ) {
      return true;
    } else if ( !Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing() ) {
      return false;
    }
  }
}
*/