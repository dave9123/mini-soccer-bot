#include <Motor/Motor.h>

void Motor::begin() {
    ledcSetup(0, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_DRV1_LPWM, Config::PWM_FREQ);

    ledcSetup(1, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_DRV1_RPWM, Config::PWM_FREQ);

    ledcSetup(2, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_DRV2_LPWM, Config::PWM_FREQ);

    ledcSetup(3, Config::PWM_FREQ, Config::PWM_RESOLUTION);    
    ledcAttachPin(Config::MOTOR_DRV2_RPWM, Config::PWM_FREQ);
}