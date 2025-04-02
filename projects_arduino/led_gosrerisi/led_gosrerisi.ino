#include <Servo.h>
Servo mtr1,mtr2;
int a1=90,a2=90,aa=1,ab=1;

void setup(){
    Serial.begin(9600);
   mtr1.attach(2);
    mtr2.attach(3);
   mtr1.write(90);
    mtr2.write(90);
}
void loop(){
        a1+=aa;
     if(a1>=30){
            aa=-1;}
    if(a1<=0){aa=1;}
      mtr1.write(a1);
      mtr2.write(a1);
      delay(5);
    
    }