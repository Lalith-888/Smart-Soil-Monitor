# Smart-Soil-Monitor
# Smart Soil Moisture Monitoring System

This project uses a **Soil Moisture Sensor**, **ESP8266**, and **NinjaIoT platform** to monitor the moisture level of soil in real-time. If the soil becomes too dry, a **buzzer alerts the user** to water the plant. It includes a **fallback mode** that ensures the alert still works even when Wi-Fi is disconnected.

---

## Project Objectives

- Monitor real-time soil moisture data.
- Send data to the cloud using [NinjaIoT](https://iot.roboninja.in/).
- Alert users via a buzzer when the soil is too dry.
- Handle Wi-Fi disconnection with a fallback local alert.

---

## Hardware Components

| Component            
|----------------------
| ESP8266    
| Soil Moisture Sensor
| Buzzer (Active)      
| Jumper Wires         
| Breadboard          

---

## Circuit connection

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

## Code Summary – Smart Soil Moisture Monitor


This Arduino code uses an ESP8266 board to read values from a soil moisture sensor (connected to pin A0). The moisture level is:

Sent to NinjaIoT cloud for real-time monitoring.

Used to control a buzzer connected to pin D6.

If the soil moisture drops below a threshold (value < 300), the buzzer is turned ON to alert the user. When moisture is sufficient, the buzzer stays OFF.

The code also includes a Wi-Fi reconnection check (fallback mode) to ensure the device reconnects to NinjaIoT if disconnected.
