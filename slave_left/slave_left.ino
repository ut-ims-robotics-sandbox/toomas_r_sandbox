#include <Wire.h>

const int addr = 8;

void setup() {
  Wire.begin(addr);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write("hilli\nsdfg"); // respond with message of 6 bytes
  // as expected by master
}
