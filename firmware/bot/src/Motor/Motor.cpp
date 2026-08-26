#include <Motor/Motor.h>

void Motor::begin() {
    ledcSetup(0, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_L_DRV_LPWM, 0);

    ledcSetup(1, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_L_DRV_RPWM, 1);

    ledcSetup(2, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_R_DRV_LPWM, 2);

    ledcSetup(3, Config::PWM_FREQ, Config::PWM_RESOLUTION);
    ledcAttachPin(Config::MOTOR_R_DRV_RPWM, 3);
}

void Motor::drive(int16_t moveY, int16_t turnX) {
    int32_t left = (int32_t)moveY + turnX;
    int32_t right = (int32_t)moveY - turnX;

    // left and right facing motors should be upside down (wowzers)
   if (left >= 0) {
    ledcWrite(0, 0);
    ledcWrite(1, abs(left));
   } else {
    ledcWrite(1, 0);
    ledcWrite(0, abs(left));
   }
   
   if (right >= 0) {
    ledcWrite(3, 0);
    ledcWrite(2, abs(right));
   } else {
    ledcWrite(2, 0);
    ledcWrite(3, abs(right));
   }
}