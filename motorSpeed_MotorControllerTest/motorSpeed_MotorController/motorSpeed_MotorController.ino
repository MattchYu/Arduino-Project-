
//all the inputs and datatype to initialize for the Motor A and Motor B 
// PWM pins for the ardiuno (speed control)
//sensor pin such that detecting the black line where threshold is 0 and 1
int irSensor = A5;

int enA = 5;
int in2A = 8;
int in1A = 9;

int enB = 6;
int in1B = 11; 
int in2B = 10; 


// code where motors move backwards
// motor B and A are reversed due to the position of the motors
void backWards(){
  analogWrite(enB,255);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, HIGH);
  analogWrite(enA,225);
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  
}
// code where motors move forward
// motor B and A are reversed of the backWards() function
void forWard(){
  analogWrite(enB,255);
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  analogWrite(enA,225);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  
}

//function to stop the motors
// setting all power to low to both motors output
void stop(){
  analogWrite(enB,255);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, LOW);
  analogWrite(enA,225);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  
}
// setup of all the OUTPUT and INPUT
void setup() {
  
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(irSensor, INPUT);
  // for only reading the Serial Monitor which reads at 9600
  Serial.begin(9600);
}

// main function which controls the speed, direction, and sensors
void loop() {

// setting a variable for the sensors where irSensor = A5 (analog 5 from the arduino)
int sensorStatus = digitalRead(irSensor);

//logic for the black line sensing where if the irSensor reads == 1 (seeing black line) 
// It will cause to move the robot backwards
  if (sensorStatus == 1){
    // this is meant for going forward from the face of the pig
    //different function because this is for the launcher when it will 
    // launch backwards
     forWard();
     delay(10000);
     stop();
     delay(10000);
  }
// if the irSensor does not detect a value of 1 and stays 0 then keeping moving forwards
  else{
   backWards();
  }

  
}
