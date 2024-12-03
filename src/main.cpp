#include <Arduino.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "sensor.hpp"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// RN2483Serial using RX2 and TX2
HardwareSerial RN2483Serial(2);

Sensor gaz_sensor;

void printSSD1306(String text) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(text);
  display.display();
}

void Init_SSD1306() {
 // SSD1306 initialization
  if(!display.begin(0x3C, 0x3C)) { // Address 0x3C for 128x64
    for(;;);
  }
  display.display();
  delay(2000); // Pause for 2 seconds

  display.clearDisplay();
  display.setTextSize(1); // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0); // Start at top-left corner

  display.println("SSD1306 Oled Initialized!");
  display.display();
  delay(1000);
}

void test_RN2483A() {
  // Send a command to the RN2483A module
  RN2483Serial.println("sys get ver");

  // Wait for a response
  delay(1000);

  // Read the response from the RN2483A module
  while (RN2483Serial.available()) {
    String response = RN2483Serial.readString();
    printSSD1306("RN2483A Response:");
    Serial.println(response);
    printSSD1306(response);
  }
}

void initGateway() {
  String devEUI = "9a0698b4e20d4d2f";
  String joinEUI = "53760ec38137bbf8";
  String appKey = "4f30040e6b6f1a4f6a0ed332fc6f7ae7";

  RN2483Serial.println("mac set deveui " + devEUI);
  delay(100);
  RN2483Serial.println("mac set appeui " + joinEUI);
  delay(100);
  RN2483Serial.println("mac set appkey " + appKey);
  delay(100);
  RN2483Serial.println("mac set pwridx 5");
  delay(100);
  RN2483Serial.println("mac join otaa");
  
  delay(5000);

  if (RN2483Serial.available()) {
    String response = RN2483Serial.readString();
    Serial.println("Join Response: " + response);
    printSSD1306("Join: " + response);

    if (response.indexOf("accepted") >= 0) {
      Serial.println("Join accepted");
      printSSD1306("Join accepted");
    } else {
      Serial.println("Join failed");
      printSSD1306("Join failed");
    }
  }
}

void sendToGateway() {
  // Send Hello : 48656c6c6f in hex
  RN2483Serial.println("mac tx uncnf 1 48656c6c6f");
  delay(1000);

  while (RN2483Serial.available()) {
    String txResponse = RN2483Serial.readString();
    Serial.println("TX Response: " + txResponse);
    printSSD1306("TX Response: " + txResponse);
  }
}


void setup() {
  Serial.begin(115200);

  // Initialize RN2483A Serial communication
  RN2483Serial.begin(57600);
  Serial.begin(115200);

  // Initialize SSD1306
  Init_SSD1306();
  delay(5000);
  initGateway();
}

void loop() {
  // test_RN2483A();
  // Serial.print("Value from sensor: ");
  // Serial.println(gaz_sensor.get_value());
  // delay(1000);

  // Test communication to gateway
  sendToGateway();
}
