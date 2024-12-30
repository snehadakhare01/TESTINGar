#include "Voltage.h"
#include "Current.h"
#define ADC_VREF 3.3f
#define ADC_RESOLUTION 4096.0f
#define Offset 1.420

float volt = 0.0f;
float volt1 = 0.0f;

float current=0;
int x=0;
//pin definication
#define Temperature 36
#define voltageSensor 32
#define CurrentSensor 33
int adc_value =0;


//Temperature
float calculateadcvalue_volatgeTemp(int adc_value1) {

    adc_value1=analogRead(36);
    volt1 = (adc_value*ADC_VREF)/ADC_RESOLUTION;
    return volt1;
}
float calculate_temperature(){
    int temperature = volt1 * 100;
    return temperature;
   
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Temperature,INPUT);
  pinMode(voltageSensor,INPUT);
  pinMode(CurrentSensor,INPUT);
}

void loop() {
  int VoltageADC = calculateadc();
  Serial.print("\tADC: ");
  Serial.print(ADC_value);
  Serial.print(",\tpin voltage: ");
  Serial.print(calculateadc());
  Serial.print("\tVoltage: ");
  Serial.println(calculate_Voltage());
  // Serial.print("\tTemperature");
  // Serial.println(calculate_temperature());
  // Serial.print(calculateadcvalue_voltage());
  // Serial.print("\tCurrent: ");
  // Serial.print(calculate_Current());
  // Serial.println(adc_value);
  // put your main code here, to run repeatedly:

}
