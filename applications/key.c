#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "io.h"
#include "key.h"

#define LOG_TAG "button"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

Button_t lane0_green_button;
Button_t lane0_yellow_button;
Button_t lane1_green_button;
Button_t lane1_yellow_button;

rt_uint8_t read_lane0_green_button(void)
{
    return rt_pin_read(LANE0_GREEN_BUTTEN_PIN);
}

rt_uint8_t read_lane0_yellow_button(void)
{
    return rt_pin_read(LANE0_YELLOW_BUTTEN_PIN);
}

rt_uint8_t read_lane1_green_button(void)
{
    return rt_pin_read(LANE1_GREEN_BUTTEN_PIN);
}

rt_uint8_t read_lane1_yellow_button(void)
{
    return rt_pin_read(LANE1_YELLOW_BUTTEN_PIN);
}

void button_init()
{
    Button_Create("lane0_green_button", &lane0_green_button, read_lane0_green_button, PIN_HIGH);

    // Button_Attach(&lane0_green_button, BUTTON_DOWM, lane0_feed);
    // Button_Attach(&lane0_green_button, BUTTON_DOUBLE, lane0_feed(0));     
    // Button_Attach(&lane0_green_button, BUTTON_CONTINUOS, lane0_feed);   // 长按持续向旋转
    // Get_Button_Event(&lane0_green_button);
}

/**
 * TODO: 
 * 短按绿色按键, 向前给进 1 个默认单位
 * 双击绿色按键, 向前给进 2mm 的最小单位
 * 长按绿色按键, 向前持续给进
 * 短按黄色键，查看默认给进单位
 * 双击黄色键，设置默认给进单位
 * 长按黄色键, 开关胶带卷料电机
 */