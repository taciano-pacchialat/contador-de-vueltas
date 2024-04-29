#include "ultrasound.h"

// reads from an ultrasound sensor and returns the distance
int read_ultrasound(int trig_pin, int echo_pin)
{
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig_pin, LOW);
  return (pulseIn(echo_pin, HIGH, 100000) * 0.034 / 2);
}

// calibrates the ultrasound with an average value;
int calibrate_ultrasound(int trig_pin, int echo_pin, int button_pin)
{
  int promedio = 0;
  int i = 0;
  while (digitalRead(button_pin))
    ;
  while (!digitalRead(button_pin))
  {
    promedio += read_ultrasound(trig_pin, echo_pin);
    i++;
    delay(100);
  }
  if ((i != 0) && (promedio != 0))
    return (promedio / i);
  else
    return 0;
}