#include <bits/stdc++.h>
#include "studentai.h"
using namespace std;

//Rikiavimas
bool compareByGalutinis(const double b, const duomenys &a) { return a.galutinis < b; }
bool compareByMediana(const double b, const duomenys &a) { return a.mediana < b; }
//Generavimas
string generuoti_varda(int ilgis) {
    string vardas;
    for (int i = 0; i < ilgis; i++) {
        if (i == 0)
            vardas += (char)(65 + rand() % 25);
        else
            vardas += (char)(97 + rand() % 25);
    }
    return vardas;
}
vector<int> generuoti_pazymius(int dydis) {
    vector<int> pazymiai(dydis);
    for (int i = 0; i < dydis; i++) {
        pazymiai[i] = rand() % 10;
    }
    return pazymiai;
}
void vardo_skaitymas(duomenys &s) {
    cout << "Irasykite studento varda\n";
    while (!(cin >> s.v)) {
        try {
            throw runtime_error("Netinkama ivestis");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Irasykite studento varda\n";
        }
    };
    cout << "Irasykite studento pavarde\n";
    while (!(cin >> s.p)) {
        try {
            throw runtime_error("Netinkama ivestis");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Irasykite studento pavarde\n";
        }
    };
    return;
}

void pazymio_skaitymas(duomenys &s) {
    while (true) {
        int kintamasis;
        cout << "Irasykite studento pazymi arba noredami uzbaigti iveskite -1\n";
        while (!(cin >> kintamasis) || kintamasis < 1 || kintamasis > 10) {
            if (kintamasis == -1) break;
            try {
                throw runtime_error("Netinkama ivestis");
            } catch (const runtime_error &e) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << e.what();
                cout << "Iveskite skaiciu nuo 1 iki 10\n";
            }
        }
        if (kintamasis == -1) break;
        s.pazymiai.push_back(kintamasis);
    }
    cout << "Irasykite studento egzamino pazymi\n";
    while (!(cin >> s.egzaminas) || s.egzaminas < 1 || s.egzaminas > 10) {
        try {
            throw runtime_error("Netinkama ivestis");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Iveskite skaiciu [1-10]\n";
        }
    }
    return;
}

void balo_skaiciavimas(duomenys &s) {
    if (s.pazymiai.size()) {
        int sum = accumulate(s.pazymiai.begin(), s.pazymiai.end(), 0);
        s.galutinis = 0.4 * sum / s.pazymiai.size() + 0.6 * s.egzaminas;
        sort(s.pazymiai.begin(), s.pazymiai.end());
        int vid = s.pazymiai.size() / 2;
        if (s.pazymiai.size() % 2) {
            s.mediana = s.pazymiai[vid];
        } else {
            s.mediana = (s.pazymiai[vid] + s.pazymiai[vid - 1]) / 2.0;
        }
        s.mediana = 0.4 * s.mediana + 0.6 * s.egzaminas;
    } else {
        s.galutinis = 0.6 * s.egzaminas;
        s.mediana = 0.6 * s.egzaminas;
    }
}
// Spausdinimas
void spausdinimas(vector<duomenys> &v) {
    stringstream spausdinimas;
    spausdinimas << left << setw(15) << "Pavarde" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while (bruksneliai--) spausdinimas << '-';
    spausdinimas << "\n";

    int vardoIlgis = 0, pavardesIlgis = 0;
    for (int i = 0; i < v.size(); i++) {
        vardoIlgis = max(vardoIlgis, (int)v[i].v.size());
        pavardesIlgis = max(pavardesIlgis, (int)v[i].p.size());
    }

    for (int i = 0; i < v.size(); i++) {
        spausdinimas << fixed << setprecision(2) << setw(pavardesIlgis + 5) << v[i].p << setw(vardoIlgis + 5) << v[i].v << setw(19) << v[i].galutinis << setw(20) << v[i].mediana << "\n";
    }
    cout << spausdinimas.rdbuf();
}

bool rikiavimas_vardas(const duomenys &a, const duomenys &b) { return (a.v > b.v); }
bool rikiavimas_pavarde(const duomenys &a, const duomenys &b) { return (a.p > b.p); }
bool rikiavimas_galutinis(const duomenys &a, const duomenys &b) { return (a.galutinis > b.galutinis); }
bool rikiavimas_mediana(const duomenys &a, const duomenys &b) { return (a.mediana > b.mediana); }

