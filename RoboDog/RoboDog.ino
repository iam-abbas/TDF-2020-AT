
#include <Servo.h>
#define SPEAKER   6

Servo myservo;  


int pos = 0;    
int i =0;
const int buttonPin = 5;
int buttonState = 1;


void setup() {
    pinMode(buttonPin, INPUT);
  myservo.attach(9);  
  pinMode(SPEAKER,OUTPUT); 

}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    //Serial.print(buttonState);
     
    Serial.print(i);
  for (pos = 0; pos <= 90; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                     
  }
  
  ruff();
  delay(2000); 

  }
  
}

void ruff() {
  uint16_t i;
  playTone(5100,50);       
  playTone(394,180);        
  for(i=990; i<1022; i+=2)  
     playTone(i,8);
  playTone(5100,40);        
}

void playTone(uint16_t tone1, uint16_t duration) {
  if(tone1 < 50 || tone1 > 15000) return;  // these do not play on a piezo
  for (long k = 0; k < duration * 1000L; k += tone1 * 2) {
     digitalWrite(SPEAKER, HIGH);
     delayMicroseconds(tone1);
     digitalWrite(SPEAKER, LOW);
     delayMicroseconds(tone1);
  }     
}
