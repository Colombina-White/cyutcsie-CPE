#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int conv(int n) {
    if (n == 0) return 10;
    int sum = 0, digits = 0;
    for (; n > 0; n /= 10) {
        sum += (n % 10);
        digits++;
    }
    return (digits * 10) + (sum % 10);
}

int main() {
    ifstream f("e.txt");
    int n, val;
    if (!(f >> n)) return 0;

    cout << n << endl;

    vector<int> v(n);
    int maxV = -1, bestO = -1;

    for (int i = 0; i < n; i++) {
        f >> v[i];
        cout << v[i] << (i == n - 1 ? "" : " ");

        int cur = conv(v[i]);
        if (cur > maxV) {
            maxV = cur;
            bestO = v[i];
        }
    }
    cout << "\nAns=" << maxV << " " << bestO << endl;

    return 0;
}
