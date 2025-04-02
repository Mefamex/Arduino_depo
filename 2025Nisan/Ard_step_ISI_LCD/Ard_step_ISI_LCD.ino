#include <LiquidCrystal.h>
#include <DHT.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
// lcd.clear();  lcd.home();
// lcd.setCursor(0-15 , 0-1 )
// lcd.print( ) lcd.write ( )
// lcd.cursor();  lcd.blink ()

// #include <DHT.h> yukarida tanimlandi
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
// dht.begin();
// float h = dht.readHumidity();
// float t = dht.readTemperature();

#define PinS1 8
#define PinS2 9
#define PinS3 10
#define PinS4 11
#define PinBuzzer 12

const bool stepHalf[8][4] = {
  { 1, 0, 0, 0 },
  { 1, 1, 0, 0 },
  { 0, 1, 0, 0 },
  { 0, 1, 1, 0 },
  { 0, 0, 1, 0 },
  { 0, 0, 1, 1 },
  { 0, 0, 0, 1 },
  { 1, 0, 0, 1 }
};

int stepPitch = 0;
int stepClockWisenumber = 1; /*1:clock wise ; -1 : counter clock wise ; *2 not half step */

void stepPower(int a, int b, int c, int d) {
  digitalWrite(PinS1, a);
  digitalWrite(PinS2, b);
  digitalWrite(PinS3, c);
  digitalWrite(PinS4, d);
}

void stepBreak() {
  stepPower(0, 0, 0, 0);
}

void stepPower(int stepp) {
  stepPower(stepHalf[stepp][0], stepHalf[stepp][1], stepHalf[stepp][2], stepHalf[stepp][3]);
}

void stepClockwise(int count = 1, int wait = 1) {
  /* count -> step/8 ; wait = ms ; wise -> 1 clock : -1 counter clock */
  if (count == 1) { wait = 0; }
  int _c = 0;
  while (_c < count) {
    _c++;
    stepPitch += stepClockWisenumber;
    if (stepPitch > 7) { stepPitch = 0; }
    if (stepPitch < 0) { stepPitch = 7; }
    stepPower(stepPitch);
    delay(wait);
  }
}

unsigned long lastMotorTime = 0;
unsigned long lastBuzzerStopTime = 0;
unsigned long lastISIolc = 0;
unsigned long lastISIGoruntuleme = 0;
unsigned long lastISIyazdirmaSayaci = 0;

float NEM = 0, SICAKLIK = 0;

void buzzerStart(int timee = 50) {
  lastBuzzerStopTime = millis() + timee;
  analogWrite(PinBuzzer, 95);
}

void ISIolc() {
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();

  if (isnan(nem) || isnan(sicaklik)) {
    NEM = -99;
    SICAKLIK = -99;
  } else {
    NEM = nem;
    SICAKLIK = sicaklik;
  }
}

void lcdHosgeldin() {
  lcd.clear();
  //lcd.home();
  lcd.print("    MEFAMEX");
  lcd.setCursor(0, 1);
  lcd.print("  03 Mart 2025");
}

void lcdIsiYazdir() {
  //lcd.clear();
  lastISIyazdirmaSayaci=(lastISIyazdirmaSayaci+1)%10;
  lcd.home();
  lcd.print("Nem: ");
  lcd.print(NEM);
  lcd.print(" %  ");
  lcd.print(lastISIyazdirmaSayaci);
  lcd.setCursor(0, 1);
  lcd.print("Sck: ");
  lcd.print(SICAKLIK);
  lcd.print(" C  ");
  lcd.print(stepPitch);
}







void setup() {
  dht.begin();

  lcd.begin(16, 2);
  lcdHosgeldin();

  pinMode(PinS1, OUTPUT);
  pinMode(PinS2, OUTPUT);
  pinMode(PinS3, OUTPUT);
  pinMode(PinS4, OUTPUT);
  
  pinMode(PinBuzzer, OUTPUT);
}









void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastMotorTime >= 890) {
    stepClockwise();
    lastMotorTime = currentTime;
  }

  if (currentTime >= lastBuzzerStopTime) { analogWrite(PinBuzzer, 0); }

  if (stepPitch == 2) { buzzerStart(); }

  if (currentTime >= lastISIolc + 2000) {
    ISIolc();
    lastISIolc = currentTime;
  }


  if (currentTime >= lastISIGoruntuleme + 890) {
    lcdIsiYazdir();
    lastISIGoruntuleme = currentTime;
  }
}
