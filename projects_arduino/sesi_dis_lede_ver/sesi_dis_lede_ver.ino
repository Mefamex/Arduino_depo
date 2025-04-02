int
sensor=0,
mind=400,
midd=500,
maxd=600;

void setup() {
			Serial.begin(9600);
					pinMode(5,INPUT);
			pinMode(10,OUTPUT);}


void loop(){
		
sensor=analogRead(5);

if(sensor>mind and sensor<midd){
				analogWrite(10,map(sensor,midd,mind,0,50));}
if(sensor>midd and sensor<maxd){
				analogWrite(10,map(sensor,midd,maxd,0,50));}
				Serial.println(sensor);
if(sensor<mind or sensor>maxd){analogWrite(10,250);}				

					delay(5);
				}