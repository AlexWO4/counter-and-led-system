const int ledPin1 = 11;
const int ledPin2 = 10;
const int ledPin3 = 9;

const int buttonPin = 2;

int buttonState = HIGH;
int count = 1;
int Bpress;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(19200);
}

void loop() {

  //adds 1 to the count for each button press
  buttonState = digitalRead(buttonPin);
  if (buttonState==LOW) {
      Bpress = count++;
      delay(500);
    }
    
   Serial.println(Bpress);

   // checks for first button press, turns on LED 1 if button has been pressed once or more
   if (Bpress >= 2) {
    digitalWrite(ledPin1, HIGH);
    } else {
      digitalWrite(ledPin1, LOW);
      }

    // checks for second button press, turns on LED 3 if button has been pressed once or more
    if (Bpress >= 3) {
      digitalWrite(ledPin2, HIGH);
      } else {
        digitalWrite(ledPin2, LOW);
        }

    // checks for third button press, turns on LED 3 if button has been pressed once and cycles through animation
    if (Bpress == 4) {
      digitalWrite(ledPin3, HIGH);
      delay(1000);
      digitalWrite(ledPin1, LOW);
      delay(250);
      digitalWrite(ledPin2, LOW);
      delay(250);
      digitalWrite(ledPin3, LOW);
      delay(1000);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(500);
      
      // resets the count to default
      Bpress = 1;
      count = 1;
      delay(250);
      
      } else {
        digitalWrite(ledPin3, LOW);
        }
  
}
