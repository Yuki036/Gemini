#include "SerialBT.h"

SerialBT SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("PicoW_Server");  // サーバーデバイス名を設定
  pinMode(32, OUTPUT);
  digitalWrite(32, LOW);
  Serial.println("Waiting for a connection...");
}

void loop() {
  if (SerialBT.available()) {
    byte inBuf[1];
    SerialBT.readBytes(inBuf, 1);
    Serial.print((char)inBuf[0]);
    Serial.println("");

    if (inBuf[0] == 's') {
      SerialBT.println("ECHO BACK >> LED ON");
      digitalWrite(32, HIGH);
    }
    if (inBuf[0] == 'g') {
      SerialBT.println("ECHO BACK >> LED OFF");
      digitalWrite(32, LOW);
    }
  }
}