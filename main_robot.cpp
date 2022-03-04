/*---------------------------------------------------------------------------*/
/* */
/* Autonomous Task */
/* */
/* This task is used to control your robot during the autonomous phase of */
/* a VEX Competition. */
/* */
/* You must modify the code to add your own robot specific commands here. */
/*---------------------------------------------------------------------------*/
 
void autonomous(void) {
// ..........................................................................
// Insert autonomous user code here.
// ..........................................................................
 Drivetrain.setDriveVelocity(100, percent);
 CyberArms.setStopping(hold);
 CyberArms.setPosition(25, degrees);
 Fishy.set(false);
 Drivetrain.driveFor(forward, 55, inches, true);
 Fishy.set(true);
 Drivetrain.driveFor(reverse,60, inches);
 }
 
/*---------------------------------------------------------------------------*/
/* */
/* User Control Task */
/* */
/* This task is used to control your robot during the user control phase of */
/* a VEX Competition. */
/* */
/* You must modify the code to add your own robot specific commands here. */
/*---------------------------------------------------------------------------*/
 
void usercontrol(void) {
 
 CyberArms.setVelocity(35, percent);
// User control code here, inside the loop
 while (1) {
   CyberArms.setStopping(hold);
   // Drivetrain.setDriveVelocity(90, percent);
   // Drivetrain.setTurnVelocity(100, percent);
 
  
   if (Controller1.ButtonR1.pressing()) {
     Controller1.Screen.clearLine();
     Controller1.Screen.print("R1 pressed");
     Fishy.set(false);
   }
  
   if (Controller1.ButtonR2.pressing()) {
     Controller1.Screen.clearLine();
     Controller1.Screen.print("R2 pressed");
     Fishy.set(true);
   }
 
 
   //Forwards and Backwards
   if (Controller1.Axis3.position() >= 10) {
      Drivetrain.setDriveVelocity(90, percent);
       Drivetrain.drive(forward);
   } else if (Controller1.Axis3.position() <= -10) {
      Drivetrain.setDriveVelocity(90, percent);
       Drivetrain.drive(reverse);
   } else if (Controller1.Axis3.position() == 0){
      Controller1.Screen.clearLine();
       Controller1.Screen.print("stop drivetrain");
       Drivetrain.setDriveVelocity(0.1, percent);
   }
 
   //Left to Right
   if (Controller1.Axis1.position() >= 10) {
     Drivetrain.setTurnVelocity(90,percent);
       Drivetrain.turn(right);
   }else if (Controller1.Axis1.position() <= -10) {
     Drivetrain.setTurnVelocity(90,percent);
       Drivetrain.turn(left);
   } else if (Controller1.Axis1.position() == 0) {
     Controller1.Screen.clearLine();
     Controller1.Screen.print("Stop Turning");
     Drivetrain.turnFor(right, 0, degrees);
   }
 
   wait(20, msec); // Sleep the task for a short amount of time to
   // prevent wasted resources.
 }
}
 
//
// Main will set up the competition functions and callbacks.
//
int main() {
 // Set up callbacks for autonomous and driver control periods.
 Competition.autonomous(autonomous);
 Competition.drivercontrol(usercontrol);
 
 // Run the pre-autonomous function.
 pre_auton();
 
 // Prevent main from exiting with an infinite loop.
 while (true) {
 wait(100, msec);
 }
}
 
