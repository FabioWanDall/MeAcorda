//Programa : Relogio com modulo RTC DS1307
 #define  GND   A2
 #define  VCC   A3
 #define  SDA   A4
 #define  SCL   A5
//Carrega a biblioteca do RTC DS1307
#include <DS1307.h>
 
//Modulo RTC DS1307 ligado as portas A4 e A5 do Arduino 
DS1307 rtc(SDA, SCL);//SDA, SCL
 
void setup()
{
  Serial.begin(9600);
  while(!Serial){;}
  Serial.print("Oieee");

  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);
  digitalWrite(GND, LOW);
  analogWrite(VCC, 170);
  //Aciona o relogio
  rtc.halt(false);
   
  //As linhas abaixo setam a data e hora do modulo
  //e podem ser comentada apos a primeira utilizacao
  //rtc.setDOW(THURSDAY);      //Define o dia da semana
  //rtc.setTime(20, 35, 0);     //Define o horario
  //rtc.setDate(31, 7, 2019);   //Define o dia, mes e ano
}
 
void loop()
{
  //Mostra as informações no Serial Monitor
  Serial.print("Hora : ");
  Serial.print(rtc.getTimeStr());
  Serial.print(" ");
  Serial.print("Data : ");
  Serial.print(rtc.getDateStr());
  Serial.print(" ");
  Serial.println(rtc.getDOWStr());
   
  //Aguarda 1 segundo e repete o processo
  delay (1000);
}
