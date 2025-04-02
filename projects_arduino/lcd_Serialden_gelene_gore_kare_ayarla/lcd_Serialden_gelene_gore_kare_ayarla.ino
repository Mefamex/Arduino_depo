#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



void setup() {
Serial.begin(9600);
  lcd.begin(16, 2);


}

void loop() {
								if(Serial.available()>0){
								int deger=Serial.parseInt();
																int a1,a2;
																
																
																	
				if(deger<16){a1=deger;a2=0;}
																
																else{a1=deger-16;
																								a2=1;}
																
								lcd.setCursor(a1,a2);
																lcd.print("a");
																
																
																}}
								

