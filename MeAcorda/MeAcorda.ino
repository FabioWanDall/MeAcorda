//Define RTC SD3231 pins
#define  GND   A2
#define  VCC   A3
#define  SDA   A4
#define  SCL   A5

//Define LED Type GND pins(red, green, blue)
#define  REDP   9
#define  GREENP 10
#define  BLUEP  6

//Carrega a biblioteca do RTC DS1307
#include <DS1307.h> 

//Modulo RTC DS1307*** ligado as portas A4 e A5 do Arduino UNO(This library work too)
DS1307 rtc(SDA, SCL);

Time t;
int maxLight = 50;
int minLight = 255;

//Set Alarm variables
int aHour = 23;
int aMin = 01;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial){;}
  Serial.println("\n\nDespertar {%d}:{%d}");

  //RTC pins
  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);
  digitalWrite(GND, LOW);
  analogWrite(VCC, 170);//~=3,33v
  //Aciona o relogio
  rtc.halt(false);

  //LED Type pins
  pinMode(REDP, OUTPUT);
  pinMode(GREENP, OUTPUT);
  pinMode(BLUEP, OUTPUT);  

  turn_off_lights();
}

void turn_off_lights(){
  digitalWrite(REDP, HIGH);
  digitalWrite(GREENP, HIGH);
  digitalWrite(BLUEP, HIGH);
}

void loop() {
  Serial.println(rtc.getTimeStr());
  t = rtc.getTime();

  if(t.hour == aHour){
    if(t.min == aMin){
      Serial.println("Alarme");
      for(int x = minLight; x > maxLight; x--){//Up the light
        analogWrite(REDP, x);
        delay(2);
      }
      delay(100);
      for(int x = maxLight; x < minLight; x++){//Down the light
        analogWrite(REDP, x);
        delay(2);
      }
      for(int x = minLight; x > maxLight; x--){//Up the light
        analogWrite(GREENP, x);
        delay(2);
      }
      delay(100);
      for(int x = maxLight; x < minLight; x++){//Down the light
        analogWrite(GREENP, x);
        delay(2);
      }
      for(int x = minLight; x > maxLight; x--){//Up the light
        analogWrite(BLUEP, x);
        delay(2);
      }
      delay(100);
      for(int x = maxLight; x < minLight; x++){//Down the light
        analogWrite(BLUEP, x);
        delay(2);
      }
    }
    turn_off_lights();   
  }
  //Aguarda x segundo e repete o processo
  delay (10000);
}
