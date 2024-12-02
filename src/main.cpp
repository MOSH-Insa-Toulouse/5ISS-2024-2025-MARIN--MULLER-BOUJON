#include <Arduino.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// RN2483Serial using RX2 and TX2
HardwareSerial RN2483Serial(2);

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
    printSSD1306(response);
  }
}


void setup() {
  // Initialize RN2483A Serial communication
  RN2483Serial.begin(57600);

  // Initialize SSD1306
  Init_SSD1306();

}

void loop() {
  test_RN2483A();
  delay(1000);
}




