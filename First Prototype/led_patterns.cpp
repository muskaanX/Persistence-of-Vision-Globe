# include <Arduino.h>

const int ledPins[] = {2, 3, 4, 5, 6};
const long totalDelay = 1000;

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void pattern_1(){
  for (int i = 0; i <= 5; i++){
    digitalWrite(ledPins[i], HIGH);
    delay(totalDelay);
    digitalWrite(ledPins[i], LOW);
    delay(totalDelay);
  }
}

void pattern_2(){
  for (int i = 5; i >= 0; i--){
    digitalWrite(ledPins[i], HIGH);
    delay(totalDelay);
    digitalWrite(ledPins[i], LOW);
    delay(totalDelay);
  }
}

void pattern_3(){
  for(int i = 0; i <= 5; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(totalDelay);
  }
  for(int i = 0; i <= 5; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void pattern_4(){
  for (int i = 5; i >= 0; i--){
    digitalWrite(ledPins[i], HIGH);
    delay(totalDelay);
  }
  for(int i = 5; i >= 0; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void pattern_5(){
  for(int i = 0; i <= 5; i = i + 2) {
    digitalWrite(ledPins[i], HIGH);
    delay(totalDelay);
    digitalWrite(ledPins[i], LOW);
  }
  for(int i = 1; i <= 5; i = i + 2) {
    digitalWrite(ledPins[i], HIGH);
    delay(totalDelay);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  pattern_1();
  pattern_2();
  pattern_3();
  pattern_4();
  pattern_5();
}
