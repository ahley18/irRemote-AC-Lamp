#include<IRremote.h>

IRrecv IR1(3);
int relay = 8;

void setup() {
  // put your setup code here, to run once:
  IR1.enableIRIn();
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay,LOW);
}

void FLASH(){
  digitalWrite(relay,HIGH);
  delay(500);
  digitalWrite(relay,LOW);
  delay(500);
  digitalWrite(relay,HIGH);
  delay(500);
  digitalWrite(relay,LOW);
  delay(500);
  digitalWrite(relay,HIGH);
  delay(500);
  digitalWrite(relay,LOW);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(IR1.decode()){
    Serial.println(IR1.decodedIRData.decodedRawData, HEX);
    if(IR1.decodedIRData.decodedRawData == 0x3F8 /*number 1 on remote*/){
      digitalWrite(relay,HIGH);
    }

    if(IR1.decodedIRData.decodedRawData == 0x3F4 /*number 2 on remote*/){
      digitalWrite(relay,LOW);
    }

    if(IR1.decodedIRData.decodedRawData == 0x3FC /*number 0 on remote*/){
       FLASH();
    }
    IR1.resume();
  }
}
