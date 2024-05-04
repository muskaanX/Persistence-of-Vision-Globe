#include <Arduino.h>

const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200;

void setup() {
  pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
}

void loop() {
  digitalWrite(dirPin, HIGH);

  for(int x = 0; x < stepsPerRevolution; x++)
	{
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(500);  // reduced from 2000 to 500
		digitalWrite(stepPin, LOW);
		delayMicroseconds(500);
	}

  delay(1000);
  digitalWrite(dirPin, LOW);

  for(int x = 0; x < stepsPerRevolution; x++)
	{
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(500);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(500);
	}
  
  delay(1000);
}
