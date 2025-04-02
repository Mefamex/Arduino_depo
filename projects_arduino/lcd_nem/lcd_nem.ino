#include <Wire.h>
#include <LiquidCrystal.h>
#include <dht11.h>
dht11 DHT;
#define DHT11_PIN 6
 int chk;

 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
byte degree[8] =
{
B11100,
B10100,
B11100,
B00000,
B00000,
B00000,
B11111,
};
byte nokta[8] =
{
B01100,
B01100,
B00000,
B00000,
B00000,
B00000,
B00000,
};
    int b=50;


void setup()
{
    lcd.begin(16,2);
    lcd.createChar(1, degree);
    lcd.createChar(2,nokta);
}
 


void silme(){
    for(int a =12;a<17;a++){
 delay(b); lcd.setCursor(a,0);lcd.write(".");}
       for(int a =16;a>11;a--){
 delay(b); lcd.setCursor(a,1);lcd.write(2);} 
delay(b);
    for(int a =12;a<17;a++){
 delay(b); lcd.setCursor(a,0);lcd.write(2);}
       for(int a =16;a>11;a--){
 delay(b); lcd.setCursor(a,1);lcd.print(".");} 
delay(b);
    

    
      }





void loop()
{
   DHT.read(); DHT.attach(6);DHT.dewPoint();
   silme();
lcd.setCursor(0, 0);
lcd.print("Nem=  _%");
lcd.setCursor(8, 0);
lcd.print(DHT.humidity, 1);lcd.write("_");
lcd.setCursor(0, 1);
lcd.print("Sicaklk_");
lcd.setCursor(8, 1);
lcd.print(DHT.temperature,1);
lcd.write(1);
    
    
}