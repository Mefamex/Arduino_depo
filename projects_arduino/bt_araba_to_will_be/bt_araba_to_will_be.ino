#include <Servo.h>

#define psagi 5 //sag ileri
#define psagg 6 //sag geri
#define psoli 10 //sol ileri
#define psolg 9 //sol geri



int defhiz=100, hiz=defhiz,
ekle=25,minh=0,maxh=250, 
yon=0, //-1=geri,0=stopped,1=ileri
yonss=0;//-1=sol,0=None,1=sag
float donmehizi=0.5;
char gln='0';
String send="";



void hizat(int sol,int sag){
  if(sol==0){
            analogWrite(psoli,0);
            analogWrite(psolg,0);}
  else if(sol>0){
            analogWrite(psoli,sol);
            analogWrite(psolg,sol);}
  else if(sol<0){
            analogWrite(psoli,-sol);
            analogWrite(psolg,-sol);}
  else{//hata kısmı
               digitalWrite(psolg,0);
               while(true){
               digitalWrite(psoli,0);delay(100);
             digitalWrite(psoli,200);delay(100);}}
 
  if(sag==0){
            analogWrite(psagi,0);
            analogWrite(psagg,0);}
  else if(sol>0){
            analogWrite(psagi,sag);
            analogWrite(psagg,sag);}
  else if(sol<0){
            analogWrite(psagi,-sag);
            analogWrite(psagg,-sag);}
  else{//hata kısmı
               digitalWrite(psagg,0);
               while(true){
               digitalWrite(psagi,0);delay(100);
             digitalWrite(psagi,200);delay(100);}}
}//hiz at

void glnat(char gln){
  switch(gln){
  case 's':hizat(0,0);yon=0;yonss=0;break;//durdur
    
  case 'i':hizat(hiz,hiz);yon=1;break;//ileri git
    
  case 'g':hizat(-hiz,-hiz);yon=-1;break;//gerigit
    
  case 'o':yonss=-1;//sol
      hizat( (hiz*donmehizi)*(yon*-1),
                      (hiz*donmehizi)*yon);break;
    
  case 'a':yonss=1;//sag
      hizat( (hiz*donmehizi)*yon,
               (hiz*donmehizi)*(yon*-1));break;
    
  case '+'://hiz arttir
      hiz+=ekle;if(hiz>maxh){hiz=maxh;}break;
    
  case '-'://hiz eksilt
      hiz-=ekle;if(hiz<minh){hiz=minh;}break;
    
  case 'r'://reset
      hiz=defhiz;yon=0;yonss=0;hizat(0,0);break;
    
    }//switch case
}


void setup(){
  Serial.begin(9600);
  pinMode(psagi ,OUTPUT);pinMode(psagg ,OUTPUT);
  pinMode(psoli ,OUTPUT);pinMode(psolg ,OUTPUT); 
}


void loop(){
  if(Serial.available()>0){
    gln=Serial.read();
    glnat(gln);//gelen veriyi isleme alir
    send=String(gln);send+="-->";
    send+="hiz=";
    send+=String(hiz);send+="--yon=";
    send+=String(yon);send+="--yonss=";
    send+=String(yonss);
    Serial.println(send);//degerler gonderildi
    
    }//serial
}//loop