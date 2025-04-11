## Main Purpose
A wirelessly communicating weather station with two ESP-32 boards, AHT20 humidity and temperature sensor, and LCD display. Please see github page for the code used to program the ESP-32 Microcontrollers.

## Materials Used
- Two ESP-32 Microcontrollers
- AHT20 Sensor
- LCD with I2C
- One Photoresistor
- Two Breadboards
- Wires
- 9V Battery
- Micro USB Cable


## Transmitter Set Up
![](https://github.com/elizaby3/Weather-Station/blob/main/images/transmitter.jpg?raw=true)

In this image, the ESP-32 transmitter board (distinguished by the green sticky note) is connected to a 9V battery, AHT20 sensor for collecting the humidity and temperature data bia I2C protocol, and a photoresistor for determining whether it is daytime or nighttime. The ESP-32 transmitter board sends data to the receiver ESP-32 board every 10 seconds via ESP-32 NOW protocol.

## Receiver Set Up
![](https://github.com/elizaby3/Weather-Station/blob/main/images/receiver.jpg?raw=true)

In this image, the ESP-32 receiver board (distinguished by the orange stickynote) is connected to the LCD display via I2C protocol where the I2C display updates every 10 seconds to display the humidity and temperature inside of the room along with the time of day.

[Link to Main Projects Page](https://elizaby3.github.io)
