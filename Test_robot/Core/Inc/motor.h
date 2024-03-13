/*
 * motor.h
 *
 *  Created on: Mar 13, 2024
 *      Author: phamv
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

void motor_init();

void motor_dir_forward(int id);

void motor_dir_backward(int id);

void motor_stop(int id);

void motor_set_speed(int id, int speed);

void motor_run();

void RunForward();

void RunBackward();

void Stop();

void TurnLeft();

void TurnRight();

#endif /* INC_MOTOR_H_ */
