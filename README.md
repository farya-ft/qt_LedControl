# Qt LED Control with ESP32

This project demonstrates how to control an **LED on an ESP32** board using a **Qt QML user interface (UI)**. The app communicates with the ESP32 via **serial communication** to send commands for turning the LED on or off.

## 🚀 Project Overview

- **Qt QML Frontend**: A user interface built with Qt and QML to control the LED on the ESP32.
- **ESP32**: An Arduino-based backend running code that listens for serial commands to control the LED.
- **Serial Communication**: The Qt app sends commands like `LED_ON` and `LED_OFF` via serial communication, and the ESP32 responds by toggling the LED.

## 🔧 Technologies Used

- **Qt Quick** (QML) for the frontend UI
- **C++** for backend logic in Qt
- **ESP32 (Arduino)** for handling the LED and serial communication
- **Serial Communication** via USB to control the LED on the ESP32

## ⚙️ Setup & Installation

1. **Clone the repository**:
    ```bash
    git clone https://github.com/farya-ft/qt_LedControl.git
    cd qt_LedControl
    ```

2. **Install Dependencies**:
    - Ensure that you have **Qt 6.x** and **Qt Creator** installed.
    - For ESP32 development, you need to have the **ESP32 Arduino framework** set up in your IDE (Arduino IDE or PlatformIO).
    - Ensure that your ESP32 is connected to the computer via USB.

3. **Build and Run the Project**:
    - Open the project in **Qt Creator** or use **VS Code** with **CMake**.
    - If you want to use **VS Code** with **CMake**, you can run the following command to build the project:
      ```bash
      cmake .
      make
      ```
    - Alternatively, use the provided **`build_and_run.sh`** script to automatically build and run the project:
      ```bash
      ./build_and_run.sh
      ```

4. **Upload the ESP32 Firmware**:
    - Use the **Arduino IDE** or **PlatformIO** to upload the **ESP32 LED control firmware**. The firmware listens for serial commands (`LED_ON`, `LED_OFF`) to toggle the LED on GPIO2 (or the pin you have connected).

## 📸 Screenshots

![Project Screenshot](images/example.png)

## 💡 How It Works

- When the app is launched, it will display a **"Connect to ESP32"** button.
- Pressing the button will initiate a **serial connection** to the ESP32 and send commands to control the LED.
- The app will send `LED_ON` or `LED_OFF` commands via **serial**.
- The **ESP32** will receive these commands and toggle the LED accordingly.
  
## 🛠 CMake Build Configuration

The project includes a **CMakeLists.txt** file for easy building on your system.

- **CMake Setup**: The project uses CMake to manage the build process for the Qt frontend.
- **Qt Setup**: Qt modules such as `Core`, `Gui`, `Qml`, `Quick`, and `QuickControls2` are used.

## 🔧 Serial Communication

For the communication to work properly between your Qt UI and ESP32, make sure the correct **serial port** is selected in the Qt code. You may need to adjust the serial port in the code or your IDE to match the port of your connected ESP32.

Example:

```cpp
serialReader.start("/dev/tty.usbserial-xxxx"); // Update with your actual serial port# qt_LedControl
