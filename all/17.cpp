//存款複利率 
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double getVal(double P, int n, double r) {
    double total = 0;
    for (int i = 0; i < n; i++)
        total = (total + P) * (1.0 + r);
    return total;
}

int main() {
    ifstream file("a.txt");
    double P, target, low = 0, high = 1, mid;
    int n;

    if (!(file >> P >> n >> target)) return 0;

    cout << fixed << setprecision(0) << P << "\n" << n << "\n" << target << endl;

    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2.0;
        if (getVal(P, n, mid) < target) low = mid;
        else high = mid;
    }

    cout << "Ans=" << setprecision(2) << mid * 100 << "%" << endl;
    return 0;
}
