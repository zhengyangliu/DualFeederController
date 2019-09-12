#ifndef __MOTOR_H
#define __MOTOR_H

#include <rtthread.h>
#include <rtdevice.h>

void lane0_feed_motor_forward(void);
void lane0_feed_motor_reverse(void);
void lane0_feed_motor_brake(void);
void lane0_feed_motor_coast(void);

void lane0_tape_motor_forward(void);
void lane0_tape_motor_brake(void);
void lane0_tape_motor_coast(void);

void lane1_feed_motor_forward(void);
void lane1_feed_motor_reverse(void);
void lane1_feed_motor_brake(void);
void lane1_feed_motor_coast(void);

void lane1_tape_motor_forward(void);
void lane1_tape_motor_brake(void);
void lane1_tape_motor_coast(void);

#endif