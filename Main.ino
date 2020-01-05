#include <Servo.h>

#define pinServo1 9   //define pin
#define pinServo2 10   //define pin
#define pinLED 2
#define pinIRED 3
#define pinIRDetect 8
Servo myServo1;
Servo myServo2;

void setup() {
  Serial.begin(9600);
  myServo1.attach(pinServo1);
  myServo2.attach(pinServo2);
  pinMode(pinLED,OUTPUT);
  pinMode(pinIRED,OUTPUT);
  pinMode(pinIRDetect,INPUT);

}

int i= 0; // out here so that LED does not stay on if object stays in range. 
int x = 0; //Servo to alternate between on and off
void loop() {
  
  boolean obstacle = lookForReflection();
  
  if(obstacle && i==0){
    digitalWrite(pinLED,HIGH);
    delay(500);
    if(x==0){         // turns light on
      lightOn();
    }
    else if(x==1){    // turn light off
      lightOff();
    }
      i++;
    digitalWrite(pinLED,LOW);
    
  } else if(!obstacle) {
    digitalWrite(pinLED,LOW);
    i = 0;
  }
  delay(500);
}

boolean lookForReflection(){
  //Send IR for 1 ms
  int halfPulse = 13;
  for(int counter = 0; counter< 32; counter++){
    digitalWrite(pinIRED,HIGH);
    delayMicroseconds(halfPulse);
    digitalWrite(pinIRED,LOW);
    delayMicroseconds(halfPulse-4);
  }

  if(digitalRead(pinIRDetect) == LOW){
    return true;
  }
  return false;
}

void lightOn(){
  myServo1.write(160);
  myServo2.write(160);
  x++;
}

void lightOff(){
   myServo1.write(20);
   myServo2.write(20);
   x--;
}

