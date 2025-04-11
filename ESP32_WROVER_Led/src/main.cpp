#include <Arduino.h>

#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "LED_ON") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED_OK");
    } else if (cmd == "LED_OFF") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED_OK");
    }
  }
}
