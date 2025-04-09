### 1. Inicijalni zadatak
U ovome zadatku potrebno je prikazati korištenje sleep mode funkcija na mikrokontroleru ESP32.

### 2. Opis projekta
U ovom projektu je implementiran sustav za upravljanje energijom koristeći sleep modeove na mikrokontroleru ESP32. 
#define LED

#define TIPKALO
Projekt je napravljen tako da kada se pokrene program LED dioda (spojena na pin 32) se upali te nakon 5 sekundi sustav prelazi u energetski efikasni sleep mode.
Sustav ostaje u sleep mode sve dok se ne pritisne tipkalo (spojeno na pin 23) ili dok ne prođe 10 sekundi od početka sleep moda.

### 3. Funkcionalnosti

#### Opis funkcionalnosti projekta

| ID    | Opis funkcionalnog zahtjeva            |
|-------|----------------------------------------|
| FR-1  | Upravljanje LED (pin 32)               | 
| FR-2  | Detekcija  tipkala (pin 23)            |
| FR-3  | Praćenje stanja sustava preko Serijala |
| FR-4  | Period aktivnosti LED od 5 sekundi     |
| FR-5  | Indikacija stanja (LED ON/OFF)         | 
| FR-6  | Automatsko buđenje LED nakon 10 sekundi    | 
| FR-7  | Reset stanja nakon buđenja             |
| FR-8  | Praćenje potrošnje struje              | 
| FR-9  | Funkcionalnost sleep moda              | 
| FR-10 | Ručno buđenje (prekid tipkala)         | 
| FR-11 | Debounce mehanizam                     | 


### 4. Što je naučeno kroz projekt
 - Korištenje prekida na ESP32
 - Korištenje sleep moda u sustav
 - Korištenje prekida za izlazak iz sleep mode-a
 - Korištenje unutarnjeg brojača (tajmer) kako bi se se moglo pratiti vrijeme u sleep modu

[Link za projekt] (https://wokwi.com/projects/427795277435780097)


