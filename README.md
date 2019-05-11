# Arduino-Robot-Control-using-Python-script
In this project I am using a PC to send commands to an Arduino based Robot. The transmitter consists of an RF 433 MHz Transmitter module connected to an Arduino Uno / Pro mini / Nano / Mega.The Transmitter Arduino is connected to a laptop/PC via a USB cable for Serial Communication. In our case the Receiver Arduino is a being used to control a Differential Drive Robot. The Receiver Arduino is mounted with an RF 433MHz Receiver Module.

### Steps for Running Python Script
- To Execute the Python Script we need to install Pygame library.
- You need pip(package installer for python) to install pygame library.
- If you don't have pip installed in your system, install pip from [here](https://pip.pypa.io/en/stable/installing/).
- run command in terminal or cmd `pip install pygame` or `sudo pip install pygame`.
- to run the script run the command in terminal or cmd `python Python_script_transmitter.py`.

### Connections for Transmitter circuit
- The arduino remains connected via USB cable to the laptop/PC running the python script at all times.
- connect +5v terminal of arduino to the Vcc terminal of RF_TX(transmitter) module.  
- connect Gnd terminal of arduino to the Gnd Terminal of RF_TX(transmitter) module.
- connect D11 terminal of arduino to the Data terminal of RF_TX(transmitter) module.
- connect the antenna terminal of RF_TX(transmitter) module to an Antenna.**(this connection is OPTIONAL)**
- The connections are illustrated in the Transmitter wiring diagram.png.

### Connections for the Receiver circuit
- The receiver arduino is standalone, so it is powered by an external 9V battery.
- connect +5v terminal of arduino to the Vcc terminal of the RF_RX(receiver) module.
- connect Gnd terminal of the arduino to the Gnd terminal of the RF_RX(receiver) module.
- connect the D11 terminal of the arduino to the Data terminal of the RF_RX(receiver) module.
- connect the antenna terminal of RF_RX(receiver) to an Antenna.**(this connection is OPTIONAL)**
- connections for the Motor Driver
  - connect the D2 terminal of the arduino to Motor 1 A terminal of Motor Driver.
  - connect the D3 terminal of the arduino to Motor 1 B terminal of Motor Driver.
  - connect the D4 terminal of the arduino to Motor 2 A terminal of Motor Driver.
  - connect the D5 terminal of the arduino to Motor 2 B terminal of Motor Driver.
  - connect the Motor Driver ext_supply terminal to +9V terminal of the battery.
  - connect the Motor Driver Gnd terminal to the Gnd terminal of the battery.
- connections are well illustrated in the Receiver wiring diagram.png.

### Installing Radiohead library
- We need to install Radiohead library for arduino to run the arduino sketches.
- Download Radiohead Library from [here.](http://www.airspayce.com/mikem/arduino/RadioHead/RadioHead-1.41.zip)
- Extract the zip file and move the 'Radiohead' folder to Documents/Arduino/Libraries folder.


### Final Project picture > Arduino Based Robot.jpg
