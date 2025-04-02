 // sscanf(mesaj1, "%d:%d", &s1key, &s1);	
#include <Servo.h>
Servo mtr1,mtr2,mtr3;
	char* mesaj1 ="";
int kayit1[2700][3]={};
int aci1=90,aci2=90,aci3=90,sira;
int kayit,gln,oynat,kayitsayisi=0,bosdur=0;
String mesaj;

void setup(){
								Serial.begin(9600);
								mtr1.attach(2);mtr2.attach(3);mtr3.attach(4);
								pinMode(A0,INPUT);mtr1.write(90);	
								pinMode(A1,INPUT);	mtr2.write(90);
								pinMode(A2,INPUT);mtr3.write(90);
				pinMode(13,OUTPUT);pinMode(12,OUTPUT);}


void silbastan(){//gln==0
							mtr1.write(90);mtr2.write(90);mtr3.write(90);
								mesaj="";mesaj1="";
	int gln,pot1,pot2,pot3,aci1,aci2,aci3,kayit=0;
int kayit1,sira=0,oynat=0,kayitsayisi=0;	}


void kayitet(){
				mtr1.write(aci1);kayit1[sira][0]=aci1;
				mtr2.write(aci2);kayit1[sira][1]=aci2;
				mtr3.write(aci3);kayit1[sira][2]=aci3;
				sira++;kayitsayisi++;
}

void kaydioynat(){
				if(sira>kayitsayisi){sira=0;}
				aci1=kayit1[sira][0];mtr1.write(aci1);
				aci2=kayit1[sira][1];mtr2.write(aci2);
				aci3=kayit1[sira][2];mtr3.write(aci3);
				sira++;}

void bosdevamet(){
mtr1.write(aci1);mtr2.write(aci2);mtr3.write(aci3);}


void loop(){
				Serial.print(sira);Serial.print("--");
				Serial.print(kayit1[sira][0]);Serial.print("--");
				
				
				
				if(Serial.available()>0){mesaj="";
	//	while(Serial.available()>0){	mesaj+=Serial.read();}
				//			gln=mesaj.toInt();
						gln=Serial.read()-48;		
								Serial.println(gln);}
								if(gln<10){															
															switch(gln){
																case 0:silbastan();break;												
																case 1:silbastan();bosdur=0;oynat=0;
																kayit=1;sira=0;break;
																case 2:sira=0;oynat=1;
																kayit=0;bosdur=0;break;
																case 3:bosdur=1;kayit=0;
																oynat=0;break;
																case 4:aci1+=10;break;
																case 5:aci1-=10;break;
																case		6:aci2+=10;break;
																case 7:aci2-=10;break;
																case 8:aci3+=10;break;
																case 9:aci3-=10;break;
																}//switch gln 
											}//gln<10
				int gln;
			if(kayit==1){if(sira>2699){kayit=0;bosdur=1;}
								kayitet();
								      if(millis()%1000<500&&millis()%1000>0){
	            	digitalWrite(13,HIGH);}
												   else{digitalWrite(13,LOW);}}
			if(oynat==1){kaydioynat();
											  	if(millis()%2000<1000&&millis()%2000>0){
	          	digitalWrite(12,HIGH);}
									    else{digitalWrite(12,LOW);}}					
			if(bosdur==1){bosdevamet();}					
								

delay(10);}								