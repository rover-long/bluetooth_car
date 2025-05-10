#include<SoftwareSerial.h>
SoftwareSerial BT(0,1);
char  command;

#define IN1 13
#define IN2 6  //right
#define IN3 11
#define IN4 12  //left


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

 void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    stopnow(); 
    switch(command){
    case 'f':  
      forward();
      break;
    case 'b':  
      backward();
      break;
    case 'l':  
      turnleft();
      break;
    case 'r':
      turnright();
      break;
    case 's':
      stopnow();
      break;
    }
  } 
}



void forward() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, 100);
  analogWrite(IN3, 100);
  digitalWrite(IN4, LOW);
  
}

void turnleft() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, 200);
  analogWrite(IN3, 0);
  digitalWrite(IN4, LOW);
  
}

void turnright() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, 0);
  analogWrite(IN3, 200);
  digitalWrite(IN4, LOW);
    
}

void stopnow() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  digitalWrite(IN4, LOW);
  
}
void backward(){
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  digitalWrite(IN4, HIGH);
}
