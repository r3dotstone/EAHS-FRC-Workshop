#include <ME480FSM.h>

//create a counter with a preset of 10
RisingEdgeCounter myCounter(10);
//create a timer with a duration of 2000ms
FSMFastTimer myTimer(2000000);


void setup() {
  // set up serial monitor to see what's going on
  Serial.begin(115200);
}

void loop() {
  // run the timer repeatedly, so that it resets itself and keeps going
  // but only if the counter's preset has not been reached.
  // use the timer's status bit TMR to trigger counting up.
  
  //update the timer. 
  //Timer has one input-- just enable.
  //keep ours enabled as long as status bit on timer false, and status bit on counter false.
  myTimer.update(!myCounter.CNT&&!myTimer.TMR);

  //update the counter. 
  //counter has three inputs in_UP, in_DOWN, and RST in that order.
  //for ours, Count up any time the timer's status bit goes true.
  myCounter.update(myTimer.TMR,false,false);


  Serial.print(myCounter.count);
  Serial.print("\t");
  Serial.print(myCounter.CNT);
  Serial.println();
  
}
