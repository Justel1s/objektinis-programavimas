#ifndef studentai_h
#define studentai_h
#include <bits/stdc++.h>
using namespace std;
struct duomenys{
    string v, p;
    vector<int> nd;
    int egz;
    double galutinis, mediana;
};
void generateFile(const string& failoPavadinimas, int kiekis);
void randomBalai(int dydis, duomenys &X);
string randomVardai(int dydis);
void variantas1(vector<duomenys> &D);
void variantas2(vector<duomenys> &D);
void variantas3(vector<duomenys> &D);
void variantas4(vector<duomenys> &D, string failas);
void rikiavimas(vector<duomenys> &D);
bool palyginimas1(const duomenys& a, const duomenys& b);
bool palyginimas2(const duomenys& a, const duomenys& b);
bool palyginimas3(const duomenys& a, const duomenys& b);
bool palyginimas4(const duomenys& a, const duomenys& b);

#endif