// Template
template <typename Container>
void failo_skaitymas(ifstream &fd, Container &v) {
    long long cnt = 0;
    string s;
    std::stringstream buffer;
    buffer << fd.rdbuf();
    if constexpr (std::is_same<Container, std::vector<duomenys>>::value) {
        std::stringstream::pos_type pos = buffer.tellg();
        while (!buffer.eof()) {
            getline(buffer, s);
            cnt++;
        }
        buffer.clear();
        buffer.seekg(pos, buffer.beg);
        v.reserve(cnt);
        cnt = 0;
    }
    while (getline(buffer, s)) {
        if (s == "") continue;
        if (cnt) {
            istringstream skaitymas(s);
            duomenys stud;
            skaitymas >> stud.v >> stud.p;
            int kintamasis;
            while (skaitymas >> kintamasis) {
                stud.pazymiai.push_back(kintamasis);
            }
            stud.egzaminas = stud.pazymiai.back();
            stud.pazymiai.pop_back();
            balo_skaiciavimas(stud);
            v.push_back(stud);
        }
        cnt++;
    }
}
// Visi duomenu tipai
template void failo_skaitymas<std::vector<duomenys>>(std::ifstream &, std::vector<duomenys> &);
template void failo_skaitymas<std::list<duomenys>>(std::ifstream &, std::list<duomenys> &);
template void failo_skaitymas<std::deque<duomenys>>(std::ifstream &, std::deque<duomenys> &);

void rusiavimas(vector<duomenys> &v) {
    cout << "1 - vardas, 2 - pavarde, 3 - galutinis vidurkis, 4 - galutinis mediana\n";
    int variantas;
    while (!(cin >> variantas) || variantas < 1 || variantas > 5) {
        try {
            throw runtime_error("Netinkama ivestis\n");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Netinkama ivestis\n";
            cout << "1 - vardas, 2 - pavarde, 3 - galutinis vidurkis, 4 - galutinis mediana\n";
        }
    }
    if (variantas == 1) sort(v.begin(), v.end(), rikiavimas_vardas);
    if (variantas == 2) sort(v.begin(), v.end(), rikiavimas_pavarde);
    if (variantas == 3) sort(v.begin(), v.end(), rikiavimas_galutinis);
    if (variantas == 4) sort(v.begin(), v.end(), rikiavimas_mediana);
    return;
}

void failo_generavimas(int dydis, string pavadinimas) {
    auto start = chrono::high_resolution_clock::now();
    stringstream buf;
    buf << left << setw(30) << "Vardas" << setw(30) << "Pavarde";
    for (int i = 1; i <= 10; i++) {
        buf << "ND" << setw(4) << i;
    }
    buf << "Egz.\n";
    for (int i = 1; i <= dydis; i++) {
        buf << "Vardas" << setw(24) << i << "Pavarde" << setw(23) << i;
        for (int j = 0; j < 11; j++) {
            buf << setw(6) << rand() % 10;
        }
        if (i != dydis) buf << "\n";
    }
    ofstream fr(pavadinimas);
    fr << buf.rdbuf();
    fr.close();
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Sugeneruotas " << pavadinimas << " failas per: " << diff.count() << " ms\n";
}
//Spausdinimas
template <typename Container>
void failo_spausdinimas(Container &v, string pavadinimas) {
    stringstream spausdinimas;
    // Spausdinimas
    spausdinimas << left << setw(15) << "Pavarde" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while (bruksneliai--) spausdinimas << '-';
    spausdinimas << "\n";

    int vardoIlgis = 0, pavardesIlgis = 0;
    for (auto &i : v) {
        vardoIlgis = max(vardoIlgis, (int)i.v.size());
        pavardesIlgis = max(pavardesIlgis, (int)i.p.size());
    }

    for (auto &i : v) {
        spausdinimas << fixed << setprecision(2) << setw(pavardesIlgis + 5) << i.p << setw(vardoIlgis + 5) << i.v << setw(19) << i.galutinis << setw(20) << i.mediana << "\n";
    }
    ofstream fr(pavadinimas);
    fr << spausdinimas.rdbuf();
    fr.close();
}
//Strategijos 
template <typename Container>
void Strategija1(Container &a, int kintamasis) {
    auto start = chrono::high_resolution_clock::now();

    typename Container::iterator vieta;
    if (kintamasis == 1)
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByMediana);

    Container b, c;

    b.insert(b.begin(), a.begin(), vieta);
    c.insert(c.begin(), vieta, a.end());

    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Strategija1 pirmunai ir vargsai per: " << diff.count() << " ms\n";
}

