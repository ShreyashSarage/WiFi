#define PIN_LED 2
#define PIN_BUTTON 0
#define DEBOUNCE_DELAY 300

bool currentLEDstate = true;
unsigned long lastDebounceTime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  Serial.begin(115200);
  Serial.println("setup complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(PIN_BUTTON);
  unsigned long currentTime = millis();

  if((reading == LOW) && ((currentTime - lastDebounceTime) > DEBOUNCE_DELAY)) 
  {
    //process thye button presss if we have exceed the debounce time

    lastDebounceTime = currentTime;
    currentLEDstate = !currentLEDstate;

    Serial.print("changing led state to: ");
    Serial.println(currentLEDstate);

    digitalWrite(PIN_LED , currentLEDstate);
  }
}
