# 🚨 IoT-Based Person & Wheelchair Fall Detection System

[![Blynk IoT](https://img.shields.io/badge/IoT-Blynk-04D0D9?style=flat-square&logo=blynk)](https://blynk.io/)
[![Hardware](https://img.shields.io/badge/Hardware-ESP32%20%7C%20LCD%20%7C%20I2C-blue?style=flat-square)](https://www.espressif.com/)

A professional-grade safety monitoring system that combines **Motion Analytics** with **Visual and Audio feedback**. This system detects falls and immediately notifies caregivers via the **Blynk Cloud** while providing local status updates on an **LCD Display**.

---

## 📊 How It Works (The Logic)
The system continuously monitors body orientation and impact forces.
1. **Detection:** The Accelerometer/Gyroscope calculates the resultant force ($A_{total}$) to identify a high-impact fall.
2. **Visual Feedback:** The **16x2 LCD** displays the real-time status (e.g., "System OK" or "FALL DETECTED!").
3. **Local Alarm:** An **Active Buzzer** triggers a loud siren to alert people nearby.
4. **IoT Alert:** The **ESP32** sends a high-priority push notification to the user's smartphone via **Blynk**.

## 🌟 Key Advantages
* **Multi-Layer Alerts:** Combines Local (Buzzer/LCD) and Remote (Smartphone) notifications.
* **Instant Information:** The LCD provides immediate data without needing to check a phone.
* **Global Monitoring:** Caregivers can track the user from anywhere in the world.
* **Hands-Free Operation:** The system triggers automatically, even if the user is unconscious.

## 🛠️ Components & Hardware
| Component | Function |
| :--- | :--- |
| **ESP32 Board** | Main IoT Controller with Wi-Fi. |
| **Accel & Gyro Sensor** | Detects motion, impact, and orientation. |
| **16x2 LCD (I2C)** | Displays system status and emergency messages. |
| **Active Buzzer** | Sounds a loud alarm during a fall event. |
| **Jumper Wires** | For secure circuit connections. |
| **Power Source** | 5V Power Bank or 3.7V Li-Po battery. |

## 🌍 Real-World Applications
* **Elderly Care:** Smart home safety for seniors living independently.
* **Smart Wheelchairs:** Accident and tip-over detection for mobility aid users.
* **Patient Monitoring:** Hospital-grade safety for high-risk fall patients.

## 🔌 Hardware Connections (I2C Shared)
*Note: Both the LCD and Sensor use the I2C bus (SDA/SCL).*

| Component Pin | ESP32 Pin | Description |
| :--- | :--- | :--- |
| **VCC** | 5V / 3.3V | Power Supply |
| **GND** | GND | Ground |
| **SDA** | GPIO 21 | Data Line (Shared) |
| **SCL** | GPIO 22 | Clock Line (Shared) |
| **Buzzer (+)** | GPIO 18 | Alarm Output |

## ⚙️ Software Setup
1. **Blynk App:** Setup your Template and get the **Auth Token**.
2. **Libraries:** Install `Blynk`, `LiquidCrystal_I2C`, and the sensor library in Arduino



