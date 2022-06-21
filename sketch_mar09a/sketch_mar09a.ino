un/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  sensorValue= map(sensorValue,0,1023,0,8);




   if (sensorValue >= 0 && sensorValue <= 1023) {
    digitalWrite(13, (sensorValue & 1));
    digitalWrite(12, (sensorValue & 2));
    digitalWrite(11, (sensorValue & 4));
   }
   Serial.println(sensorValue);
   delay(1000);
  // print out the value you read:
 /* digitalWrite(13, HIGH);     // Turn the LED on

  delay(sensorValue);             // Pause for sensorValue
                                  // milliseconds

  digitalWrite(13, LOW);      // Turn the LED off

  delay(sensorValue);             // Pause for sensorValue
                                  // milliseconds
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability*/
}
