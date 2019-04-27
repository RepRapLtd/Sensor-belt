
Vibrator::Vibrator(const int pin, const int defaultMark, const int maxSpc, const float maxD, const int thresh)
{
  vPin = pin;
  pinMode(vPin, OUTPUT);
  digitalWrite(vPin, 0);
  mark = defaultMark;
  maxSpace = maxSpc;
  maxDistance = maxD;
  threshold = thresh;
  maxVibrate = 255.0 - (float)threshold;
  SetDistance(50 + (int)maxDistance);  
}

// Set the vibration pattern

void Vibrator::SetDistance(int distance)
{
  float frac = (float)distance/maxDistance;
  if(frac > 1.0)
  {
    switchedOff = true;
    digitalWrite(vPin, 0);
    return;
  }

  switchedOff = false;
  space = (int)(0.5 + maxSpace*frac);
  vibrateValue = threshold + (int)(0.5 + maxVibrate*(1.0 - frac));
  nextChange = (long)millis() - 10;
}

// Execute the vibration pattern

void Vibrator::Spin()
{
  if(switchedOff)
    return;
    
  long t = (long)millis();
  if(nextChange - t > 0)
    return;
  if(on)
  {
    on = false;
    analogWrite(vPin, 0);
    nextChange = t + space;
  } else
  {
    on = true;
    analogWrite(vPin, vibrateValue);
    nextChange = t + mark;    
  }
}

