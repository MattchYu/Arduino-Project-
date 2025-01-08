
#include<Servo.h>

  //sensors
  int irSens = 13;
  const int sensorEcho = 8;
  const int sensorTrig = 7;
  int Led = 4;
  int Led2 = 2;


  //motors
  Servo Servo1; 
  Servo Servo2;


  int pos1 = 90;
  int pos2 = 180;
  int pos3 = -90;


void setup() {
  pinMode(sensorTrig, OUTPUT);
  pinMode(sensorEcho, INPUT);
  pinMode(Led, OUTPUT);
  pinMode(Led2,OUTPUT);
  pinMode(irSens, INPUT);
  Serial.begin(9600);
  Servo1.attach(9);
  Servo2.attach(10);
}

void loop() {
  // Send a 10 microsecond pulse to trigger the sensor

  digitalWrite(sensorTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTrig, LOW);

  // Read the echo time
  long duration = pulseIn(sensorEcho, HIGH);

  // Calculate the distance (speed of sound is 34300 cm/s)
  int distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);

  int sensorStatus = digitalRead(irSens);
  Serial.print("value of ir sensor: ");
  Serial.println(sensorStatus);

  delay(500);
 

  if (distance <4) { 

    if(sensorStatus == 0){
    digitalWrite(Led, HIGH);
    Servo1.write(pos2);
    delay(2000);
    }

    else if (sensorStatus == 1) {
    digitalWrite(Led2, HIGH);
    digitalWrite(Led, LOW);
    Servo2.write(pos3);
    delay(2000);

    }

  } 

  else{

    digitalWrite(Led2, LOW);
    digitalWrite(Led, LOW);
    Servo2.write(pos1);
    Servo1.write(pos1);

  }
 // Wait for half a second before the next measurement
}
