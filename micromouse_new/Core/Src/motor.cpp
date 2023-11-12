/*
 * motor.cpp
 *
 *  Created on: Nov 11, 2023
 *      Author: lethalpanda13
 */


#include <iostream>  // For input and output
#include <stdexcept> // For exceptions
#include "motor.h"
#include "main.h"

//sets Left OR Right Motor to
void Motor_Forward(int x) {
	//left motor forward
	if(x = 0){
		HAL_GPIO_WritePin(LMOTOR_GPIO_PORT, LMOTOR_DIR1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LMOTOR_GPIO_PORT, LMOTOR_DIR2_PIN, GPIO_PIN_RESET);
	}
	//right motor forward
	else{
		HAL_GPIO_WritePin(RMOTOR_GPIO_PORT, RMOTOR_DIR1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RMOTOR_GPIO_PORT, RMOTOR_DIR2_PIN, GPIO_PIN_RESET);
	}
}

void Motor_Reverse(int x) {
	//left motor backward
	if(x = 0){
		HAL_GPIO_WritePin(LMOTOR_GPIO_PORT, LMOTOR_DIR1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LMOTOR_GPIO_PORT, LRMOTOR_DIR2_PIN, GPIO_PIN_SET);
	}
	//right motor backward
	else{
		HAL_GPIO_WritePin(RMOTOR_GPIO_PORT, RMOTOR_DIR1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RMOTOR_GPIO_PORT, RMOTOR_DIR2_PIN, GPIO_PIN_SET);
	}
}


// Function to set PWM duty cycle for the left motor
void SetLeftMotorSpeed(uint16_t speed) {
  // Ensure the speed is within bounds (0 to 100)
  if (speed > 100) {
    speed = 100;
  }

  // Calculate pulse value based on the desired duty cycle
  uint32_t pulse = (htim_left.Init.Period * speed) / 100;

  // Set the pulse value for the left motor PWM channel
  __HAL_TIM_SET_COMPARE(&htim_left, TIM_CHANNEL_1, pulse);
}



// Function to set PWM duty cycle for the right motor
void SetRightMotorSpeed(uint16_t speed) {
  // Ensure the speed is within bounds (0 to 100)
  if (speed > 100) {
    speed = 100;
  }

  // Calculate pulse value based on the desired duty cycle
  uint32_t pulse = (htim_right.Init.Period * speed) / 100;

  // Set the pulse value for the right motor PWM channel
  __HAL_TIM_SET_COMPARE(&htim_right, TIM_CHANNEL_1, pulse);
}




void RightTurn(uint16_t LeftSpeed, uint16_t RightSpeed) {

    Motor_Forward(1);
    Motor_Reverse(0);

    SetLeftMotorSpeed(LeftSpeed);
    SetRightMotorSpeed(RightSpeed);
}

void LeftTurn(uint16_t LeftSpeed, uint16_t RightSpeed) {

    Motor_Forward(0);
    Motor_Reverse(1);

    SetLeftMotorSpeed(LeftSpeed);
    SetRightMotorSpeed(RightSpeed);
}




//MUST READ FROM DIFFERENT SENSORS TO CALCULATE DIFFERENT LEFT AND RIGHT SPEEDS
// Function to read IR sensor values
float ReadIRSensor() {
  // Implement your code to read IR sensor values
  // Return the distance via converting the read voltage into a float that the PID can use
  // ...

  return 0.0f; // Placeholder, replace with actual sensor reading
}





// Define constants
#define KP 1.0f  // Proportional gain
#define KI 0.1f  // Integral gain
#define KD 0.01f // Derivative gain

#define DESIRED_DISTANCE 50.0f // Desired distance from the wall (must change)

// Variables for PID control
float error = 0.0f;
float integral = 0.0f;
float derivative = 0.0f;
float previousError = 0.0f;


// PID control function
void PIDControl() {
  float actualDistance = ReadIRSensor();
  error = DESIRED_DISTANCE - actualDistance;
  integral += error;
  derivative = error - previousError;

  // PID control equation
  float pidOutput = KP * error + KI * integral + KD * derivative;

  // Adjust motor speed based on PID output
  SetMotorSpeed((uint16_t)pidOutput);

  // Update previous error for the next iteration
  previousError = error;
}
