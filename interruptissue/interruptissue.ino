int a =0;
void IRAM_ATTR pulseInterrupt(){
  a++;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(2,pulseInterrupt,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(a);
}
