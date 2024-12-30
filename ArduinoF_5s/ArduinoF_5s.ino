// Define GPIO pins
const int hallSensor1 = 2; // GPIO pin for hall sensor 1   ok
const int hallSensor2 = 3; // GPIO pin for hall sensor 2 ok
const int hallSensor3 = 7; // GPIO pin for hall sensor 3  ok
const int brakeLow = 6;   // GPIO pin for brake signal 1 
const int  brakeHigh= 15;   // GPIO pin for brake signal 2 high
const int pasPin = 16;      // GPIO pin for PAS (Pedal Assist System) signal ok
const int buttonPin = 8;   // GPIO pin for push button
const int swsPin = 5;
const int throttle =17; // GPIO pin for analog output for throttle   ok
// Hall sensor sequence: 1, 5, 4, 6, 2, 3
int hallSequence[] = {
  0b001, // 1
  0b101, // 5
  0b100, // 4
  0b110, // 6
  0b010, // 2
  0b011  // 3
};
int hallStep = 0; // Track the current step in the sequence

// Brake signal sequence: (0, 0), (0, 1), (1, 0), (1, 1)
int brakeSequence[][2] = {
  {0, 0},
  {0, 1},
  {1, 0},
  {1, 1}
};
int brakeStep = 0; // Track the current step in the sequence

// PAS signal durations and steps
const unsigned long pasDurations[] = {500, 400, 100};
int pasStep = 0;
//SWS signal durations and steps
const unsigned long swsDurations[] = {500, 400, 100};
int swsStep = 0;

// Timer variables
unsigned long currentTime = 0;
unsigned long previousTime = 0;
const unsigned long hallInterval = 100; // Interval for hall signals
const unsigned long brakeInterval = 500; // Interval for brake signals
unsigned long pasInterval = pasDurations[pasStep] / 2; // Interval for PAS signal
unsigned long swsInterval = swsDurations[swsStep] /2; //Interval for SWS signal

void setup() {
  // Initialize GPIO pins as outputs
  pinMode(hallSensor1, OUTPUT);
  pinMode(hallSensor2, OUTPUT);
  pinMode(hallSensor3, OUTPUT);
  pinMode(brakeHigh, OUTPUT);
  pinMode(brakeLow, OUTPUT);
  pinMode(pasPin, OUTPUT);
  pinMode(swsPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Button with internal pull-up
  pinMode(throttle, OUTPUT);
  // Set initial states
  digitalWrite(hallSensor1, HIGH);
  digitalWrite(hallSensor2, HIGH);
  digitalWrite(hallSensor3, HIGH);
  digitalWrite(brakeLow, HIGH); // Initial state HIGH (1)
  digitalWrite(brakeHigh, LOW);  // Initial state LOW (0)
  digitalWrite(pasPin, LOW);     // Initial state LOW (0)
  digitalWrite(throttle,LOW);
  delay(3000);
  Serial.begin(9600); // Initialize UART communication
}

void loop() {
  // Check for button press
  //  if (digitalRead(buttonPin) == LOW) {
  //    delay(50); // Debounce delay
  //    if (digitalRead(buttonPin) == LOW) {
      startTestingSequence();
  //    }
  //  }
}

void startTestingSequence() {
  // Test 1: Hall sensor signals for 5 seconds
  Serial.println("TEST1");
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    generateHallSignals();
    delay(100);
  }
//
 // Test 2: Low brake signals for 5 seconds
  Serial.println("TEST2");
  startTime = millis();
  digitalWrite(brakeHigh,0);
  while (millis() - startTime < 5000) {
    generateLowBrakeSignals();
    delay(400);
  }

  // Test 3: high brake signals for 5 seconds
  Serial.println("TEST3");
  startTime = millis();
  digitalWrite(brakeLow,1);
  while(millis() - startTime < 5000) {
    generateHighBrakeSignals();
    delay(400);    
  }
  // Test 4: PAS (Pedal Assist System) signals for 5 seconds
  Serial.println("TEST4");
  startTime = millis();
  while (millis() - startTime < 1666) {
    generatePASSignal();
    delay(pasDurations[0]);
    }
  while (millis() - startTime < 3333) {
    generatePASSignal();
    delay(pasDurations[1]);
  }
  while (millis() - startTime < 5000) {
    generatePASSignal();
    delay(pasDurations[2]);
  }

// // Test 5:SWS(signal wire Speed) signal for 5 seconds
  Serial.println("TEST5");
  startTime = millis();
  while (millis() - startTime < 1666) {
    generateSWSSignal();
    delay(swsDurations[0]);
    }
  while (millis() - startTime < 3333) {
    generateSWSSignal();
    delay(swsDurations[1]);
  }
  while (millis() - startTime < 5100) {
    generateSWSSignal();
    delay(swsDurations[2]);
  }
  //     // Perform analog signal generation from 0.9V to 5V in 5 seconds
    // Serial.println("Analog signal test starting.");
    // generateAnalogSignal();
    // Test 2: Low brake signals for 5 seconds
  Serial.println("TEST6");
  startTime = millis();
  digitalWrite(throttle,0);
  while (millis() - startTime < 5000) {
    throttleSignals();
    delay(400);
  }
}
void generateHallSignals() {
  digitalWrite(hallSensor1, hallSequence[hallStep] & 0b001);
  digitalWrite(hallSensor2, hallSequence[hallStep] & 0b010);
  digitalWrite(hallSensor3, hallSequence[hallStep] & 0b100);
  hallStep = (hallStep + 1) % 6;
}

void generateLowBrakeSignals() {
  digitalWrite(brakeLow, !digitalRead(brakeLow));
  // digitalWrite(brakePin1, brakeSequence[brakeStep][0]);
  // digitalWrite(brakePin2, brakeSequence[brakeStep][1]);
  // brakeStep = (brakeStep + 1) % 4;
}

void generateHighBrakeSignals() {

  digitalWrite(brakeHigh, !digitalRead(brakeHigh));
}

void generatePASSignal() {
  digitalWrite(pasPin, !digitalRead(pasPin)); // Toggle PAS pin state
}

void generateSWSSignal(){
  digitalWrite(swsPin , !digitalRead(swsPin)); // Toggle SWS pin State
}
// void generateAnalogSignal() {
//   unsigned long startTime = millis();
//   while (millis() - startTime < 5000) {
//     unsigned long elapsedTime = millis() - startTime;
//     float voltage = 0.9 + (4.1 * elapsedTime / 5000.0); // Linearly increase from 0.9V to 5V
//     int analogValue = (int)(voltage * 255.0 / 5.0); // Map voltage to analog value (0-255)
//     analogWrite(analogPin, analogValue);
//     delay(1);
//   }
// }

void throttleSignals() {
  digitalWrite(throttle, !digitalRead(throttle));
  
}