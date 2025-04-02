#include <dht11.h> 

dht11 DHT11;
int bklaram=25;
int bkl=50;
int bklu=2500;
int dongu=1;
void setup()
{
				DHT11.attach(2);
  Serial.begin(9600);
}

void loop()
{
				delay(bkl);
				int chk = DHT11.read(2);
				
				
  if(chk!=0){Serial.println("DEGER SAGLIKLI DEGIL");}
				
				else{
				
								switch(dongu){
												case 1:
  Serial.print("Nem (%): ");
												delay(bklaram);
  Serial.println((float)DHT11.humidity, 2);
         break;
				
				      case 2:
Serial.print("Sicaklik (Celcius): ");
												delay(bklaram);
Serial.println((float)DHT11.temperature,2);
				       break;
				
          case 3:
  Serial.print("Sicaklik (Fahrenheit): ");
												delay(bklaram);
  Serial.println(DHT11.fahrenheit(), 2);
          break;
				
				       case 4:
  Serial.print("Sicaklik (Kelvin): ");
												delay(bklaram);
  Serial.println(DHT11.kelvin(), 2);
          break;
				
				
         case 5:
  Serial.print("Cig Olusma Noktasi: ");
												delay(bklaram);
  Serial.println(DHT11.dewPoint(), 2);
         break;
          }//  SWITCH BITTI...
								
  }// if Bitti...
				dongu++;
				if(dongu<1||dongu>5){dongu=1;}
				if(dongu==5){delay(bklu);
		Serial.println("");}
}//LOOP BITTI

