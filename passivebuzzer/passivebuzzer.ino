int Buzz=3;
void setup ()
{
Serial.begin(9600);
pinMode(Buzz,OUTPUT);
tone(Buzz,5000); // for more details on tone function please visit Arduino.cc
delay(1000);
}
void loop()
{
for(int i=0;i<255;i++)
{
analogWrite(Buzz,i);
delay(100);
analogWrite(Buzz,0);
delay(100);
analogWrite(Buzz,255);
}
}
