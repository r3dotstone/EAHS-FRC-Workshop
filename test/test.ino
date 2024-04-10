#include <ME480FSM.h>
// https://electricdiylab.com/controlling-n20-encoder-micro-gear-motor-with-arduino/
FSMEncoder1 encode1;

const int speed = 1;
const int dir = 2;
long counts = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(counts, INPUT);
  pinMode(speed, OUTPUT);
  pinMode(dir, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
