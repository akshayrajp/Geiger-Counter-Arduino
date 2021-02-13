#include <Time.h>
#include <TimeLib.h>

// Connect the GND pin on Arduino to the GND pin on the Geiger counter.
// Connect the 5V pin on Arduino to the 5V pin on the Geiger counter.
// Connect the VIN pin on the Geiger counter to the D2 pin on Arduino.

unsigned long counts;               // variable for GM Tube events
unsigned long previousMillis;       // variable for measuring time
#define LOG_PERIOD 1000             // count rate
#define usv_multiplier 0.1          // For the J305β tube
#define cpm_multiplier 2.3456       // For the J305β tube

void impulse() {
  counts++;
}

void setup()
{
    counts = 0;
    Serial.begin(9600);
    pinMode(2, INPUT);
    attachInterrupt(digitalPinToInterrupt(2), impulse, FALLING); // define external interrupts
}

void loop()
{
    String usv, cpm;
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis > LOG_PERIOD)
    {
        previousMillis = currentMillis;

        if(counts != 0)
        {
	         // Log the time
	        time_t t = now();
	        String time = String((minute(t) * 60) + (second(t)));

          // Print in μSv/hr
	        usv = String(counts * usv_multiplier);
          Serial.println("usv " + time + " " + usv);

          // Print in CPM
	        cpm = String(counts * cpm_multiplier);
          Serial.println("cpm " + time + " " + cpm);
        }
        counts = 0;
    }
}
