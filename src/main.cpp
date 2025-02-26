#include <Arduino.h>
const int pin = 2;
const int potPin = A0;

int ledPins[] = {10, 11, 12, 13};

struct Range
{
  int start;
  int end;
};

Range a[] = {
    {0, 15},     // N
    {167, 182},  // 1
    {337, 352},  // 2
    {507, 522},  // 3
    {677, 692},  // 4
    {847, 862},  // 5
    {1017, 1024} // Assuming "R" corresponds to index 6
};

void setup()
{
  Serial.begin(9600);
  pinMode(pin, INPUT);
  pinMode(potPin, INPUT);

  for (int i = 0; i < 4; i++)
  {
    pinMode(ledPins[i], OUTPUT); // Set each pin as output
  }
}

void runLedSequence()
{
  static int i = 0;
  digitalWrite(ledPins[i], HIGH);           // Turn ON LED
  digitalWrite(ledPins[(i + 1) % 4], HIGH); // Turn ON LED
  delay(1000);
  digitalWrite(ledPins[i], LOW);           // Turn OFF LED
  digitalWrite(ledPins[(i + 1) % 4], LOW); // Turn OFF LED
  i = (i + 1) % 4;
}

void loop()
{
  int potValue = analogRead(potPin);

  if (digitalRead(pin) == HIGH && potValue < 150)
  {
    runLedSequence();

    // Serial.println("Pin is HIGH");
  }
  else
  {
    Serial.println("Pin is LOW");
  }
  Serial.println(potValue);

  // delay(500);
}
