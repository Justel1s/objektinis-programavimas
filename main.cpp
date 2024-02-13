#include <bits/stdc++.h>
using namespace std;

struct duomenys{
    string v, p;
    int nd, egz;
};
int main()
{
    duomenys D[INT_MAX];
    int kiekis, n, nd;
    double vidurkis, galutinis;
    cout << "Pavardė        Vardas         Galutinis (Vid.)" << endl;
    cout << "----------------------------------------------" << endl;
    cin >> kiekis;
    for(int i = 0; i < kiekis; i++)
    {
        int med[INT_MAX];
        cin >> D[i].v >> D[i].p >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> nd;
            med[j] = nd;
            D[i].nd += nd;
        }
        cin >> D[i].egz;
        med[n] = D[i].egz;
        
        vidurkis = D[i].nd / n;
        galutinis = 0.4 * vidurkis + 0.6 * D[i].egz;
        cout << left << setw(15) << D[i].p << left << setw(15) << D[i].v << left << setw(15) << setprecision(2) << fixed << galutinis << endl;
    }
    return 0;
}
