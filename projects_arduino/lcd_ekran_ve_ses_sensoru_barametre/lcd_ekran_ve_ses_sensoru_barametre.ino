#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte sifir[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte bes[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

int deger=5;
int sira=0;
				
void setup() {
  pinMode(A0,INPUT);
  lcd.begin(16, 2);
  lcd.createChar(1,sifir);
  lcd.createChar(5,bes);  
}

void loop() {sira++;
 deger=map(analogRead(A0),200,800,0,16);
 

  
				for(sira=0;sira<deger;sira++){
								lcd.setCursor(sira,0);
								lcd.write(5);}
				for(;sira<17;sira++){
								lcd.setCursor(sira,0);
								lcd.write(1);}
				
				
			}
