
const int ledPin = 11;      
const int knockSensor =A0;
int sensorReading = 0;    
int ledState = LOW;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);      
}

void loop() {
  
  sensorReading = analogRead(knockSensor);
Serial.println(sensorReading);
  
  if (sensorReading >300) {
    
    digitalWrite(ledPin, HIGH);
    Serial.println("Knock!");
  }
   
  delay(50);  
    digitalWrite(ledPin,LOW);
    delay(50);
}

