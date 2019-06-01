
#include "motor.h"
#include "io.h"

#define LOG_TAG              "motor"
#define LOG_LVL              LOG_LVL_DBG
#include <ulog.h>

#define MOTOR_PWM_PERIOD                50000     // 0.05ms 20KHz
#define MOTOR_FULL_SPEED                100

struct rt_device_pwm *ch0;
struct rt_device_pwm *ch1;

int motor_init(void)
{
    rt_pin_write(CHANNEL0_BACK_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(CHANNEL0_BACK_MOTOR_DRIVER_INB_PIN, PIN_LOW);
    rt_pin_write(CHANNEL1_BACK_MOTOR_DRIVER_INA_PIN, PIN_LOW);
    rt_pin_write(CHANNEL1_BACK_MOTOR_DRIVER_INB_PIN, PIN_LOW);

    rt_pin_mode(CHANNEL0_BACK_MOTOR_DRIVER_INA_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(CHANNEL0_BACK_MOTOR_DRIVER_INB_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(CHANNEL1_BACK_MOTOR_DRIVER_INA_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(CHANNEL1_BACK_MOTOR_DRIVER_INB_PIN, PIN_MODE_OUTPUT);

    ch0 = (struct rt_device_pwm *)rt_device_find(CHANNEL0_FRONT_MOTOR_DRIVER_PWM_DEV_NAME);
    if (ch0 == RT_NULL)
    {
        LOG_E("pwm sample run failed! can't find %s device!\n", CHANNEL0_FRONT_MOTOR_DRIVER_PWM_DEV_NAME);
        return RT_ERROR;
    }
    ch1 = (struct rt_device_pwm *)rt_device_find(CHANNEL0_FRONT_MOTOR_DRIVER_PWM_DEV_NAME);
    if (ch0 == RT_NULL)
    {
        LOG_E("pwm sample run failed! can't find %s device!\n", CHANNEL0_FRONT_MOTOR_DRIVER_PWM_DEV_NAME);
        return RT_ERROR;
    }

    rt_pwm_set(ch0, CHANNEL0_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, 0);
    rt_pwm_set(ch0, CHANNEL0_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, 0);
    rt_pwm_set(ch1, CHANNEL0_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, 0);
    rt_pwm_set(ch1, CHANNEL0_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, 0);

    LOG_D("motor initilize complete\n");
}

void motor_front_set_speed(rt_uint8_t channel, rt_int32_t speed)
{
    speed = speed * (MOTOR_PWM_PERIOD / MOTOR_FULL_SPEED);     // Expan speed to period

    LOG_D("set channel %d front motor speed %d\n", channel, speed);

    if(channel == 0)
    {
        if(speed > 0)
        {
            rt_pwm_set(ch0, CHANNEL0_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, 0);
            rt_pwm_set(ch0, CHANNEL0_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, speed);
        }
        else
        {
            rt_pwm_set(ch0, CHANNEL0_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, -speed);
            rt_pwm_set(ch0, CHANNEL0_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, 0);
        }
    }
    else if(channel == 1)
    {
        if(speed > 0)
        {
            rt_pwm_set(ch1, CHANNEL1_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, 0);
            rt_pwm_set(ch1, CHANNEL1_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, speed);
        }
        else
        {
            rt_pwm_set(ch1, CHANNEL1_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, -speed);
            rt_pwm_set(ch1, CHANNEL1_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, 0);
        }
    }
}

void motor_front_brake(rt_uint8_t channel)
{
    LOG_D("brake channel %d front motor\n", channel);

    if(channel == 0)
    {
        rt_pwm_set(ch0, CHANNEL0_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, MOTOR_PWM_PERIOD);
        rt_pwm_set(ch0, CHANNEL0_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, MOTOR_PWM_PERIOD);
    }
    else if(channel == 1)
    {
        rt_pwm_set(ch1, CHANNEL1_FRONT_MOTOR_DRIVER_INA_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, MOTOR_PWM_PERIOD);
        rt_pwm_set(ch1, CHANNEL1_FRONT_MOTOR_DRIVER_INB_PWM_DEV_CHANNEL, MOTOR_PWM_PERIOD, MOTOR_PWM_PERIOD);
    }
}

void motor_back_set(rt_uint8_t channel, rt_uint8_t state)
{
    if(state == MOTOR_FRONT_STOP)
        LOG_D("set channel %d back motor stop\n", channel);
    else
        LOG_D("set channel %d back motor run\n", channel);

    if(channel == 0)
    {
        rt_pin_write(CHANNEL0_BACK_MOTOR_DRIVER_INA_PIN, !state);
        rt_pin_write(CHANNEL0_BACK_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
    }
    else if(channel == 1)
    {
        rt_pin_write(CHANNEL1_BACK_MOTOR_DRIVER_INA_PIN, !state);
        rt_pin_write(CHANNEL1_BACK_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
    }
}

void motor_back_brake(rt_uint8_t channel)
{
    LOG_D("set channel %d back motor brake\n", channel);

    if(channel == 0)
    {
        rt_pin_write(CHANNEL0_BACK_MOTOR_DRIVER_INA_PIN, PIN_HIGH);
        rt_pin_write(CHANNEL0_BACK_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
    }
    else if(channel == 1)
    {
        rt_pin_write(CHANNEL1_BACK_MOTOR_DRIVER_INA_PIN, PIN_HIGH);
        rt_pin_write(CHANNEL1_BACK_MOTOR_DRIVER_INB_PIN, PIN_HIGH);
    }
}






