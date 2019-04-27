
class Vibrator
{
  public:
    Vibrator(const int pin, const int defaultMark, const int maxSpc, const float maxD, const int thresh);
    void SetDistance(int distance);
    void Spin();

  private:
    int mark;
    int space;
    long nextChange;
    int vibrateValue;
    bool on;
    bool switchedOff;
    int vPin;
    int maxSpace;
    float maxDistance;
    int threshold;
    float maxVibrate;
};
