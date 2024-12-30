#include "Current.h"
#include "Arduino.h"
//Current
float calculateadcvalue_voltage() {

    adc_value=analogRead(33);
    volt = (adc_value*ADC_VREF)/ADC_RESOLUTION;
    // return volt;
}   
float calculate_Current(){
    if(volt <= 0.90 ){
        current = 0;
        return current;
    }
    // if(volt >= 1.831){
    //     float x = volt - Offset;
    //     current = x* 27.21f;
    //     return current;
    // }
    // else{
        float y = volt - Offset;
        current = y* 33.64f;
        return current;
    // }
   
}