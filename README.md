# 🌱 Smart Plant Monitoring & Irrigation System 

## Overview
The _**Smart Plant Monitoring & Irrigation System**_ is an IoT-enabled automation project designed to intelligently manage irrigation while providing real-time monitoring of plant conditions. By leveraging internet connectivity, this system allows users to remotely track soil moisture levels and ensure plants receive the right amount of water, reducing both overwatering and underwatering.

Built with a NodeMCU (ESP8266) microcontroller, soil moisture sensors and a relay-controlled water pump, the system automates irrigation by activating the pump only when moisture levels fall below a predefined threshold with also manual control. Additionally, the IoT integration enables data logging and remote access, making plant care more efficient, sustainable and user-friendly.

This repository contains:

✅ Project code to read sensor data and control the irrigation process through web or mobile application

✅ List of required hardware components

✅ Circuit diagram for assembling the hardware components and softwares

✅ All images related to the project

## Features

- **Automated Irrigation** – Controls water flow based on soil moisture levels though web dashboard or mobile application.
- **Real-time Monitoring** – Displays soil moisture and system status via LCD, web and mobile UI.
- **Manual Pump Control** - Lets control water pump through web or mobile UI.

## Components Required 
### Hardwares
+ NODEMCU - ESP8266
+ Soil Moisture Sensor
+ 1Channel 5V Relay Module
+ 3V to 12V Mini DC Submersible Pump
+ Li-ion Rechargeable Battery
+ Breadboard
+ Battery Holder
+ Connecting Wires
+ LCD Display With I2C Module

### Softwares
+ Arduino IDE
+ Blynk Mobile Application

## Circuit Diagram

Follow the diagram to assemble the components correctly.

<div align="center">
  <img src="Project Materials/Circuit Diagram.jpg" alt="Circuit Diagram" width="800"/>
</div>

## Installation and Usage

1. Test all your components one by one to make sure they are working before you hook them up together.
2. Place the ESP8266 on your breadboard and wire it to the LCD-I2C like this: VCC to +Ve, GND to -Ve, SDA to D2, and SCL to D1.
3. Now connect the Soil Moisture Sensor to the ESP8266. Add VCC to +Ve and A0 to A0.
4. Next, connect the 1-Channel Relay Module to the ESP8266. Use VCC to 3.3V, GND to GND, and IN to D3.
5. Time to set up the power supply. Connect the black wires of the battery holder and the pump together. Then connect the red wires like this: Pump to NO and Battery to COM of the Relay
6. Open up Blynk and create a new template. Give it the same name as your project so it’s easy to track.
7. Inside the template, make two datastreams: one called Moisture Value on virtual pin V0 and another called Water Pump on virtual pin V1.
8. Build your web dashboard by adding a gauge for the Moisture Value and a switch for the Water Pump. Save it, then create a new device using this template.
9. Head over to your Arduino code and paste in the Authentication Token from Blynk. Don’t forget to add your Wi-Fi name and password.
10. Do the same setup on the Blynk mobile app: create the dashboard and link the same datastreams.
11. Now it’s time to test! Stick the Soil Moisture Sensor into some dry soil.
12. Watch the gauge. It should show a low moisture level. Then hit the ‘Switch’ on the app or dashboard and you will see the relay power up the pump. If the pump is sitting in water, it will start watering your dry soil automatically.

## Contributing

Contributions are welcome! If you have improvements or additional features, clone the repository:

   git clone `https://github.com/RaianRashidRimon/Smart-Plant-Monitoring-And-Irrigation-System.git`

Or feel free to fork this repository and submit a pull request.





















