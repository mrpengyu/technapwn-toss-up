#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    POT_LIFT,       sensorPotentiometer)
#pragma config(Sensor, in2,    GYRO,           sensorGyro)
#pragma config(Sensor, in3,    POT_SELECTOR,   sensorPotentiometer)
#pragma config(Sensor, dgtl1,  QUAD_LEFT,      sensorQuadEncoder)
#pragma config(Sensor, dgtl12, CATAPULT,       sensorDigitalOut)
#pragma config(Motor,  port1,           DRIVE_BL1,     tmotorVex393, openLoop)
#pragma config(Motor,  port2,           DRIVE_BR2,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           LIFT_R,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           DRIVE_FR,      tmotorVex393, openLoop)
#pragma config(Motor,  port5,           DRIVE_FL,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           INTK_L,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           LIFT_L2,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           LIFT_L,        tmotorVex393, openLoop)
#pragma config(Motor,  port9,           DRIVE_BL2,     tmotorVex393, openLoop)
#pragma config(Motor,  port10,          DRIVE_BR1,     tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "DefinitionsAndDeclarations.c"
#include "Autos/Scripts.c"
#include "Autos/AutoTests.c"
#include "Autos/AutoRedMiddle.c"
#include "Autos/AutoBlueMiddle.c"
#include "Autos/AutoRedHanging.c"
#include "Autos/AutoBlueHanging.c"
#include "Autos/AutoRedProgSkills.c"
#include "OtherFunctions.c"
#include "State.c"
#include "Sensors.c"
#include "Operator.c"
#include "Autonomous.c"
#include "Output.c"
#include "LCD.c"
//#include "Sound.c"

//============= Nora.c =============//
//    Author: Joseph Dykstra        //
//      Team: Techna PWN Robotics   //
//   Created: 2013-05-15            //
//============== 3018 ==============//

task main()
	{
	initializeOutput();
	initializeLCD();
	initializeSensors();
	while(1)
		{
		inputProcessState();
		inputSensors();
		inputOperator();

		processLCD();
		if (sysState.curr == OPERATOR)
			{
			processScripts();
			processOperator();
			}
		else if (sysState.curr == AUTONOMOUS)
			{
			processAutonomous();
			}

		outputMotion();
		outputLCD();
		//outputSound();
		constantLoopTime();
		}
	}