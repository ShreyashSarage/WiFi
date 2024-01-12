
#define LED_BUILTIN 2

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Setup Complete");
}

void loop()
{
  Serial.println("LED ON");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  Serial.println("LED OFF");
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
