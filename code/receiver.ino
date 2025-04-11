//Receiver Code

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFiConfig.h>

//LCD setup
#define I2C_SDA 8
#define I2C_SCL 10

LiquidCrystal_I2C lcd(0x27, 16,2);

//Storing Trasmitter Data in report
WeatherReport report;

void setup() {

  wifi_setup();
  Wire.begin(I2C_SDA,I2C_SCL);

  //LCD setup
  lcd.init();
  lcd.backlight();

  //setting up to get data
  set_report_receiver(&report);

  Serial.begin(115200);
}

void loop() {
  
  //reset LCD text
  lcd.clear();
  lcd.setCursor(0,0);

  //print transmitter data
  lcd.print("Temp: " + String(report.temperature) + "C");
  lcd.setCursor(0,1);
  lcd.print("Hum: " + String(report.humidity) + "%,");

  //determining whether it is day or night
  lcd.setCursor(8,1);
  if (report.light == 1) {
    lcd.print(" Day");
  } else if (report.light == 0); {
    lcd.print(" Night");
  }
  
  delay(10000);
}
