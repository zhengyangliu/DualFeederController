#ifndef __ADVANCE_H
#define __ADVANCE_H

#include <rtthread.h>

#define FEED_2MM      1
#define FEED_4MM      2
#define FEED_8MM      4

void feedercontrol_init(void);
void feed(rt_uint8_t ch, rt_uint8_t len);

#endif