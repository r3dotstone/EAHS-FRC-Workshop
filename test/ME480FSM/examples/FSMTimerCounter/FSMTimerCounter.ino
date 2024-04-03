#include <ME480FSM.h>

//This program uses a FSM to alternately count to 5 at two counts per second
//and count to 10 at one count per second.
//The FSM has four states:
//  Waiting while counting to 5
//  Incrementing the counter to 5
//  Waiting while counting to 10
//  Incrementing the counter to 10



//create a counter with a preset of 10
RisingEdgeCounter countTo10(10);
//create a counter with a preset of 5
RisingEdgeCounter countTo5(5);

//create a millisecond timer with a duration of 500ms
FSMTimer time500ms(500);
//create a microsecond timer with a duration of 1000ms
FSMFastTimer time1000ms(1000000);

//declare the state variables
bool stateInc5;
bool stateWait5;
bool stateInc10;
bool stateWait10;

void setup() {
  // set up serial monitor to see what's going on
  Serial.begin(115200);
  // initialize the states:
  stateInc5 = false;
  stateInc10 = false;
  stateWait5 = true;
  stateWait10 = false;
}

void loop() {
  // Block 1 - handle timers and counters 
  // Enable the timers when we are in the corresponding wait state
  time1000ms.update(stateWait5);
  time500ms.update(stateWait10);
  // count up when entering the corresponding increment state
  // reset the counter when counting the other number
  countTo5.update(stateInc5,false,stateWait10);
  countTo10.update(stateInc10,false,stateWait5);

  //Block 2 - transition logic
  //These make use of the TMR and CNT variables exposed in the class
  bool wait5ToInc5 = stateWait5 && time1000ms.TMR;
  bool wait5ToWait5 = stateWait5 && !time1000ms.TMR;
  bool inc5ToWait5 = stateInc5 && !countTo5.CNT;
  bool inc5ToWait10 = stateInc5 && countTo5.CNT;  
  bool wait10ToInc10 = stateWait10 && time500ms.TMR;
  bool wait10ToWait10 = stateWait10 && !time500ms.TMR;
  bool inc10ToWait10 = stateInc10 && !countTo10.CNT;
  bool inc10ToWait5 = stateInc10 && countTo10.CNT;    

  //Block 3 - Update States
  stateWait5 = inc10ToWait5 || inc5ToWait5 || wait5ToWait5;
  stateInc5 = wait5ToInc5;
  stateWait10 = inc5ToWait10 || inc10ToWait10 || wait10ToWait10;
  stateInc10 = wait10ToInc10;

  //Block 4 - output to state the serial monitor
  if(stateWait5)  Serial.print("stateWait5  ");
  if(stateInc5)   Serial.print("stateInc5   ");
  if(stateWait10) Serial.print("stateWait10 ");
  if(stateInc10)  Serial.print("stateInc10  ");

  //print out the other information from the timers and counters
  Serial.print(time500ms.elapsed);
  Serial.print("\t");
  Serial.print(countTo10.count);
  Serial.print("\t");
  Serial.print(time1000ms.elapsed);
  Serial.print("\t");
  Serial.println(countTo5.count);

}
