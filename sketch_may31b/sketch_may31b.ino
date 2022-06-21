int motor1s = 3;
int motor1d = 12;

int motor2s = 11;
int motor2d = 13;

int mspeed = 0;
void setup() {
  pinMode(motor1s,OUTPUT);
  pinMode(motor1d,OUTPUT);
  pinMode(motor2s,OUTPUT);
  pinMode(motor2d,OUTPUT);
}

void loop() {
 forward();
 delay(2000);
 reverse();
 delay(2000);
 left();
 delay(2000);
 right();
 delay(2000);
}

void forward(){
  digitalWrite(motor1d,HIGH);
 digitalWrite(motor2d, LOW);

 mspeed = 250;
 analogWrite(motor1s, mspeed);
 analogWrite(motor2s, mspeed);
}

void right(){
  digitalWrite(motor1d,HIGH);
 digitalWrite(motor2d, HIGH);

 mspeed = 250;
 analogWrite(motor1s, mspeed);
 analogWrite(motor2s, mspeed);
}

void reverse(){
  digitalWrite(motor1d,LOW);
 digitalWrite(motor2d, HIGH);

 mspeed = 250;
 analogWrite(motor1s, mspeed);
 analogWrite(motor2s, mspeed);
}

void left(){
  digitalWrite(motor1d,LOW);
 digitalWrite(motor2d, LOW);

 mspeed = 250;
 analogWrite(motor1s, mspeed);
 analogWrite(motor2s, mspeed);
}
