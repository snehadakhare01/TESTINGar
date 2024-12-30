#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

void setup() {
  Serial.begin(115200); // Faster baud rate for ESP32
  while (!Serial); // Wait for Serial Monitor to connect

  // Initialize the I2C communication for RTC
  Wire.begin(21, 22); // Default I2C pins for ESP32: SDA (21), SCL (22)
  
  // Check if the RTC is running and initialize it
  if (!rtc.begin()) {
    Serial.println("RTC initialization failed! Check connections.");
    while (1); // Stop execution if RTC initialization fails
  }
  
  if (!rtc.isrunning()) {
    Serial.println("RTC is not running. Setting current time...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Set RTC to compile time
    Serial.println("RTC time has been set.");
  }
}

void loop() {
  // Fetch the current time from the RTC
  DateTime now = rtc.now();
  
  // Print the current time in a more user-friendly format
  Serial.printf("%04d/%02d/%02d %02d:%02d:%02d\n", 
                now.year(), now.month(), now.day(),
                now.hour(), now.minute(), now.second());
  
  delay(1000); // Wait for 1 second
}
