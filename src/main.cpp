#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
extern "C"
{
#include "ultrasound.h"
}

#define TRIG_PIN 8
#define ECHO_PIN 9
#define BUTTON_PIN 12
#define ERROR 4

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup()
{
  // ultrasound pins setup
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // button setup:
  //   0 = pressed
  //   1 = released
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // lcd setup
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
}

int calibracion;
unsigned long tiempo = 0;
int lectura;
void loop()
{
  calibracion = calibrate_ultrasound(TRIG_PIN, ECHO_PIN, BUTTON_PIN);
  lectura = calibracion;
  if (calibracion != 0)
  {
    Serial.print("Calibracion: "); // debug
    Serial.println(calibracion);   // debug
    while ((lectura <= calibracion + ERROR) && (lectura >= calibracion - ERROR))
      lectura = read_ultrasound(TRIG_PIN, ECHO_PIN);
    tiempo = millis();
    Serial.println("milestone 1"); // debug
    delay(5000);
    lectura = calibracion;
    while ((lectura <= calibracion + ERROR) && (lectura >= calibracion - ERROR))
    {
      Serial.print("lectura: "); // debug
      Serial.println(lectura);   // debug
      lectura = read_ultrasound(TRIG_PIN, ECHO_PIN);
    }
    tiempo = (millis() - tiempo); // [s]
    Serial.print("\nTiempo: ");
    Serial.println(tiempo);
  }
  else
    Serial.println("Error en la calibracion");
}
