int rightForward = 2; 
int rightBackward = 4; 
int leftForward = 7; 
int leftBackward = 8;

int enableA = 3;
int enableB = 5; 

// *************************

void setup() {
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  
  pinMode(rightForward, OUTPUT); 
  pinMode(rightBackward, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT); 

  digitalWrite(enableA, HIGH);
  digitalWrite(enableB, HIGH); 
} // END setup

void loop() {
  sampleMove(); 
  delay(500); 
} // END loop

// *************************

// Sample Movement
//
void sampleMove(){
  forward();
  delay(1000);
  backward();
  delay(1000);
  right(); 
  delay(1000);
  forward(); 
  stop();
  delay(1000);
  left();
  backward();
} // END sampleMove


// Moves the bot forward
//
void forward() {
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
  
  digitalWrite(rightForward, HIGH);
  digitalWrite(leftForward, HIGH);
} // END forward


// Moves the bot backward 
//
void backward() {
  digitalWrite(rightForward, LOW);
  digitalWrite(leftForward, LOW);
  
  digitalWrite(rightBackward, HIGH);
  digitalWrite(leftBackward, HIGH);
} // END backward


// The bot moves by inertia alone
//
void coast() {
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);

  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
} // END coast


// The bot stops moving
//
void stop(){
  digitalWrite(rightForward, HIGH); 
  digitalWrite(rightBackward, HIGH); 
  digitalWrite(leftForward, HIGH); 
  digitalWrite(leftBackward, HIGH); 
} // END stop


// The bot rotates left
//
void left(){
  digitalWrite(rightForward, HIGH); 
  digitalWrite(leftBackward, HIGH); 
  
  digitalWrite(rightBackward, LOW); 
  digitalWrite(leftForward, LOW); 
} // END left


// The bot rotates right
//
void right(){
  digitalWrite(rightBackward, HIGH); 
  digitalWrite(leftForward, HIGH); 

  digitalWrite(rightForward, LOW); 
  digitalWrite(leftBackward, LOW); 
} // END left
