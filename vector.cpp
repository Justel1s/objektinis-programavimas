#include <bits/stdc++.h>
#include "student.h"

using namespace std;

int main(){
    auto start = chrono::high_resolution_clock::now();

    vector<duomenys> D;
    int pasirinkimas;
    while(true){
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti iš failo, 5 - testi darba" << endl;        
        if(cin>>pasirinkimas){
            if(pasirinkimas == 1) variantas1(D);
            if(pasirinkimas == 2) variantas2(D);
            if(pasirinkimas == 3) variantas3(D);
            if(pasirinkimas == 4) {
                auto start = chrono::high_resolution_clock::now();
                //Laiko skaiciavimo pradzia
                variantas4(D);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
                cout << "Time taken to read from file: " << duration.count() << " milliseconds" << endl;
            }
            if(pasirinkimas == 5) break;
        }
        else {cout << "KLAIDA" << endl; break;}
    }
    cout << "Rikiavimas pagal: 1 - varda, 2 - pavarde, 3 - galutini, 4 - mediana" << endl;
    // if(cin>>pasirinkimas){
            pasirinkimas = 1;
            if(pasirinkimas == 1) sort(D.begin(), D.end(), palyginimas1);
            if(pasirinkimas == 2) sort(D.begin(), D.end(), palyginimas2);
            if(pasirinkimas == 3) sort(D.begin(), D.end(), palyginimas3);
            if(pasirinkimas == 4) sort(D.begin(), D.end(), palyginimas4);
        // }
    for(int i = 0; i < D.size(); i++){
        if(i == 0){
            cout << "Pavardė        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        cout << left << setw(15) << D[i].p << left << setw(15) << D[i].v << left << setw(19) << setprecision(2) << fixed << D[i].galutinis << setprecision(2) << fixed << D[i].mediana << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken by program is : " << duration.count() << " milliseconds" << endl;
    return 0;
}
