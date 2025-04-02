#include <IRremote.h>
IRrecv irrecv(12);
decode_results results;
int gln;
void setup(){
    Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}//setup

void loop(){
  if (irrecv.decode(&results)){
    gln=results.value;
    if(gln>2000 and gln<3000){gln-=2048;}
    if(gln>75 and gln<120){
    Serial.print(gln);}
    irrecv.resume();}
  }
  
  