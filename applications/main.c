/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-03-08     obito0   first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "motor.h"
#include "io.h"

#define LOG_TAG              "main"
#define LOG_LVL              LOG_LVL_DBG
#include <ulog.h>

int main(void)
{

    motor_init();

    while (1)
    {
        motor_front_set_speed(CHANNEL1, 90);
        rt_thread_mdelay(3000);
        motor_front_set_speed(CHANNEL1, 0);
        rt_thread_mdelay(3000);

        // motor_back_set(CHANNEL1, MOTOR_BACK_RUN);
        // rt_thread_mdelay(3000);
        // motor_back_set(CHANNEL1, MOTOR_BACK_STOP);
        // rt_thread_mdelay(3000);

    }

    return RT_EOK;
}


