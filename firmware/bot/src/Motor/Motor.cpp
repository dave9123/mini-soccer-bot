#include <Motor/Motor.h>

void Motor::begin() {
    ledcSetup(0, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_L_DRV_LPWM, Config::PWM_FREQ);

    ledcSetup(1, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_L_DRV_RPWM, Config::PWM_FREQ);

    ledcSetup(2, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_R_DRV_LPWM, Config::PWM_FREQ);

    ledcSetup(3, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_R_DRV_RPWM, Config::PWM_FREQ);
}