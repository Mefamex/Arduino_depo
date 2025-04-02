#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int x[33]={};
int text='a';
int sira=0;
int devam=0;
int gsira=0;
int silsira=0;
int a1,a2,deger=0;
int doluluk=0;
String ic="";

byte yok[8]={
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				};
				
void setup(){  
								lcd.begin(16,2);
								lcd.home();
								lcd.println("MEMOFiKA");
								lcd.setCursor(4,1);
								lcd.println("TiME");
								delay(1000);
								for(int xxx=9;xxx>=0;xxx--){
																for(int yyy=0;yyy<16;yyy++){
																								lcd.setCursor(yyy,0);
																								lcd.print(xxx);delay(40-xxx*4);}
																for(int yyy=15;yyy>=0;yyy--){
																									lcd.setCursor(yyy,1);
																						lcd.print(xxx);delay(40-xxx*4);}}
		delay(500);	lcd.clear();delay(500);
									lcd.createChar(5,yok);
	}






void sil(){	if(sira>23||devam==1){devam=1;
							deger=x[silsira];
											if(deger<16){a1=deger;a2=0;}
																else{a1=deger-16;a2=1;}
				lcd.setCursor(a1,a2);
								lcd.write(5);
			silsira++;	if(silsira==32){silsira=0;}}}


void degerata(){	if(doluluk<sira){doluluk=sira;}
									deger=random(0,33);		
				for(int konsay=0;konsay<doluluk;konsay++){
							if(deger==x[konsay]){degerata();}
				}}	

void karmayerlestir(){
				degerata();
			x[sira]=deger;
			if(deger<16){a1=deger;a2=0;}
																else{a1=deger-16;a2=1;}
					lcd.setCursor(a1,a2);
			if(text<='z'){	lcd.write(text);}
				else{lcd.print(text);} 
    text++;
				delay(400);
				if(text>'z'){text='a';}
								}

void dolumu(){				if(sira==33){
							text='a';sira=0;
								for(int aqw=0;aqw<33;aqw++){x[aqw]=0;}
															delay(2000);
								lcd.home();lcd.clear();
																lcd.print("temizleniyor...");
								delay(1000);
								setup();}}




void loop(){
								sil();
				//dolumu();
	
karmayerlestir();
sira++;
								if(sira==32){sira=0;}
								}