#include <Servo.h>
Servo mtr1,mtr2,mtr3,mtr4,mtr5;
//    0-1  2-3  4-5  6-7  8-9
int aci1=90,aci2=90,aci3=90,aci4=90,aci5=90;
int aci11=0,aci22=0,aci33=0,aci44=0,aci55=0;
char gln,dly=50,yak=0,yak1=0;
int a1,a2,a3,a4,a5;

void setup(){
    Serial.begin(9600);Serial.println(int("1"));
    mtr1.attach(2);mtr2.attach(3);mtr3.attach(4);mtr4.attach(5);mtr5.attach(6);
    mtr1.write(aci1);mtr2.write(aci2);mtr3.write(aci3);mtr4.write(aci4);mtr5.write(aci5);
    pinMode(13,OUTPUT);
     }



void ayarla(){switch(gln){
    case 'a':dly+=dly/10;break;
    case 'b':dly-=dly/10;break;}
    if(dly<10){dly=10;}else if(dly>1000){dly=1000;}
}

void loop(){
    delay(dly);
    if(Serial.available()>0){gln=Serial.read();
    if(gln>='a' and gln<='b'){ayarla();}   }

    if(aci1<a1){aci1++;}else if(aci1>a1){aci1--;}else{a1=random(0,180);delay(50);}
    if(aci2<a2){aci1++;}else if(aci2>a2){aci2--;}else{a2=random(0,180);delay(50);}
    if(aci3<a3){aci1++;}else if(aci3>a3){aci3--;}else{a3=random(0,180);delay(50);}
    if(aci4<a4){aci1++;}else if(aci4>a4){aci4--;}else{a4=random(0,180);delay(50);}
    if(aci5<a5){aci1++;}else if(aci5>a5){aci5--;}else{a5=random(0,180);delay(50);}


    mtr1.write(aci1);mtr2.write(aci2);mtr3.write(aci3);mtr4.write(aci4);mtr5.write(aci5);

/*yakk*/if(yak==1){yak1=millis();digitalWrite(13,HIGH);if(millis()-yak1>100){yak=0;digitalWrite(13,LOW);}}


}

