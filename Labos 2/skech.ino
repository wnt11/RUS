#include <Arduino.h>

#define TIPKALO 23
#define LED 32      
volatile bool b_BUDAN = false;
unsigned long VRIJEME; 
volatile bool b_SPAVANJE = false;    
float f_potrosnja; 

// Prekidna rutina za buđenje tipkom
void  buditi() {
  unsigned long lastInterruptTime = 0;
  unsigned long vrijeme_prekid = millis();
  
  if (vrijeme_prekid - lastInterruptTime > 200) {
    b_BUDAN = true;
  }
  lastInterruptTime = vrijeme_prekid;
}

void spavati() {
  f_potrosnja = 0.001;
  Serial.print("Ulazim u sleep mode. Potrosnja je ");
  Serial.print(f_potrosnja);
  Serial.println(" mA");;
  digitalWrite(LED, LOW);
  VRIJEME = millis();
  b_SPAVANJE = true;
   
  esp_sleep_enable_ext0_wakeup((gpio_num_t)TIPKALO, LOW);
  esp_sleep_enable_timer_wakeup(10 * 1000000);
  esp_light_sleep_start();
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(TIPKALO, INPUT_PULLUP);
  f_potrosnja = 5.9;
  
  attachInterrupt(digitalPinToInterrupt(TIPKALO), buditi, FALLING);
  
  Serial.print("Sustav pokrenut. LED upaljen na 5 sekundi. Potrosnja je ");
  Serial.print(f_potrosnja);
  Serial.println(" mA");;
  digitalWrite(LED, HIGH);
  delay(5000);
  spavati();
}

void loop() {
  if (b_BUDAN || (b_SPAVANJE && (millis() - VRIJEME) > 8000)) {
    f_potrosnja = 5.9;
    if (b_BUDAN) {
      Serial.print("Dogodio se prekid. LED upaljen na 5 sekundi. Potrosnja je ");
      Serial.print(f_potrosnja);
      Serial.println(" mA");;
    } 
    else {
      Serial.print("Tajmer istekao! LED upaljen na 5 sekundi.Potrosnja je ");
      Serial.print(f_potrosnja);
      Serial.println(" mA");;
    }
    
    digitalWrite(LED, HIGH);
    delay(5000);
    spavati();
    b_BUDAN = false;
  }
}
