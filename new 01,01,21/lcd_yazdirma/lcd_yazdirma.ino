#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int t1=0,t2=0;

void setup() {
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("Well Come toHere");
lcd.setCursor(7,2);
lcd.print("07.01.21");
}

void loop() {
lcd.setCursor(0,1);
lcd.print(" ");
if(t1<10){lcd.print("0");}
lcd.print(t1);
lcd.print(":");
if(t2<10){lcd.print("0");}
lcd.print(t2);
t2+=15;
if(t2>59){t1+=1;t2=0;}
if(t1>24){t1=0;}
delay(500);

}

/*
lcd.home();
lcd.setCursor(2, 1);
lcd.noCursor();
lcd.cursor();
lcd.blink ( )
lcd.noDisplay();
lcd.display();

byte customChar[8] = {
0b00110,
0b01001,
0b01001,
0b00110,
0b00000,
0b00000,
0b00000,
0b00000
};
lcd.createChar(0, customChar);
lcd.write((uint8_t)0);
 */
