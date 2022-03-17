#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

motor intakeMotor = motor(PORT8, ratio18_1, true);
motor mogoMotor = motor(PORT4, ratio36_1, true);
motor liftMotor = motor(PORT5, ratio18_1, true);

motor clawMotor = motor(PORT10, ratio18_1, false);
motor clawElev = motor(PORT9, ratio18_1, true);

bumper mogoStop = bumper(Brain.ThreeWirePort.C);

motor leftMotorA = motor(PORT1, ratio18_1, true);
motor leftMotorB = motor(PORT2, ratio18_1, true);
motor_group leftDrive = motor_group(leftMotorA, leftMotorB);

motor rightMotorA = motor(PORT6, ratio18_1, false);
motor rightMotorB = motor(PORT7, ratio18_1, false);
motor_group rightDrive = motor_group(rightMotorA, rightMotorB);

drivetrain Drivetrain = drivetrain(leftDrive, rightDrive, 200, 47, 45, mm, 1);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

int powerDir;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {

    
    if(driveAhead) {
      powerDir = 1;
    } else if (!driveAhead) {
      powerDir = -1;
    }
    

    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int drivetrainLeftSideSpeed = (Controller1.Axis3.position() / powerDir) + Controller1.Axis1.position() / turnSpeed;
      int drivetrainRightSideSpeed = (Controller1.Axis3.position() / powerDir) - Controller1.Axis1.position() / turnSpeed;
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          leftDrive.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          rightDrive.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        leftDrive.setVelocity(drivetrainLeftSideSpeed, percent);
        leftDrive.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        rightDrive.setVelocity(drivetrainRightSideSpeed, percent);
        rightDrive.spin(forward);
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}
