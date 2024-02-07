#include <bits/stdc++.h>
using namespace std;

struct duomenys{
    string v, p;
    int nd, egz;
};
int main()
{
    duomenys D[999];
    int kiekis, n, nd;
    double vidurkis, galutinis;
    cout << "Pavardė        Vardas       Galutinis (Vid.)" << endl;
    cout << "--------------------------------------------" << endl;
    cin >> kiekis;
    for(int i = 0; i < kiekis; i++)
    {
        cin >> D[i].v >> D[i].p >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> nd;
            D[i].nd += nd;
        }
        cin >> D[i].egz;
        vidurkis = D[i].nd / n;
        galutinis = 0.4 * vidurkis + 0.6 * D[i].egz;
        cout << D[i].p << D[i].v << galutinis << fixed << setprecision(2) << endl;
    }
    return 0;
}
