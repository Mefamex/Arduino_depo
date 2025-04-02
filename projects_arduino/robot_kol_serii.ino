#include <Servo.h>
Servo mtr1,mtr2,mtr3,mtr4,mtr5;
//    0-1  2-3  4-5  6-7  8-9
int aci1=90,aci2=75,aci3=90,aci4=90,aci5=90;
int aci11=0,aci22=0,aci33=0,aci44=0,aci55=0;
char gln,dly=50;

void setup(){
    Serial.begin(9600);
    mtr1.attach(2);mtr2.attach(3);mtr3.attach(4);mtr4.attach(5);mtr5.attach(6);
    mtr1.write(aci1);mtr2.write(aci2);mtr3.write(aci3);mtr4.write(aci4);mtr5.write(aci5);
     }

void motor(){
    switch(gln){
        case '0':if(aci11==-1){aci11=0;}else{aci11=-1;}break;
        case '1':if(aci11==1){aci11=0;}else{aci11=1;}break;
        case '2':if(aci22==-1){aci22=0;}else{aci22=-1;}break;
        case '3':if(aci22==1){aci22=0;}else{aci22=1;}break;
        case '4':if(aci33==-1){aci33=0;}else{aci33=-1;}break;
        case '5':if(aci33==1){aci33=0;}else{aci33=1;}break;
        case '6':if(aci44==-1){aci44=0;}else{aci44=-1;}break;
        case '7':if(aci44==1){aci44=0;}else{aci44=1;}break;
        case '8':if(aci55==-1){aci55=0;}else{aci55=-1;}break;
        case '9':if(aci55==1){aci55=0;}else{aci55=1;}break;}}

void ilerle(){
    aci1+=aci11;aci2+=aci22;aci3+=aci33;aci4+=aci44;aci5+=aci11;
    if(aci1>180){aci1=180;}else if(aci1<0){aci1=0;}
    if(aci2>150){aci2=150;}else if(aci2<0){aci2=0;}
    if(aci3>180){aci3=180;}else if(aci3<0){aci3=0;}
    if(aci4>180){aci4=180;}else if(aci4<0){aci4=0;}
    if(aci5>180){aci5=180;}else if(aci5<0){aci5=0;}
    mtr1.write(aci1);mtr2.write(aci2);mtr3.write(aci3);mtr4.write(aci4);mtr5.write(aci5);}
void ayarla(){switch(gln){
    case 'a':if(dly<10){dly+=2;}else{dly+=10;}break;
    case 'b':if(dly<=10){dly-=2;}else{dly-=10;}break;}
    if(dly<2){dly=2;}else if(dly>400){dly=400;}
}

void loop(){
delay(dly);ilerle();
if(Serial.available()>0){
    gln=Serial.read();
    if(gln>='0' and gln<='9'){motor();}
    else if(gln>='a' and gln<='b'){ayarla();}}

};

