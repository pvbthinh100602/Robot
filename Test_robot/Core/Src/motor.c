/*
 * motor.c
 *
 *  Created on: Mar 13, 2024
 *      Author: phamv
 */

#include "motor.h"
#include "tim.h"

#define STOP		0
#define FORWARD		1
#define BACKWARD	2

int motor_dir[4] = {STOP, STOP, STOP, STOP};

#define MOTOR1 0
#define MOTOR2 1
#define MOTOR3 2
#define MOTOR4 3

uint16_t motor_forward_pin[4] = {MOTOR1_FORWARD_Pin, MOTOR2_FORWARD_Pin, MOTOR3_FORWARD_Pin, MOTOR4_FORWARD_Pin};
uint16_t motor_backward_pin[4] = {MOTOR1_BACKWARD_Pin, MOTOR2_BACKWARD_Pin, MOTOR3_BACKWARD_Pin, MOTOR4_BACKWARD_Pin};

int motor_speed[4] = {0,0,0,0};

void motor_init(){
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
}

void motor_dir_forward(int id){
	if(id < 0 || id > 3) return;
	motor_dir[id] = FORWARD;
}

void motor_dir_backward(int id){
	if(id < 0 || id > 3) return;
	motor_dir[id] = BACKWARD;
}

void motor_stop(int id){
	if(id < 0 || id > 3) return;
	motor_dir[id] = STOP;
	motor_speed[id] = 0;
}

void motor_set_speed(int id, int speed){
	if(speed < 0 || speed > 100) return;
	motor_speed[id] = speed;
}

void testing(){
	HAL_GPIO_WritePin(GPIOA, motor_forward_pin[0], 1);
	HAL_GPIO_WritePin(GPIOA, motor_backward_pin[0], 0);
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 80);
}

void motor_run(){
	for(int id = 0; id < 4; id++){
		switch (motor_dir[id]) {
			case STOP:
				HAL_GPIO_WritePin(GPIOA, motor_forward_pin[id], 0);
				HAL_GPIO_WritePin(GPIOA, motor_backward_pin[id], 0);
				break;
			case FORWARD:
				HAL_GPIO_WritePin(GPIOA, motor_forward_pin[id], 1);
				HAL_GPIO_WritePin(GPIOA, motor_backward_pin[id], 0);
				break;
			case BACKWARD:
				HAL_GPIO_WritePin(GPIOA, motor_forward_pin[id], 0);
				HAL_GPIO_WritePin(GPIOA, motor_backward_pin[id], 1);
				break;
			default:
				break;
		}
	}
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, motor_speed[0]);
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, motor_speed[1]);
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_3, motor_speed[2]);
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_4, motor_speed[3]);
}

void RunForward(){
	motor_set_speed(MOTOR1, 60);
	motor_set_speed(MOTOR2, 60);
	motor_set_speed(MOTOR3, 60);
	motor_set_speed(MOTOR4, 60);
	motor_dir_forward(MOTOR1);
	motor_dir_forward(MOTOR2);
	motor_dir_forward(MOTOR3);
	motor_dir_forward(MOTOR4);
}

void RunBackward(){
	motor_set_speed(MOTOR1, 60);
	motor_set_speed(MOTOR2, 60);
	motor_set_speed(MOTOR3, 60);
	motor_set_speed(MOTOR4, 60);
	motor_dir_backward(MOTOR1);
	motor_dir_backward(MOTOR2);
	motor_dir_backward(MOTOR3);
	motor_dir_backward(MOTOR4);
}

void Stop(){
	motor_stop(MOTOR1);
	motor_stop(MOTOR2);
	motor_stop(MOTOR3);
	motor_stop(MOTOR4);
}

void TurnLeft(){

}

void TurnRight(){

}
