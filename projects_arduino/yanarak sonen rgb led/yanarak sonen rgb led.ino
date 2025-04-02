int x=0,a=3,d=1;
int y=255,b=4,e=(-1);
int art=1,bekle=3;
int sayac=8;

void setup(){Serial.begin(9600);
   pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    
digitalWrite(4,HIGH);
}

void beyaz(){sayac=0;
for(;y<=250;y+=art){delay(bekle);
        analogWrite(b,y);}
    for(;x<=250;x+=art){delay(bekle);
        analogWrite(a,x);}delay(bekle*3);
    for(int qw=250; qw>=0;qw-=art){delay(bekle*2);
        analogWrite(3,qw);
        analogWrite(5,qw);
        analogWrite(6,qw);}
             delay(bekle*3);               
             x=250;y=0;             
                      }

void loop(){
    if(x>=250){sayac++;Serial.println(sayac);
   // if(sayac>=10){beyaz();}
        if(a!=3&&b!=3){a=3;}
        else if(a!=5&&b!=5){a=5;}
        else if(a!=6&&b!=6){a=6;}
        d=-1; e=1;
        }
    if(y>=250){
        if(a!=3&&b!=3){b=3;}
        else if(a!=5&&b!=5){b=5;}
        else if(a!=6&&b!=6){b=6;}
        d=1; e=-1;
        }
    x+=d; y+=e;
    analogWrite(a,x);
   analogWrite(b,y);
    delay(bekle);  
    } 