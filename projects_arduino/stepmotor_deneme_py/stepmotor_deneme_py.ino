     int hiz=10,s1=9,s2=10,s3=11,s4=12;
     int dly=20;
  
void yak(int yak1,int yak2,int yak3,int yak4){
    if(yak1==1){digitalWrite(s1,HIGH);}else{
                   digitalWrite(s1,LOW);}
    if(yak2==1){digitalWrite(s2,HIGH);}else{
                   digitalWrite(s2,LOW);}
    if(yak3==1){digitalWrite(s3,HIGH);}else{
                   digitalWrite(s3,LOW);}
    if(yak4==1){digitalWrite(s4,HIGH);}else{
                   digitalWrite(s4,LOW);}}


void a(){
 int ssss=0,ssss1=100/dly;ssss1-=ssss1%4;ssss1+=4;
    for(int q=0;q<=int(100/dly);q++,ssss++){
        if(ssss%4==0){yak(1,0,0,0);}
        else if(ssss%4==1){yak(0,1,0,0);}
        else if(ssss%4==2){yak(0,0,1,0);}
        else if(ssss%4==3){yak(0,0,0,1);}
        delay(dly);
        }
 }


void setup(){
    pinMode(s1 and s2 and s3 and s4,OUTPUT);
    Serial.begin(9600);
    }

void loop(){
    a();
    if(Serial.available()>0){dly=int(Serial.parseInt());
        Serial.println(dly);}
    };
