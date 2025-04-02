 int buyukluk=0;
int sensorValue = 0;
int outputValue = 0;
				int x=0,a=3,d=1;
int y=250,b=4,e=(-1);
int art=1,bekle=3;
int sayac=8;
double sonuc=0;

void setup() {
				pinMode(A0,INPUT);
   pinMode(3,OUTPUT);
				pinMode(9,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
				}


void loop(){
    if(x>=250){sayac++;
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
			buyukluk=	map(analogRead(A0),530,900,0,1024);
				buyukluk=800;
	analogWrite(9,buyukluk);

				   analogWrite(a,x);

				 analogWrite(b,y);
			
   delay(8); 
    }; 

/*
 

	*/