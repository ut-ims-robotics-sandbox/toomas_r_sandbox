#include <Wire.h>

const int addr = 8;
const int n_bytes = 8;
byte a, b;
int16_t bigNum;
int16_t smallNum;
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
    Serial.print(bigNum);
    Serial.print(" ");
  }
  Serial.println();
  delay(500);
}
