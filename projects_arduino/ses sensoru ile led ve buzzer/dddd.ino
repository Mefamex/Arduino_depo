int deger;
void setup() {
    pinMode(5,INPUT);
    pinMode(10,OUTPUT);
    pinMode(5,OUTPUT);
    Serial.begin(9600);
    }
void loop() { 
   while(true){ deger =analogRead(5);
  
        deger-=500-deger;
        Serial.println(deger);
    if(deger<500){
            analogWrite(10,0);
            delay(10);
            continue;}
    deger=map(deger,400,600,0,240);
    if(deger>800){analogWrite(10,HIGH);}
    else{analogWrite(10,deger);}
   // Serial.println(deger);
  delay(30);
    }}
