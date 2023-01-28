// Import libraries
#include <Arduino.h>
#include <U8x8lib.h>

// Make synonyms using #define.  No semi-colons needed here.
#define MOSFET 2   // The MOSFET driver for the water pump on digital I/O 2
#define REDLED 4   // Big red LED on digital I/O 4
#define MOISTURE A1 // The moisture sensor
#define WET_THRESH 600 // (update) below 600 is considered wet.

auto display = U8X8_SSD1306_128X64_NONAME_HW_I2C(U8X8_PIN_NONE);

int moistureValue = 0;


/* -------------- Initialize the Grove board ------------- */
void setup() {
  Serial.begin(9600); //(update) enable serial @9600 baud 
    pinMode(MOSFET, OUTPUT); // Sets the D2 pin (MOSFET + Pump) to output
    pinMode(REDLED, OUTPUT); // Sets the D4 pin (LED) to output
    pinMode(MOISTURE, INPUT);// Sets the D6 pin (Button) to input
    digitalWrite(MOSFET, LOW);    // pump off

    display.begin(); // start up the OLED display
    display.setFlipMode(0); // set to 1 or 0, depending on orientation of board
    display.clearDisplay();                     // blank display
    display.setFont(u8x8_font_profont29_2x3_r); 
}

/* --------------- Run this over and over ------------------- */
void loop() {

    // Read soil moisture sensor & assign to a variable
    moistureValue = analogRead(MOISTURE);
    
  if(analogRead(MOISTURE) > WET_THRESH) // sensor detects dry soil
  {
      digitalWrite(MOSFET, HIGH);    // pump on
      digitalWrite(REDLED, HIGH);    // LED on
      display.setCursor(0,0);
      display.print("Soil Dry!");

   } 
   else   // sensor detects soil is not dry
   {
      digitalWrite(MOSFET, LOW);    // pump off
      digitalWrite(REDLED, LOW);    // LED off
      display.setCursor(0,0);
      display.print("Watered!");
   }
}
