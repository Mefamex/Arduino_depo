#include <Servo.h>


int echopin=2,trigpin=3;
int sure=0,uzaklik=0,aci=90,gosteraci=0,buzaklik,
mincm=5,maxcm=200;
bool sag=true;
Servo mtr,mtr2;int mtrpin=6;

void setup(){
				pinMode(echopin,INPUT);
				pinMode(trigpin,OUTPUT);
				mtr.attach(mtrpin);
				mtr2.attach(5);
				Serial.begin(9600);
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
//############################################
void motordon(){
				buzaklik=180;
				while(aci<=180){
								aci+=1;
								delay(5);
								if(aci>=179){delay(20);};
								mtr.write(aci);
								uzaklikolc();
								if(uzaklik<5 or uzaklik>800){continue;}
								Serial.print("????  ");
								Serial.println(uzaklik);
				 			int 	olcsure=millis()/1000;
								Serial.print("-----");
								Serial.print(aci);
								if(uzaklik<buzaklik){
																buzaklik=uzaklik;
																gosteraci=aci;}
												
									}
				
}
void loop(){
				motordon();
				aci=0;
				mtr.write(aci);
				delay(50);
				mtr2.write(gosteraci);
				Serial.print("______");
				Serial.print(gosteraci);
				};