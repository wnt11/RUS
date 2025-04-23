# RUS--Nadzor i praćenje spremnika smeća
## Opis sustava
Sustav za nadzor i praćenje spremnika smeća je ugradbeni sustav razvijen na platformi Arduino. Sustav je napravljen u svrhu provjere napunjenosti spremnika smeća te upozorava korisnika ako je kkod kuće (spojen je na BT) ako je u spremniku ostalo malo slobodnog mjesta. U svrhu projekta napravljena je poesbna aplikacija sa kojom se preko BT šalju signali mikrokontroleru te se time postiže minimalna potrošnja energije.
...

## Slika sustava
![nadzor spremnika za smeće](https://wokwi.com/projects/new/arduino-uno)

## Cilj projekta
Cilj projekta je razviti siguran, pouzdan i lako implementiran sustav za nadzor i praćenej spremnika smeća.
###  Funkcionalnosti

#### Opis funkcionalnosti projekta

| ID    | Opis funkcionalnog zahtjeva                |
|-------|--------------------------------------------|
| FR-1  | Upravljanje LED (na samo mikrkontroelru)   | 
| FR-2  | Detekcija  tipkala (pin 8)                 |
| FR-3  | Praćenje stanja sustava preko Serijala     |
| FR-4  | Primanje podataka preko BT                 |
| FR-5  | Mjerenje udaljenosti senzorom	             |
| FR-6  | Detekcija prisutnosti vlasnika preko BT    |
| FR-7  | Reset stanja preko BT                      |

## Potencijalna korist projekta
•	Mogućnost praćenja napunjenosti spremnika smeća
•	Prima podatke sa mobilne aplikacije
•	Vizualna upozorenja

## Postojeća slična rješenja
Na tržištu postoje komercijalni spremnici za smeće koji u sebi imaju mnoge mogućnosti, a jedna od nnjih je i praćenje količine napunjenosti

## Mogućnost prilagodbe rješenja
Sustav se u budućnosti može nadograditi dodavanjem:
•	LCD-a te ispisom na isti
•	Alarmnim sustavom koji bi se upalio kada se dosegne odeređena razina
•	Wi-Fi povezivosti te dostupnost informacija na cloudu
## Opseg projektnog zadatka
Projekt uključuje:
•	Razvoj softvera za Arduino Uno
•	Dizajn i implementaciju elektroničkih komponenti
•	Testiranje sigurnosnih aspekata sustava
## Moguće nadogradnje
•	Više korisnika jednosg sustvaa
•	Npajanje preko solarnih modula
•	Integracija sa sigurnosnim alarmom<br>
•	IoT povezivost za nadzor putem interneta<br>

## Dijagram aktivnosti (UML)
1.	Početak (ultrazvučni senzor mjeri udaljenost do kraj kante ili smeća unutar spremnika)
2.	Sustav provjerava je li tipkalo pritisnuto
   o	Ako je cijeli sustav će stati na 10s
   o	Ako nije sustav će nastaviti sa radom
4.	Sustav provjerava kolika je udaljenost ultrazvučnog senzora od smeća
o	Ako je udaljenost veća od 20cm → sustav će nastaviti mjeriti udaljenost
o	Ako je udaljenost manja od 20cm → sustav će nastaviti mjeriti udaljenost i upalit će se LED 
o	Ako je udaljenost manja od 10cm → sustav će nastaviti mjeriti udaljenost i krenut će treperiti LED 
5.	Prikaz statusa na LCD ekranu<br>

## Plan ispitivanja
•	Testiranje udaljenosti od ultrazvučnog senzora
•	Provjera rada LED-ice
•	Testiranje ispisa u serial portu
•	Testiranje HC-05 Bluetooth modula
## Shema sustava
Električna shema sustava uključuje povezivanje Arduino Uno mikrokontrolera, HC-04 ultrazvučnog senzora, tipkala i HC-05 Bluetooth modula.
## Dokumentirani kôd
Sav kôd će biti detaljno komentiran, s objašnjenjem funkcija, ulaznih i izlaznih parametara te glavnih dijelova sustava. To će omogućiti laku prilagodbu i nadogradnju sustava.

