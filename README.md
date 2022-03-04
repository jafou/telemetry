# telemetry
Aristotle Racing Team Telemetry System

This repository contains the source code implementing the Telemetry System for ART-16 prototype race car.
The Telemetry is used to extract and visualise valuable data from on board the vehicle in real time, both during testing and racing. Examples of data collected are:
  - Engine Oil pressure
  - Engine Oil temperature
  - Engine temperature
  - Throttle position
  - Brake pressure
  - Brake disc temperature
  - MAP (Manifold Air Pressure)

The software part of the telemetry system comprises of two parts:
  1) The code running on the ATMega microcontroller on board the car. This code gathers the sensor data from the CAN Bus and transmits them serially to a Zigbee module in order
     to be sent wirelessly to the receiver end.
  2) The desktop application running on the Race engineer's laptop. This code is implemented in C++ using Qt framework.
     A Zigbee receiver module is connected to the laptop and inputs the incoming data to the USB port. The application reads the serial messages, extracts the required data
     and visualizes the aforementioned properties on a simple GUI:
     
![telemetry_GUI](https://user-images.githubusercontent.com/23053353/156830330-6f4eb23f-70ba-4437-a94e-f475806a16e9.png)