template <typename Container>
void Strategija2(Container &a, Container &b, int kintamasis) {
    auto start = chrono::high_resolution_clock::now();

    typename Container::iterator vieta;
    if (kintamasis == 1)
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByMediana);

    b.insert(b.begin(), vieta, a.end());
    a.erase(vieta, a.end());

    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Strategija2 pirmunai ir vargsai per: " << diff.count() << " ms\n";
}

template <typename Container>
void Strategija3(Container &a, Container &b, int kintamasis) {
    auto start = chrono::high_resolution_clock::now();

    typename Container::iterator vieta;
    if (kintamasis == 1)
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByMediana);
    std::copy(vieta, a.end(), std::back_inserter(b));
    a.erase(vieta, a.end());
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Strategija3 pirmunai ir vargsai per: " << diff.count() << " ms\n";
}

template <typename Container>
void Strategija4(Container &a, Container &b, int kintamasis) {
    auto start = chrono::high_resolution_clock::now();
    typename Container::iterator vieta;
    if (kintamasis == 1)
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByMediana);

    if constexpr (is_same<Container, list<duomenys>>::value) {
        b.splice(b.begin(), a, vieta, a.end());
    } else {
        b.assign(vieta, a.end());
        a.erase(vieta, a.end());
    }
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Strategija4 pirmunai ir vargsai per: " << diff.count() << " ms\n";
}
//Laiko skaiciavimas
template <typename Container>
void laiko_skaiciavimas(ifstream &fd) {
    auto visasLaikas = chrono::high_resolution_clock::now();
    auto start = chrono::high_resolution_clock::now();
    Container pirmunai, vargsai;
    failo_skaitymas(fd, pirmunai);
    fd.close();
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Failas perskaitytas per: " << diff.count() << " ms\n";
    auto rinkLaikas = chrono::high_resolution_clock::now();
    int kintamasis = 0;
    cout << "Rusiuoti pagal 1 - Galutinis vid., 2 - Galutinis med.\n";
    while (!(cin >> kintamasis) && kintamasis > 2 && kintamasis < 1) {
        try {
            throw runtime_error("Netinkama ivestis\n");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Rusiuoti pagal 1 - Galutinis vid., 2 - Galutinis med.\n";
        }
    }
    auto rinkLaikasPab = chrono::high_resolution_clock::now();
    auto rinkLaikasdiff = chrono::duration_cast<chrono::milliseconds>(rinkLaikasPab - rinkLaikas);

    start = chrono::high_resolution_clock::now();
    if constexpr (std::is_same<Container, std::list<duomenys>>::value) {
        if (kintamasis == 1)
            pirmunai.sort(rikiavimas_galutinis);
        else
            pirmunai.sort(rikiavimas_mediana);
    } else {
        if (kintamasis == 1)
            sort(pirmunai.begin(), pirmunai.end(), rikiavimas_galutinis);
        else
            sort(pirmunai.begin(), pirmunai.end(), rikiavimas_mediana);
    }

    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Surikiuoti studentai per: " << diff.count() << " ms\n";

    Strategija1(pirmunai, kintamasis);
    Strategija2(pirmunai, vargsai, kintamasis);
    Strategija3(pirmunai, vargsai, kintamasis);
    Strategija4(pirmunai, vargsai, kintamasis);

    start = chrono::high_resolution_clock::now();
    failo_spausdinimas(pirmunai, "pirmunai.txt");
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Isspausdintas pirmunu failas per: " << diff.count() << " ms\n";

    start = chrono::high_resolution_clock::now();
    failo_spausdinimas(vargsai, "vargsai.txt");
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Isspausdintas vargsu failas per: " << diff.count() << " ms\n";

    auto visasLaikasPab = chrono::high_resolution_clock::now();
    auto visasLaikasdiff = chrono::duration_cast<chrono::milliseconds>(visasLaikasPab - visasLaikas);
    cout << "Visas programos veikimo laikas: " << visasLaikasdiff.count() - rinkLaikasdiff.count() << " ms\n";
}
//Paskutinei daliai
void paskutine(int dydis, string pavadinimas) {
    cout << "\n" << pavadinimas.substr(0, pavadinimas.size() - 4) << "\n";

    failo_generavimas(dydis, pavadinimas);

    cout << "\nVector\n";
    ifstream fd(pavadinimas);
    laiko_skaiciavimas<vector<duomenys>>(fd);
    fd.close();

    cout << "\nList\n";
    fd.open(pavadinimas);
    laiko_skaiciavimas<list<duomenys>>(fd);
    fd.close();

    cout << "\nDeque\n";
    fd.open(pavadinimas);
    laiko_skaiciavimas<deque<duomenys>>(fd);
    fd.close();
    return;
}