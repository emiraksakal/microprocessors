const int relayPin = 2;     // use this pin to drive the transistor
const int timeDelay = 1000; // delay in ms for on and off phases
const int photoPin = A0;
int lightlevel,lightlevelCalibrated;

// You can make timeDelay shorter, but note that relays, being
// mechanical devices, will wear out quickly if you try to drive
// them too fast.


void setup()
{
  pinMode(relayPin, OUTPUT);  // set pin as an output
  Serial.begin(9600);
}


void loop()
{

  lightlevel = analogRead(photoPin);
  Serial.println(lightlevel);
  lightlevelCalibrated = map(lightlevel,0,1023,0,300);
  lightlevelCalibrated = constrain(lightlevelCalibrated,0,300);
  Serial.println(lightlevelCalibrated);

  if(lightlevelCalibrated < 100){
    digitalWrite(relayPin, HIGH);
    Serial.print("The light is on at calibrated level of: ");
    Serial.println(lightlevelCalibrated);
  
  }
  else{
    digitalWrite(relayPin, LOW);
  }
    delay(100);
}
