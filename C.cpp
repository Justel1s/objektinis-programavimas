#include <bits/stdc++.h>
using namespace std;

//Strukturos apsirasymas
struct duomenys{
    string v, p;
    int egz, dydis;
    int* nd;
};
//Pagalbines funkcijos
int* randomBalai(int dydis){
    int *pazymiai = new int[dydis];
    for(int i = 0; i < dydis; i++){
        pazymiai[i] = rand()%10;
    }
    return pazymiai;
}
string randomVardai(int dydis){
    string vardas;
    for(int i = 0; i < dydis; i++){
        if(i==0) vardas += (char)(65 + rand() % 25);
        else vardas += (char)(97 + rand() % 25);
    }
    return vardas;
}
double galutinis(duomenys *D, int i){
    double vidurkis = accumulate(D[i].nd, D[i].nd + D[i].dydis, 0.0) / D[i].dydis;
    return 0.4 * vidurkis + 0.6 * D[i].egz;
}

double mediana(duomenys *D, int i){
    D[i].dydis++;
    D[i].nd[D[i].dydis-1] = D[i].egz;
    sort(D[i].nd, D[i].nd + D[i].dydis);
    return D[i].dydis % 2 == 0 ? (D[i].nd[D[i].dydis/2 - 1] + D[i].nd[D[i].dydis/2]) / 2.00 : D[i].nd[D[i].dydis/2];
}
//1 varianto algoritmas
void variantas1(duomenys *D, int skaicius){
    while(true){
        cout << "Iveskite pavarde: ";
        if(!(cin >> D[skaicius].p)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cout << "Iveskite varda: ";
        if(!(cin >> D[skaicius].v)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        D[skaicius].dydis = 0;
        int skaicius2 = 1;
        D[skaicius].nd = new int[skaicius2];
        while(true){
            cout << "Iveskite pazymi, o jei norite atsaukti - bet kokia raide: ";
            if(!(cin >> D[skaicius].nd[D[skaicius].dydis])){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            D[skaicius].dydis++;
            if(D[skaicius].dydis == skaicius2){
                skaicius2 += 4;
                int* laikinas = new int[skaicius2];
                for(int i = 0; i < D[skaicius].dydis; i++){
                    laikinas[i] = D[skaicius].nd[i];
                }
                delete[] D[skaicius].nd;
                D[skaicius].nd = laikinas;
            }
        }
        skaicius2 = 0;
        cout << "Iveskite egzamino pazymi: ";
        if(!(cin >> D[skaicius].egz)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        break;
    }
}
//2 varianto algoritmas
void variantas2(duomenys *D, int skaicius){
    while(true){
        cout << "Iveskite pavarde: ";
        if(!(cin >> D[skaicius].p)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cout << "Iveskite varda: ";
        if(!(cin >> D[skaicius].v)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        D[skaicius].dydis = rand()%10;
        D[skaicius].nd = randomBalai(D[skaicius].dydis);
        D[skaicius].egz = rand()%10;
        break;
    }
}
//3 varianto algoritmas
void variantas3(duomenys *D, int skaicius){
    while(true){
        int random = rand() % 10;
        D[skaicius].v = randomVardai(random);
        D[skaicius].p = randomVardai(random);
        D[skaicius].dydis = rand() % 10;
        D[skaicius].nd = randomBalai(D[skaicius].dydis);
        D[skaicius].egz = rand()%10;
        break;
    }
}
//Pagrindine funkcija
int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    int pasirinkimas, skaicius = 0, ilgis = 1;
    duomenys* D = new duomenys[skaicius];
    
    while(true){
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba" << endl;        
        if(cin>>pasirinkimas){
            if(pasirinkimas == 1) variantas1(D, skaicius);
            if(pasirinkimas == 2) variantas2(D, skaicius);
            if(pasirinkimas == 3) variantas3(D, skaicius);
            if(pasirinkimas == 4) break;
            skaicius++;
            if(skaicius == ilgis){
                ilgis++;
                duomenys* laikinas = new duomenys[ilgis];
                for(int i = 0; i < skaicius; i++){
                    laikinas[i] = D[i];
                }
                delete[] D;
                D = laikinas;
            }
        }
        else {cout << "KLAIDA" << endl; break;}
    }
    for(int i = 0; i < skaicius; i++){
        if(i == 0){
            cout << "Pavardė        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        cout << left << setw(15) << D[i].p << left << setw(15) << D[i].v << left << setw(19) << setprecision(2) << fixed << galutinis(D, i) << setprecision(2) << fixed << mediana(D, i) << endl;
        delete[] D[i].nd;
    }
    delete[] D;
    return 0;
}
