const int pin = 2;
const int potPin = A0;

int ledPins[] = {10,11,12,13};



void setup() {
    Serial.begin(9600);
    pinMode(pin, INPUT);
     pinMode(potPin, INPUT);

    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);  // Set each pin as output
    }
}

void runLedSequence() {
    static int i = 0;
    digitalWrite(ledPins[i], HIGH); // Turn ON LED
    digitalWrite(ledPins[(i+1) % 4], HIGH); // Turn ON LED
    delay(500);
    digitalWrite(ledPins[i], LOW);  // Turn OFF LED
    digitalWrite(ledPins[(i+1) % 4], LOW); // Turn OFF LED
    i = (i + 1) % 4;
}

void loop() {
    int potValue = analogRead(potPin);

    if (digitalRead(pin) == HIGH && potValue < 150)  {
      runLedSequence();
     
      // Serial.println("Pin is HIGH");

    } else {
        Serial.println("Pin is LOW");
    }
    Serial.println(potValue);

    
    // delay(500);
}































// int ledPins[] = {13, 12, 11, 10};

// void setup() {
//   for (int i = 0; i < 4; i++) {
//         pinMode(ledPins[i], OUTPUT);  // Set each pin as output
//     }
// }
// void loop() {

//         static int i = 0;
//         digitalWrite(ledPins[i], HIGH); // Turn ON LED
//         digitalWrite(ledPins[(i+1)%4], HIGH); // Turn ON LED

//         delay(10);
//         digitalWrite(ledPins[i], LOW);  // Turn OFF LED
//         digitalWrite(ledPins[(i+1)%4], LOW); // Turn ON LED

//         i = (i + 1) % 4; 
   


// }





// void setup() {
//   Serial.begin(9600); // Initialize serial communication at 9600 bits per second
// }

// void loop() {
//   int sensorValue = analogRead(A0); // Read the input on analog pin A0
//   Serial.println(sensorValue);      // Print the value to the Serial Monitor
//   delay(100);                       // Wait for 100 milliseconds
// }



