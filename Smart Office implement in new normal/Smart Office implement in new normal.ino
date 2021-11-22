#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

int led=8,buzzer=9,pir1=10,pir2=11,rs=2,ena=3,db4=4,db5=5,db6=6,db7=7;
int orang=0,gerak1,gerak2,flag=0, flag_gerak1, flag_gerak2;
int lampu=12,tombol=A5,pinButton;
int masuk,keluar;
void setup(){
    Serial.begin(9600); //serial monitor
  	lcd.begin(16,2);    //Mulai Lcd 
    pinMode(buzzer,OUTPUT);
    pinMode(led,OUTPUT);  
  	pinMode(lampu,OUTPUT);  
    pinMode(pir1,INPUT);
    pinMode(pir2,INPUT);
    pinMode(tombol,INPUT);
    digitalWrite(led,LOW);//set awal led kondisi mati
    digitalWrite(buzzer,LOW);//buzzer mati	
}

void loop(){
   pinButton=digitalRead(tombol);//pembacaan nilai pada saklar
   if(pinButton == HIGH){ //jika saklar hidup mode jadi manual,menghidupkan lampu dan mematikan perangkat
     lcd.clear();   
     digitalWrite(led,LOW);
     digitalWrite(buzzer,LOW);
     digitalWrite(lampu,HIGH); 
 }
  
 else{ 
    digitalWrite(lampu,LOW);
    bacapir(); //baca pergerakan pir dan tambah/kurangi orang
    efekorang(); //efek jika ada/tidak ada orang
    delay(1000);
  }  
} 


void bacapir(){ 
gerak1=digitalRead(pir1);  //deteksi gerakan pir 1
gerak2=digitalRead(pir2);  //deteksi gerakan pir 2
  
  /*
  skenario:
  pir kiri diletakan dipintu masuk, pir kanan diletakan dipintu keluar
  */
  while(gerak1==1){ //jika terdapat gerakan di pir1
   orang+= 1; 
    masuk=1;
    digitalWrite(led,HIGH);
    tampillcd();
    gerak1=0;
  	}
 	
  
  while(gerak2==1){ //jika terdapat gerakan di pir2
    if(orang>0){
   		orang-=1;
      	keluar=1;
      	tampillcd();
      	gerak2=0;
    }
    else{
      break;
	}
  }
}

void tampillcd(){
lcd.setCursor(0,0); 
lcd.println("SEMANGAT KERJA!!");
lcd.setCursor(0,1);
lcd.print  ("JUMLAH  ORANG:");
lcd.print(orang);
}



void efekorang(){
  if(orang<=0){ //jika tidak ada orang
     orang=0;
     lcd.clear();//bersihkan lcd
     digitalWrite(led,LOW);
     digitalWrite(buzzer,LOW);//kemudian matikan lcd,led 
  }
  
  if(masuk==1){
   digitalWrite(buzzer,HIGH);
	tone(buzzer, 5000,100);
    digitalWrite(buzzer,LOW);
    delay(1000);
    digitalWrite(buzzer,HIGH);
	tone(buzzer, 5000,300);
    digitalWrite(buzzer,LOW);
    delay(1000);
    digitalWrite(buzzer,HIGH);
	tone(buzzer, 5000,300);
    digitalWrite(buzzer,LOW);
    masuk=0;
  }   
  
  else if(keluar==1){
   digitalWrite(buzzer,HIGH);
	tone(buzzer, 500,100);
    digitalWrite(buzzer,LOW);
    delay(1000);
    digitalWrite(buzzer,HIGH);
	tone(buzzer, 500,300);
    digitalWrite(buzzer,LOW);
    delay(1000);
    digitalWrite(buzzer,HIGH);
	tone(buzzer, 500,300);
    digitalWrite(buzzer,LOW);
    
    keluar=0;
  }   
  
}
