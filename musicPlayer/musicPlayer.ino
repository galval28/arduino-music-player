#include <stdio.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include <CurieBLE.h>
#include "Waveforms.h"
rgb_lcd lcd;

const int readPin = A0;
const int speakPin = 2;
int r = 10;
int b = 100;
int g = 50;
const int B = 233;
const int C = 261;
const int D = 294;
const int E = 311;
const int F = 349;
const int stopPin = 1;
void setup() {
  analogWriteResolution(12);
  Serial.begin(9600);
  pinMode(speakPin, OUTPUT);
  lcd.begin(16,2);
  lcd.setRGB(r, g, b);
  pinMode(stopPin, INPUT_PULLUP);

}
int voltage;
int voltagea;
int voltageb;
int voltagec;
int freq;
void loop() {
  
 // lcd.clear();
  
  //voltagea = analogRead(readPin);
  //delay(100);
  //voltageb = analogRead(readPin);
  //delay(100);
  //voltagec = analogRead(readPin);
  //delay(100);
 // voltage = (voltagec+voltagea+voltageb)/3;
  //lcd.print(voltage);
  voltage = analogRead(readPin);
  if (voltage<204){
    freq=B;
  }
   if (204<voltage && voltage<408){
    freq=C;
  }
   if (408<voltage && voltage<612){
    freq=D;
  }
   if (612<voltage && voltage<816){
    freq=E;
  }
   if (voltage>816){
    freq=F;
  }
  
  
  Serial.print(freq);
  Serial.print("f v");
  Serial.println(voltage);
  Serial.println(digitalRead(stopPin));
  //freq=((voltage-5)*2);
 
 
  if(digitalRead(stopPin)==!HIGH){
    
    noTone(speakPin);
  }
   if(digitalRead(stopPin)==!LOW){
    
    noTone(speakPin);
    tone(speakPin,freq);
  }
  
  

}
