#define ECHO 15      // Ultrazvučni senzor - Echo
#define TRIG 16      // Ultrazvučni senzor - Trigger
#define TIPKA1 18    // Tipkalo 1 (prekidni ulaz)
#define TIPKA2 27    // Tipkalo 2 (prekidni ulaz)
#define LED1 33      // LED1 za indikaciju
#define LED2 22      // LED2 za indikaciju

volatile bool b_PRITISNUT1 = false;  // TIPKA1 pritisnuta
volatile bool b_PRITISNUT2 = false;  // TIPKA2 pritisnuta
volatile int i_BROJAC = 0;           // Brojač za TIPKA1

// ISR za TIPKA2 (prekidni ulaz) - pokreće LED2 i ultrazvučni senzor
void IRAM_ATTR ISR_TIPKA2() {
  b_PRITISNUT2 = true;  // TIPKA2 je pritisnuta
}

// ISR za TIPKA1 (prekidni ulaz) - pokreće LED1
void IRAM_ATTR ISR_TIPKA1() {
  b_PRITISNUT1 = true;  // TIPKA1 je pritisnuta
}

// ISR za ECHO signal s HC-SR04 (detektira reflektirani val)
void IRAM_ATTR ISR_ECHO() {
  // Ovdje možete obraditi reflektirani signal s ultrazvučnog senzora
}

void setup() {
  Serial.begin(115200);  // Pokreni serijsku komunikaciju
  delay(1000);
  Serial.println("ESP32 - Kontrola LED i Ultrazvučni senzor");

  // Postavka pinova
  pinMode(TIPKA1, INPUT_PULLUP);
  pinMode(TIPKA2, INPUT_PULLUP);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  // Inicijaliziraj prekide
  attachInterrupt(digitalPinToInterrupt(TIPKA1), ISR_TIPKA1, FALLING);  // TIPKA1
  attachInterrupt(digitalPinToInterrupt(TIPKA2), ISR_TIPKA2, FALLING);  // TIPKA2
  attachInterrupt(digitalPinToInterrupt(ECHO), ISR_ECHO, RISING);  // ECHO signal
}

void loop() {
  // Obrada TIPKA2
  if (b_PRITISNUT2) {
    // LED2 i ultrazvučni senzor trebaju blinkati
    digitalWrite(LED2, HIGH);
    delay(500);  // Kratka pauza za treperenje LED2
    digitalWrite(LED2, LOW);  
    delay(500);  // Kratka pauza za treperenje LED2

    // Pošaljemo TRIG signal za HC-SR04
    digitalWrite(TRIG, LOW);
    delayMicroseconds(20000);  // Kratka pauza
    digitalWrite(TRIG, HIGH);  // Pošaljemo TRIG signal
    delayMicroseconds(10000);  // Kratka pauza
    digitalWrite(TRIG, LOW);

    Serial.print("TIPKA2 pritisnuta, broj pritisaka: ");
    Serial.println(i_BROJAC);

    Serial.println("Ultrazvučni senzor aktiviran!");

    // Resetiranje LED1
    digitalWrite(LED1, LOW);

    // Provjeri je li TIPKA1 pritisnuta
    if (b_PRITISNUT1) {
      i_BROJAC++;  // Povećaj broj pritisaka TIPKA1
      b_PRITISNUT1 = false;  // Resetiraj stanje TIPKA1
    }

    // Resetiraj broj pritisaka nakon 5 pritisaka
    if (i_BROJAC == 5) {
      i_BROJAC = 0;
      b_PRITISNUT2 = false;  // Resetiraj stanje TIPKA2
    }
  }

  // Ako TIPKA2 nije pritisnuta, LED2 i senzor neće treperiti
  if (!b_PRITISNUT2 && b_PRITISNUT1) {
    digitalWrite(LED2, LOW);  // Isključi LED2
    digitalWrite(LED1, HIGH);  // Uključi LED1
  }
}
