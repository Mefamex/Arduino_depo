int x=0;
void setup(){
								Serial.begin(9600);
								pinMode(3,OUTPUT);
								}

void loop(){
								if(Serial.available()>0){
																x=Serial.parseInt();}
								analogWrite(3,x);}