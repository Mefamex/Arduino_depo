#include <Servo.h>

 #include "Wire.h"
 #include "I2Cdev.h"
 #include "MPU6050.h"
 MPU6050 mpu;
 int16_t ax, ay, az;
 int16_t gx, gy, gz;

  Servo mtr1,mtr2,mtr3,mtr4;
  int aci1=180,aci2=45,aci3=0,aci4=120;
char gln;int kat=3,dlytop,ekle,average=10;


void setup(){
   Wire.begin();
   mpu.initialize();
    Serial.begin(38400);
      mtr1.attach(2);mtr1.write(aci1);
      mtr2.attach(3);mtr2.write(aci2);
      mtr3.attach(4);mtr3.write(aci3);
      mtr4.attach(5);mtr4.write(aci4);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);

}//void SETUP

void acikontrol(){
  if(aci1>180){aci1=180;}else if(aci1<0){aci1=0;};
  if(aci2>180){aci2=180;}else if(aci2<0){aci2=0;};
  if(aci3>180){aci3=180;}else if(aci3<0){aci3=0;};
  if(aci4>180){aci4=180;}else if(aci4<0){aci4=0;};}

int duzelt(int a,int ming,int maxg){
  if(a>maxg){a=maxg;}
  else if(a<ming){a=ming;};
  return a;}
//MAX MIN e gore duzenle

void dly(int dly1){dlytop+=dly1;delay(dly1);}
void bekle(int beklet){if(beklet-dlytop>0){delay(beklet-dlytop);};dlytop=0;}



void loop(){
 
  bekle(10);

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  ax=duzelt(ax,-17000,17000);ay=duzelt(ay,-17000,17000);az=duzelt(az,-17000,17000);

  ekle=map(ay,-17000,17000,90,-90);
  if(ekle>average or ekle<-average){aci4+=ekle/20;}aci4=duzelt(aci4,0,180);
  Serial.println(String(ekle)+" --- "+String(aci4));dly(5);
  

  
  //mtr1.write(aci1);dly(5);
  //mtr2.write(aci2);dly(5);
  //mtr3.write(aci3);
  mtr4.write(aci4);

  
 }//void LOOP
