#include <Servo.h>

Servo m1;
int e1=1,a1=0,dly=4;

void setup() {
    m1.attach(9);
}

void loop() {
     a1+=e1;
    if(a1>=180){e1=-1;delay(200);}
    if(a1<=0){e1=1;delay(200);}
    m1.write(a1);
    delay(dly);
    
}