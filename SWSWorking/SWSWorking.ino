int td=0;
float a=0;
int present =1;
int prev =1;
int present_Time = 0;
int prev_Time=0;
unsigned long int SWS() {
  int m=digitalRead(26);
  if(m==1){
    digitalWrite(26,LOW);
  }else{
    digitalWrite(26,HIGH);
  }
  
  if(td == 0){
       return 0;;
  }
  a = (1000.0 / td);

  unsigned long rpm = a * 60;
  return rpm;
}

void setup() {
  // put your setup code here, to run once:
  Serial2.begin(9600);
  pinMode(34, INPUT_PULLUP);
  pinMode(26,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  present = digitalRead(34);
  // Serial.println(present);
  
  if(present == 0){
    if(prev == 1){
      prev = present;
      // Serial.println("Yes");
      
      present_Time =millis();
      td = present_Time - prev_Time;
      // Serial.print("present_time: ");
      // Serial.println(present_Time);
      // Serial.print("prev_time: ");
      // Serial.println(prev_Time);
      Serial2.print("td: ");
      Serial2.println(td);
      Serial2.print("SWS: ");
      Serial2.println(SWS());
    }
    prev_Time = present_Time;
    // Serial.print("no");
  }
  prev = present ;
  delay(2); // this speeds up the simulation
}
