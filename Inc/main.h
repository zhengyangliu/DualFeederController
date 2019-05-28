/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_LED_1_Pin GPIO_PIN_13
#define BTN_LED_1_GPIO_Port GPIOC
#define BTN_YELLOW_1_Pin GPIO_PIN_14
#define BTN_YELLOW_1_GPIO_Port GPIOC
#define BTN_GREEN_1_Pin GPIO_PIN_15
#define BTN_GREEN_1_GPIO_Port GPIOC
#define GATE_1B_Pin GPIO_PIN_0
#define GATE_1B_GPIO_Port GPIOA
#define GATE_1A_Pin GPIO_PIN_3
#define GATE_1A_GPIO_Port GPIOA
#define SOLCTL_1_Pin GPIO_PIN_4
#define SOLCTL_1_GPIO_Port GPIOA
#define H1_IN1_Pin GPIO_PIN_6
#define H1_IN1_GPIO_Port GPIOA
#define H1_IN2_Pin GPIO_PIN_7
#define H1_IN2_GPIO_Port GPIOA
#define H1_IN4_Pin GPIO_PIN_0
#define H1_IN4_GPIO_Port GPIOB
#define H1_IN3_Pin GPIO_PIN_1
#define H1_IN3_GPIO_Port GPIOB
#define GATE_0A_Pin GPIO_PIN_10
#define GATE_0A_GPIO_Port GPIOB
#define SOLCTL_0_Pin GPIO_PIN_11
#define SOLCTL_0_GPIO_Port GPIOB
#define GATE_0B_Pin GPIO_PIN_8
#define GATE_0B_GPIO_Port GPIOA
#define TXD_Pin GPIO_PIN_9
#define TXD_GPIO_Port GPIOA
#define RXD_Pin GPIO_PIN_10
#define RXD_GPIO_Port GPIOA
#define BTN_LED_0_Pin GPIO_PIN_12
#define BTN_LED_0_GPIO_Port GPIOA
#define H0_IN1_Pin GPIO_PIN_15
#define H0_IN1_GPIO_Port GPIOA
#define H0_IN2_Pin GPIO_PIN_3
#define H0_IN2_GPIO_Port GPIOB
#define BTN_YELLOW_0_Pin GPIO_PIN_4
#define BTN_YELLOW_0_GPIO_Port GPIOB
#define BTN_GREEN_0_Pin GPIO_PIN_5
#define BTN_GREEN_0_GPIO_Port GPIOB
#define H0_IN4_Pin GPIO_PIN_6
#define H0_IN4_GPIO_Port GPIOB
#define H0_IN3_Pin GPIO_PIN_7
#define H0_IN3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
