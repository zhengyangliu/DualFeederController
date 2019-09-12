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
#include "io.h"
#include "motor.h"
#include "feedercontrol.h"
#include "key.h"

#define LOG_TAG              "main"
#define LOG_LVL              LOG_LVL_DBG
#include <ulog.h>

#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       512
#define THREAD_TIMESLICE        5

// 胶带电机关闭延迟时间，防止电机在临界点震荡
#define TAPE_MOTOR_CLOSE_DELAY_TIME         100

static void lane0_tape_check(void *parameter);
static void lane1_tape_check(void *parameter);

int main(void)
{
    io_init();

    // lane0_led_on();
    // lane1_led_on();
    // rt_thread_mdelay(1000);
    // lane0_led_off();
    // lane1_led_off();

    /** 
     * TODO: 打印信息
     */

    // feedercontrol_init();
    // button_init();

    /* 喂料器动作处理任务 */

    /* 胶带卷皮任务 */
    rt_thread_t TChk0 = rt_thread_create("TChk0", lane0_tape_check, RT_NULL, 256, 5, 1);
    if (TChk0 != RT_NULL)
    {
        rt_thread_startup(TChk0);
    }

    rt_thread_t TChk1 = rt_thread_create("TChk1", lane1_tape_check, RT_NULL, 256, 5, 1);
    if (TChk1 != RT_NULL)
    {
        rt_thread_startup(TChk1);
    }

    /* 通讯处理任务 */

    /* 按键任务 */

    /* 如果获得线程控制块，启动这个线程 */

    return RT_EOK;
}

static void lane0_tape_check(void *parameter)
{
    while(1)
    {
        if(lane0_tape_gate_read() == IDLE)  // 胶带松弛，传感器被遮挡
        {
            lane0_tape_motor_forward();
            while(1)
            {
                if(lane0_tape_gate_read() == ACTIVE)
                    break;
                rt_thread_mdelay(10);   // 100Hz扫描
            }
            rt_thread_mdelay(TAPE_MOTOR_CLOSE_DELAY_TIME);  // 延时一段时间后刹车
            lane0_tape_motor_brake();
            rt_thread_mdelay(20);
            lane0_tape_motor_coast();
            rt_thread_mdelay(10);
        }
        rt_thread_mdelay(10); // 100Hz扫描
    }
}

static void lane1_tape_check(void *parameter)
{
    while(1)
    {
        if(lane1_tape_gate_read() == IDLE)  // 胶带松弛，传感器被遮挡
        {
            lane1_tape_motor_forward();
            while(1)
            {
                if(lane1_tape_gate_read() == ACTIVE)
                    break;
                rt_thread_mdelay(10);   // 100Hz扫描
            }
            rt_thread_mdelay(TAPE_MOTOR_CLOSE_DELAY_TIME);  // 延时一段时间后刹车
            lane1_tape_motor_brake();
            rt_thread_mdelay(20);
            lane1_tape_motor_coast();
            rt_thread_mdelay(10);
        }
        rt_thread_mdelay(10); // 100Hz扫描
    }
}

