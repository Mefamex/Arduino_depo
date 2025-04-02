#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// lcd.clear()
// lcd.home())
// lcd.setCursor(0-15 , 0-1 )
// lcd.print( ) lcd.write ( )
// lcd.cursor();  lcd.blink ()

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}
void loop() {
}