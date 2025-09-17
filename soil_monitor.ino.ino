#include <NinjaIoT.h>
#include <ESP8266WiFi.h>

NinjaIoT iot;

int SoilMoisture = 0;
const int buzzerPin = D6;

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  iot.connect("shubhajaani", "druvilalu27", "LJ09");   // NinjaIoT credentials
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi disconnected! Reconnecting...");
    iot.connect("shubhajaani", "druvilalu27", "LJ09");
  }

  SoilMoisture = analogRead(A0);
  Serial.print("Soil Moisture: ");
  Serial.println(SoilMoisture);

  if (WiFi.status() == WL_CONNECTED) {
    iot.WriteVar("SoilMoisture", SoilMoisture);
  }

  if (SoilMoisture < 300) {
    digitalWrite(buzzerPin, HIGH);  // Buzzer ON
  } else {
    digitalWrite(buzzerPin, LOW);   // Buzzer OFF
  }

  delay(1500);
}
