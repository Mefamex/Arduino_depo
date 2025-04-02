#include <Servo.h>
Servo mtr1,mtr2,mtr3,mtr4;
int aci1=90,aci2=45,aci3=150,aci4=180;
char gln;int kat=3;

void setup(){
    Serial.begin(9600);
    mtr1.attach(2);
    mtr2.attach(3);
    mtr3.attach(4);
    mtr4.attach(5);
   pinMode(13,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);
     }

void yak(){
    digitalWrite(10,HIGH);delay(20);
    digitalWrite(10,LOW);delay(10);
    digitalWrite(10,HIGH);delay(20);
    digitalWrite(10,LOW);
    }




void loop(){
    mtr1.write(aci1);
    mtr2.write(aci2);
    mtr3.write(aci3);
    mtr4.write(aci4);
    if(Serial.available()>0){
        digitalWrite(13,HIGH);
         
         char gln=Serial.read();
        
        switch(gln){
            case '0':
            aci1-=kat;
            if(aci1<0){aci1=0;yak();}
            mtr1.write(aci1);
            Serial.print("aci1=");
            Serial.println(aci1);
            break;
            
            case '1':
            aci1+=kat;
            if(aci1>180){aci1=180;yak();}
            mtr1.write(aci1);
            Serial.print("aci1=");
            Serial.println(aci1);
            break;
            
            
            case '2':
            aci2-=kat;
            if(aci2<0){aci2=0;yak();}
            mtr2.write(aci2);
            break;
            
            case '3':
            aci2+=kat;
            if(aci2>180){aci2=180;yak();}
            mtr2.write(aci2);
            break;
            
            
            case '4':
            aci3-=kat;
            if(aci3<0){aci3=0;yak();}
            mtr3.write(aci3);
            break;
            
            case '5':
            aci3+=kat;
            if(aci3>180){aci3=180;yak();}
            mtr3.write(aci3);
            break;
            
            
            case '6':
            aci4-=kat*3/2;
            if(aci4<0){aci4=0;yak();}
            mtr4.write(aci4);
            break;
            
            case '7':
            aci4+=kat*3/2;
            if(aci4>180){aci4=180;yak();}
            mtr4.write(aci4);
            break;
            
            
            case '8':
            kat-=3;
            if(kat<3){kat=3;yak();}
            analogWrite(11,map(kat,3,15,10,100));
            break;
            
            case '9':
            kat+=3;
            if(kat>15){kat=15;yak();}
            analogWrite(11,map(kat,3,15,10,100));
            break;
            
            
           }   // case 
        
         
       digitalWrite(13,LOW); 
        }// serial availabke  
  
    
      delay(1);      
   
    

 }

