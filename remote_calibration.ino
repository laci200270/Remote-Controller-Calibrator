#include <EEPROM.h>
#include "datas.h"


void setup() {
  Serial.begin(115200);
  Serial.println("Remote controller entered to calibration mode!");
  Serial.println("Do you want to clear EEPROM?");
  sendInfo();
  if(parseAnswer()){
    for ( int i = 0 ; i < EEPROM.length() ; i++ ){
    EEPROM.update(i, 0);}
    Serial.println("EEPROM cleared");
    Serial.println("Filling EEPROM with default datas");
    EEPROM.update(minThr,0);
    EEPROM.update(maxThr,255);
    EEPROM.update(invertThr,0);

    EEPROM.update(minThr,0);
    EEPROM.update(maxThr,255);
    EEPROM.update(invertThr,0);

    EEPROM.update(minThr,0);
    EEPROM.update(maxThr,255);
    EEPROM.update(invertThr,0);

    EEPROM.update(minThr,0);
    EEPROM.update(maxThr,255);
    EEPROM.update(invertThr,0);

    Serial.println("EEPROM filled with default data!");
    
    
    }
    Serial.println("Do you want to calibrate throttle?");
    if(parseAnswer()){
        Serial.println("You now have 10 sec to move throttle joystick between end points!");
        calibrateJoy(pinThr,minThr,maxThr);
        Serial.println("Do you want to invert it?");
        if(parseAnswer()){
          EEPROM.update(invertThr,1);
          }
      }
      Serial.println("Do you want to calibrate yaw?");
    if(parseAnswer()){
        Serial.println("You now have 10 sec to move yaw joystick between end points!");
        calibrateJoy(pinYaw,minYaw,maxYaw);
        Serial.println("Do you want to invert it?");
        if(parseAnswer()){
         EEPROM.update(invertYaw,1);
          }
      }
      Serial.println("Do you want to calibrate pitch?");
    if(parseAnswer()){
        Serial.println("You now have 10 sec to move pitch joystick between end points!");
        calibrateJoy(pinPitch,minPitch,maxPitch);
        Serial.println("Do you want to invert it?");
        if(parseAnswer()){
          EEPROM.update(invertPitch,1);
          }
      }
      Serial.println("Do you want to calibrate roll?");
    if(parseAnswer()){
        Serial.println("You now have 10 sec to move roll joystick between end points!");
        calibrateJoy(pinRoll,minRoll,maxRoll);
        Serial.println("Do you want to invert it?");
        if(parseAnswer()){
          EEPROM.update(invertThr,1);
          }
      }
  
}

void loop() {
 }

void sendInfo(){
    Serial.println("Type 'Y' for yes");
    Serial.println("Type 'N' for no");
  }
 boolean parseAnswer(){
    
    
    while(1){
      char answer=Serial.read();
      if(answer=='Y'){
        return true;
        }
       if(answer=='N'){
        return false;
        } 
        else
          Serial.println("You entered incorrect value!");
          sendInfo();
      }
    }

  void calibrateJoy(int pin,int coordMin,int coordMax){

    long start=millis();
    int joyMin=100;
    int joyMax=100;
    while(millis()-start>10000){
      
      //Divide by 4 because EEPROM can store numbers between 0 and 255 
       
      int value=analogRead(pin)/4;
     if(value>joyMax){
        joyMax=analogRead(pin);
   }
   if(value<joyMin){
        joyMin=analogRead(pin);
   }}
   EEPROM.update(coordMin,joyMin);
   EEPROM.update(coordMax,joyMax);
   }   
