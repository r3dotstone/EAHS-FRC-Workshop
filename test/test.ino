//#include <ME480FSM.h>
//// https://electricdiylab.com/controlling-n20-encoder-micro-gear-motor-with-arduino/
//FSMEncoder1 encode1;
//
//const int speed = 1;
//const int dir = 2;
//long counts = 0;
//
//
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  pinMode(counts, INPUT);
//  pinMode(speed, OUTPUT);
//  pinMode(dir, OUTPUT);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//
//}

#define PIN_A   2
#define PIN_B   3

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize pins as an output.
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  // Spin the motor clockwise direction for 2 seconds
  analogWrite(PIN_A,100);
  digitalWrite(PIN_B,HIGH);
  Serial.println("A");
  delay(2000);

  // Spin the motor in the opposite direction for 2 seconds
  digitalWrite(PIN_A,HIGH);
  digitalWrite(PIN_B,LOW);
  Serial.println("B");
  delay(2000);
}
