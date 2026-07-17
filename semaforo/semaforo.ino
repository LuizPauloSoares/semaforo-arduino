#include <LiquidCrystal_I2C.h>

int velorSensor;
//Constantes referentes aos semaforos
const int sensor      = 0;
const int carroVermelho = 7;
const int carroAmarelo  = 6;
const int carroVerde  = 5;
 
const int pedVermelho = 4;
const int pedVerde    = 3;
 
const int botao     = 2;
 
const int buzzerPin   = 10;
 
const int trigPin = 12;
const int echoPin = 11;
float duration, distance;
 
//Variaveis referentes a tempo e estado do semaforo
int tempoTravessia    = 5000;
int estado        = 0;
long changeTime;



LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup(){
  //Tipando as pinagens
  pinMode (carroVermelho, OUTPUT);
  pinMode (carroAmarelo, OUTPUT);
  pinMode (carroVerde, OUTPUT);
 
  pinMode (pedVermelho, OUTPUT);
  pinMode (pedVerde, OUTPUT);
 
  pinMode (botao, INPUT);
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  pinMode(buzzerPin,   OUTPUT); // Define o pino do buzzer como saída
//Inicialização da comunicação serial
    Serial.begin(9600);

        lcd.init();
    lcd.backlight();  
}
void loop(){
   int valorSensor = analogRead(sensor);
   int state = digitalRead (botao);
  if (valorSensor < 450){
      lcd.clear();
      Serial.println("Ambiente considerado escuro");
      lcd.setCursor(0, 1);
      lcd.print("Ambiente escuro");
      
      apagaLeds();
      Serial.print("Valor lido pelo sensor: ");
    Serial.println(valorSensor);
    Serial.println("========================================");
    Serial.println();
    delay(1000);
      }else if (state == HIGH && (millis() - changeTime) > 5000){
        lcd.clear();
      Serial.println ("AGUARDE! Fechando semaforo para os carros.");
      lcd.setCursor(0,0);
      lcd.print("AGUARDE!");
      delay(100);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fechando semaforo ");
      delay(200);
      lcd.clear();
      changeLights();
      estado = 0;
      }else{
        lcd.clear();
      if (estado == 0){
        Serial.println("Semaforo aberto para os carros e fechado para pedestres");
      lcd.setCursor(0,0);
      lcd.print("abrindo semaforo ");
      delay(200);
      lcd.clear();
        estado =1;
      }
}
 
  digitalWrite (carroVerde, HIGH);
  digitalWrite (pedVermelho, HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
 
 
     if (distance > 30.99 && distance < 150.99){
  tone(buzzerPin, 250, 250);
   delay(500);
  }
 
   else if(distance < 30.99){
    tone(buzzerPin, 250, 250);
    delay(100);
   }
 
  }
void changeLights(){
  digitalWrite (carroVerde, LOW);
  digitalWrite (carroAmarelo, HIGH);
  delay(2000);
  digitalWrite (carroAmarelo, LOW);
  digitalWrite (carroVermelho, HIGH);
  delay(1000);
  digitalWrite (pedVermelho, LOW);
  digitalWrite (pedVerde, HIGH);
  Serial.println("Pedestre, pode atravessar");
  lcd.setCursor(0,0);
  lcd.print("Pedestre liberado ");
  delay(tempoTravessia);
 
  for(int x = 10; x >= 1; x--){
      lcd.clear();
    tone(buzzerPin, 250, 250);
    Serial.println ("ATENCAO, o semaforo do pedestre fechara em " + (String)x + " segundos");
    lcd.setCursor(0,0);
    lcd.print("abrindo " +(String)x);
    digitalWrite (pedVerde, HIGH);
    delay(500);
    digitalWrite (pedVerde, LOW);
    delay(500);
  }
  lcd.clear();
  digitalWrite (pedVermelho, HIGH);
  delay(500);
  digitalWrite (carroVermelho, LOW);
  delay(1000);
  digitalWrite (carroVerde, HIGH);
  changeTime = millis();
  }
void apagaLeds(){
    
    digitalWrite (carroAmarelo, HIGH);
    delay(50);
    digitalWrite (carroAmarelo, LOW);
    delay(50);
 

}