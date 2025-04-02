#include <Servo.h>

int echopinR=2,trigpinR=3,echopinL=4,trigpinL=5;
int echopin=echopinR,trigpin=trigpinR;
int sure=0,uzaklik=0,aci=90,aciekle=1,mincm=5;
bool sag=true;
Servo mtr;int mtrpin=6;
void setup(){
				pinMode(echopinR,INPUT);
				pinMode(trigpinR,OUTPUT);
				pinMode(echopinL,INPUT);
				pinMode(trigpinL,OUTPUT);
				mtr.attach(mtrpin);
}

//#############################################
void uzaklikolc(){
				digitalWrite(trigpin, LOW); 
				delayMicroseconds(5); 
				digitalWrite(trigpin, HIGH);
				delayMicroseconds(10);
			 digitalWrite(trigpin, LOW);
				sure = pulseIn(echopin, HIGH);
				uzaklik= sure /29.1/2;}	
//#############################################
void sensorpinayarla(){
				if(sag==true){
								echopin=echopinL;
								trigpin=trigpinL;
								sag=false;
								aciekle=-1;
					}
			 	else if(sag=false){
								echopin=echopinR;
								trigpin=trigpinR;
								sag=true;
								aciekle=1;
						}
}
//#############################################
void sagayarla(){
if (uzaklik<15){
				sag=true;}
else if (uzaklik>	45){
				sag=false;}
}
//#############################################

void loop(){
				aci+=aciekle;
				mtr.write(aci);
				sensorpinayarla();
				uzaklikolc();
				sagayarla();
				
				
				
				
				
}