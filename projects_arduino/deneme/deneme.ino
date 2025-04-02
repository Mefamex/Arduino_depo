void setup(){
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}
void l(int p,int a){
  if(a==1){digitalWrite(p,HIGH);}
  else{digitalWrite(p,LOW);}
  }
void loop(){
  l(3,1);
  if(analogRead(A0)>40){
    l(2,1);l(3,0);delay(1000);
    l(2,0);}
}
/*Hocam sarı kabloyu A0 pinine bagliyonuz.
eger sarıdan 0.20V dan fazla elektrik gelirse
2.pindeki ledi yakıyo, 1saniye bekliyo, söndürüp geri 3.pindeki ledi yakıyo ..
kartın içinde eğer bakiye yoksa onu algılayamıyo,
oradaki degerleri ölçmem lazım bakiye olmadiğinda bişe yapması için*/