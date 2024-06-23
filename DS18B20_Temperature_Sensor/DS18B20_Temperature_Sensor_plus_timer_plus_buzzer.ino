//https://wokwi.com/projects/401506835603830785

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is conntec to the Arduino digital pin 4
#define ONE_WIRE_BUS 32

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

// Variable to store the previous temperature
float previousTemperature = 0.0;
const float temperatureThreshold = 0.5; // Define the threshold for significant change


void setup(){
pinMode(23,INPUT);
pinMode(22,INPUT);
pinMode(21,INPUT);
pinMode(19,INPUT);
pinMode(18,INPUT);
pinMode(5,OUTPUT);

//pinMode(32,INPUT);

Serial.begin(9600);
 Serial.print("hello start");

  // Start up the library
  sensors.begin();
}

void loop(){

 // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 

  float currentTemperature = sensors.getTempCByIndex(0);
  
 if (abs(currentTemperature - previousTemperature) >= temperatureThreshold && currentTemperature != -127.00) {
    Serial.print("Celsius temperature: ");
    Serial.println(currentTemperature);
    // Update the previous temperature
    previousTemperature = currentTemperature;
  }

  

if(digitalRead(23)==LOW){
  Serial.print("hello bitches");
  delay(500);
}
if(digitalRead(22)==LOW){
  Serial.print("hello nigga");
  delay(500);
}
if(digitalRead(21)==LOW){
  Serial.print("hello xin ping");
  delay(500);
}
if(digitalRead(19)==LOW){
  Serial.print("hail hydra");
  delay(500);
}
if(digitalRead(18)==LOW){
  Serial.print("its full bitches");
  playSound();
  delay(500);
}
}

void playSound() {
  tone(5, 1000, 500); // Play tone on pin 5 at 1000Hz for 500ms
}