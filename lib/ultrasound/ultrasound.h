#ifndef ULTRASOUND_DEFINED
#define ULTRASOUND_DEFINED
#include <Arduino.h>

int calibrate_ultrasound(int trig_pin, int echo_pin, int button_pin);
int read_ultrasound(int trig_pin, int echo_pin);

#endif