
#include "io.h"

#define LOG_TAG              "io"
#define LOG_LVL              LOG_LVL_DBG
#include <ulog.h>

void io_init(void)
{
    /* 初始化轨道0接口*/
    rt_pin_mode(LANE0_FEED_GATE_PIN, PIN_MODE_INPUT);
    rt_pin_mode(LANE0_TAPE_GATE_PIN, PIN_MODE_INPUT);
    rt_pin_mode(LANE0_YELLOW_BUTTEN_PIN, PIN_MODE_INPUT);
    rt_pin_mode(LANE0_GREEN_BUTTEN_PIN, PIN_MODE_INPUT);

    rt_pin_write(LANE0_LED_PIN, PIN_LOW);
    rt_pin_write(LANE0_SOLENOID_PIN, PIN_LOW);
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INB_PIN, PIN_LOW);
    rt_pin_write(LANE0_TAPE_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE0_TAPE_MOTOR_DRIVER_INB_PIN, PIN_LOW);

    rt_pin_mode(LANE0_LED_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE0_SOLENOID_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE0_FEED_MOTOR_DRIVER_INA_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE0_FEED_MOTOR_DRIVER_INB_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE0_TAPE_MOTOR_DRIVER_INA_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE0_TAPE_MOTOR_DRIVER_INB_PIN, PIN_MODE_OUTPUT);
    
    /* 初始化轨道1接口*/
    rt_pin_mode(LANE1_FEED_GATE_PIN, PIN_MODE_INPUT);
    rt_pin_mode(LANE1_TAPE_GATE_PIN, PIN_MODE_INPUT);
    rt_pin_mode(LANE1_YELLOW_BUTTEN_PIN, PIN_MODE_INPUT);
    rt_pin_mode(LANE1_GREEN_BUTTEN_PIN, PIN_MODE_INPUT);

    rt_pin_write(LANE1_LED_PIN, PIN_LOW);
    rt_pin_write(LANE1_SOLENOID_PIN, PIN_LOW);
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INB_PIN, PIN_LOW);
    rt_pin_write(LANE1_TAPE_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE1_TAPE_MOTOR_DRIVER_INB_PIN, PIN_LOW);

    rt_pin_mode(LANE1_LED_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE1_SOLENOID_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE1_FEED_MOTOR_DRIVER_INA_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE1_FEED_MOTOR_DRIVER_INB_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE1_TAPE_MOTOR_DRIVER_INA_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LANE1_TAPE_MOTOR_DRIVER_INB_PIN, PIN_MODE_OUTPUT);

    LOG_D("I/O initilize complete\n");
}

void lane0_led_on(void)
{
    rt_pin_write(LANE0_LED_PIN, PIN_HIGH);
}

void lane0_led_off(void)
{
    rt_pin_write(LANE0_LED_PIN, PIN_LOW);
}

void lane1_led_on(void)
{
    rt_pin_write(LANE1_LED_PIN, PIN_HIGH);
}

void lane1_led_off(void)
{
    rt_pin_write(LANE1_LED_PIN, PIN_LOW);
}

void lane0_solenoid_open(void)
{
    rt_pin_write(LANE0_SOLENOID_PIN, PIN_HIGH);
}

void lane0_solenoid_close(void)
{
    rt_pin_write(LANE0_SOLENOID_PIN, PIN_LOW);
}

void lane1_solenoid_open(void)
{
    rt_pin_write(LANE1_SOLENOID_PIN, PIN_HIGH);
}

void lane1_solenoid_close(void)
{
    rt_pin_write(LANE1_SOLENOID_PIN, PIN_LOW);
}




