void setup(){
    pinMode(A0,INPUT);
    pinMode(13,OUTPUT);
    }

void loop(){
    int a=analogRead(A0);
    if(a>300){digitalWrite(13,HIGH);delay(15);}
    
        digitalWrite(13,LOW);}