#include <bits/stdc++.h>
using namespace std;

//Strukturos apsirasymas
struct duomenys{
    string v, p;
    vector<int> nd;
    int egz;
    double galutinis, mediana;
};
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
        if(!(cin >> X.p)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cout << "Iveskite varda: ";
        if(!(cin >> X.v)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        while(true){
            int x;
            cout << "Iveskite pazymi, o jei norite atsaukti - bet kokia raide: ";
            if(!(cin >> x) && 0 < x < 11){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            X.nd.push_back(x);
        }
        cout << "Iveskite egzamino pazymi: ";
        if(!(cin >> X.egz) && 0 < X.egz < 11){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
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
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cout << "Iveskite varda: ";
        if(!(cin >> X.v)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
//Pagrindine funkcija
int main(){
    vector<duomenys> D;
    int pasirinkimas;
    while(true){
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba" << endl;        
        if(cin>>pasirinkimas){
            if(pasirinkimas == 1) variantas1(D);
            if(pasirinkimas == 2) variantas2(D);
            if(pasirinkimas == 3) variantas3(D);
            if(pasirinkimas == 4) break;
        }
        else {cout << "KLAIDA" << endl; break;}
    }
    for(int i = 0; i < D.size(); i++){
        if(i == 0){
            cout << "Pavardė        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        cout << left << setw(15) << D[i].p << left << setw(15) << D[i].v << left << setw(19) << setprecision(2) << fixed << D[i].galutinis << setprecision(2) << fixed << D[i].mediana << endl;
    }
    
    return 0;
}
