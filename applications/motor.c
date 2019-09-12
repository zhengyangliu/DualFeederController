
#include "motor.h"
#include "io.h"

#define LOG_TAG              "motor"
#define LOG_LVL              LOG_LVL_DBG
#include <ulog.h>

/* --------------------------------- 轨道0 ---------------------------------- */
void lane0_feed_motor_forward(void)
{
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
}

void lane0_feed_motor_reverse(void)
{
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INA_PIN, PIN_HIGH);
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INB_PIN, PIN_LOW);
}

void lane0_feed_motor_brake(void)
{
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INA_PIN, PIN_HIGH);
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
}

void lane0_feed_motor_coast(void)
{
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE0_FEED_MOTOR_DRIVER_INB_PIN, PIN_LOW);
}

void lane0_tape_motor_forward(void)
{
    rt_pin_write(LANE0_TAPE_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE0_TAPE_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
}

void lane0_tape_motor_brake(void)
{
    rt_pin_write(LANE0_TAPE_MOTOR_DRIVER_INA_PIN, PIN_HIGH);
    rt_pin_write(LANE0_TAPE_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
}

void lane0_tape_motor_coast(void)
{
    rt_pin_write(LANE0_TAPE_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE0_TAPE_MOTOR_DRIVER_INB_PIN, PIN_LOW);
}

/* --------------------------------- 轨道1 ---------------------------------- */
void lane1_feed_motor_forward(void)
{
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
}

void lane1_feed_motor_reverse(void)
{
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INA_PIN, PIN_HIGH);
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INB_PIN, PIN_LOW);
}

void lane1_feed_motor_brake(void)
{
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INA_PIN, PIN_HIGH);
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
}

void lane1_feed_motor_coast(void)
{
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE1_FEED_MOTOR_DRIVER_INB_PIN, PIN_LOW);
}

void lane1_tape_motor_forward(void)
{
    rt_pin_write(LANE1_TAPE_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE1_TAPE_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
}

void lane1_tape_motor_brake(void)
{
    rt_pin_write(LANE1_TAPE_MOTOR_DRIVER_INA_PIN, PIN_HIGH);
    rt_pin_write(LANE1_TAPE_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
}

void lane1_tape_motor_coast(void)
{
    rt_pin_write(LANE1_TAPE_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(LANE1_TAPE_MOTOR_DRIVER_INB_PIN, PIN_LOW);
}



