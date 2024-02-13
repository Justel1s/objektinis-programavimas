#include <bits/stdc++.h>
using namespace std;

struct duomenys{
    string v, p;
    int nd, egz;
};
double galutinis(duomenys *D, int n, int i){
    double vidurkis = D[i].nd / n;
    return 0.4 * vidurkis + 0.6 * D[i].egz;
}
double mediana(int med[], int n){
    n++;
    sort(med, med+n);
    return n % 2 == 0 ? (med[n/2 - 1] + med[n/2]) / 2.00 : med[n/2];
}
int main(){
    duomenys D[999];
    int kiekis, n, nd;
    cin >> kiekis;
    for(int i = 0; i < kiekis; i++){
        int med[999];
        cin >> D[i].v >> D[i].p >> n;
        for(int j = 0; j < n; j++){
            cin >> nd;
            med[j] = nd;
            D[i].nd += nd;
        }
        cin >> D[i].egz;
        med[n] = D[i].egz;
        if (i == 0){
            cout << "Pavardė        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        cout << left << setw(15) << D[i].p << left << setw(15) << D[i].v << left << setw(19) << setprecision(2) << fixed << galutinis(D, n, i) << setprecision(2) << fixed << mediana(med, n) << endl;
    }
    return 0;
}
