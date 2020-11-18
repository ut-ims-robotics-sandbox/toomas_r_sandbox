#include <Wire.h>

const int addr = 8;
const int n_bytes = 4*4;
byte a, b;
int16_t bigNum;
int16_t smallNum;

float voltage[4];
void setup() {
  voltage[0] = 1.23456789;
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(addr, n_bytes);    // request 6 bytes from slave device addr
  String dataString = "";

  unsigned char bytes[4];

  
  while (Wire.available()) { // slave may send less than requested
//    a = Wire.read();
//    b = Wire.read();
//    smallNum = a;
//    bigNum = smallNum << 8 | b;
////    Serial.print(bigNum);
////    Serial.print(" ");
//    voltage[0] = bigNum;

      for(int i=0; i<
      byte c = Wire.read();
      byte d = Wire.read();
      byte e = Wire.read();
      byte f = Wire.read();
      
      //Serial.print(c);
      //dataString = dataString + c;
      bytes[0] = c;
      bytes[1] = d;
      bytes[2] = e;
      bytes[3] = f;
  }
  float x;
  memcpy(&voltage[0], bytes, sizeof voltage[0]);
  
  //Serial.print(dataString);
  //voltage[0] = dataString.toFloat();
  //voltage[0] = *(float *)&dataString;
  
  Serial.print(" pinge on ");
  Serial.print(voltage[0], 6);

//  for(int i=0; i<4; i++){
//    Serial.print(voltage[i] * (5.0/1023.0) );
//    Serial.print(' ');
//  }
  Serial.println();
  delay(500);
  
}
