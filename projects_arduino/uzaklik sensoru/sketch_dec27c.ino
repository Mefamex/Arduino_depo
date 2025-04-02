#include <SoftwareSerial.h>
#include <Servo.h>
int trigPin=6;
int echoPin=7;
long sure;
long uzaklik;
Servo mtr;
int aci=0;
int bkle1=50;
int bkle2=bkle1/2;
int sira=0;
int ekle=1;

void setup(){while(!Serial){}
mtr.attach(8);
				
				
				pinMode(trigPin, OUTPUT); 
			 pinMode(echoPin,INPUT); 
				
				
Serial.begin(9600);
pinMode(13, OUTPUT);
	mtr.write(0);
				delay(2000);
			

				
for(int sira=0;sira<=36;sira++){
								aci=sira*5;
								mtr.write(aci);
						
								delay(bkle1);
								
								
				
				digitalWrite(trigPin, LOW); /* sensör pasif hale getirildi */ delayMicroseconds(5); digitalWrite(trigPin, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */ delayMicroseconds(10); digitalWrite(trigPin, LOW); /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ sure = pulseIn(echoPin, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */ uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */ 
							
        
        	if(uzaklik>800){
            sira--;
												Serial.println("HATA");
            mtr.write(aci+ekle);ekle++;}
						
        	else {Serial.print("uzaklik : ");
												Serial.println(uzaklik);
												ekle=1;
            		}
				
				
								delay(bkle2);
}
				mtr.write(0);
}
void loop(){}
