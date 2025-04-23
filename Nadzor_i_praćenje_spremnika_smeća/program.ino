#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1);

// Inicijalizacija za mjerenje vremena i daljine
int duration, distance;

// Deklariranje pinova
int trigPin = 4;
int echoPin = 5;
int tipkalo = 8;

// Inicijaliziranje za primanje podataka sa Bluetooth
int receivedChar;

void setup() {
  // Pokretanje Bluetooth-a na mikrokontroleru
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Spreman za BT komunikaciju!");

  // Konfiguracija pinova
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tipkalo, INPUT_PULLUP);  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Čitanje stanja tipkala
  if(digitalRead(tipkalo) == LOW) {  
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Pritisnuta je tipka");
    delay(10000);
    if(digitalRead(tipkalo) == LOW) {
      delay(5000);
    }
  }

  // Mjerenje udaljenosti
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  Serial.print("1st Sensor: ");
  Serial.print(distance);
  Serial.println("cm ");

  // LED logika bazirana na udaljenosti
  if(distance <= 10) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  } else if(distance <= 20) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  // Bluetooth komunikacija
  if(BT.available()) {
    receivedChar = BT.read();
    Serial.print("Received:");
    Serial.println(receivedChar);

    if(receivedChar == '1') {  
      Serial.println("Bluetooth je uspješno povezan");
    }
    
    if(receivedChar == '2') {
      Serial.println("Vlasnik je doma");
    }
    
    if(receivedChar == '3') {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    
    if(receivedChar == '4') {
      digitalWrite(LED_BUILTIN, LOW);
      brojac = 0;
    }
  if(receivedChar == '5') {
      Serial.println("Vlasnik odlazi od doma");
      pinMode(LED_BUILTIN, LOW);
    }
  }
  }
  }
  delay(500);  // Manji delay za bolju responzivnost
}
