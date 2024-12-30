#define thermistorPin 35
#define referenceVoltage 3.3f
#define referenceResistor 10000
#define beta 3950
#define nominalTemperature 25
#define nominalResistance 10000

float CalculateTempearture(){
  int adcValue = analogRead(thermistorPin);
  float voltage = (adcValue * referenceVoltage) / 4095.0; // Calculate voltage
  float resistance = (voltage * referenceResistor) / (referenceVoltage - voltage); // Calculate thermistor resistance with updated configuration
  // Calculate temperature using the Beta parameter equation
  float tempK = 1 / (((log(resistance / nominalResistance)) / beta) + (1 / (nominalTemperature + 273.15)));
  
  float tempC = (tempK - 273.15)-8; 
  // if(tempC >= 70){
  //    tempC = (tempK - 273.15)-25; 
  // }else 
  if(tempC >= 50){
    tempC = (tempK - 273.15)-10; 
  }
  return tempC;
}
void setup() {
  
  Serial2.begin(9600);
  pinMode(thermistorPin, INPUT);
}

void loop() {
  
  Serial2.println(CalculateTempearture());
}
