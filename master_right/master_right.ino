#include <Wire.h>

const int addr = 8;
const int n_bytes = 8;
byte a, b;
int16_t bigNum;
int16_t smallNum;

int voltage[4];

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(addr, n_bytes);    // request 6 bytes from slave device addr

  while (Wire.available()) { // slave may send less than requested
    a = Wire.read();
    b = Wire.read();
    smallNum = a;
    bigNum = smallNum << 8 | b;
//    Serial.print(bigNum);
//    Serial.print(" ");
    voltage[0] = bigNum;

    a = Wire.read();
    b = Wire.read();
    smallNum = a;
    bigNum = smallNum << 8 | b;
//    Serial.print(bigNum);
//    Serial.print(" ");
    voltage[1] = bigNum + voltage[0];

    a = Wire.read();
    b = Wire.read();
    smallNum = a;
    bigNum = smallNum << 8 | b;
//    Serial.print(bigNum);
//    Serial.print(" ");
    voltage[2] = bigNum + voltage[1];

    a = Wire.read();
    b = Wire.read();
    smallNum = a;
    bigNum = smallNum << 8 | b;
//    Serial.print(bigNum);
//    Serial.print(" ");
    voltage[3] = bigNum + voltage[2];
  }

  for(int i=0; i<4; i++){
    Serial.print(voltage[i] * (5.0/1023.0) );
    Serial.print(' ');
  }
  Serial.println();
  delay(500);
  
}
