int sensor = 0, mind = 500, maxd = 510;
int maxl=200, minl=0, cikis=1;
int ledp = 11, sensorp = A0;
int mss=10 ; float  ort=0;

int minler=0 , maxlar=1024, adetmin=10, adetmax=10;

const int partpart=250;
int partmin=0 , partmax=1024,partnumber=0, mutlak=0,maxval=0;
int partval[partpart];

//========================================================================
//========================================================================

void setup() {
  for (int q=0;q<partpart;q++){partval[q]=0;}
  Serial.begin(9600);
  pinMode(sensorp, INPUT);
  pinMode(ledp, OUTPUT);}

//========================================================================
//========================================================================

void setled(int sens){
  mutlak = ort+abs(sens-ort);
  maxval=max(mind,maxd);
  cikis= map(mutlak, ort, maxval, minl, maxl);
  //Serial.print(ort);Serial.print(" - ");Serial.print(cikis);Serial.print(" - ");
  if      (sens>=maxd or sens<=mind )  {cikis=200;}//
  else if (cikis>180 ){cikis=cikis;}
  else if (cikis>150 ){cikis=cikis/3;}
  else {cikis/=4;}
  //Serial.println(cikis);
  
  analogWrite(ledp,cikis);}

//========================================================================

void setled1(int sens){
  cikis= map(sensor, mind, maxd, minl, maxl);
  if      (sens>=maxd)  {cikis=250;}
  else if (sens<=mind )  {cikis=1;}   //mind+(maxd-mind)/4
  else if (sens<(maxd+mind)/(100/75)){cikis=cikis/4;}
  
  else                  {cikis=cikis;}
  analogWrite(ledp,cikis);}

//===============================
//===============================

void setminmax(int news){
  partval[partnumber]=news;
  partmin=1024;partmax=0;ort+=(news-ort)/partpart;
  for (int q=0;q<partpart;q++){   //ort+=partval[q];
    if (partval[q]<partmin){partmin=partval[q];}
    if (partval[q]>partmax){partmax=partval[q];}}
  partnumber+=1; if (partnumber>=partpart){partnumber=0;}  //ort/=partpart;

  mind=partmin;maxd=partmax;
  //Serial.print(mind);Serial.print(" - ");Serial.print(maxd);Serial.print(" --- ");
  //Serial.print(partmin);Serial.print(" - ");Serial.print(partmax);Serial.print(" - ");Serial.print(ort);Serial.print(" --- ");Serial.print(news);Serial.print(" --- ");Serial.println(cikis);
  
}

//========================================================================
//========================================================================

void loop() {

  sensor = analogRead(sensorp);
  //Serial.print(sensor);Serial.print("-");
  setled(sensor);
  //Serial.println(cikis);

  setminmax(sensor);
  
  //delay(mss);
  //if(cikis>180){delay(10);}
  //else{
  delay(25);
}

//========================================================================
//========================================================================
