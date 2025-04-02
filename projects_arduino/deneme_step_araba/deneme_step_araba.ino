int sirali[]={}, sirali1[]={},
    adet=0, gln=0, kayit=0, baslangic=0, bitis=0, 
    sira=0;
    
void setup(){
    Serial.begin(9600);
    }

void gonder(String gidecekolan){
    Serial.println(gidecekolan);}

void geldi(int gln){
    while(true){
   if(Serial.available()>0){gln=Serial.read()-48;}    
        
        if(gln==0 or gln==1 or gln==2 or gln==3 or
         gln==4 or gln==5 or gln==6 or gln==7){
         gonder(String(gln));
         sirali[adet]=gln;
         sirali1[adet]=millis();
         adet+=1;   
            }
    
        
    if(gln==9){bitis=millis();break;}}
}

void donder(){
    int sure=0;
    while(true){
        if(Serial.available()>0){
            gln=Serial.read()-48;
            if(gln!=9){break;}
           }         
        sure=millis()%(bitis-baslangic)-baslangic;
        if(sure>bitis){sira=0;}
        if(sure>sirali1[sira]){
            gonder(String(sirali[sira]));
            sira+=1;
           } 
        
        
        }}



void loop(){
    if(Serial.available()>0){
        gln=int(Serial.read()-48);
       if(gln==0 or gln==1 or gln==2 or gln==3 or
         gln==4 or gln==5 or gln==6 or gln==7){
         gonder(String(gln));}    
        
       if(gln==8){int sirali[]={},sirali1[]={};
            baslangic=millis();geldi(gln);}
       if(gln==9){donder();}
    
    }
    
    
    
    
    
    }