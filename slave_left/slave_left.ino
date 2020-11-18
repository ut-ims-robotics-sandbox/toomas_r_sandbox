#include <Wire.h>

const int addr = 8;

int16_t sensor_value0;
int16_t sensor_value1;
int16_t sensor_value2;
int16_t sensor_value3;

byte myArray[2];


void setup() {
  Wire.begin(addr);                // join i2c bus with address addr
  Wire.onRequest(requestEvent); // register event

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  //master küsib meilt infot, teostame mõõtmised ja vastame talle

  sensor_value0 = analogRead(A0);
  sensor_value1 = analogRead(A1);
  sensor_value2 = analogRead(A2);
  sensor_value3 = analogRead(A3);

//  sensor_value0 = 1023;
//  sensor_value1 = 103;
//  sensor_value2 = 800;
//  sensor_value3 = 987;


  myArray[0] = (sensor_value0 >> 8) & 0xFF;
  myArray[1] = sensor_value0 & 0xFF;
  Wire.write(myArray, 2);

  myArray[0] = (sensor_value1 >> 8) & 0xFF;
  myArray[1] = sensor_value1 & 0xFF;
  Wire.write(myArray, 2);
  
  myArray[0] = (sensor_value2 >> 8) & 0xFF;
  myArray[1] = sensor_value2 & 0xFF;
  Wire.write(myArray, 2);
  
  myArray[0] = (sensor_value3 >> 8) & 0xFF;
  myArray[1] = sensor_value3 & 0xFF;
  Wire.write(myArray, 2);

  //Wire.write(sensor_value0);
  //Wire.write("hilli\nsdfg"); // respond with message of 6 bytes
  // as expected by master
}
