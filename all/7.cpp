#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b); 
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (!a || !b) return 0;
    return (a / gcd(a, b)) * b;
}

int main() {
    ifstream file("c.txt");
    vector<long long> v;
    long long n;

    while (file >> n) {
        v.push_back(n);
        cout << n << (file.peek() == EOF ? "" : " ");
    }
    cout << endl;
    if (v.empty()) return 0;

    long long res = v[0];
    for (int i = 1; i < (int)v.size(); i++) {
        res = lcm(res, v[i]);
    }

    cout << "Ans=" << res << endl;
    return 0;
}
