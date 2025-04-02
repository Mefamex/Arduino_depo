#include <Servo.h>
#include <SoftwareSerial.h>
Servo srv,srv1;


static const int Pin0 = 10;
static const int Pin1 = 11;
static const int Pin2 = 12;
static const int Pin3 = 13;
static int gln=0,step=0,dly=40,ileri=0,aci=140,
   led2=5,yanmasuresi1=0,duduk=1,dudukdly=0,
       duduk1=0 ,yak=0,yak1=0,sonyak=HIGH,
        motor=6;
//2-3servo____4 duduk___5 led____10-11-12-13-step
void setup() {
    pinMode(motor,OUTPUT);
    srv.attach(2);
    srv1.attach(3);
    pinMode(led2,OUTPUT);
    pinMode(4,OUTPUT);
    srv.write(aci);
    srv1.write(aci);
    Serial.begin(9600);
    pinMode(A0,INPUT);
  pinMode(Pin0, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
    yanmasuresi1=millis();
    analogWrite(Pin0,LOW);
analogWrite(Pin1,LOW);
analogWrite(Pin2,LOW);
    }



void  don(){
    switch(step) {
    case 0:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
    case 1:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 5:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 6:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;}
    }


//0=geri___1=durdur__2=ileri
//3=hizlandir__4=yavaslat__
//5=saga don__6=sola don
void git(){
    switch(gln){
        case 0:
        ileri=-1;
        break;
        
        case 1:
        ileri=0;
        break;
        
        case 2:
        ileri=1;
        break;
        
        case 3:
        dly--;
        if(dly>25){dly-=3;}
        if(dly>40){dly-=7;}
        if(dly>75){dly-=20;}
        if(dly<16){dly=16;yak=1;}
        break;
                
        case 4:
        dly++;
        if(dly>25){dly+=3;}
        if(dly>40){dly+=7;}
        if(dly>75){dly+=20;}
        if(dly>200){dly=100;yak=1;}
        break;
        
        case 5:
        aci-=5;
        if(aci<0){aci=0;yak=1;}
        delay(20);
        srv.write(aci);
        srv1.write(aci);
        delay(20);
        break;  
        
        case 6:
        aci+=5;
        if(aci>180){aci=180;yak=1;}
        delay(20);
        srv.write(aci);
        srv1.write(aci);
        delay(20);
        break;
        
        case 7:
        duduk=1;
        break;
        
       }gln=10;}
        
      
   
void loop() {


    
    if(ileri==1){
       for(step=0;step<8;step++){
    don();delay(dly/16);}}
    if(ileri==-1){
      for(step=7;step>=0;step--){
       don();delay(dly/16);}}
              
    

    if(Serial.available()>0){
            gln=Serial.read()-48;
            Serial.println(gln);
            git();
        /* Serial.println(ileri);delay(10);
         Serial.println(dly);delay(10);
         Serial.println(aci);delay(10);
         Serial.println("------");*/ }
    
    
    if(duduk==1){dudukdly=millis();duduk=0;
                  duduk1=1;}
    if(duduk1==1){tone(4,
        (millis()-dudukdly)*10+1000,8);}
    if(duduk1==1 and millis()-dudukdly>100){
         digitalWrite(4,LOW);duduk=0;duduk1=0;}
    
        
        
    if(yak==1){
        srv1.write(aci);
        srv.write(aci);
       for(int a =0;a<2;a++){
          delay(40);  digitalWrite(led2,HIGH);
          delay(40);  digitalWrite(led2,LOW);
        }yak=0;}
    
    
    if(millis()%30000-yanmasuresi1>500){
        srv.write(aci);
        Serial.println(aci);
        if(sonyak==30){sonyak=0;} 
        else{sonyak=30;}
        yanmasuresi1=int(millis()%30000);
        analogWrite(led2,sonyak);}
             
        
}
