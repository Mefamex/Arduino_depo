void setup() {
  Serial.begin(9600); // Seri Portu başlat.
}
 
void loop() {
  if (Serial.available()>1){
    Serial.println(Serial.read());
    
  }
  




}
