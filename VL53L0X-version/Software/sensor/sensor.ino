/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X.h>

const int maxReading = 2000;
const int minExcitation = 70;
const int minDelay = 100;
const int maxDelay = 1000;
const int vibePin = 3;
const int debugPin = 2;
char debug = 0;
int range;

VL53L0X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();
  pinMode(vibePin, OUTPUT);
  pinMode(debugPin, INPUT_PULLUP);
  debug = !digitalRead(debugPin);
  
}

void loop()
{
  int reading = sensor.readRangeContinuousMillimeters();
  if(reading > maxReading)
    range = maxReading;
  else
    range = reading;
    
  if (sensor.timeoutOccurred() && debug)
    Serial.print(" TIMEOUT");


  float frac = (float)(maxReading - range)/(float)maxReading;
  int v = minExcitation + (int)((255.0 - (float)minExcitation)*frac);
  if(debug)
  {
    Serial.print(reading);
    Serial.print(' ');
    Serial.print(range);
    Serial.print(' ');
    Serial.println(v);
  }
  analogWrite(vibePin, v);
  delay(300);
  analogWrite(vibePin, 0);
  v = minDelay + maxDelay - 
  int((float)(maxDelay - minDelay)*frac);
  delay(v);  

  debug = !digitalRead(debugPin);
}
