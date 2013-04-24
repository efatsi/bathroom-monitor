const int sensorPin = 0;
const int relayPin = 2;
const int ledPin   = 9;

int lightLevel;

void setup()
{
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  lightLevel = analogRead(sensorPin);
  if (lightLevel < 500) {
    digitalWrite(relayPin, HIGH);
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(relayPin, LOW);
    digitalWrite(ledPin, LOW);
  }
}
