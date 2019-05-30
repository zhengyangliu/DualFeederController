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

#define LOG_TAG              "main"
#define LOG_LVL              LOG_LVL_DBG
#include <ulog.h>

/* defined the LED0 pin: PC13 */
// #define SAMPLE_UART_NAME       "uart2"      /* 串口设备名称 */

int main(void)
{
    /* set LED0 pin mode to output */
    // rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
    
    uint8_t count = 128;

    rt_kprintf("System online\r\n");


    LOG_D("LOG_D(%d): RT-Thread is an open source IoT operating system from China.", count);
    LOG_I("LOG_I(%d): RT-Thread is an open source IoT operating system from China.", count);
    LOG_W("LOG_W(%d): RT-Thread is an open source IoT operating system from China.", count);
    LOG_E("LOG_E(%d): RT-Thread is an open source IoT operating system from China.", count);

    while (1)
    {
        rt_thread_mdelay(500);
    }

    return RT_EOK;
}
