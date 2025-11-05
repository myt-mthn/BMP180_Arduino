#include <Wire.h>
#include <Adafruit_BMP085.h>  // or BMP180 library

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
    Serial.println("BMP180 sensor not found!");
    while(1);
  }
}

void loop() {
  Serial.print("Temperature: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" C");

  Serial.print("Pressure: ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  float seaLevelPressure = 100400; // replace with local value in Pa
  float altitude = bmp.readAltitude(seaLevelPressure);

  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");

  delay(1000);
}
