#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial mySerial(0); // Use UART0 (RX0, TX0)

void setup() {
  Serial.begin(115200); // Initialize Serial Monitor
  mySerial.begin(57600); // Initialize RN2483A Serial communication

  Serial.println("Testing RN2483A module...");

  // Send a command to the RN2483A module
  mySerial.println("sys get ver");

  // Wait for a response
  delay(1000);

  // Read the response from the RN2483A module
  while (mySerial.available()) {
    String response = mySerial.readString();
    Serial.println("RN2483A Response: " + response);
  }
}

void loop() {
  // Idle loop
  mySerial.begin(115200);
  Serial.println("Idle...");
  delay(1000);
}