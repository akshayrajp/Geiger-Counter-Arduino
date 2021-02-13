# Radiation Level Monitor using Arduino and Geiger-Müller Tube
### My mini-project for college.

This repository contains the source code to implement a low-cost, yet effective and extensible Geiger Counter (aka Dosimeter), using an Arduino Uno (ATmega328P microcontroller)
and a Geiger-Müller Tube (in my case, it was the J305β Geiger-Müller tube). You will also need a DC-DC Voltage Boost Converter because the voltage provided by the Arduino (5V DC)
is nowhere close to what is required by the Geiger-Müller Tube (can range from anywhere between 350V to 1000V DC).


## Dependencies:
Hardware components:

1. Geiger-Müller Tube
2. DC-DC Voltage Boost Converter
3. Arduino Uno (ATmega328P microcontroller)

To build the source code, you will need:

1. Arduino IDE, with the Time Library.
2. Python3
3. Matplotlib and pyserial.

I'm using Matplotlib to plot the values of radiation against time. Specifically, μSv/hr (microSieverts/hour) vs time (seconds) and CPM (Counts per Minute) vs time (seconds)
A better solution would be to use the RRDtool, as we're logging and plotting time-series data. Plotting the values in real-time would be cool. I am yet to implement this, however.

## Running the code
Compile the .ino file and dump it onto the Arduino. You should start hearing the buzzer clicks as soon as the code is dumped. To view the measurements, open the serial monitor 
and select the appropriate port.

To visualize the data:
1. Close the serial monitor, if it is open.
2. Run ```python3 fileio.py```, and let it run for a while. Ideally for 2-3 minutes. You should see the readings being printed out onto the terminal.
During this time, place objects that emit radiation (such as the radium-coated dials of old watches), and observe the increase in the magnitude of the readings.
3. Next, stop the execution by pressing ```CTRL + C``` (on UNIX-based systems) and then run ```python3 plot.py```
This should output two graphs onto the screen, one of which is μSv/hr vs time (seconds) and the second being CPM vs time(seconds).
If you don't see any graphical output, ensure that all the dependencies are installed properly.


