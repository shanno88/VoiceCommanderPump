#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11);   //RX.TX
String receive_data;

void setup(){
  mySerial.begin(115200);
  Serial.begin(115200);
  receive_data = "";
  pinMode(5, OUTPUT);
}

void loop(){
  while (mySerial.available() > 0) {
    receive_data = String(receive_data) + String(char(mySerial.read()));
  }
  if (String(receive_data).indexOf("kaishichus") >= 0) {
    digitalWrite(5,HIGH);
    Serial.println("开始出水");
    receive_data = "";
    delay(2000);
    digitalWrite(5,LOW);
  } 
}