#define mircros

int delayTime = 1120;

void setup() {
  // put your setup code here, to run once:
  DDRD |= 0b11100000;
}

void loop() {
  // sequence: 1(001), 5(101), 4(100), 6(110), 2(010), 3(011)
  // PORTD = (PIND & 0b00011111) | 0b11100000;
  // delay(50);
  // PORTD = (PIND & 0b00011111) | 0b00000000;
  // delay(50);
  while(1){
    PORTD = (PIND & 0b00011111) | 0b00100000;
    #ifdef mircros
      delayMicroseconds(delayTime);
    #else
      delay(delayTime);
    #endif

    PORTD = (PIND & 0b00011111) | 0b10100000;
    #ifdef mircros
      delayMicroseconds(delayTime);
    #else
      delay`(delayTime);
    #endif
    
    PORTD = (PIND & 0b00011111) | 0b10000000;
    #ifdef mircros
      delayMicroseconds(delayTime);
    #else
      delay(delayTime);
    #endif

    PORTD = (PIND & 0b00011111) | 0b11000000;
    #ifdef mircros
      delayMicroseconds(delayTime);
    #else
      delay(delayTime);
    #endif

    PORTD = (PIND & 0b00011111) | 0b01000000;
    #ifdef mircros
      delayMicroseconds(delayTime);
    #else
      delay(delayTime);
    #endif

    PORTD = (PIND & 0b00011111) | 0b01100000;
    #ifdef mircros
      delayMicroseconds(delayTime);
    #else
      delay(delayTime);
    #endif
  }
}
// arduino uno  Output pins are D5, D6, D7 