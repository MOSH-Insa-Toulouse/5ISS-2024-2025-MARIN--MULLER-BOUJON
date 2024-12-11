#include "Arduino.h"
#include "BluetoothSerial.h"
#include <Wire.h>
#include <SPI.h>

BluetoothSerial SerialBT;

const int LED_BUILTIN = 2;

String receivedMessage = "";

void processBluetoothMessage(String message);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    Serial.begin(115200);
    Serial.println("Starting Bluetooth...");

    if (!SerialBT.begin("ESP32 Yohan et Robin")) {
        Serial.println("Error on starting Bluetooth");
        while (1);
    }

    Serial.println("Bluetooth started, waitint for connections...");
}

void loop() {
    if (SerialBT.available()) {
        char receivedChar = SerialBT.read();

        receivedMessage += receivedChar;
        Serial.print("Current message: ");
        Serial.println(receivedMessage);

        if (receivedMessage.endsWith("o")) {
            processBluetoothMessage("ON");
            receivedMessage = "";
        } else if (receivedMessage.endsWith("f")) {
            processBluetoothMessage("OFF");
            receivedMessage = "";
        }
    }
}

void processBluetoothMessage(String message) {
    message.trim();
    Serial.println("Received: " + message);

    if (message.equalsIgnoreCase("ON")) {
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("Turning LED ON");
    } else if (message.equalsIgnoreCase("OFF")) {
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("Turning LED OFF");
    } else {
        Serial.println("Invalid command received");
    }
}
