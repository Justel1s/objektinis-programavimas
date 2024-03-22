# Projekto README.md

## Aprašymas

Programa skirta skaičiuoti galutinį balą pagal įvestus duomenis.

Programa pakeista pagal programavimo standartus. Sudarytas daugiafailis projektas, patobulintas algoritmais randantis klaidas.

Programa naudoja kelis konteinerių tipus apskaičiuoti veikimo spartą su skirtingais duomenų tipais.

## Testavimo sistemos parametrai

- **CPU**: 5th Gen Intel(R) Core(TM) i5-8365U 1.60GHz
- **RAM**: 16GB - DDR4 - 2666MHz
- **HDD**: SSD - 236GB

# Spartos analizės

## Spartos analizė be papildomų algoritmų

## Programos testavimo laikai (5 kartų vidurkis)

#### Vector
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 10 ms | 0 ms | 0 ms | 30 ms |
| studentai10000 | 91 ms | 20 ms | 0 ms | 163 ms |
| studentai100000 | 846 ms | 342 ms | 35 ms | 2039 ms |
| studentai1000000 | 10024 ms | 5516 ms | 342 ms | 16202 ms |
| studentai10000000 | 162431 ms | 72118 ms | 13353 ms | 320132 ms |
#### List
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 10 ms | 0 ms | 0 ms | 40 ms |
| studentai10000 | 90 ms | 20 ms | 0 ms | 159 ms |
| studentai100000 | 964 ms | 282 ms | 32 ms | 1769 ms |
| studentai1000000 | 10553 ms | 3468 ms | 375 ms | 16227 ms |
| studentai10000000 | 130205 ms | 34716 ms | 3993 ms | 224437 ms |

#### Deque
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 17 ms | 2 ms | 0 ms | 19 ms |
| studentai10000 | 94 ms | 35 ms | 1 ms | 170 ms |
| studentai100000 | 946 ms | 430 ms | 35 ms | 1962 ms |
| studentai1000000 | 14444 ms | 6779 ms | 406 ms | 20012 ms |
| studentai10000000 | 102309 ms | 81516 ms | 4702 ms | 203908 ms |

## Skirstymo strategijų testavimo laikai (5 kartų vidurkis)

#### Vector
|  | Strategija 1 | Strategija 2 | Strategija 3 | Originali strategija |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 0 ms | 0 ms | 0 ms | 0 ms |
| studentai10000 | 9 ms | 0 ms | 1 ms | 0 ms |
| studentai100000 | 59 ms | 51 ms | 49 ms | 38 ms |
| studentai1000000 | 674 ms | 456 ms | 592 ms | 432 ms |

#### List
|  | Strategija 1 | Strategija 2 | Strategija 3 | Originali strategija |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 0 ms | 0 ms | 0 ms | 0 ms |
| studentai10000 | 10 ms | 1 ms | 0 ms | 0 ms |
| studentai100000 | 142 ms | 110 ms | 110 ms | 42 ms |
| studentai1000000 | 1498 ms | 1188 ms | 1145 ms | 375 ms |

#### Deque
|  | Strategija 1 | Strategija 2 | Strategija 3 | Originali strategija |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 0 ms | 0 ms | 0 ms | 0 ms |
| studentai10000 | 8 ms | 0 ms | 0 ms | 3 ms |
| studentai100000 | 67 ms | 52 ms | 59 ms | 48 ms |
| studentai1000000 | 663 ms | 493 ms | 502 ms | 496 ms |

## Funkcionalumas

- Įvedimo langas, kuriame vartotojas įveda studento vardą, pavardę, namų darbų pažymius ir egzamino rezultatą.
- Galutinio balo skaičiavimas pagal vidurkį ar medianą.
- Išvedimo langas, kuriame pateikiami studentų galutiniai balai.

# Releasai ir paleidimas

## Releasų istorija

- **V.pradine**: Sukurta preliminari programa, kurioje vartotojui įvedus studentų kiekį ir studentų duomenis (vardą, pavardę, pažymius) apskaičiuoja ir atspausdina studento duomenis su galutiniu rezultatu ir mediana. 
- **V0.1**: Programa papildyta taip, kad iš anksto nėra žinomas nei namų darbų kiekis, nei mokinių. Pridėta galimybė, jog mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai.
- **V0.2**: Pridėta galimybė nuskaityti duomenis iš failo ir patobulintas atspausdinimo metodas.
- **V0.3**: Struktūros perkeltos į atraštinius failus, o funkcijos į atskirą funkcijų failą. Pridėtas išimčių valdymas.
- **V0.4**: Sukurta failų generatoriaus funkcija. Studentai surūšiuojami į dvi kategorijas pagal pažymius ir išvedami į du naujus failus. Atlikta programos veikimo greičio analizė.
- **V1.0**: Atliktas konteinerių testavimas su vector, list ir deque konteineriais. Atliktas konteinerių skaidymo į dvi dalis testavimas. 

## Paleidimas

### Programos, kurias reik turėt

- [MinGW]
- [CMake]
- [Visual Studio Code]


### Instrukcija

1. Atsisiųskite programos "source code" iš repozitorijos.
2. Naviguokite į atsisiųstą programos aplanką naudodami terminalą.
3. Įvykdykite komandą "make".
4. Paleiskite programą terminale naudodami komandą ./vector.exe (Windows) 