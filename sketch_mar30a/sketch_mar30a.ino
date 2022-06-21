#include <Servo.h>

Servo servo1;
const int flexpin = 0; 
 

int clicka = 3; // move the servo in + 
int clickb = 2; // move the servo in -
int pos0;
int posa;
int posb;
int led1 = 13;
int led2 = 12;
int led3 = 11;



void setup()
{
  
  servo1.attach(9);  // attaches the servo on pin 7 to the servo object
  pinMode(clicka, INPUT_PULLUP);
  pinMode(clickb, INPUT_PULLUP);
  servo1.write(0);  // servo Start at point 0
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  Serial.begin(9600);

}


void loop() {

  int flexposition;    // Input value from the analog pin.
  int servodelay;   // Output value to the servo.
  flexposition = analogRead(flexpin);
  servodelay = map(flexposition, 180, 560, 20, 100);
  servodelay = constrain(servodelay, 10, 100);

  if(servodelay <= 40){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  } else if(servodelay <= 70){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
  } else if(servodelay <= 100){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
  }


pos0=servo1.read();  // read the current position of the servo
posa=pos0+10;    // the servo will move 1 degree forward
posb=pos0-10;    // the servo will move 1 degree forward

if (digitalRead(clicka)==LOW)  // by click on one button 
{servo1.write(posa);
Serial.println(posa);// the servo will move 
delay(servodelay);}


if (digitalRead(clickb)==LOW)   // by click other button 
{servo1.write(posb);
Serial.println(posb);// the servo will move other way 
delay(servodelay);}


delay(30);}
