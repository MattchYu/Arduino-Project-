// other things
int sensorPin = A5; //still neeed to wire the photoresistor 
int enA = 7;
int enB = 6;

// Motor A
int motorin1A = 9;
int motorin2A = 8;

//Motor B (still need to conect motor B to arduino)
int motorin1B = 10;
int motorin2B=  11;

void setup() {
  pinMode(motorin1A, OUTPUT);
  pinMode(motorin2A, OUTPUT);
  pinMode( motorin1B, OUTPUT);
  pinMode(motorin2B, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
 // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working"); // Test to check if serial is working or not
  pinMode(sensorPin, INPUT); // IR Sensor pin INPUT
}

void loop() {
  // Detect if the sensor is picking up

 
 int sensorStatus = digitalRead(value); // Set the GPIO as Input
  Serial.println("value of ir sensor: ");
  Serial.println(sensorStatus);
 

    Serial.println("Analog  Value: ");
    Serial.println(value);
    
    if (sensorStatus == 1) {
        forward();
    } else {
        backwards();
    }
    
    delay(100);

}

// Function to move forward
void forward() {
  digitalWrite(motorin1A, HIGH); // Can use analogWrite(motorForw, 255) for speed control
  digitalWrite(motorin2A, LOW);

  digitalWrite(motorin1B, HIGH);
  digitalWrite(motorin2B, LOW);
  Serial.println("Spinning Forward");
}

// Function to move backward
void backwards() {
  // Stop the motor first to prevent strain
  digitalWrite(motorin1A, LOW);
  digitalWrite(motorin2A, LOW);
  digitalWrite(motorin1B, LOW);
  digitalWrite(motorin2B, LOW);
  Serial.println("Motors have stopped 1");
  delay(500); // Delay to ensure smooth transition
  
  // Move backward
  digitalWrite(motorin1A, LOW);
  digitalWrite(motorin2A, HIGH);

  digitalWrite(motorin1B, LOW);
  digitalWrite(motorin2B, HIGH);
  Serial.println("Spinning Backwards");
  delay(7000);

  digitalWrite(motorin1A, LOW);
  digitalWrite(motorin2A, LOW);
  digitalWrite(motorin1B, LOW);
  digitalWrite(motorin2B, LOW);
  Serial.println("Motors have stopped 2");
  delay(7000); // Delay to ensure smooth transition
}
