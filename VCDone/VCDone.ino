// #include "Arduino.h"
#include "Sensor.h"
//pin definication
#define Temperature 36
#define voltageSensor 32
#define CurrentSensor 33

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Serial1.begin(9600);
  Serial2.begin(9600);
  pinMode(Temperature,INPUT);
  pinMode(voltageSensor,INPUT);
  pinMode(CurrentSensor,INPUT);
}



void loop() {
  float Voltage = calculate_Voltage();
  Serial2.println(Voltage);
  Serial2.println(calculate_Current());
}
