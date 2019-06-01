#ifndef __IO_H
#define __IO_H

#include <board.h>

#define CHANNEL0                                           0
#define CHANNEK1                                           1

/* ----------------------------- 通道0接口定义 ------------------------------ */
/* 光电开关接口 */
#define CHANNEL0_FRONT_PHOTOELECTRIC_SWTICH_PIN            GET_PIN(B, 10)
#define CHANNEL0_BACK_PHOTOELECTRIC_SWTICH_PIN             GET_PIN(A,  8)
/* 按键板接口 */
#define CHANNEL0_YELLOW_BUTTEN_PIN                         GET_PIN(B,  4)
#define CHANNEL0_GREEN_BUTTEN_PIN                          GET_PIN(B,  5)
#define CHANNEL0_LED_PIN                                   GET_PIN(A, 12)
/* 电磁铁接口 */
#define CHANNEL0_ELECTROMAGNET_PIN                         GET_PIN(B, 11)
/* 电机接口 */
#define CHANNEL0_BACK_MOTOR_DRIVER_INA_PIN                 GET_PIN(B,  7)
#define CHANNEL0_BACK_MOTOR_DRIVER_INB_PIN                 GET_PIN(B,  6)
#define CHANNEL0_FRONT_MOTOR_DRIVER_PWM_DEV_NAME           "pwm2"
#define CHANNEL0_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL    1
#define CHANNEL0_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL    2

/* ----------------------------- 通道1接口定义 ------------------------------ */
/* 光电开关接口 */
#define CHANNEL1_FRONT_PHOTOELECTRIC_SWTICH_PIN            GET_PIN(A,  3)
#define CHANNEL1_BACK_PHOTOELECTRIC_SWTICH_PIN             GET_PIN(A,  0)
/* 按键板接口 */
#define CHANNEL1_YELLOW_BUTTEN_PIN                         GET_PIN(C, 14)
#define CHANNEL1_GREEN_BUTTEN_PIN                          GET_PIN(C, 15)
#define CHANNEL1_LED_PIN                                   GET_PIN(C, 13)
/* 电磁铁接口 */
#define CHANNEL1_ELECTROMAGNET_PIN                         GET_PIN(A,  4)
/* 电机接口  */
#define CHANNEL1_BACK_MOTOR_DRIVER_INA_PIN                 GET_PIN(B,  1)
#define CHANNEL1_BACK_MOTOR_DRIVER_INB_PIN                 GET_PIN(B,  0)
#define CHANNEL1_FRONT_MOTOR_DRIVER_PWM_DEV_NAME           "pwm3"
#define CHANNEL1_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL    1
#define CHANNEL1_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL    2

#endif