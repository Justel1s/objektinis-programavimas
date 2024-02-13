#include <bits/stdc++.h>
using namespace std;

// Structure
struct duomenys{
    string v, p;
    int egz, dydis;
    int* nd; // Dynamically allocated array
};

// Global variables
duomenys* D; // Dynamically allocated array of duomenys structures

// Data input function
void variantas1(int & kiekis){
    while(true){
        int kiekis2 = 0;
        D = new duomenys[kiekis]; // Allocate memory for D array
        D[kiekis].nd = new int[kiekis2]; // Allocate memory for nd array
        cout << "Iveskite pavarde: ";
        if(!(cin >> D[kiekis].p)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cout << "Iveskite varda: ";
        if(!(cin >> D[kiekis].v)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        while(true){
            cout << "Iveskite pazymi, o jei norite atsaukti - bet kokia raide: ";
            if(!(cin >> D[kiekis].nd[kiekis2])){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            kiekis2++;
        }
        D[kiekis].dydis = kiekis2;
        kiekis2 = 0;
        cout << "Iveskite egzamino pazymi: ";
        if(!(cin >> D[kiekis].egz)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cout << "Jei norite baigti - iveskite 1, jei norite testi - 2: ";
        int x;
        if(!(cin >> x)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        kiekis++;
        if(x == 1) break;
    }
}

// Function to calculate average
double galutinis(int i){
    double vidurkis = accumulate(D[i].nd, D[i].nd + D[i].dydis, 0.0) / D[i].dydis;
    return 0.4 * vidurkis + 0.6 * D[i].egz;
}

// Function to calculate median
double mediana(int i){
    D[i].dydis++;
    D[i].nd[D[i].dydis-1] = D[i].egz;
    sort(D[i].nd, D[i].nd + D[i].dydis);
    return D[i].dydis % 2 == 0 ? (D[i].nd[D[i].dydis/2 - 1] + D[i].nd[D[i].dydis/2]) / 2.00 : D[i].nd[D[i].dydis/2];
}

// Main function
int main(){
    int pasirinkimas, kiekis = 0;
    cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba" << endl;
    if(cin>>pasirinkimas){
        if(pasirinkimas == 1) variantas1(kiekis);
        // if(pasirinkimas == 2) variantas2();
        // if(pasirinkimas == 3) variantas3();
        // if(pasirinkimas == 4) break;
    }
    for(int i = 0; i < kiekis; i++){
        if(i == 0){
            cout << "Pavardė        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        cout << left << setw(15) << D[i].p << left << setw(15) << D[i].v << left << setw(19) << setprecision(2) << fixed << galutinis(i) << setprecision(2) << fixed << mediana(i) << endl;
        delete[] D[i].nd; // Free memory for nd array
    }
    delete[] D; // Free memory for D array
    return 0;
}
