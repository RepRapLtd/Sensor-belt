/*
 * Program to control skin vibrator from LIDAR distance
 * 
 * Adrian Bowyer
 * reprapltd.com
 * 
 * 25 April 2019
 * 
 * Licence: GPL
 * 
 */

#include <Wire.h>
#include <VL53L1X.h>
#include "Vibrator.h"

#define VPIN 6

bool debug = true;
Vibrator* vibrator;
VL53L1X sensor;
long nextRead;
long readInterval = 1000;

// Read the distance typed

void ReadSensor()
{
  long t = (long)millis();
  if(nextRead - t > 0)
    return;
    
  sensor.read();
  int d = sensor.ranging_data.range_mm;
  if(debug)
  {
      Serial.print("Distance: ");
      Serial.println(d);
  }
  
  vibrator->SetDistance(d);
  nextRead = t + readInterval;
}


void setup() 
{
  Serial.begin(9600);

  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C
  
  if(debug)
    Serial.println("\nVibe test.");

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }

  // Use long distance mode and allow up to 50000 us (50 ms) for a measurement.
  // You can change these settings to adjust the performance of the sensor, but
  // the minimum timing budget is 20 ms for short distance mode and 33 ms for
  // medium and long distance modes. See the VL53L1X datasheet for more
  // information on range and timing limits.
  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(50000);

  // Start continuous readings at a rate of one measurement every 50 ms (the
  // inter-measurement period). This period should be at least as long as the
  // timing budget.
  sensor.startContinuous(100);

  vibrator = new Vibrator(VPIN, 50, 1000, 4000.0, 50);
  nextRead = millis() + readInterval;
}

void loop() 
{
  vibrator->Spin();
  ReadSensor();
}
