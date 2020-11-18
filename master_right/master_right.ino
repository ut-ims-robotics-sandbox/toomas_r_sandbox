#include <Wire.h>

//test 2 to github
//test 3 to github

const int addr = 8;
const int n_bytes = 16;

float voltage[4];

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(addr, n_bytes);    // request 4*4 bytes from slave device addr

  unsigned char bytes[4];

  while (Wire.available()) {

      for(int i=0; i<4; i++){
        unsigned char bytes[4];

        for(int j=0; j<4; j++){
          bytes[j] = Wire.read();
        }

        memcpy(&voltage[i], bytes, sizeof voltage[i]);
      
      }
      
  }

  for(int i=0; i<4; i++){
    Serial.print(voltage[i], 6); 
    Serial.print(' ');   
  }
  
  Serial.println();
  delay(500);
  
}
