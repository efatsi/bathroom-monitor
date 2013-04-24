const int sensorPin    = 0;
const int relayPin     = 2;
const int ledPin       = 9;
const int bounceBuffer = 1000;

long onStart  = millis();
long offStart = millis();

bool on = false;

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
  Serial.println(lightLevel);
  if (lightLevel < 300) {
    if (on == false) {
      onStart = millis();
      on = true;
    }
    else if (millis() - onStart > bounceBuffer) {
      digitalWrite(relayPin, HIGH);
      digitalWrite(ledPin, HIGH);
    }
  }
  else {
    if (on == true) {
      offStart = millis();
      on = false;
    }
    else if (millis() - offStart > bounceBuffer) {
      digitalWrite(relayPin, LOW);
      digitalWrite(ledPin, LOW);
    }
  }
}
