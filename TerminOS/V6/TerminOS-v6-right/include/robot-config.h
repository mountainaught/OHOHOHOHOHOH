using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;

extern motor intakeMotor;
extern motor mogoMotor;
extern motor liftMotor;

extern motor clawMotor;
extern motor clawElev;

extern motor_group leftDrive;
extern motor_group rightDrive;

extern bumper mogoStop;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

void autoCode( void );