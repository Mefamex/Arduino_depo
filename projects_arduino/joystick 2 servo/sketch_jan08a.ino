#include <Servo.h>
Servo mtr1;
Servo mtr2;
int aci1=0;
int aci2=0;

void setup(){
    mtr1.attach(2);
    mtr2.attach(3);
				delay(1000);
				Serial.println(9600);
				
				}
void loop(){ 
    aci1= map(analogRead(A0),1,1023,0,180);
				aci2=map(analogRead(A2),1,1023,0,180);
    mtr1.write(aci1);
    mtr2.write(aci2);
    Serial.print(aci1);
    delay(10);
    Serial.print("   ");
    delay(10);
    Serial.println(aci2);
    delay(10);
				}// LOOP