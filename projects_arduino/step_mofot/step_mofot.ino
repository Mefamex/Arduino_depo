


void setup() {
    Serial.begin(9600);
    pinMode(3,OUTPUT);
    digitalWrite(3,HIGH);
    while(true){
    for(int a=1;a<260;a+=1){
        analogWrite(3,a);
        delay(10);
        Serial.println(a+"\n");}
    
}}

void loop() {
    digitalWrite(3,HIGH);
}


