
#include "motor.h"
#include "io.h"
#include "feedercontrol.h"

#define LOG_TAG              "feedctl"
#define LOG_LVL              LOG_LVL_DBG
#include <ulog.h>

// 给进时脉冲数量
#define FEED_FWD_ENC_PULSE   2 // it's actually this value + 1
// encoder pulses: >(lane0FeedDistance * FEED_FWD_ENC_PULSE)
// 3 for 1 position, 5 for 2 positions

// 滤波器采样次数及阈值
#define FILTER_COUNT         50
#define FILTER_PASS_COUNT    45

// 脉冲计数器
rt_uint8_t lane0FeedEdge = 0;
rt_uint8_t lane1FeedEdge = 0;

void lane0_feed_gate_irq_handler(void *args)
{
    rt_uint8_t i = 0, count = 0, last_state;

    // 滤波，防止信号误触发
    last_state = lane0_feed_gate_read();
    for(; i < FILTER_COUNT; i++)
    {
        if(last_state != lane0_feed_gate_read())
            break;
        else
            count++;
    }
    if(count > 45)
        lane0FeedEdge++;
}

void lane1_feed_gate_irq_handler(void *args)
{
    rt_uint8_t i = 0, count = 0, last_state;

    // 滤波，防止信号误触发
    last_state = lane1_feed_gate_read();
    for(; i < FILTER_COUNT; i++)
    {
        if(last_state != lane1_feed_gate_read())
            break;
        else
            count++;
    }
    if(count > 45)
        lane1FeedEdge++;
}

void feedercontrol_init(void)
{
    // 通道0电机复位
    lane0_feed_motor_reverse();
    rt_thread_mdelay(50);
    lane0_feed_motor_coast();

    // 通道1电机复位
    lane1_feed_motor_reverse();
    rt_thread_mdelay(50);
    lane1_feed_motor_coast();

    // 绑定中断处理
    rt_pin_attach_irq(LANE0_FEED_GATE_PIN, PIN_IRQ_MODE_RISING_FALLING, lane0_feed_gate_irq_handler, RT_NULL);
    rt_pin_attach_irq(LANE1_FEED_GATE_PIN, PIN_IRQ_MODE_RISING_FALLING, lane1_feed_gate_irq_handler, RT_NULL);
}

/**
 * @brief 
 * 
 * @param ch 给进轨道
 * @param len 给进长度 1 = 2mm, 2 = 4mm
 */
void feed(rt_uint8_t ch, rt_uint8_t len)
{
    if(ch == LANE0)
    {
        lane0FeedEdge = 0;
        lane0_solenoid_close();
        lane0_led_on();

        rt_pin_irq_enable(LANE0_FEED_GATE_PIN, PIN_IRQ_ENABLE);
        lane0_feed_motor_forward();

        while(1)
        {
            rt_thread_mdelay(5);
            if(lane0FeedEdge > (FEED_FWD_ENC_PULSE * len))
            {
                lane0FeedEdge = 0;
                lane0_feed_motor_brake();
                lane0_feed_motor_reverse();
                break;
            }
        }
        while(1)
        {
            rt_thread_mdelay(1);
            if (lane0FeedEdge > 1)
            {
                lane0_feed_motor_brake();
                rt_thread_mdelay(20);
                lane0_feed_motor_coast();
                rt_thread_mdelay(10);
                break;
            }
        }
        lane0_led_off();
        rt_pin_irq_enable(LANE0_FEED_GATE_PIN, PIN_IRQ_DISABLE);
    }
    else if(ch == LANE1)
    {
        lane1FeedEdge = 0;
        lane1_solenoid_close();
        lane1_led_on();

        rt_pin_irq_enable(LANE1_FEED_GATE_PIN, PIN_IRQ_ENABLE);
        lane1_feed_motor_forward();

        while(1)
        {
            rt_thread_mdelay(5);
            if(lane1FeedEdge > (FEED_FWD_ENC_PULSE * len))
            {
                lane1FeedEdge = 0;
                lane1_feed_motor_brake();
                lane1_feed_motor_reverse();
                break;
            }
        }
        while(1)
        {
            rt_thread_mdelay(1);
            if (lane1FeedEdge > 1)
            {
                lane1_feed_motor_brake();
                rt_thread_mdelay(20);
                lane1_feed_motor_coast();
                rt_thread_mdelay(10);
                break;
            }
        }
        lane1_led_off();
        rt_pin_irq_enable(LANE1_FEED_GATE_PIN, PIN_IRQ_DISABLE);
    }
}




