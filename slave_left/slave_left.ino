#include <Wire.h>

const int addr = 8;

float sensor_value0;
float sensor_value1;
float sensor_value2;
float sensor_value3;

float voltage[4];

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

  sensor_value0 = analogRead(A0) * 5.0/1023.0;
  sensor_value1 = analogRead(A1) * 5.0/1023.0;
  sensor_value2 = analogRead(A2) * 5.0/1023.0;
  sensor_value3 = analogRead(A3) * 5.0/1023.0;

  //do conversions abd calculations
  voltage[0] = sensor_value0;
  voltage[1] = sensor_value1;
  voltage[2] = sensor_value2;
  voltage[3] = sensor_value3;


  for(int i=0; i<4; i++){ //for every measurement
    for(int j=0; j<4; j++){ //for every byte in that measurement
      Wire.write(*((unsigned char*)&voltage[i] + j));
    }    
  }
  
}
