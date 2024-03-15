/*
 * sensor.c
 *
 *  Created on: Mar 14, 2024
 *      Author: phamv
 */

#include "sensor.h"
#include "gpio.h"
#include "motor.h"

#define INIT		0
#define LINE_CENTER	1
#define LINE_LEFT	2
#define LINE_RIGHT	3
//#define INIT		0

uint8_t sensor_line = 0;
int status_robot = 0;

void getLineSensor(){
	sensor_line = 0;
	if(HAL_GPIO_ReadPin(LEFT_LINE_GPIO_Port, LEFT_LINE_Pin) == 0) sensor_line += 4;
	if(HAL_GPIO_ReadPin(CENTER_LINE_GPIO_Port, CENTER_LINE_Pin) == 0) sensor_line += 2;
	if(HAL_GPIO_ReadPin(RIGHT_LINE_GPIO_Port, RIGHT_LINE_Pin) == 0) sensor_line += 1;
}

void lineFollow(){
	switch (status_robot) {
		case INIT:
			if(sensor_line == 0b010) status_robot = LINE_CENTER;
			if(sensor_line == 0b100 || sensor_line == 0b110){
				status_robot = LINE_LEFT;
			}
			if(sensor_line == 0b001 || sensor_line == 0b011){
				status_robot = LINE_LEFT;
			}
			break;
		case LINE_CENTER:
			RunForward();
			if(sensor_line == 0b000){
				RunBackward();
			}

			if(sensor_line == 0b100 || sensor_line == 0b110){
				status_robot = LINE_LEFT;
			}
			if(sensor_line == 0b001 || sensor_line == 0b011){
				status_robot = LINE_RIGHT;
			}

			break;
		case LINE_RIGHT:
			motor_set_speed(MOTOR_TOP_LEFT, 80);
			motor_set_speed(MOTOR_BOT_LEFT, 80);
			motor_set_speed(MOTOR_TOP_RIGHT, 50);
			motor_set_speed(MOTOR_BOT_RIGHT, 50);
			motor_dir_forward(MOTOR_TOP_LEFT);
			motor_dir_forward(MOTOR_BOT_LEFT);
			motor_dir_forward(MOTOR_TOP_RIGHT);
			motor_dir_forward(MOTOR_BOT_RIGHT);

			if(sensor_line == 0b000) TurnRight();

			if(sensor_line == 0b010) {
				Stop();
				status_robot = LINE_CENTER;
			}
			break;

		case LINE_LEFT:
			motor_set_speed(MOTOR_TOP_LEFT, 50);
			motor_set_speed(MOTOR_BOT_LEFT, 50);
			motor_set_speed(MOTOR_TOP_RIGHT, 80);
			motor_set_speed(MOTOR_BOT_RIGHT, 80);
			motor_dir_forward(MOTOR_TOP_LEFT);
			motor_dir_forward(MOTOR_BOT_LEFT);
			motor_dir_forward(MOTOR_TOP_RIGHT);
			motor_dir_forward(MOTOR_BOT_RIGHT);

			if(sensor_line == 0b000) TurnLeft();

			if(sensor_line == 0b010) {
				Stop();
				status_robot = LINE_CENTER;
			}
			break;
		default:
			break;
	}
//	switch (sensor_line) {
//		case 0b000:
//			Stop();
//			break;
//		case 0b110:
//			RunForward();
//			motor_set_speed(MOTOR_TOP_LEFT, 50);
//			motor_set_speed(MOTOR_BOT_LEFT, 50);
//			motor_set_speed(MOTOR_TOP_RIGHT, 60);
//			motor_set_speed(MOTOR_BOT_RIGHT, 60);
//			break;
//		case 0b011:
//			RunForward();
//			motor_set_speed(MOTOR_TOP_LEFT, 60);
//			motor_set_speed(MOTOR_BOT_LEFT, 60);
//			motor_set_speed(MOTOR_TOP_RIGHT, 50);
//			motor_set_speed(MOTOR_BOT_RIGHT, 50);
//			break;
//		case 0b100:
//			RunForward();
//			motor_set_speed(MOTOR_TOP_LEFT, 50);
//			motor_set_speed(MOTOR_BOT_LEFT, 50);
//			motor_set_speed(MOTOR_TOP_RIGHT, 80);
//			motor_set_speed(MOTOR_BOT_RIGHT, 80);
//			break;
//		case 0b010:
//			RunForward();
//			break;
//		case 0b001:
//			RunForward();
//			motor_set_speed(MOTOR_TOP_LEFT, 80);
//			motor_set_speed(MOTOR_BOT_LEFT, 80);
//			motor_set_speed(MOTOR_TOP_RIGHT, 50);
//			motor_set_speed(MOTOR_BOT_RIGHT, 50);
//			break;
//		default:
//			break;
//	}
}
