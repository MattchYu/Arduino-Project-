
// Pins for all the mtors within the ardiuno 
int enA = 5;
int in2A = 8;
int in1A = 9;

int enB = 6;
int in1B = 11; 
int in2B = 10; 

// function to move forwards setting all motors HIGH
void forWard(){
  analogWrite(enB,255);
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  analogWrite(enA,255);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
}
// setup function which initializes all the pints to be used
void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(enB, OUTPUT);
  Serial.begin(9600);

}

// main fucntion which loops
// only making the motors move forward with a delay reaction to start of 1 second
void loop() {

  delay(1000);
  forWard();

}
