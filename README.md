# Trečias projektas #
# Pirmoji užduotis v3.0 #
Sukurtas programos studentų galutiniams balams skaičiuoti diegimo failas - setup.exe

### setup.exe naudojimas
- Atsiųskite setup.exe ar .msi failą
- Sekite Setup Wizard nurodymus, jums reikės nurodyti kur instaliuoti programą
- Sparčiasias programėlės nuorodas rasite ant darbalaukio ir programų meniu

### Naudojimas:
Paleidus programą bus prašoma:
- Pasirinkti ar norite generuoti failą
Jei pasirenkate generuoti failą prašoma:
- Įvesti kiek pažymių generuoti studentams
- Įvesti studentų skaičių 
Jei pasirenkate negeneruoti failo prašoma:
- Įvesti kiek pažymių turės studentas
- Įvesti studento varda ir pavarde
- Pasirinkti ar atsitiktinai sugeneruoti pažymius
    - Suvesti norimus pažymius baigus įvedant '0'bei įvesti egzamino rezutatą
    - Įvesti norimo sugeneruoti pažymių skaičių

### Reikalavimai įvedimui:
- Įvedant studentų skaičių, pažymių skaičių, egzamino balą nepriimamos raidės ar simbolių reikšmės
- Nepriimami kiti atsakymai nei pateikia dviejų pasirinkimų klausimas 

# Antras projektas #
# Pirmoji užduotis v1.1 #
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;

1. Programos realizaciją (versiją v1.0) pakeista taip, kad vietoje sukurtos data structūros jos pagrindu sukurta class'ę data.
2. Struct ir Class realizacijos sparta (palyginimas):

| TIPAS  | KIEKIS   | F! NUSKAITYMAS IR SKAIČIAVIMAS | SUSKIRSTYMAS/RŪŠIAVIMAS Į VEKTORIUS | IŠVEDIMAS  |
|--------|----------|--------------------------------|-------------------------------------|------------|
| struct | 100000   | 0.051365 s                     | 0.0172147 s                         | 0.534344 s |
|        | 1000000  | 1.17018 s                      | 0.540851 s                          | 1.1299 s   |
|        | 10000000 | 32.5802 s                      | 15.0002 s                           | 19.21 s    |
|        |          |                                |                                     |            |
| class  | 100000   | 0.0855839 s                    | 0.0148084 s                         | 0.29665 s  |
|        | 1000000  | 1.0516 s                       | 0.496612 s                          | 2.37164 s  |
|        | 10000000 | 35.3514 s                      | 7.4089 s                            | 29.1266 s  |

3. Atlikta eksperimentinė analizė priklausomai nuo kompiliatoriaus optimizavimo lygio (palyginimas):

| FLAG'AS | KIEKIS   | NUSKAITYMAS | IŠSKIRSTYMAS | IŠVEDIMAS  |
|---------|----------|-------------|--------------|------------|
| 01      | 100000   | 0.279883 s  | 0.0328482 s  | 0.20165 s  |
|         | 1000000  | 3.5737 s    | 0.39092 s    | 2.94953 s  |
|         | 10000000 | 27.6266 s   | 9.56357 s    | 21.6099 s  |
|         |          |             |              |            |
| 02      | 100000   | 0.317432 s  | 0.038894 s   | 0.253594 s |
|         | 1000000  | 3.45165 s   | 0.372269 s   | 2.62386 s  |
|         | 10000000 | 31.2177 s   | 7.4315 s     | 22.4425 s  |
|         |          |             |              |            |
| 03      | 100000   | 0.370935 s  | 0.0354623 s  | 0.26057 s  |
|         | 1000000  | 3.45865 s   | 0.371608 s   | 2.7613 s   |
|         | 10000000 | 28.6496 s   | 8.76929 s    | 25.9495 s  |

# Antroji užduotis v1.2 #
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Papildyta: copy constructor, copy assignment operator taip pat destructor (bet 'užkomentuota' dėl netikslumų)

# Trečioji užduotis v1.5 #
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1.Vietoje turimos vienos Data klasės sukurtos dvi: bazinė klasė - Student, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinė (derived) klasė - Data.
2.Student bazinė klasė - abstrakčioji klasė,

# Ketvirtoji užduotis v2.0 #
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1.Sukurkita dokumentacija panaudojant Doxygen 1.5 projekto pagrindu.

# Pirmas projektas #
# Studentų galutinio balo skaičiuoklė v0.1 #
Programa skirta apskaičiuoti kiekvieno studento galutinį balą panaudojant vidukį/medianą.

