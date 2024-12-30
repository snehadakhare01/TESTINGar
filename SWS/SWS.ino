#include <Arduino.h>
#include <stdint.h>
const int hallSensorPin = 18;  // Pin connected to the Hall Effect sensor
float td = 0;
float a = 0;
int last = 0;
void IRAM_ATTR pulseInterrupt() {

  // Serial.println("interrupt");
  // delay(1);
  // if (digitalRead(13) == LOW) {
  //   return;
  // } else {
  //   //nothing
  // }
  // a++;
  int present = millis();
   int x = present - last;
  if(x > 300){
    td=x;
  }
  last = present;
}

void setup() {
  Serial.begin(115200);
  pinMode(18, INPUT_PULLUP);
  // pinMode(13, OUTPUT);
  attachInterrupt(18, pulseInterrupt, FALLING);
  // Serial.println("sneha");
}

unsigned long int SWS() {
  if(td == 0){
       return 0;;
  }
  a = (1000.0 / td);

  unsigned long rpm = a * 60;
  return rpm;
}


void loop() {
  // Serial.print("a= ");
  Serial.println(a);
  // pulseInterrupt();
  Serial.print("\ttd: ");
  Serial.println(td);
  Serial.print("\tSWS:");
  Serial.println(SWS());
  delay(500);
  // td=0;
}