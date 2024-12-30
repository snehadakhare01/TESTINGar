
#define ADC_VREF 3.3f
#define ADC_RESOLUTION 4096.0f
#define Offset 1.420
#define ADC_VREF 3.3f
#define ADC_RESOLUTION 4096.0f
float volt = 0.0f;
float volt1 = 0.0f;
float volt2 = 0.0f;
float current=0;
int x=0;
//pin definication
#define Temperature 36
#define voltageSensor 32
#define CurrentSensor 33
int adc_value =0;
int ADC_value =0;
//Current
float calculateadcvalue_voltage() {

    adc_value=analogRead(33);
    volt = (adc_value*ADC_VREF)/ADC_RESOLUTION;
    return volt;
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

//voltage

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
      Vout = (volt2*100.0f)/1.5f;
    }
    return Vout;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Temperature,INPUT);
  pinMode(voltageSensor,INPUT);
  pinMode(CurrentSensor,INPUT);
}

void loop() {
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