- - - 
## Veikimo principas ##
1. Vartotojas įvedą studento vardą ir pavardę. Studentų kiekis nėra ribojamas. Suvedus reikiamus duomenis apie studentą, vartotojas gauna užkalausą: "Ar norite ivesti dar vieno studento duomenis: [y/n]";
2. Vartotojas turi pasirinkimą namų darbų pažymius ir egzamino rezultatą suvesti rankiniu būdų arba sugeneruoti atsitiktinai. Užklausa:  "Ar norite atsitiktinai generuoti pazymius? [y/n]";
  2.2 Jei pazymius vartotojas veda pats. Vartotojas įvedą egzamino pažymį ir taip pat iki 10 namų darbų pažymių;
3. Galutinis pažymys yra apsakičiaujamas tiek su pažymių vidurkiu, tiek ir su mediana;

Programa išvedą studentų vardus ir pavardes bei studentų galutinius pažymius suskaičiuotus su pažymiu vidurkiu ir mediana.

# Antroji užduotis v0.2 #
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas.

- - - 
## Veikimo principas ##
1. v0.1 buvo papildyta, tuo kad dabar galima duomenis ne tik įvesti bet ir nuskaityti iš failo. Vartotojui suteikiamas pasirinkimas.
2. Studentai yra surūšiuojami pagal vardus.
3. Funkcijos, nauji duomenų tipai buvo perkelti į antraštinius (header) failus, bei sukurti trys nauji .cpp failai.
4. Minimaliai panaudotas išimčių valdymas.

# Trečioji užduotis v0.3 #
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;

- - - 
## Veikimo principas ##
1. Atsirado nauja funkcija Failų generacija. Vartotojas pasirenka kiek studentų ir kiek studentų pažymių bus.
2. Studentai yra surušiuojami į dvi grupes; vargšiukai ( x>5 ) ir gudročiai ( x<5 ).
3. Studentai atspausdinami į du skirtingus failus.

# Ketvirtoji užduotis v0.4 #

- - - 
## Veikimo principas ##
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Buvo sukurtos dvi atskiros programos su dviejais skirtingais konteineriais: vector, list.
2. Buvo atlikti laiko matavymai šių dvieju konteinerių spartumo.
3. Laiko matavimai:

|        |              | 1000         | 10000        | 100000      | 1000000    |
|--------|--------------|--------------|--------------|-------------|------------|
| Vector | Nuskaitymas  | 0.00071426 s | 0.0046599 s  | 0.0524893 s | 0.833517 s |
|        | Isskirstymas | 0.00017619 s | 0.00187795   | 0.01768 s   | 0.442079 s |
| List   | Nuskaitymas  | 0.00068584 s | 0.00538527 s | 0.0978146 s | 1.08923 s  |
|        | Isskirstymas | 0.00017354 s | 0.00249038 s | 0.018878 s  | 0.331265 s |

Analizė: 
Greičiausias suskirstymas studentu į skirtingus konteinerius - vector;
Greičiausias failo nuskaitymas ir suskaičiavimas - List;

# Penktoji užduotis v1.0 #

- - - 
## Veikimo principas ##
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Buvo ištestuotos 2 strategijos - vector, list konteineriams

| Konteineris | Kiekis  | 1 strategija  | 2 strategija |
|-------------|---------|---------------|--------------|
| Vector      | 1000    | 0.000167511 s | 0.00385861 s |
|             | 10000   | 0.00183247 s  | 0.745063 s   |
|             | 100000  | 0.0228837 s   | 82.761 s     |
|             | 1000000 | 0.511233 s    |       -      |
|             |         |               |              |
| List        | 1000    | 0.00014788 s  | 0.0001256 s  |
|             | 10000   | 0.00150157 s  | 0.00136816 s |
|             | 100000  | 0.0188806 s   | 0.011321 s   |
|             | 1000000 | 0.485813 s    | 0.141843 s   |

Analizė:
1 strategija greitesnė - List konteineriu;
2 strategija greitesnė - List konteineriu;
2. Pritaikyti algoritmai studentų dalijimo procedūrai paspartinti (vector - konteinerio) - pritaikytas remove_if algoritmas

| Strategija    | Kiekis  | Studentu iskirstymas i viena varksiuku vektoriu |
|---------------|---------|-------------------------------------------------|
|               |         |                                                 |
| II strategija | 1000    | 0.00385861 s                                    |
| erase         | 10000   | 0.745063 s                                      |
|               | 100000  | 82.761 s                                        |
|               | 1000000 | -                                               |
|               |         |                                                 |
| Algoritmas    | 1000    | 0.00019944 s                                    |
| remove_if     | 10000   | 0.00139885 s                                    |
|               | 100000  | 0.0148008 s                                     |
|               | 1000000 | 0.322558 s                                      |

II strategija pagreitėjo ir optimizavosi panaudojus remove_if algoritmą.

### Versijos ###
*[v0.1](https://github.com/Kamile11/Project-1.git) - pirminė programos versija.
*[v0.2] 
*[v0.3]
*[v0.4]
*[v1.0]
*[v1.1]
*[v1.2]
*[v1.5]
*[v2.0]
*[v3.0]
