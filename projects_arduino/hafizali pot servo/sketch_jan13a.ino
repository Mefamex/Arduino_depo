#include <Servo.h>
 int degerler[101]={};
Servo mtr;

 int pot=0;
 int aci=0;
int adet=1;
int sira=1;
int gln=0;
int dugme=0;
int dolu=0;

void setup(){
   mtr.attach(2);
Serial.begin(9600);
    pinMode(13,OUTPUT);
    analogWrite(13,1030);
   
}

void loop(){
    pot=analogRead(A0);
    aci=map(pot,1,1023,0,180);
    
    
    
    if(Serial.available()>0){
        gln=Serial.read()-48;
        if(gln==2){
            sira=1;if(dolu==0){gln=9;};
            }//gln 2 mi
        }// serial 1
    
    
    switch(gln){
        case 0:break; 
        case 1:break;
        case 2:break;
        default: mtr.write(aci);
        gln==9; }// case
    
        
        
    if(gln==1){
        degerler[sira]=aci;
         mtr.write(degerler[sira]);
        adet=sira; sira++;
        dolu=1;
        Serial.println(degerler[sira-1]);
       if(sira>100){sira=1;gln=9;}
        }// if 1
    
    
    
    if(gln==0){
        Serial.println("0 dayiz");
        gln=9;
        sira=1;
        adet=1;
        dolu=0;
        }
    
    
    if(gln==2&&dolu==1){
        if(sira>adet){sira=1;}
        mtr.write(degerler[sira]);
        Serial.println(degerler[sira]);
        sira++;
        }
    
    
 if(gln==9){
        Serial.print(" gln 9   ");
        Serial.print(aci);
        Serial.print("   ");
        Serial.println(pot);}
    
    delay(100);}