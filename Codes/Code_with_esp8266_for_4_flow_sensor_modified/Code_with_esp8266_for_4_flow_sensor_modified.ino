

#include <FlowMeter.h>
#include <SPI.h>
#include "Wire.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define led 12
FlowMeter Meter1 = FlowMeter(2);
FlowMeter Meter2 = FlowMeter(3);
FlowMeter Meter3 = FlowMeter(18);
FlowMeter Meter4 = FlowMeter(19);


// define an 'interrupt service handler' (ISR) for every interrupt pin you use
void Meter1ISR() {
  // let our flow meter count the pulses
  Meter1.count();
}
// define an 'interrupt service handler' (ISR) for every interrupt pin you use
void Meter2ISR() {
  // let our flow meter count the pulses
  Meter2.count();
}

void Meter3ISR() {
  // let our flow meter count the pulses
  Meter3.count();
}

void Meter4ISR() {
  // let our flow meter count the pulses
  Meter4.count();
}


void setup() {

  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();

  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);

  attachInterrupt(INT0, Meter1ISR, RISING);
  attachInterrupt(INT1, Meter2ISR, RISING);
  attachInterrupt(INT4, Meter3ISR, RISING);
  attachInterrupt(INT5, Meter4ISR, RISING);
  Meter1.reset();
  Meter2.reset();
  Meter3.reset();
  Meter4.reset();
}
void loop() {


  information();

}

void information() {

  Meter1.tick(3000);
  Meter2.tick(3000);
  Meter3.tick(3000);
  Meter4.tick(3000);

  Serial.print(String(Meter1.getCurrentFlowrate()));
  Serial.print("l/m");
  Serial.print(":");
  Serial.print( String(Meter1.getTotalVolume()));
  Serial.print("L total");
  Serial.print(":");
  Serial.print(String(Meter2.getCurrentFlowrate()));
  Serial.print("l/m");
  Serial.print(":");
  Serial.print( String(Meter2.getTotalVolume()));
  Serial.print("L total:");
  Serial.println(" ");

  Serial.print(String(Meter3.getCurrentFlowrate()));
  Serial.print("l/m");
  Serial.print(":");
  Serial.print( String(Meter3.getTotalVolume()));
  Serial.print("L total");
  Serial.print(":");
  Serial.print(String(Meter4.getCurrentFlowrate()));
  Serial.print("l/m");
  Serial.print(":");
  Serial.print( String(Meter4.getTotalVolume()));
  Serial.print("L total:");
  Serial.println(" ");



  display.clearDisplay();
  display.setCursor(10, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("Water Flow meter");


  display.setCursor(4, 11);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("1--------");

  display.setCursor(0, 18);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("R:");
  display.print(Meter1.getCurrentFlowrate());
  display.setCursor(43, 18);
  display.setTextSize(1);
  display.print("L/M");

  display.setCursor(0, 28);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("V:");
  display.print(Meter1.getTotalVolume());

  display.setCursor(43, 28 );
  display.setTextSize(1);
  display.print("L");
  display.display();


  display.setCursor(4, 36);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("2--------");

  display.setCursor(0, 45);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("R:");
  display.print(Meter2.getCurrentFlowrate());
  display.setCursor(43, 45);
  display.setTextSize(1);
  display.print("L/M");

  display.setCursor(0, 55);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("V:");
  display.print(Meter2.getTotalVolume());
  display.setCursor(43, 55 );
  display.setTextSize(1);
  display.print("L");
  display.display();


  display.setCursor(70, 11);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("--------3");

  display.setCursor(68, 18);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("R:");
  display.print(Meter3.getCurrentFlowrate());
  display.setCursor(110, 18);
  display.setTextSize(1);
  display.print("L/M");


  display.setCursor(68, 28);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("V:");
  display.print(Meter3.getTotalVolume());
  display.setCursor(110, 28);
  display.setTextSize(1);
  display.print("L");
  display.display();

  display.setCursor(70, 36);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("--------4");

  display.setCursor(68, 45); //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("R:");
  display.print(Meter4.getCurrentFlowrate());
  display.setCursor(110, 45); //oled display
  display.setTextSize(1);
  display.print("L/M");

  display.setCursor(68, 55); //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("V:");
  display.print(Meter4.getTotalVolume());
  display.setCursor(110, 55); //oled display
  display.setTextSize(1);
  display.print("L");
  display.display();
  delay (3000);
}
