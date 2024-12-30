#include <Arduino.h>

void setup() {
  Serial.begin(9600); 

  
}

void loop() {
  
  unsigned long currentMillis = millis();


  int seconds = currentMillis / 1000;
  int minutes = seconds / 60;
  int hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;
  hours %= 24;

  Serial.print("\nThis program has been written at (date and time): ");
  Serial.print(hours, DEC);
  Serial.print(":");
  Serial.print(minutes, DEC);
  Serial.print(":");
  Serial.print(seconds, DEC);
  Serial.println();

  
}