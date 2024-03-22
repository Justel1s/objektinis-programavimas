#include <bits/stdc++.h>
#include "studentai.h"
using namespace std;

int main() {
    srand(time(nullptr));
    vector<duomenys> D;

    int variantas;

    while (true) {
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus/pavardes, 4 - skaityti is failo, 5 - generuoti failus, 6 - baigti\n";
        if (!(cin >> variantas) || variantas < 1 || variantas > 6) {
            cout << "Netinkama ivestis\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (variantas == 5) {
            vector<int> sizes = {1000, 10000, 100000, 1000000};
            for (int size : sizes) {
                paskutine(size, "studentai" + to_string(size) + ".txt");
            }
            continue;
        }
        if (variantas == 6) break;
        
        duomenys laikinas;

        if (variantas == 1 || variantas == 2) {
            vardo_skaitymas(laikinas);
            if (variantas == 1) {
                pazymio_skaitymas(laikinas);
            } else {
                laikinas.pazymiai = generuoti_pazymius(rand() % 10);
                laikinas.egzaminas = rand() % 10;
            }
        } else if (variantas == 3) {
            laikinas.v = generuoti_varda(3 + rand() % 5);
            laikinas.p = generuoti_varda(3 + rand() % 10);
            laikinas.pazymiai = generuoti_pazymius(rand() % 10);
            laikinas.egzaminas = rand() % 10;
        }
        // else if (variantas == 4) {
        //     ifstream fd("studentai1000000.txt");
        //     if (!fd) {
        //         cout << "Failo skaitymo klaida\n";
        //         continue;
        //     }
        //     failo_skaitymas(fd, v);
        //     fd.close();
        //     break;
        // }
        balo_skaiciavimas(laikinas);
        D.push_back(laikinas);
    }
    rusiavimas(D);
    spausdinimas(D);
    return 0;
}
