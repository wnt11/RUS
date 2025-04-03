### 1. Opis zadatka

U ovome zadatku treba napraviti sustav koji koristi prekide za obradu ulaznih signala s tipkala i mjerača udaljenosti te generira vizualne indikacije pomoću LED dioda.

### 2. Opis projekta

Projekt je napravljen tako da svaki pritisak gumba pokreće prekid.

Ovaj projekt implementira upravljanje prekidima pomoću mikrokontrolera i tipkala

Glavni ciljevi su detekcija prekida, njihova obrada prema prioritetima i vizualizacija statusa pomoću LED-ica.

Projekt je koristan za učenje rada s prekidima, senzorima i serijskom komunikacijom te može poslužiti kao temelj za složenije sustave kod priroritizitanja u ugrađenim sustavima.
Prioriteti su napravljeni da budu prikazani pomoću led dioda:

#define LED2 // Crvena (visoki prioritet)

#define LED1 // Žuta (niski prioritet)

###3. Funkcionalnosti
ID 	Opis funkcionalnosti
FR-1 	Upravljanje LED-icama: Crvena (INT0), Žuta (INT1), Zelena (INT2), Plava (senzor), Bijela (timer).
FR-2 	Detekcija pritiska na tipkala (INT0, INT1, INT2) i generiranje prekida.
FR-3 	Mjerenje udaljenosti pomoću HC-SR04 senzora i generiranje prekida ako je udaljenost manja od 100 cm.
FR-4 	Konfiguracija Timer1 za generiranje prekida svake sekunde (najviši prioritet).
FR-5 	Obrada prekida prema prioritetima: Timer1 > INT0 > INT1 > INT2 > senzor udaljenosti.
FR-6 	Vizualizacija aktivnih prekida pomoću odgovarajućih LED-ica.
FR-7 	Debounce mehanizam za tipkala kako bi se izbjeglo višestruko okidanje prekida.
FR-8 	Serial komunikacija za ispisivanje poruka o aktivnim prekidima.
FR-9 	Automatsko gašenje svih LED-ica prilikom aktivacije prekida višeg prioriteta.
FR-10 	Bljeskajuća LED-ica (plava) kao indikacija alarmnog stanja zbog blizine predmeta.
FR-11 	Testiranje istovremenog okidanja svih prekida i provjera hijerarhije prioriteta.
4. Što sam naučio radeći ovaj projekt
- Integriranje prekida na Arduino MEGA
- Dodavanje prioriteta prekidima
- Korištenje millis() naredbe umjesto delay()
- Upravljanje više prekida u jednome trenutku
- Debounce mehanizam protiv grešaka
### Naslov 3

*Kurziv* ili _Kurziv_
**Podebljano** ili __Podebljano__

- Neuređena lista
1. Uređena lista

[Link](https://wokwi.com/projects/427255141919498241)
