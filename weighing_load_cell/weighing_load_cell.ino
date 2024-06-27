#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

// Replace with your calibration factor
float calibration_factor = 7050; 

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare();  // Reset the scale to 0
}

void loop() {
  float weight = scale.get_units(10);
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" grams");
  delay(1000);
}
