#include <IRremote.h>
int IRRECVP = 3;
IRrecv irrecv(IRRECVP); 
decode_results results;

/*0-9 = 64-73
v+-=80-81
channel +-=96-97
ust alt =84 83
sag sol =86 85
*/
#define a0 64
#define a1 65
#define a2 66
#define a9 73
#define v1 80
#define v2 81
#define c1 96
#define c2 97
#define ust 84
#define alt 83
#define sag 86
#define sol 85
#define ok  117
#define m1  5//int 1 pin
#define m1d 6//int 2 pin
#define m2  9//int 3
#define m2d 10//int 4
/*
#define a0 64
#define a1 65
#define a2 66
#define a9 73
#define v1 1086294645
#define v2 1086281895
#define c1 1086262005
#define c2 1086296175
#define ust 1086259455
#define alt 1086292095
#define sag 1086275775
#define sol 1086308415
#define ok  1086322695
#define m1  5//int 1 pin
#define m1d 6//int 2 pin
#define m2  9//int 3
#define m2d 10//int
*/
long gln,gln1,gln2;
int hiz=0,maxhiz=255,minhiz=0,art=10,yon=0;
void setup(){
  pinMode(m1,OUTPUT);pinMode(m1d,OUTPUT);
  pinMode(m2,OUTPUT);pinMode(m2d,OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);
 
}//setup

/*void glnkontrol(){
  if (irrecv.decode(&results)){
    gln1=results.value;
    if(gln1==-1){gln=gln2;}
    else{gln=gln1;gln2=gln;}
    irrecv.resume();
    Serial.println(gln1);
    Serial.println(gln);}
  }*/
void glnkontrol(){
  if (irrecv.decode(&results)){gln=results.value;
    gln=gln%2048;irrecv.resume();
    Serial.println(gln);}
}//gln Kontrol      
void moat(int m1hiz,int m2hiz){
       if(m1hiz>=0){
       analogWrite(m1,m1hiz);analogWrite(m1d,0);}
  else if(m1hiz<0){
       analogWrite(m1,0);analogWrite(m1d,-m1hiz);}
      if(m2hiz>=0){
       analogWrite(m2,m2hiz);analogWrite(m2d,0);}
  else if(m2hiz<0){
       analogWrite(m2,0);analogWrite(m2d,-m1hiz);}            
    }//MOAT 

void hizat(int ig,int h){
        if(ig==1){yon=1;moat(hiz,hiz);}
   else if(ig==0){yon=0;moat(0,0);}
   else if(ig==-1){yon=-1;moat(-hiz,-hiz);}
   else if(ig==-2){moat(0,hiz*yon);}
   else if(ig==2){moat(hiz*yon,0);}
   else if(h==1){hiz+=art;
            if(hiz>maxhiz){hiz=maxhiz;}
            else if(hiz<minhiz){hiz=minhiz;}}
   else if(h==-1){hiz-=art;
            if(hiz>maxhiz){hiz=maxhiz;}
            else if(hiz<minhiz){hiz=minhiz;}}
  
  Serial.print("       ");
  Serial.println(hiz);
}//HIZ AT

void loop(){
  glnkontrol();
       if(gln==v1){hizat(100,1);hizat(yon,0);}
  else if(gln==v2){hizat(100,-1);hizat(yon,0);}
  else if(gln==ust){hizat(1,0);}
  else if(gln==alt){hizat(-1,0);}
  else if(gln==ok){hizat(0,0);}
  else if(gln==c1){hiz=maxhiz;hizat(yon,0);}
  else if(gln==c2){hiz=minhiz;hizat(yon,0);}
  else if(gln==sol){hizat(-2,0);}
  else if(gln==sag){hizat(2,0);}
  gln=0;
}//loop