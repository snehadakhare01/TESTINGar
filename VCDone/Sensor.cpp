#include "Sensor.h"
#include "Arduino.h"
#define ADC_VREF 3.3f
#define ADC_RESOLUTION 4096.0f
#define Offset 1.40f
#define ADC_VREF 3.3f
#define ADC_RESOLUTION 4096.0f

//Current
float calculate_Current(){
  int adc_valueCurrent=analogRead(33);
  float voltCurrent = (adc_valueCurrent*ADC_VREF)/ADC_RESOLUTION;
  float current=0.0f;
        float x = voltCurrent - Offset;
        current = x* 32.5f;
        return current;
   
}
//Voltage
double calculate_Voltage(){
    int ADC_valueVoltage=analogRead(32);
    return (double)((ADC_valueVoltage-499)*0.0375f)+28;
}
//Temperature

float calculate_temperature(){
    int adc_value1=analogRead(36);
    float volt1Temperature = (adc_value1*ADC_VREF)/ADC_RESOLUTION;
    int temperature = volt1Temperature * 100;
    return temperature;
   
}