#include <bits/stdc++.h>
using namespace std;

struct duomenys{
    string v, p;
    int egz, dydis;
    int nd[999];
};

int kiekis;
duomenys D[999];

void duomenuGavimas()
{
    cin >> kiekis;
    if(kiekis == (int)kiekis){
        for(int i = 0; i < kiekis; i++){
        cin >> D[i].v >> D[i].p >> D[i].dydis;
            for(int j = 0; j < D[i].dydis; j++){
                cin >> D[i].nd[j];
            }
        cin >> D[i].egz;
        }
    }
    else abort();
    
}
double galutinis(int i){
    double vidurkis = accumulate(D[i].nd, D[i].nd + D[i].dydis, 0.0) / D[i].dydis;
    return 0.4 * vidurkis + 0.6 * D[i].egz;
}
double mediana(int i){
    D[i].dydis++;
    sort(D[i].nd, D[i].nd + D[i].dydis);
    return D[i].dydis % 2 == 0 ? (D[i].nd[D[i].dydis/2 - 1] + D[i].nd[D[i].dydis/2]) / 2.00 : D[i].nd[D[i].dydis/2];
}
int main(){
    duomenuGavimas();
    for(int i = 0; i < kiekis; i++){
        if(i == 0){
            cout << "Pavardė        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        cout << left << setw(15) << D[i].p << left << setw(15) << D[i].v << left << setw(19) << setprecision(2) << fixed << galutinis(i) << setprecision(2) << fixed << mediana(i) << endl;
    }
    return 0;
}
