#ifndef __MOTOR_H
#define __MOTOR_H

#include <rtthread.h>
#include <rtdevice.h>

#define MOTOR_BACK_STOP    0
#define MOTOR_BACK_RUN     1

int motor_init(void);
void motor_front_set_speed(rt_uint8_t channel, rt_int32_t speed);
void motor_front_brake(rt_uint8_t channel);
void motor_back_set(rt_uint8_t channel, rt_uint8_t state);
void motor_back_brake(rt_uint8_t channel);

#endif