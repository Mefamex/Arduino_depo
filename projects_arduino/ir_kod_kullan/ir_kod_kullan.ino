#include <IRremote.h>
int pin = 3,gln; 
IRrecv irrecv(pin); 
decode_results results;
void setup(){
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop(){
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume();
    }
 
  
}