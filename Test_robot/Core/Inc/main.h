/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR1_FORWARD_Pin GPIO_PIN_0
#define MOTOR1_FORWARD_GPIO_Port GPIOA
#define MOTOR1_BACKWARD_Pin GPIO_PIN_1
#define MOTOR1_BACKWARD_GPIO_Port GPIOA
#define MOTOR2_FORWARD_Pin GPIO_PIN_2
#define MOTOR2_FORWARD_GPIO_Port GPIOA
#define MOTOR2_BACKWARD_Pin GPIO_PIN_3
#define MOTOR2_BACKWARD_GPIO_Port GPIOA
#define MOTOR3_FORWARD_Pin GPIO_PIN_4
#define MOTOR3_FORWARD_GPIO_Port GPIOA
#define MOTOR3_BACKWARD_Pin GPIO_PIN_5
#define MOTOR3_BACKWARD_GPIO_Port GPIOA
#define LED_DEBUG_Pin GPIO_PIN_2
#define LED_DEBUG_GPIO_Port GPIOB
#define MOTOR4_FORWARD_Pin GPIO_PIN_8
#define MOTOR4_FORWARD_GPIO_Port GPIOA
#define MOTOR4_BACKWARD_Pin GPIO_PIN_9
#define MOTOR4_BACKWARD_GPIO_Port GPIOA
#define LEFT_LINE_Pin GPIO_PIN_4
#define LEFT_LINE_GPIO_Port GPIOB
#define CENTER_LINE_Pin GPIO_PIN_5
#define CENTER_LINE_GPIO_Port GPIOB
#define RIGHT_LINE_Pin GPIO_PIN_6
#define RIGHT_LINE_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
