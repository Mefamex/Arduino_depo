#include <IRremote.h>
IRrecv irrecv(12); 
decode_results results;
#include <Servo.h>
Servo mtr1,mtr2,mtr3,mtr4;

/*0-9 = 64-73
v+-=80-81
channel +-=96-97
ust alt =84 83
sag sol =86 85
*/
#define a0 64
#define a1 65
#define a2 66
#define a9 73

#define v1 80
#define v2 81
#define c1 96
#define c2 97
#define ust 84
#define alt 83
#define sag 86
#define sol 85
#define ok  117
#define menu 112
#define back  74

#define m1  5//int 1 pin
#define m1d 6//int 2 pin
#define m2  9//int 3
#define m2d 10//int 4


int aci1=90,aci2=45,aci3=150,aci4=180;
int gln;int kat=3;
void setup(){
  
    Serial.begin(9600);
    mtr1.attach(2);
    mtr2.attach(3);
    mtr3.attach(4);
    mtr4.attach(5);
   pinMode(13,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);
  
  irrecv.enableIRIn();
  irrecv.blink13(true);
  Serial.begin(9600);
 
}//setup

void glnkontrol(){
  if(Serial.available()){gln=Serial.parseInt();
    Serial.println(gln);}
  }
void yak(){
    digitalWrite(10,HIGH);delay(20);
    digitalWrite(10,LOW);delay(10);
    digitalWrite(10,HIGH);delay(20);
    digitalWrite(10,LOW);
    }
void loop(){
    mtr1.write(aci1);mtr2.write(aci2);
    mtr3.write(aci3);mtr4.write(aci4);
    glnkontrol();
    if(gln!=0 and gln<200){
        digitalWrite(13,HIGH);
        
        switch(gln){
            case sol:
            aci1-=kat;
            if(aci1<0){aci1=0;yak();}
            mtr1.write(aci1);
            Serial.print("aci1=");
            Serial.println(aci1);
            break;
            
            case sag:
            aci1+=kat;
            if(aci1>180){aci1=180;yak();}
            mtr1.write(aci1);
            Serial.print("aci1=");
            Serial.println(aci1);
            break;
            
            
            case ust:
            aci2-=kat;
            if(aci2<0){aci2=0;yak();}
            mtr2.write(aci2);
            break;
            
            case alt:
            aci2+=kat;
            if(aci2>180){aci2=180;yak();}
            mtr2.write(aci2);
            break;
            
            
            case v1:
            aci3-=kat;
            if(aci3<0){aci3=0;yak();}
            mtr3.write(aci3);
            break;
            
            case v2:
            aci3+=kat;
            if(aci3>180){aci3=180;yak();}
            mtr3.write(aci3);
            break;
            
            
            case c1:
            aci4-=kat*3/2;
            if(aci4<0){aci4=0;yak();}
            mtr4.write(aci4);
            break;
            
            case c2:
            aci4+=kat*3/2;
            if(aci4>180){aci4=180;yak();}
            mtr4.write(aci4);
            break;
            
            
            case menu:
            kat-=3;
            if(kat<3){kat=3;yak();}
            analogWrite(11,map(kat,3,15,10,100));
            break;
            
            case back:
            kat+=3;
            if(kat>15){kat=15;yak();}
            analogWrite(11,map(kat,3,15,10,100));
            break;
            
            
           }   // case 
       gln=0;   
       digitalWrite(13,LOW); 
        }// serial availabke  
  
 }

