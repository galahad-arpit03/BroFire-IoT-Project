
# BroFire IoT Project

**BroFire** is an IoT-based project that allows wireless control of room lights and fans using the **Blynk Cloud**. This project enhances home automation by connecting electrical appliances to the internet, enabling control through a smartphone or other devices.

## Features
- **Wireless Control**: Remotely control room lights and fans via the Blynk app.
- **Real-Time Monitoring**: Check the status of appliances (on/off) through the app.
- **IoT Integration**: Uses Blynk Cloud for seamless wireless communication and control.
- **User-Friendly**: Easy setup and control with a smartphone from anywhere.

## Components Used
- **NodeMCU ESP8266** (for Wi-Fi connectivity)
- **Relay Module** (to control electrical appliances)
- **Blynk App** (for wireless control)
- **Light & Fan Setup** (connected to relay)
- **Jumper Wires & Breadboard**

## How It Works
1. **Connection to Blynk Cloud**: The system connects to the Blynk Cloud through the NodeMCU, enabling wireless control.
2. **Relay Control**: The relay module is used to switch the lights and fans on or off based on commands sent from the Blynk app.
3. **Mobile App Control**: The user can control the appliances wirelessly through the Blynk app interface.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/brofire-iot.git
   ```
2. Install the required libraries:
   - **ESP8266WiFi.h** (for Wi-Fi connectivity)
   - **BlynkSimpleEsp8266.h** (for Blynk cloud communication)
3. Flash the code onto the **NodeMCU ESP8266** board.
4. Configure the **Blynk App** with the provided authentication token.

## Setup Steps
1. Connect the **NodeMCU ESP8266** to the **Relay Module** and your light/fan setup.
2. In the **Blynk App**, create buttons for controlling the light and fan.
3. Use the app to control the devices wirelessly through the Blynk Cloud.

## Usage
1. Power up the system and connect to Wi-Fi.
2. Open the **Blynk App** on your smartphone.
3. Use the buttons in the app to switch lights and fans on or off wirelessly.

## Contributing
If you'd like to contribute, feel free to submit issues or pull requests!
