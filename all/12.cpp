//中國餘數定理
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream f("e.txt");
    vector<int> p, r;
    int v1, v2;
    while (f >> v1 >> v2) {
        p.push_back(v1); r.push_back(v2);
        cout << v1 << " " << v2 << " ";
    }
    cout << endl;
    if (p.empty()) return 0;
    long long N = 1, X = 0;
    for (int i = 0; i < (int)p.size(); i++) N *= p[i];
    for (int i = 0; i < (int)p.size(); i++) {
        long long Mi = N / p[i];
        int yi = 1;
        while ((Mi * yi) % p[i] != 1) yi++;
        
        X += Mi * yi * r[i];
    }
    cout << "Ans=" << X % N << endl;
    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("12.txt");
    int p[100], r[100]; 
    int n = 0;         
    while (f >> p[n] >> r[n]) {
        cout << p[n] << " " << r[n] << " ";
        n++;
    }
    cout << endl;
    if (n == 0) return 0;
    long long N = 1;
    for (int i = 0; i < n; i++) {
        N *= p[i];
    }
    long long X = 0;
    for (int i = 0; i < n; i++) {
        long long Mi = N / p[i];
        int yi = 1;
        while ((Mi * yi) % p[i] != 1) {
            yi++;
        }
        X += Mi * yi * r[i];
    }
    cout << "Ans=" << X % N << endl;

    return 0;
}
