int a[]={};
int sira=0;
void setup(){
pinMode(A0,INPUT);
		Serial.begin(9600);		pinMode(3,OUTPUT);				
}
void loop(){
/*				for(sira=0;sira<16000;sira++){
	if(Serial.available()>0){break;}
															Serial.println(sira);
								a[sira]=analogRead(A0);}
				analogWrite(3,a[sira]);
				sira++;if(sira>15998){sira=0;}Serial.println(sira);*/
				Serial.println(analogRead(A0));
				analogWrite(3,analogRead(A0));
				}