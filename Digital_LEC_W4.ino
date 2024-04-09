int ledPinArray[4] = { 29, 30, 31, 32 };
int buttonPinArray[3] = { 33, 34, 35 };
int switchPinArray[1] = { 36 };

int totalLeds = 4;
int totalButtons = 3;

int inCrease = 500;
int potValue = 0;

long randNumber;
long randNumber2;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < totalLeds; i++) {
    pinMode(ledPinArray[i], OUTPUT);
  }
  for (int i = 0; i < totalButtons; i++) {
    pinMode(buttonPinArray[i], INPUT);
  }
  pinMode(switchPinArray[0], INPUT);
  randomSeed(analogRead(0));
}

void loop() {
  potValue = analogRead(A13);
  Serial.println(inCrease);
  randNumber = random(300);
  delay(100);
  if (digitalRead(buttonPinArray[0]) == HIGH) {
    for (int i = 3; i >= 0; i--) {
      digitalWrite(ledPinArray[i], HIGH);
      delay(inCrease);
      digitalWrite(ledPinArray[i], LOW);
      delay(inCrease);
      inCrease -= 25;
      if (inCrease < 0) {
        inCrease = 0;
        for (int i = 3; i >= 0; i--) {
          digitalWrite(ledPinArray[i], LOW);
          delay(inCrease);
        }
        inCrease = 500;
      }  //The inCrease variable is used like a count down so the sequence starts at 500ms and then goes faster and faster until the delay hits 0. Sort of like a time bomb.
    }
  }
  if (digitalRead(switchPinArray[0]) == LOW) {
    if (digitalRead(buttonPinArray[1]) == HIGH) {
      for (int i = 3; i >= 0; i--) {
        digitalWrite(ledPinArray[i], HIGH);
        delay(potValue);
        digitalWrite(ledPinArray[i], LOW);
        delay(potValue);
      }
    }
  }
  if (digitalRead(switchPinArray[0]) == HIGH) {
    if (digitalRead(buttonPinArray[1]) == HIGH) {
      for (int i = 0; i < totalLeds; i++) {
        digitalWrite(ledPinArray[i], HIGH);
        delay(potValue);
        digitalWrite(ledPinArray[i], LOW);
        delay(potValue);
      }
    }
  }
  if (digitalRead(buttonPinArray[2]) == HIGH) {
    int randNumber2 = random(0, 4);
    digitalWrite(ledPinArray[randNumber2], HIGH);
    delay(potValue);
    digitalWrite(ledPinArray[randNumber2], LOW);
    delay(potValue);
  }
}