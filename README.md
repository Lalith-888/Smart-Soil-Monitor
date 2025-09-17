# Smart-Soil-Monitor
# 🌱 Smart Soil Moisture Monitoring System

This project uses a **Soil Moisture Sensor**, **ESP8266**, and **NinjaIoT platform** to monitor the moisture level of soil in real-time. If the soil becomes too dry, a **buzzer alerts the user** to water the plant. It includes a **fallback mode** that ensures the alert still works even when Wi-Fi is disconnected.

---

## 📌 Project Objectives

- Monitor real-time soil moisture data.
- Send data to the cloud using [NinjaIoT](https://iot.roboninja.in/).
- Alert users via a buzzer when the soil is too dry.
- Handle Wi-Fi disconnection with a fallback local alert.

---

## 🔧 Hardware Components

| Component            
|----------------------
| ESP8266    
| Soil Moisture Sensor
| Buzzer (Active)      
| Jumper Wires         
| Breadboard          

---

## 🔌 Circuit Diagram

![WhatsApp Image 2025-09-18 at 01 48 57_e9357dd3](https://github.com/user-attachments/assets/863598ba-1c0f-4bf0-9a87-f12a088c8320)

**Connections:**

### Soil Moisture Sensor
- **VCC** → 3.3V (or VIN)
- **GND** → GND
- **A0** → A0 pin of NodeMCU

### Buzzer
- **+ (Positive)** → D6
- **– (Negative)** → GND

---

## 📄 Code Overview

```cpp
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
    digitalWrite(buzzerPin, HIGH);
    Serial.println("⚠️ Soil is dry!");
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(1500);
}
