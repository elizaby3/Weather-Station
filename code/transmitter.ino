//Transmitter Code
#include <Adafruit_AHTX0.h>
#include <Wire.h>
#include <WiFiConfig.h>

//Setting up communicatio iwht AHT20 sensor
#define I2C_SDA 6
#define I2C_SCL 7
sensors_event_t humidity, temp;

const int PHOTO = 10;

Adafruit_AHTX0 aht;

uint8_t receiverAddress[] = {0x34, 0xb7,0xda,0xf6,0x38,0xb8};

//shared variable report for data between transmitter and receiver
WeatherReport report;

void setup() {
  pinMode(PHOTO, INPUT);

  //Start communication with AHT20 Sensor
  Wire.begin(I2C_SDA,I2C_SCL);
  aht.begin();

  //Start ESP-32 NOW communication protocol with receiver ESP-32
  wifi_setup();
  peer_setup(receiverAddress);
  Serial.begin(115200);

}

void loop() {
  aht.getEvent(&humidity, &temp);

  //Collecting Data
  report.temperature = int(temp.temperature);
  report.humidity = int(humidity.relative_humidity);
  
  if (digitalRead(PHOTO) == HIGH) {
    report.light = 1;
  } else if (digitalRead(PHOTO) == LOW) {
    report.light = 0;
  }

  //Sending Data
  send_report(receiverAddress, report);

  delay(10000);
}
