#include "Arduino.h"
#include "Voltage.h"
//voltage
#define ADC_VREF 3.3f
#define ADC_RESOLUTION 4096.0f
int ADC_value =0;
float volt2 = 0.0f;
int calculateadc(){
    // int x = (Vin/3.3f)*4096;
    // return x;
    ADC_value=analogRead(32);
    volt2 = (ADC_value*ADC_VREF)/ADC_RESOLUTION;
    
    return volt2;
} 
double calculate_Voltage(){
    

    float Vout = 0.0f;
    
    if(Vout >= 36.00f){
      Vout = (volt2*100.0f)/1.7f;
    }else{
      Vout = (volt2*100.0f)/1.4f;
    }
    return Vout;
}
