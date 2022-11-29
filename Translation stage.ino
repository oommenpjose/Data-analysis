
// Define Constants

// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 3; // Step
const int ms[3]={4,5,6};

//Step sizes
const int full[3] = {LOW,LOW,LOW};
const int half[3] = {HIGH,LOW,LOW};
const int quarter[3] = {LOW,HIGH,LOW};
const int eighth[3] = {HIGH,HIGH,LOW};
const int sixteenth[3] = {HIGH,HIGH,HIGH};
int stepsize[3];
int dirstat;
// Motor steps per rotation
const int STEPS_PER_REV = 200;
//Exectuion status 0 for not executed 1 for executed
int k=0;
//Number of rotations required
int rotations=7;
//Speed of rotation 0-9
int speed=10;
//Direction "forward":away from laser,"backward":towards laser
int direction;

void setup() {
  
  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
  
}
void loop() {
  direction=2;
  Serial.println("Enter direction forward(1):away from laser,backward(0):towards laser");
  while(Serial.available()==0){}
  direction=Serial.parseInt();
  while (Serial.available() > 0) {
    Serial.read();
  }
  if(direction==1){
    dirstat=HIGH;
    k=0;
  }
  else if(direction==0){
    dirstat=LOW;
    k=0;
  }
  else
  {
    Serial.println("Try again");
  }
  if(k==0){
    Serial.println("Enter number of rotations required");
    while(Serial.available()==0){}
    rotations=Serial.parseInt();
    while (Serial.available() > 0) {
    Serial.read();
    }
    Serial.println("Enter speed from 0-9");
    while(Serial.available()==0){}
    speed=Serial.parseInt();
    while (Serial.available() > 0) {
    Serial.read();
    }
    Serial.println("Execution started");
    digitalWrite(dirPin,dirstat);
    delay(1000);
    for(int x = 0; x < (STEPS_PER_REV*rotations); x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(16000-(speed*1600));
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(16000-(speed*1600));
    }
    Serial.println("Execution completed");
    k=1;
  }
/*
  // Set motor direction clockwise
  digitalWrite(dirPin,LOW); 
  delayMicroseconds(2000);
  // Spin motor one rotation slowly
  for(int x = 0; x < (STEPS_PER_REV*7); x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000);
  }
  
  // Pause for one second
  delay(1000); 
  
  // Set motor direction counterclockwise
  digitalWrite(dirPin,HIGH);
  
  // Spin motor two rotations quickly
  for(int x = 0; x < (STEPS_PER_REV*7); x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000);;
  }
  
  // Pause for one second
  delay(1000);
  */
}