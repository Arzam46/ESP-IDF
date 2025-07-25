🎚️ ESP32 ADC Reading with Potentiometer (ADC1 Channel 6)
This project demonstrates how to read analog input from a potentiometer connected to the ESP32 using ESP-IDF. The potentiometer is connected to GPIO34 (ADC1 Channel 6)

📁 Project Structure

adc-potentiometer/
├── main/
│   ├── main.c                 # Application code
│   └── CMakeLists.txt         # CMake config for main app
├── CMakeLists.txt             # Root CMake file
├── sdkconfig                  # ESP-IDF config (generated)
└── README.md                  # Project documentation

🧰 Requirements
ESP32 development board
10kΩ Potentiometer
ESP-IDF v4.4+ installed and configured

⚙️ Hardware Setup
Potentiometer Pin	ESP32 Pin
VCC	3.3V
GND	GND
Wiper (Middle)	GPIO34 (ADC1_CH6)

🧪 Features
Uses ADC1 Channel 6 (GPIO34)
Reads 12-bit analog values (0–4095)
Logs the potentiometer value every 500ms

🔧 Build and Flash
idf.py build
idf.py -p COMx flash monitor
Replace COMx with your actual COM port.

🖥️ Monitor Output (Example)
ADC Value: 2489

📝 Notes
The ADC resolution is set to 12 bits (default), giving values from 0 to 4095.
GPIO34 is input-only, suitable for ADC reading.
No external library is needed for this project.

📝 License
This project is licensed under the MIT License.
Copyright (c) 2025 Muhammad Arzam

