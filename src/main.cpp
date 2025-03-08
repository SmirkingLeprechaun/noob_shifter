#include <Arduino.h>
#define INVALID_PIN -1

const int pin = INVALID_PIN; // No valid pin assigned
const int potPin = A0;
int ledPins[] = {10, 11, 12, 13};

// experimental pin configuration (REMOVABLE)
int experimentalPins[] = {2, 3, 4, 5, 6, 7};

////////////////////////////////////////////////////////////////////////

// stepper motor error cofiguration
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
////////////////////////////////////////////////////////////////////////

void setup()
{
  Serial.begin(9600);
  pinMode(pin, INPUT);
  pinMode(potPin, INPUT);

  for (int i = 0; i < 4; i++)
  {
    pinMode(ledPins[i], OUTPUT); // Set each pin as output
  }

  // Experimental pin configuration (REMOVEABLE)
  for (int i = 0; i < 6; i++)
  {
    pinMode(experimentalPins[i], INPUT); // Set each pin as output
  }
  ////////////////////////////////////////////////////////////////////////
}

void runLedSequence()
{
  static int i = 0;
  digitalWrite(ledPins[i], HIGH);           // Turn ON LED
  digitalWrite(ledPins[(i + 1) % 4], HIGH); // Turn ON LED
  delay(10);
  digitalWrite(ledPins[i], LOW);           // Turn OFF LED
  digitalWrite(ledPins[(i + 1) % 4], LOW); // Turn OFF LED
  i = (i + 1) % 4;
}

void loop()
{
  int potValue = analogRead(potPin);
  // runLedSequence();

  if (digitalRead(2) == HIGH && potValue < 167)
  {
    runLedSequence();

    // Serial.println("Pin is HIGH");
  }
  else if (digitalRead(3) == HIGH && potValue < 337)
  {
    runLedSequence();
  }
  else if (digitalRead(4) == HIGH && potValue < 507)
  {
    runLedSequence();
  }
  else if (digitalRead(5) == HIGH && potValue < 677)
  {
    runLedSequence();
  }
  else if (digitalRead(6) == HIGH && potValue < 847)
  {
    runLedSequence();
  }
  else if (digitalRead(7) == HIGH && potValue < 1017)
  {
    runLedSequence();
  }
}

// Serial.println("////////////////////////////////////////////////////////////////");
// Serial.println(potValue);

// for (int j = 0; j < 6; j++)
// {
//   Serial.print("Gear Val: ");

//   Serial.print(j + 1); // Print gear number
//   Serial.print(" - Pin State: ");
//   Serial.println(digitalRead(experimentalPins[j])); // Print pin state & move to the next line
// }
// Serial.println("////////////////////////////////////////////////////////////////");

// delay(500);