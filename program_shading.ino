#include <Arduino.h>
#include "shading.h"

#define MOTOR_DIR_CW    0 // Searah jarum jam
#define MOTOR_DIR_CCW   1 // Berlawanan arah jarum jam

#define MOTOR_ENABLE    1 // Menyalakan Motor
#define MOTOR_DISABLE   0 // Mematikan motor

#define STEPPER_PIN_PULL  7 
#define STEPPER_PIN_DIR   6
#define STEPPER_PIN_EN    5

#define LimitA    8 // Batas atas sampai menyentuh sensor
#define LimitB    9 // Batas bawah sampai menyentuh sensor
#define Sensor    3

uint8_t direction = MOTOR_DIR_CW;

void setup() {
  Serial.begin(9600);
  pinMode (LimitA, INPUT_PULLUP);
  pinMode (LimitB, INPUT_PULLUP);
  pinMode (Sensor, INPUT);
  shading_motor_init(STEPPER_PIN_PULL, STEPPER_PIN_DIR, STEPPER_PIN_EN);  
}

void loop() {
  while (0) {
    shading_motor_set(MOTOR_DIR_CW, STEPPER_PIN_DIR, MOTOR_ENABLE, STEPPER_PIN_EN);
    if (!digitalRead(LimitA)) {
      while(!digitalRead(LimitA));
      Serial.println("Jendela terbuka");
      break;
    }
    shading_motor_step(1, STEPPER_PIN_PULL);
}

while (1) {
  shading_motor_set(MOTOR_DIR_CCW, STEPPER_PIN_DIR, MOTOR_ENABLE, STEPPER_PIN_EN);
  if (!digitalRead(LimitB)) {
    while(!digitalRead(LimitB));
    Serial.println("Jendela tertutup");
    break;
  }

  shading_motor_step(1, STEPPER_PIN_PULL);
  }
}
