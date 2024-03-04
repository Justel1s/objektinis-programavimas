#include <bits/stdc++.h>
#include "studentai.h"
using namespace std;
int main(){
    auto start = chrono::high_resolution_clock::now();
    vector<duomenys> D;
    int pasirinkimas;
    while(true){
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti iš failo, 5 - failu generavimas, 6 - testi darba" << endl;        
        while(!(cin>>pasirinkimas) || pasirinkimas < 1 || pasirinkimas > 6){
            try{
                throw runtime_error("Netinkama isvestis\n");
            }
            catch (const runtime_error &e){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << e.what();
                cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti iš failo, 5 - failu generavimas, 6 - testi darba" << endl;        
            }
        }
        if(pasirinkimas == 1) variantas1(D);
        if(pasirinkimas == 2) variantas2(D);
        if(pasirinkimas == 3) variantas3(D);
        if(pasirinkimas == 4) {
            auto start = chrono::high_resolution_clock::now();
            //Laiko skaiciavimo pradzia
            variantas4(D);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Laikas, kuri truko nuskaityti is failo: " << duration.count() << " milliseconds" << endl;
        }
        if(pasirinkimas == 5){
            int variantas;
            cout << "1 var. - studentai1000.txt\n2 var. - studentai10000.txt\n3 var. - studentai100000.txt\n4 var. - studentai1000000.txt\n5 var. - studentai10000000.txt\n";
            while(!(cin>>variantas) || variantas < 1 || variantas > 5){
                try{
                    throw runtime_error("Netinkama isvestis\n");
                }
                catch (const runtime_error &e){
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << e.what();
                    cout << "1 var. - studentai1000.txt\n2 var. - studentai10000.txt\n3 var. - studentai100000.txt\n4 var. - studentai1000000.txt\n5 var. - studentai10000000.txt\n";

                }
            }
            if(variantas == 1) generateFile("studentai1000.txt", 1000);
            if(variantas == 2) generateFile("studentai10000.txt", 10000);
            if(variantas == 3) generateFile("studentai100000.txt", 100000);
            if(variantas == 4) generateFile("studentai1000000.txt", 1000000);
            if(variantas == 5) generateFile("studentai10000000.txt", 10000000);
        }
        if(pasirinkimas == 6) break;
    }
    while(true){
        cout << "Rikiavimas pagal: 1 - varda, 2 - pavarde, 3 - galutini, 4 - mediana" << endl;
        while(!(cin>>pasirinkimas) || pasirinkimas < 1 || pasirinkimas > 4){
            try{
                throw runtime_error("Netinkama ivestis\n");
            }
            catch (const runtime_error &e){
                cin.clear();
                cout << e.what();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Rikiavimas pagal: 1 - varda, 2 - pavarde, 3 - galutini, 4 - mediana" << endl;
            }
        }
        pasirinkimas = 1;
        if(pasirinkimas == 1) sort(D.begin(), D.end(), palyginimas1);
        if(pasirinkimas == 2) sort(D.begin(), D.end(), palyginimas2);
        if(pasirinkimas == 3) sort(D.begin(), D.end(), palyginimas3);
        if(pasirinkimas == 4) sort(D.begin(), D.end(), palyginimas4);
        break;
    }
    for(int i = 0; i < D.size(); i++){
        if(i == 0){
            cout << "Pavardė        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        cout << left << setw(15) << D[i].p << left << setw(15) << D[i].v << left << setw(19) << setprecision(2) << fixed << D[i].galutinis << setprecision(2) << fixed << D[i].mediana << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Programa uztruko: " << duration.count() << " millisekundes" << endl;
    return 0;
}
