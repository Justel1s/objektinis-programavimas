#ifndef studentai_h
#define studentai_h
#include <bits/stdc++.h>

struct duomenys{
    std::string v, p;
    std::vector<int> pazymiai;
    int egzaminas;
    double galutinis, mediana;
};
void balo_skaiciavimas(duomenys&);
std::string generuoti_varda(int);
std::vector<int> generuoti_pazymius(int);

template <typename Container>
void failo_skaitymas(std::ifstream &, Container&);
void vardo_skaitymas(duomenys &);
void pazymio_skaitymas(duomenys &);
void balo_skaiciavimas(duomenys &);
bool rikiavimas_vardas(const duomenys &, const duomenys &);
bool rikiavimas_pavarde(const duomenys &, const duomenys &);
bool rikiavimas_galutinis(const duomenys &, const duomenys &);
bool rikiavimas_mediana(const duomenys &, const duomenys &);
void failo_generavimas(int, std::string);
void rusiavimas(std::vector<duomenys>&);
void paskutine(int, std::string);
void spausdinimas(std::vector<duomenys> &);

#endif