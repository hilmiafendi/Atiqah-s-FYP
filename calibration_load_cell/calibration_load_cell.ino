#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("HX711 Calibration");

  Serial.println("Remove all weight from scale");
  delay(5000);
  
  Serial.println("Initializing scale...");
  scale.set_scale();
  scale.tare();  // Reset the scale to 0

  Serial.println("Place a known weight on the scale");
  delay(5000);

  long reading = scale.get_units(10);
  Serial.print("Reading: ");
  Serial.println(reading);
  Serial.println("Enter the known weight in grams:");

  while (!Serial.available());
  float known_weight = Serial.parseFloat();

  float calibration_factor = reading / known_weight;
  Serial.print("Calibration Factor: ");
  Serial.println(calibration_factor);
}

void loop() {
  // Nothing to do here
}
