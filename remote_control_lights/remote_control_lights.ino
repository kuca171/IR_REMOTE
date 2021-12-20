////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////  Author: Jiri Kucera                                   ////
////  Description: remote control light                     ////
////                                                        ////
////  Using board: Robotdyn Uno R3 (Arduino Uno)            ////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
////  include libraries and set pin                         ////
////////////////////////////////////////////////////////////////

#include <IRremote.hpp>

const int IR_PIN = 4;

//led pins
const int LED1_PIN = 2;
const int LED2_PIN = 3;

////////////////////////////////////////////////////////////////
////  Setup                                                 ////
////////////////////////////////////////////////////////////////

void setup(){
  //initialize serial for debugging and print result
  Serial.begin(115200);
  //start the receiver
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK); 

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}
////////////////////////////////////////////////////////////////
////  Loop                                                  ////
////////////////////////////////////////////////////////////////

void loop() {
  if (IrReceiver.decode()) {
    //print result to serial
    Serial.print("HEX= ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    //to print all fields
    IrReceiver.printIRResultShort(&Serial); 
    Serial.println("");
     
    //enable receiving of the next value
    IrReceiver.resume(); 

    //check the received data and blink led
    if (IrReceiver.decodedIRData.command == 0x0C) {
      digitalWrite(LED1_PIN, HIGH);
      delay(2000);
      digitalWrite(LED1_PIN, LOW);} 
    else if (IrReceiver.decodedIRData.command == 0x18) {
      digitalWrite(LED2_PIN, HIGH);
      delay(2000);
      digitalWrite(LED2_PIN, LOW);  
    }
  }
}
