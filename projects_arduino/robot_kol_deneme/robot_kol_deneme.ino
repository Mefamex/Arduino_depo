#include <Servo.h>
Servo mtr1,mtr2,mtr3,mtr4,mtr5;
int aci1=90,aci2=90,aci3=90,aci4=90,aci5=90;
char gln;

void setup(){
     Serial.begin(9600);
     mtr1.attach(2);mtr2.attach(3);mtr3.attach(4);
                mtr4.attach(5);mtr5.attach(6);




}

void loop(){
  if(Serial.available()>0){
    gln=Serial.read();
    if(gln>=0 or gln<=){}
  }
}