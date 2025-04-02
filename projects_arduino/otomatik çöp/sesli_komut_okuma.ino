#include <Servo.h>
int trigPin=6;
int echoPin=7;int mavi=3,yesil=4;
long sure;
long uzaklik=150;
Servo mtr;
void setup(){
   	pinMode(trigPin, OUTPUT); 
			 pinMode(echoPin,INPUT); 
    pinMode(mavi,OUTPUT);pinMode(yesil,OUTPUT);
    digitalWrite(yesil,HIGH);
    mtr.attach(2);
    mtr.write(80);delay(300);
    mtr.write(20);delay(300);
    }// setup bitti    
void olc(){				
digitalWrite(trigPin, LOW); /* sensör pasif hale getirildi */ delayMicroseconds(5); digitalWrite(trigPin, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */ delayMicroseconds(10); digitalWrite(trigPin, LOW); /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ sure = pulseIn(echoPin, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */ uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */ 
}// uzaklik olcuyo
void motordon(){
    digitalWrite(yesil,LOW);
    digitalWrite(mavi,HIGH);
   int aci=83;mtr.write(aci);
    delay(2500);
    for(int aci=82;aci>18;aci--){
    mtr.write(aci); delay(7);}
    delay(150);
    digitalWrite(mavi,LOW);
    digitalWrite(yesil,HIGH);
    }
void loop(){
   if(uzaklik<40){motordon();}
    olc();
    delay(10);
    }
