int rakam=0;
char deger='1';
void setup() {
for(int i=2;i<9;i++){
        pinMode(i,OUTPUT);}
    Serial.begin(9600);
}

void sifir(){
    digitalWrite(2,HIGH);  
    digitalWrite(3,HIGH);  
    digitalWrite(4,HIGH);  
    digitalWrite(5,LOW);  
    digitalWrite(6,HIGH);  
    digitalWrite(7,HIGH);  
    digitalWrite(8,HIGH); 
     
}

void bir(){
    digitalWrite(2,HIGH);  
    digitalWrite(3,LOW);  
    digitalWrite(4,LOW);  
    digitalWrite(5,LOW);  
    digitalWrite(6,LOW);  
    digitalWrite(7,LOW);  
    digitalWrite(8,HIGH); 
    
}


void iki(){
    digitalWrite(2,HIGH);  
    digitalWrite(3,HIGH);  
    digitalWrite(4,LOW);  
    digitalWrite(5,HIGH);  
    digitalWrite(6,HIGH);  
    digitalWrite(7,HIGH);  
    digitalWrite(8,LOW); 
    
}

void uc(){
    digitalWrite(2,HIGH);  
    digitalWrite(3,HIGH);  
    digitalWrite(4,LOW);  
    digitalWrite(5,HIGH);  
    digitalWrite(6,LOW);  
    digitalWrite(7,HIGH);  
    digitalWrite(8,HIGH); 
    digitalWrite(9,LOW);     
}



void dort(){
    digitalWrite(2,HIGH);  
    digitalWrite(3,LOW);  
    digitalWrite(4,HIGH);  
    digitalWrite(5,HIGH);  
    digitalWrite(6,LOW);  
    digitalWrite(7,LOW);  
    digitalWrite(8,HIGH); 
    digitalWrite(9,LOW);     
}



void bes(){
    digitalWrite(2,LOW);  
    digitalWrite(3,HIGH);  
    digitalWrite(4,HIGH);  
    digitalWrite(5,HIGH);  
    digitalWrite(6,LOW);  
    digitalWrite(7,HIGH);  
    digitalWrite(8,HIGH); 
    digitalWrite(9,LOW);     
}


void alti(){
    digitalWrite(2,LOW);  
    digitalWrite(3,HIGH);  
    digitalWrite(4,HIGH);  
    digitalWrite(5,HIGH);  
    digitalWrite(6,HIGH);  
    digitalWrite(7,HIGH);  
    digitalWrite(8,HIGH); 
    digitalWrite(9,LOW);     
}


void yedi(){
    digitalWrite(2,HIGH);  
    digitalWrite(3,HIGH);  
    digitalWrite(4,LOW);  
    digitalWrite(5,LOW);  
    digitalWrite(6,LOW);  
    digitalWrite(7,LOW);  
    digitalWrite(8,HIGH); 
    digitalWrite(9,LOW);     
}


void sekiz(){
    digitalWrite(2,HIGH);  
    digitalWrite(3,HIGH);  
    digitalWrite(4,HIGH);  
    digitalWrite(5,HIGH);  
    digitalWrite(6,HIGH);  
    digitalWrite(7,HIGH);  
    digitalWrite(8,HIGH); 
    digitalWrite(9,LOW);     
}


void dokuz(){
    digitalWrite(2,HIGH);  
    digitalWrite(3,HIGH);  
    digitalWrite(4,HIGH);  
    digitalWrite(5,HIGH);  
    digitalWrite(6,LOW);  
    digitalWrite(7,HIGH);  
    digitalWrite(8,HIGH); 
    digitalWrite(9,LOW);     
}


void nokta(){ 
    digitalWrite(9,HIGH);     
}



void sil(){
    digitalWrite(2,LOW);  
    digitalWrite(3,LOW);  
    digitalWrite(4,LOW);  
    digitalWrite(5,LOW);  
    digitalWrite(6,LOW);  
    digitalWrite(7,LOW);  
    digitalWrite(8,LOW); 
    digitalWrite(9,LOW);     
}

void loop() {
if(  Serial.available()>0){
   rakam=Serial.read()-48;Serial.println(rakam);
         switch(rakam){
  case 0:sifir();break;
   case 1:bir();break;
  case 2:iki();break;
  case 3:uc();break;
    case 4:dort();break;
   case 5:bes();break;  
   case 6:alti();break; 
    case 7:yedi();break;
   case 8:sekiz();break; 
   case 9:dokuz();break;                
 case -2:nokta();break; 
case 49:sil();break;                         
  }
      
        }
    
    

}
