int stepLEDTop[] = {2,3,4,5,6,7,8,9,10,11};            // LED array for PWM 2,3,4 and 5
int numOfLEDsTop = 10;                    // LEDs of index 0-3
int stepLEDBot[] = {11,10,9,8,7,6,5,4,3,2};
int numOfLEDsBot = 10;
int pirState = LOW;

int pirVal3 = 0;
int pirVal4 = 0;

int pirSensor = 12;
int pirSensorTop = 13;
int delayPeriod = 1000;

void setup() {                        // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(pirSensor, INPUT);
  pinMode(pirSensorTop, INPUT);


  int i;
  for(i = 0; i < numOfLEDsTop; i++) {
    pinMode(stepLEDTop[i], OUTPUT);
  }

    for(i = 0; i < numOfLEDsBot; i++) {
    pinMode(stepLEDBot[i], OUTPUT);
  }

}

void loop()  {
  

  pirVal3 = digitalRead(pirSensor);
  pirVal4 = digitalRead(pirSensorTop);
  
  int i;                
                                        // if motion is captured, light the LEDs in sequence

  if (pirVal3 == HIGH) {
  for (i= 0; i < numOfLEDsBot; i++) {
    analogWrite(stepLEDBot[i], 255);
    delay (delayPeriod);
  }
  delay (1000);
   for (i= 0; i < numOfLEDsBot; i++) {
    analogWrite(stepLEDBot[i], 0);
    delay (delayPeriod);
  }
  if (pirState == LOW) {
      pirState = HIGH;
    }
  }
                                        // else, set all LED values to zero
  else {
    analogWrite(stepLEDBot[9], 0);
    analogWrite(stepLEDBot[8], 0);
    analogWrite(stepLEDBot[7], 0);
    analogWrite(stepLEDBot[6], 0);
    analogWrite(stepLEDBot[5], 0);
    analogWrite(stepLEDBot[4], 0);
    analogWrite(stepLEDBot[0], 0);
    analogWrite(stepLEDBot[1], 0);
    analogWrite(stepLEDBot[2], 0);
    analogWrite(stepLEDBot[3], 0);

    
    if (pirState == HIGH) {
      pirState = LOW;
  }
}
if (pirVal4 == HIGH) {
  for (i= 0; i < numOfLEDsTop; i++) {
    analogWrite(stepLEDTop[i], 255);
    delay (delayPeriod);
  }
  delay (1000);
   for (i= 0; i < numOfLEDsTop; i++) {  analogWrite(stepLEDTop[i], 0);
    delay (delayPeriod);
  }
  if (pirState == LOW) {
      pirState = HIGH;
    }
  }
                                        // else, set all LED values to zero
  else {
    analogWrite(stepLEDTop[0], 0);
    analogWrite(stepLEDTop[1], 0);
    analogWrite(stepLEDTop[2], 0);
    analogWrite(stepLEDTop[3], 0);
    if (pirState == HIGH) {
        pirState = LOW;
  }
}
}
