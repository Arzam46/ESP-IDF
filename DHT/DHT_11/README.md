# 🌡️ DHT11 Sensor with ESP32 using ESP-IDF

This project demonstrates how to interface a **DHT11 temperature and humidity sensor** with the **ESP32** using the **ESP-IDF framework** and the [UncleRus `esp-idf-lib`](https://github.com/UncleRus/esp-idf-lib) DHT driver.

---

## 📁 Project Structure

DHT/
├── components/
│ ├── dht/ # DHT driver (from esp-idf-lib)
│ └── esp_idf_lib_helpers/ # Helper component (dependency)
├── main/
│ ├── main.c # Main application code
│ └── CMakeLists.txt # CMake config for main app
├── CMakeLists.txt # Root CMake config
├── sdkconfig # ESP-IDF configuration file
└── README.md # This file

---

## 🚀 Features

- Read **temperature** and **humidity** from the DHT11 sensor.
- Log values using ESP-IDF's `ESP_LOGI`.
- Graceful error handling with readable logs.
- Reads data every 2 seconds.

---

## 🧰 Requirements

- ESP32 board
- DHT11 sensor
- ESP-IDF v4.4+ installed and configured
- DHT11 connected to **GPIO 27** (default, configurable)

---

## 🔧 Hardware Connections

| DHT11 Pin | ESP32 Pin |
|-----------|-----------|
| VCC       | 3.3V      |
| GND       | GND       |
| DATA      | GPIO 27   |

*(A 10kΩ pull-up resistor between VCC and DATA is recommended)*

---

## 🛠️ Setup Instructions

1. **Clone the esp-idf-lib repo (optional method)**  
   If using git:
   ```bash
   git clone --recursive https://github.com/UncleRus/esp-idf-lib.git

Or manually download:

dht → place in components/dht
esp_idf_lib_helpers → place in components/esp_idf_lib_helpers

Build and Flash
idf.py build
idf.py -p COMx flash monitor


Monitor output

I (1234) DHT: Temperature: 26.0 °C, Humidity: 55.0 %

📄 License
This project is licensed under the MIT License — feel free to use.