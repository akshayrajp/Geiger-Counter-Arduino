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
    Serial.println("Begin");
}

void loop() 
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis > LOG_PERIOD) 
    {
        previousMillis = currentMillis;

        if(counts != 0)
        {
          // Print in usV
          Serial.print(counts * usv_multiplier);
          Serial.println(" μSv/h");

          // Print in CPM
          Serial.print(counts * cpm_multiplier);
          Serial.println(" CPM");
        }

        counts = 0;
    }
}
