////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////  Author: Jiri Kucera                                   ////
////  Description: Search key data command for your remote  ////
////               control                                  ////
////  Using board: Robotdyn Uno R3 (Arduino Uno)            ////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
////  include libraries and set pin                         ////
////////////////////////////////////////////////////////////////

#include <IRremote.hpp>

const int IR_PIN = 4;

////////////////////////////////////////////////////////////////
////  Setup                                                 ////
////////////////////////////////////////////////////////////////

void setup(){
  //initialize serial for debugging and print result
  Serial.begin(115200);
  //start the receiver
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK); 

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
  }
}
