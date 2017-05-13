// HariFun 138: Playing with AdaFruit's Circuit Playground Arduino board
// v0 - Read capacitance on port 0.  Works but the threshold need to be adjusted depending on whether we use a wire or touch it directly.
// v1 - Instead of setting a value threshold, let's try a DIFFERENCE threshold.

#include <Adafruit_CircuitPlayground.h>

int prevCap = 0;
int prevAve = 0;
int ave;
int isOn; 
void setup() {
  Serial.begin(9600);
  Serial.println("Playing with Circuit Playground");

  CircuitPlayground.begin();
}

//void debug(string label, float value)
//{
//  Serial.print(" ");
//  Serial.print(label);
//  Serial.print("=");
//  Serial.print(value);
//}

void plot(int value)
{
  Serial.print(value);
  Serial.print(" ");
}

void loop() {
  int cap = CircuitPlayground.readCap(0);
  //plot(prevCap);
  plot(cap);
  if (cap != prevCap) {
    ave = (cap + prevCap) / 2;
    
    int change = cap - prevCap;
    if ( abs(change) > 40)
    {
      isOn = (change>0);
    }
    prevCap = cap;
  }
    plot(ave);
    plot(isOn);
  Serial.println();
  delay(500);
}
