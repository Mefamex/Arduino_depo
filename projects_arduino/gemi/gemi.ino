#include <Servo.h>
Servo mtr;
int aci=90;
int hiz=0;
int gln,yakilacak;
void setup(){
								mtr.attach(8);
								Serial.begin(9600);Serial.setTimeout(1);
								pinMode(4,OUTPUT);
								pinMode(5,OUTPUT);
								pinMode(6,OUTPUT);
								pinMode(7,OUTPUT);
								pinMode(9,OUTPUT);
								pinMode(10,OUTPUT);
								pinMode(11,OUTPUT);
							digitalWrite(4,HIGH);digitalWrite(7,HIGH);
								}
void yak(int yakilacak){
								if(yakilacak==0){
																digitalWrite(4,LOW);delay(100);
																digitalWrite(4,HIGH);}
								
								if(yakilacak==1){
																digitalWrite(7,LOW);delay(100);
																digitalWrite(7,HIGH);}
}

void aciayarla(){
								if(aci<30){aci=30;yak(1);}
								if(aci>150){aci=150;yak(1);}			
								}
void hizayarla(){
								
								if(hiz<0){hiz=0;yak(0);}
								if(hiz>255){hiz=255;yak(0);}
	
								
}								
								
void durdur(){
								mtr.write(0);
								analogWrite(3,255);
								analogWrite(5,255);
								analogWrite(6,255);
								analogWrite(9,255);
								analogWrite(10,255);
								analogWrite(11,255);}
							

void loop(){
					//			while(!Serial){yak(0);yak(1);durdur();}
								if(Serial.available()>0){
															gln=Serial.read()-48;
								       if(gln==0){hiz=0;aci=0;durdur();}
								       if(gln==1){hiz-=51;}
					   											if(gln==2){hiz+=51;}
																if(gln==3){aci+=15;}
																if(gln==4){aci-=15;}
								
								hizayarla();
								aciayarla();}
																analogWrite(3,255-hiz);
																analogWrite(5,255-hiz);
																analogWrite(6,255-hiz);
																	analogWrite(9,255-hiz);
																analogWrite(10,255-hiz);
																analogWrite(11,255-hiz);
											mtr.write(aci);}