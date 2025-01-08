// includes all the pints and their assigned number from the ardino
int irSensor = A5;

int enA = 5;
int in2A = 8;
int in1A = 9;

int enB = 6;
int in1B = 11; 
int in2B = 10; 

// unusable function which exist program to stop the loop

void stopLoop(){

  return 1;

}

// setup for INPUT and OUTPUT
// setting up such that it will be initialize in the void loop() function
void setup() {

  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(enB, OUTPUT);
  Serial.begin(9600);
  pinMode(irSensor, INPUT);

}

// main function which detects the black line, stop, then initialize the launch contraption 
void loop() {
// initialize a datatype where sensorStatus will read the value of analogPin A5
//varibale used is irSensor = A5
  int sensorStatus = digitalRead(irSensor);
  
  // if sensorStatus reads a value of 1, then initalize the code within the if(condition) block.
  // this will stop the robot with a delay of 0.5 seconds, launch the trash using Motor A turning in CCW direction for 0.6 seconds
  // after the sequence, the robot will stop all motors for 100 seoncds until retrieval of the bot
  if(sensorStatus == 1){

    stop();
    delay(500);
    Launch();
    delay(600);
    stop();
    delay(100000);

  }
// if the sensor does not read a value of 1, then continue going forward until it detects a black line
else {
backwards();
delay(1000);
 analogWrite(enB,255);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, LOW);
  analogWrite(enA,225);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGh);
delay(1000);

backwards();





}


}                                                   

// function for the launch mechanism where motor A is only in action
void Launch(){

analogWrite(enB,255);
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  analogWrite(enA,225);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  
}

// Function to move forward setting all motors to HIGH in a different direction
void forwards() {

 analogWrite(enB,255);
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  analogWrite(enA,225);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  
  Serial.println("Spinning in forWard");
}

// Function to move backward where all motors are set to HIGH in the opposite direction
void backwards() {

  analogWrite(enB,255);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, LOW);
  analogWrite(enA,225);
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
   Serial.println("Spinning in backWards");
}

// function to stop the motors setting the motors all LOW
void stop(){

  analogWrite(enB,255);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, LOW);
  analogWrite(enA,225);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  
}