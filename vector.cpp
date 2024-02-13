#include <bits/stdc++.h>
using namespace std;

// Structure
struct duomenys{
    string v, p;
    int egz, dydis;
    int* nd; // Dynamically allocated array
};

// Global variables
int kiekis;
duomenys* D; // Dynamically allocated array of duomenys structures

// Data input function
void duomenuGavimas(){
    cin >> kiekis;
    D = new duomenys[kiekis]; // Allocate memory for D array
    for(int i = 0; i < kiekis; i++){
        cin >> D[i].v >> D[i].p >> D[i].dydis;
        D[i].nd = new int[D[i].dydis]; // Allocate memory for nd array
        for(int j = 0; j < D[i].dydis; j++){
            cin >> D[i].nd[j];
        }
        cin >> D[i].egz;
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
    duomenuGavimas();
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
