int r=3;
int g=5;
int b=6;
int r1=0,r2,g1=0,g2,b1=0,b2;
const int dly=1000;
float bekle;
int toplamtur;
int son=100;
 

void setup() {
pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(b,OUTPUT);
}

 
void hesapla(){
								toplamtur=0;
								if(r1<r2){toplamtur+=r2-r1;}
							 else if(r1>r2){toplamtur+=r1-r2;}
								
								if(g1<g2){toplamtur+=g2-g1;}
								else if(g1>g2){toplamtur+=g1-g2;}
								
								if(b1<b2){toplamtur+=b2-b1;}
								else if(b1>b2){toplamtur+=b1-b2;}
								bekle=dly/toplamtur;
								}

void loop() {
								r2=random(255-son,255);
								g2=random(255-son,255);
								b2=random(255-son,255);
								hesapla();
								for(;r1!=r2;){
																if(r1<r2){r1++;}
																else if(r1>r2){r1--;}
																else{break;}
																analogWrite(r,r1);
																delay(bekle);}

									for(;g1!=g2;){
																if(g1<g2){g1++;}
																else if(g1>g2){g1--;}
																else{break;}
																analogWrite(g,g1);
																delay(bekle);}
								
										for(;b1!=b2;){
																if(b1<b2){b1++;}
																else if(b1>b2){b1--;}
																else{break;}
																analogWrite(b,b1);
																delay(bekle);}
							
delay(200);
}

