//include statements
#include "WPILib.h"
#include "math.h"

//main class
class BuiltinDefaultCode : public IterativeRobot
{
	// Declare variables/pointers (mostly for the different mechanical parts of the robot like motors, joysticks, solenoids...etc) ???
	//Exmaples...
	
	RobotDrive *drivetrain;//Drivetrain
	DriverStation *m_ds; //Driver Station Object
	
	Joystick *gamepad;//Gamepad
	
	Jaguar *topManip;//Jaguar motor
	Victor *potmotorTwo;//Victor Motor
	
	Solenoid *minibot1pressure; //Solenoid
    Compressor *pneumaticMain; //Compressor
	
	AnalogChannel *pot;//Analog channel for a pot

	DigitalInput *leftsense; //Digital Input for line tracking sensor

	Timer *minibottimer; //Timer
	PIDController *potcontroller;//PID loop
	
	
	//Something to do with joystick buttons...
	static const int NUM_JOYSTICK_BUTTONS = 12;
	bool gamepadButtonState[(NUM_JOYSTICK_BUTTONS+1)];
	
	
	// Declare global variables here...
	float right;
	bool finallydone;



public:
	

	BuiltinDefaultCode(void)	{

        //???...

		// Create a drivetrain using standard right/left robot drive on PWMS 5, 6, 7, and 8
		drivetrain = new RobotDrive(6, 8, 5, 7);
		drivetrain->SetExpiration(15);

		// Acquire the Driver Station object
		m_ds = DriverStation::GetInstance();
		m_priorPacketNumber = 0;
		m_dsPacketsReceivedInCurrentSecond = 0;

		// Create a drivetrain using standard right/left robot drive on PWMS 5, 6, 7, and 8
		drivetrain = new RobotDrive(6, 8, 5, 7);
		drivetrain->SetExpiration(15);
		
		// Acquire the Driver Station object
		m_ds = DriverStation::GetInstance();
		m_priorPacketNumber = 0;
		m_dsPacketsReceivedInCurrentSecond = 0;
		
		//Gamepad
		gamepad = new Joystick(1);
		
		//Jaguar Motor
		topManip=new Jaguar(1);
		
		//Victor Motor
		potmotorTwo = new Victor(9);
	
		//Solenoid
		minibot1pressure=new Solenoid(1);
		
		//Digital Input for line tracking sensor
		leftsense = new DigitalInput(1);

		//Compressor
		pneumaticMain=new Compressor(5,1);
		
		
		
	

		// Define global variables here
		right=0;
		finallydone=false;
		
	}
	

/********************************* Init Routines *************************************/

	void RobotInit(void) {
		// Actions which would be performed once (and only once) upon initialization of the robot would be put here.
		
		
		//Start compressor
		pneumaticMain->Start();

	}
	
	
	
	void DisabledInit(void) {	
    }



	void AutonomousInit(void) {		
	}


	void TeleopInit(void) {
    }


/********************************** Periodic Routines *************************************/
	
    void DisabledPeriodic(void)  {
		
	// while disabled, printout the duration of current disabled mode in seconds
	static INT32 printSec = (INT32)GetClock() + 1;
	static const INT32 startSec = (INT32)GetClock();
	if (GetClock() > printSec) {
		// Move the cursor back to the previous line and clear it.
		printf("\x1b[1A\x1b[2K");
		printf("Disabled seconds: %d\r\n", printSec - startSec);			
		printSec++;
	}
	
		//Set initial Solenoid value
		minibot1pressure->Set(false);
		
	}
	
	
	
	

	void AutonomousPeriodic(void) {
		
		//Autonomous code goes here...
	}



	
	void TeleopPeriodic(void) {
		/* 
	    Code placed in here will be called only when a new packet of information
	    has been received by the Driver Station.
	    */
	    
     	//Start Compressor
	    pneumaticMain->Start();		
			
			
		//declare voids
		minibot();
		elevator();
	}
	
	
	
	
/********************************** Miscellaneous Routines *************************************/

    //This is where the real code goes...	 
	
	void minibot(void) {
		//code to control minibot
	}


	void elevator(void) {
			//code to control elevator
	}
	
	//etc.....

	    
		
};

START_ROBOT_CLASS(BuiltinDefaultCode);