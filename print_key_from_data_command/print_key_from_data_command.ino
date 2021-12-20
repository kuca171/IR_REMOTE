////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////  Author: Jiri Kucera                                   ////
////  Description: Print key from data command to serial    ////
////                                                        ////
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

    //switch decode data command to key
    switch(IrReceiver.decodedIRData.command){
      case 0x45:
      Serial.println("CH-");
      break;
      case 0x46:
      Serial.println("CH");
      break;
      case 0x47:
      Serial.println("CH+");
      break;
      case 0x44:
      Serial.println("|<<");
      break;
      case 0x40:
      Serial.println(">>|");
      break ;  
      case 0x43:
      Serial.println(">|");
      break ;               
      case 0x07:
      Serial.println("-");
      break ;  
      case 0x15:
      Serial.println("+");
      break ;  
      case 0x09:
      Serial.println("EQ");
      break ;  
      case 0x16:
      Serial.println("0");
      break ;  
      case 0x19:
      Serial.println("100+");
      break ;
      case 0x0D:
      Serial.println("200+");
      break ;
      case 0x0C:
      Serial.println("1");
      break ;
      case 0x18:
      Serial.println("2");
      break ;
      case 0x5E:
      Serial.println("3");
      break ;
      case 0x08:
      Serial.println("4");
      break ;
      case 0x1C:
      Serial.println("5");
      break ;
      case 0x5A:
      Serial.println("6");
      break ;
      case 0x42:
      Serial.println("7");
      break ;
      case 0x52:
      Serial.println("8");
      break ;
      case 0x4A:
      Serial.println("9");
      break ;      
    }  
  }
}
