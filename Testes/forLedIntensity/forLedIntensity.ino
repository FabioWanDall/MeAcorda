/*
*Testa as 3 cores do ponto mais forte para o posto mais fraco
*/

int redPin   = 9;
int greenPin = 10;
int bluePin  = 11;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  Serial.println("vermelho");
  for(int vRed=0; vRed<255; vRed++)
  {
    analogWrite(redPin, vRed);
    delay(2);
    Serial.println(vRed);
  }
  delay(50);
  Serial.println("verde");
  for(int vRed=0; vRed<255; vRed++)
  {
    analogWrite(greenPin, vRed);
    delay(2);
    Serial.println(vRed);
  }
  delay(50);
  Serial.println("azul");
  for(int vRed=0; vRed<255; vRed++)
  {
    analogWrite(bluePin, vRed);
    delay(2);
    Serial.println(vRed);
  }

  
}
