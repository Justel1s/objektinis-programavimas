#include "studentai.h"
#include <bits/stdc++.h>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 10);
//Failu generavimas
void generateFile(const string& failoPavadinimas, int kiekis) {
    ofstream fr(failoPavadinimas);


    if (fr.is_open()) {
        int nd = dis(gen);
        fr << setw(40) << left << "Vardas" << setw(40) << left << "Pavarde";
        for (int i = 0; i < nd; i++) {
            fr << setw(20) << left << "ND" + to_string(i);
        }
        fr << setw(10) << left << "Egz" << endl;
        for (int i = 0; i < kiekis; ++i) {
            fr << setw(40) << left << "Vardas" + to_string(i + 1) << setw(40) << left << "Pavarde" + to_string(i + 1);
            for (int j = 0; j <= nd; j++) {
                fr << setw(20) << left << to_string(dis(gen));
            }
            fr << endl;
        }
        fr.close();
        cout << "Sugeneruotas failas: " << failoPavadinimas << endl;
    }   else {
        cout << "Klaida: " << failoPavadinimas << endl;
    }
}
//Rikiavimas
void rikiavimas(vector<duomenys> &D){
    auto start = std::chrono::high_resolution_clock::now();
    vector<duomenys> blog;
    vector<duomenys> geri;
    for(int i = 0; i < D.size(); i++){
        if(D[i].galutinis < 5) blog.push_back(D[i]);
        if(D[i].galutinis > 4) geri.push_back(D[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Failo skirstymo laikas: " << duration.count() << " ms" << std::endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    ofstream fr1("blogi.txt");
    ofstream fr2("geri.txt");
    fr1 << "Pavardė        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
    fr1 << "-----------------------------------------------------------------" << endl;
    for(int i = 0; i < blog.size(); i++){
        fr1 << left << setw(15) << blog[i].p << left << setw(15) << blog[i].v << left << setw(19) << setprecision(2) << fixed << blog[i].galutinis << setprecision(2) << fixed << blog[i].mediana << endl;
    }
    fr2 << "Pavardė        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
    fr2 << "-----------------------------------------------------------------" << endl;
    for(int i = 0; i < geri.size(); i++){
        fr2 << left << setw(15) << geri[i].p << left << setw(15) << geri[i].v << left << setw(19) << setprecision(2) << fixed << geri[i].galutinis << setprecision(2) << fixed << geri[i].mediana << endl;
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "Failo irasymo laikas: " << duration.count() << " ms" << std::endl;
    
}
//Pagalbines funkcijos
void randomBalai(int dydis, duomenys &X){
    vector<int> paz(dydis);
    for(int i = 0; i < dydis; i++){
        paz[i] = 1 + rand()%9;
        X.nd.push_back(paz[i]);
    }
}
string randomVardai(int dydis){
    string vardas;
    for(int i = 0; i < dydis; i++){
        if(i==0) vardas += (char)(65 + rand() % 25);
        else vardas += (char)(97 + rand() % 25);
    }
    return vardas;
}
//1 varianto algoritmas
void variantas1(vector<duomenys> &D){
    while(true){
        duomenys X;
        cout << "Iveskite pavarde: ";
        while(!(cin >> X.p)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        while(!(cin>>X.p)){
            try{
                throw runtime_error("Netinkama isvestis\n");
            }
            catch (const runtime_error &e){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << e.what();
                cout << "Iveskite pavarde: ";            
            }
        }
        cout << "Iveskite varda: ";
        if(!(cin >> X.v)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        bool nulis = false;
        while(true){
            int x;
            if(nulis) cout << "Iveskite pazymi, o jei norite baigti - 0: ";
            else cout << "Iveskite pazymi: ";
            if (!(cin >> x)) {
                cout << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Klaida: Prasome ivesti skaiciu" << endl;
                continue;
            }
            if (x == 0){
                if(!nulis){
                    cout << "Bent viena pazymi reikia tureti!" << endl;
                    continue;
                }
                break;
            }
            if (x < 1 || x > 10) {
                cout << "Klaida: Ivertinimas turi buti tarp 1 ir 10" << endl;
                continue;
            }
            X.nd.push_back(x);
            if(!nulis) nulis = true;
        }
        while(true){
            cout << "Iveskite egzamino pazymi: ";
            if (!(cin >> X.egz)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Klaida: Prasome ivesti skaiciu" << endl;
                continue;
            }
            if (X.egz < 1 || X.egz > 10) {
                cout << "Klaida: Ivertinimas turi buti tarp 1 ir 10" << endl;
                continue;
            }
            else break;
            
        }
        //Vidurkis
        double vidurkis = accumulate(X.nd.begin(), X.nd.end(), 0.0) / X.nd.size();
        X.galutinis = 0.4 * vidurkis + 0.6 * X.egz;
        //Mediana
        X.nd.push_back(X.egz);
        sort(X.nd.begin(), X.nd.end());
        int vidurys = X.nd.size()/2;
        
        if(X.nd.size()%2) X.mediana = X.nd[vidurys];
        else X.mediana = (X.nd[vidurys] + X.nd[vidurys-1] / 2.0);
        //Viska sudeda i D
        D.push_back(X);
        break;
    }
}
//2 varianto algoritmas
void variantas2(vector<duomenys> &D){
    while(true){
        duomenys X;
        cout << "Iveskite pavarde: ";
        if(!(cin >> X.p)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cout << "Iveskite varda: ";
        if(!(cin >> X.v)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        randomBalai(1 + rand()%9, X);
        X.egz = rand()%10;
        //Vidurkis
        double vidurkis = accumulate(X.nd.begin(), X.nd.end(), 0.0) / X.nd.size();;
        X.galutinis = 0.4 * vidurkis + 0.6 * X.egz;
        //Mediana
        X.nd.push_back(X.egz);
        sort(X.nd.begin(), X.nd.end());
        int vidurys = X.nd.size()/2;
        if(X.nd.size()%2) X.mediana = X.nd[vidurys];
        else X.mediana = (X.nd[vidurys] + X.nd[vidurys-1] / 2.0);
        //Viska sudeda i D
        D.push_back(X);
        break;
    }
}
//3 varianto algoritmas
void variantas3(vector<duomenys> &D){
    while(true){
        duomenys X;
        int random = rand() % 10;
        X.p = randomVardai(random);
        X.v = randomVardai(random);
        randomBalai(1 + rand()%9, X);
        X.egz = rand()%10;
        //Vidurkis
        double vidurkis = accumulate(X.nd.begin(), X.nd.end(), 0.0) / X.nd.size();;
        X.galutinis = 0.4 * vidurkis + 0.6 * X.egz;
        //Mediana
        X.nd.push_back(X.egz);
        sort(X.nd.begin(), X.nd.end());
        int vidurys = X.nd.size()/2;
        if(X.nd.size()%2) X.mediana = X.nd[vidurys];
        else X.mediana = (X.nd[vidurys] + X.nd[vidurys-1] / 2.0);
        //Viska sudeda i D
        D.push_back(X);
        break;
    }
}
//4 varianto algoritmas
void variantas4(vector<duomenys> &D, string failas){
    try{
        ifstream fd(failas);
        if(!fd.is_open()){
            throw ios_base::failure("Failas neatidarytas\n");
        }
    }
    catch(const ios_base::failure &e){
        cout << e.what();
    }
    ifstream fd(failas);
    string kiekis, nereikalinga;
    int ilgis = 0;
    fd >> nereikalinga >> nereikalinga;
    while(true){
        fd >> kiekis;
        if(isdigit(kiekis[2])) ilgis++;
        else break;
    }
    while (true){
        duomenys X;
        fd >> X.v;
        if(X.v.empty())
            break;
        fd >> X.p;
        for (int i = 0; i < ilgis; i++){
            int x;
            fd >> x;
            X.nd.push_back(x);
        }
        fd >> X.egz;
        //Vidurkis
        double vidurkis = accumulate(X.nd.begin(), X.nd.end(), 0.0) / X.nd.size();;
        X.galutinis = 0.4 * vidurkis + 0.6 * X.egz;
        //Mediana
        X.nd.push_back(X.egz);
        sort(X.nd.begin(), X.nd.end());
        int vidurys = X.nd.size()/2;
        if(X.nd.size()%2) X.mediana = X.nd[vidurys];
        else X.mediana = (X.nd[vidurys] + X.nd[vidurys-1]) / 2.0;
        //Viska sudeda i D
        D.push_back(X);
    }
    fd.close();
}
//Palyginimo funckijos
bool palyginimas1(const duomenys& a, const duomenys& b){
    return a.v < b.v;
}

bool palyginimas2(const duomenys& a, const duomenys& b){
    return a.p < b.p;
}

bool palyginimas3(const duomenys& a, const duomenys& b){
    return a.galutinis > b.galutinis;
}

bool palyginimas4(const duomenys& a, const duomenys& b){
    return a.mediana > b.mediana;
}

