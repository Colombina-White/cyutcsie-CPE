#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("d.txt");
    double x, sum = 0.0, term = 1.0;
    int n;

    if (!(f >> x >> n)) return 0;

    cout << (int)x << "\n" << n << endl;

    for (int k = 1; k <= n; k++) {
        term *= (x / k);
        sum += term;
    }

    cout << "Ans=" << (long long)sum << endl;

    return 0;
}
