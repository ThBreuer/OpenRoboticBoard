# OpenRoboticBoard
**An open source hardware and software package to control simple robots**

## Quick Start Guide (MicroPython)
1. Download and install Software, Tools and Examples from ![OpenRoboticBoard.exe](https://github.com/ThBreuer/OpenRoboticBoard/blob/main/OpenRoboticBoard.exe)
2. Install [Notepad++](https://notepad-plus-plus.org)
3. Install the ORB Notepad plugin: Copy directory `%ORB%\Tools\NotepadPlugin\OpenRoboticBoard` into `%PROG%\Notepad++\plugins`
5. Load example `%ORB%\Example\MicroPython\Demo\demo.py`in Notepad++
6. Compile an start application with Notepad++ menu *Plugins* - *Open Robotic Board* - *Monitor*, or use the menu icon ...
   

## Content of the OpenRoboticBoard's Repositories

* [`ORB-Hardware`](https://github.com/ThBreuer/ORB-Hardware): Schematics, CAD
* [`ORB-Firmware`](https://github.com/ThBreuer/ORB-Firmware): A firmware for the ORB
* [`ORB-Application`](https://github.com/ThBreuer/ORB-Application): Template to create own Applications for the ORB
* [`ORB-Monitor_Windows`](https://github.com/ThBreuer/ORB-Monitor_Windows): Windows-Application monitoring the ORB (Local Application) 
* [`ORB-Monitor_Android`](https://github.com/ThBreuer/ORB-Monitor_Android): Android-Application monitoring the ORB (Local Application)
* [`ORB-Mobile_Android`](https://github.com/ThBreuer/ORB-Mobile_Android): Android-Application with a Javascript Interface to the ORB

## Features

The board integrates the control electronics required to operate a robot. Sensors and actuators can be connected directly.

* **Dimensions:**
  * 104 mm x 72 mm

* **Power supply:**
  * The board can be powerd by a 7.4V voltage source (battery or LiPo).

* **Sensor connections:**
  * 4 ports to connect sensors, each with a 5V power supply as well as 4 additional signal lines that can be used either as analog input (2x), digital IO (4x), UART or I2C interface. Alternatively, RJ-12 or 6-pin PCB header connector can be soldered in as a plug connection.
  * 2 ports for connecting an external push button (binary input)

* **Actuator connections:**
  * 4 ports to connect DC motors, each with a power output (H-bridge) as well as a power supply and digital input for an encoder.
  * 2 ports to connect servo actuators

* **Bus connections:**
  * 1 port as I2C bus connection with power supply (5V)

* **Communication:**
  * Bluetooth module
  * USB C

* **Software download:**
  * USB boot loader
  * SWD debug interface

* **User interface:**
  * 1 push buttons
  * 3 LEDs
  * 1 main switch

![Board Overview](https://github.com/ThBreuer/ORB-Hardware/blob/main/Ver-01.xx/Doc/Hardware-Overview.png)

[Hardware Interface and Port Description](https://github.com/ThBreuer/ORB-Hardware/blob/main/Ver-01.xx/Doc/Hardware-InterfaceSpezification.pdf)

[Schematics](https://github.com/ThBreuer/ORB-Hardware/blob/main/Ver-01.xx/Doc/Schematics.pdf)

[KiCad project files](https://github.com/ThBreuer/ORB-Hardware/blob/main/Ver-01.xx/KiCad)

## Programming
Of course, you can build software from the scratch. Once done, you can download and debug your software either with a bootloader via USB or with a debugger via the 6-pin SWD-connector.

A more comfortable way to build an user application is using the firmware. Therefore the firmware is equipped with an internal API (for a **local application** running from flash) and an external USB/Bluetooth interface protocoll (for a **remote application** running on external devices).

### Firmware
The firmware provides various services:
* Sensor reading of different sensor types:
  * EV3-sensors with UART interface
  * NXT ultrasonic (limited to small distances)
  * EV3 and NXT touch sensor
  * MakeBlock ultrasonic sensor
  * MakeBlock line follower
  * Sensors with analog output (e.g. NXT light sensor)
* Motor controlling 
  * DC motors with/without encoder (NXT, EV3, MakeBlock and others)
  * Brake or power mode
  * Speed or position control for motors with encoder
* Servo controlling
  * Positioning and Speed
* Communication interface via USB or Bluetooth
  * Sensor readings and motor commands
  * Board configuration
* Local Application
  * Download to ORB flash memory
  * Execution and data exchange (API)
  * Emulated button input and text output via USB/Bluetooth

#### Update the Firmware
The firmware can be updated via USB.

#### Start-up
* Power ORB with battery or LiPo. The red LED (voltage indicator) is flashing
* Connect ORB with external device (Windows-PC, Android-Device) by USB or pair as Bluetooth device. In case of Bluetooth connected: a red LED near of the Bluetooth module is flashing twice.

#### Documentation
See [Firmware Specification](https://github.com/ThBreuer/ORB-Firmware/blob/main/Doc/Firmware-Specification.pdf)

### Local Application
The local application is a software, which can be loaded with the `ORB-Monitor (Windows)` to the ORB flash memory. Once loaded, the local application can be started/stopped by pressing a button either on the ORB or on the `ORB-Monitor`.
The local application can use the firmware API to read sensors or to set motor and servo actions. Furthermore, the local application can receive key events from the virtual keyboard of the `ORB-Monitor` or can send text strings to the text field of the `ORB-Monitor`.

[ORB-Application](https://github.com/ThBreuer/ORB-Application)

### Remote Application
A remote application controls the ORB via the USB/Bluetooth interface protocol of the firmware. 

[ORB-Firmware: Remote Application Interface Protocoll](https://github.com/ThBreuer/ORB-Firmware/blob/main/Doc/Firmware-RemoteInterfaceProtocol.pdf)

## Tools

### ORB-Monitor (Windows-App or Android-App)
This app is usefull to handle a local application.

* Download local applications (Windows version only)
* Start and stop a local application
* Virtual keyboard and text output fields as local application's I/O 
* Configuration options

### ORB-Mobile (Android-App)
This app executes Javascript based applications provided by an external HTTP server. The Javascript can communicate with the app to control the ORB via USB/Bluetooth. This way, the Javascript can read sensors and set actuators.

* By default, the `Open Roberta Lab` page is loaded. Here you can program and run your own application.
* Configuration options
* Built-in test site to check sensors and actuators

[ORB-Mobile: Javascript Interface](https://github.com/ThBreuer/ORB-Mobile_Android/blob/main/Doc/JavascriptInterface.pdf)
