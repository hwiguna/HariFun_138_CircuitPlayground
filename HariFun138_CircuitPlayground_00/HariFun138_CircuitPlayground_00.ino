// HariFun 138: Playing with AdaFruit's Circuit Playground Arduino board
// v0 - Read capacitance on port 0.  Works but the threshold need to be adjusted depending on whether we use a wire or touch it directly.

#include <Adafruit_CircuitPlayground.h>

int oldCap0 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Playing with Circuit Playground");
  
  CircuitPlayground.begin();
}

void loop() {
  int cap = CircuitPlayground.readCap(0);
  if (cap != oldCap0) {
    Serial.print("Capsense #0: "); Serial.print(cap);
    if (cap>10) Serial.print(" *");
     Serial.println();
    oldCap0 = cap;
  }
}
