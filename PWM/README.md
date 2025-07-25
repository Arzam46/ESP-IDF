# PWM LED Control - ESP-IDF Project

This project demonstrates how to use Pulse Width Modulation (PWM) to control the brightness of an LED using ESP-IDF on the ESP32.

## 📁 Project Structure

PWM/
├── main/
│ ├── CMakeLists.txt
│ └── pwm_led.c # Main application logic
├── CMakeLists.txt # Project configuration
├── sdkconfig # ESP-IDF configuration file
└── README.md # This file

## 💡 Features

- Control an LED's brightness with PWM
- Smooth fading effect using software timer or hardware PWM
- Customizable GPIO pin, duty cycle, and frequency

## 🧰 Requirements

- ESP32 development board
- LED + resistor (connected to PWM-capable GPIO, e.g., GPIO 2)
- ESP-IDF installed and configured

## 🚀 How to Build and Flash

```bash
idf.py build
idf.py -p COMx flash
idf.py monitor

📌 Notes
You can change the GPIO number and PWM settings in main/pwm_led.c.
Make sure the board is properly connected and the COM port is correct.
Compatible with ESP-IDF v4.x and v5.x

📜 License
This project is open source and available under the MIT License.


---


