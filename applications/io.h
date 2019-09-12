#ifndef __IO_H
#define __IO_H

#include <board.h>

#define LANE0                                              0
#define LANE1                                              1

/* ----------------------------- 轨道0接口定义 ------------------------------ */
/* 光电开关接口 */
#define LANE0_FEED_GATE_PIN                                GET_PIN(B, 10)
#define LANE0_TAPE_GATE_PIN                                GET_PIN(A,  8)
/* 按键板接口 */
#define LANE0_YELLOW_BUTTEN_PIN                            GET_PIN(B,  4)
#define LANE0_GREEN_BUTTEN_PIN                             GET_PIN(B,  5)
#define LANE0_LED_PIN                                      GET_PIN(A, 12)
/* 电磁铁接口 */
#define LANE0_SOLENOID_PIN                                 GET_PIN(B, 11)
/* 电机接口 */
#define LANE0_FEED_MOTOR_DRIVER_INA_PIN                    GET_PIN(A, 15)
#define LANE0_FEED_MOTOR_DRIVER_INB_PIN                    GET_PIN(B,  3)
#define LANE0_TAPE_MOTOR_DRIVER_INA_PIN                    GET_PIN(B,  7)
#define LANE0_TAPE_MOTOR_DRIVER_INB_PIN                    GET_PIN(B,  6)

/* ----------------------------- 轨道1接口定义 ------------------------------ */
/* 光电开关接口 */
#define LANE1_FEED_GATE_PIN                                GET_PIN(A,  3)
#define LANE1_TAPE_GATE_PIN                                GET_PIN(A,  0)
/* 按键板接口 */
#define LANE1_YELLOW_BUTTEN_PIN                            GET_PIN(C, 14)
#define LANE1_GREEN_BUTTEN_PIN                             GET_PIN(C, 15)
#define LANE1_LED_PIN                                      GET_PIN(C, 13)
/* 电磁铁接口 */
#define LANE1_SOLENOID_PIN                                 GET_PIN(A,  4)
/* 电机接口  */
#define LANE1_FEED_MOTOR_DRIVER_INA_PIN                    GET_PIN(A,  6)
#define LANE1_FEED_MOTOR_DRIVER_INB_PIN                    GET_PIN(A,  7)
#define LANE1_TAPE_MOTOR_DRIVER_INA_PIN                    GET_PIN(B,  1)
#define LANE1_TAPE_MOTOR_DRIVER_INB_PIN                    GET_PIN(B,  0)

void io_init(void);
void lane0_led_on(void);
void lane0_led_off(void);
void lane1_led_on(void);
void lane1_led_off(void);
void lane0_solenoid_open(void);
void lane0_solenoid_close(void);
void lane1_solenoid_open(void);
void lane1_solenoid_close(void);

#define lane0_feed_gate_read()      rt_pin_read(LANE0_FEED_GATE_PIN)
#define lane1_feed_gate_read()      rt_pin_read(LANE1_FEED_GATE_PIN)
#define lane0_tape_gate_read()      rt_pin_read(LANE0_TAPE_GATE_PIN)
#define lane1_tape_gate_read()      rt_pin_read(LANE1_TAPE_GATE_PIN)

#define ACTIVE                      PIN_HIGH
#define IDLE                        PIN_LOW

#endif