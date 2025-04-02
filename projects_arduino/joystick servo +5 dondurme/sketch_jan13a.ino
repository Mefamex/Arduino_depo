#include <Servo.h>
 int degerler[101]={};
Servo mtr;

 int pot=0;
int artis=1;
 int aci=90;

void setup(){
   mtr.attach(2);
Serial.begin(9600);
    pinMode(13,OUTPUT);
    analogWrite(13,1030);
   
}

void loop(){
    pot=analogRead(A0);
  artis=map(pot,1,624,-5,5);
 aci+=artis;
    
   if(aci>180){aci=180;}
    if(aci<0){aci=0;}
    
        mtr.write(aci);
        Serial.print(aci);
        Serial.print("   ");
        Serial.println(pot);
    
    
    

    delay(50);}