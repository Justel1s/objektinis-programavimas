#include "studentai.h"
#include <bits/stdc++.h>
using namespace std;

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
void variantas4(vector<duomenys> &D){
    ifstream fd("studentai10000.txt");
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
        else X.mediana = (X.nd[vidurys] + X.nd[vidurys-1] / 2.0);
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