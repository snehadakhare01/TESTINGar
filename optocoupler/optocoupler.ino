#include <Arduino.h>

const int hallSensorPin = 26;  // Pin connected to the Hall Effect sensor
volatile unsigned long td = 0;
int a= 0;
int last =0;
void IRAM_ATTR pulseInterrupt() {
  // Serial.println("interrupt");
  a++;
  int present = millis();
  td=present-last;
  last = present;
  // Serial.println(td);

  
}

void setup() {
  Serial.begin(115200);
  pinMode(26, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(26), pulseInterrupt, RISING);
  Serial.println("sneha");
}

unsigned long SWS( ) {
     
    float a1= (1000.0/td);
    unsigned long rpm = a1 *60; 
    return rpm;
}

void loop() {
  pulseInterrupt();
  
  Serial.println(SWS());
  delay(2000);
  // Serial.println(a);
  // Reset the pulse counter for the next measurement
  // td = 0;
}