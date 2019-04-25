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

const int vibrator = 3;
const float dmax = 4000.0;
const float maxSpace = 1000.0;
const int threshold = 50;
const float maxVibrate = 255.0 - (float)threshold;

int mark = 50;
int space = 1000;
long nextChange;
int vibrateValue = 0;
int d;
bool on;
bool debug = true;

// Set the vibration pattern

void SetVibrating(int distance)
{
  if(debug)
  {
    Serial.print("Setting distance: ");
    Serial.println(distance);
  }
  float frac = (float)distance/dmax;
  if(frac > 1.0)
    frac = 1.0;
  space = (int)(maxSpace*frac);
  vibrateValue = threshold + (int)(maxVibrate*(1.0 - frac));
  nextChange = (long)millis() - 10;
}

// Execute the vibration pattern

void Vibrate()
{
  long t = (long)millis();
  if(nextChange - t > 0)
    return;
  if(on)
  {
    on = false;
    analogWrite(vibrator, 0);
    nextChange = t + space;
  } else
  {
    on = true;
    analogWrite(vibrator, vibrateValue);
    nextChange = t + mark;    
  }
}

// Read the distance typed

void ReadInput()
{
  if(!Serial.available())
    return;
    
  // This is a nasty way to read an integer...
  
  char c = (char)Serial.read();
  if(c == '\n')
  {
    SetVibrating(d);
    d = 0;
  }else
  {
    d = 10*d + c - '0';
  } 
}


void setup() 
{
  pinMode(vibrator, OUTPUT);
  digitalWrite(vibrator, 0);

  Serial.begin(9600);
  
  if(debug)
    Serial.println("\nVibe test.");
    
  SetVibrating((int)(dmax+0.5));
}

void loop() 
{
  Vibrate();
  ReadInput();
}
