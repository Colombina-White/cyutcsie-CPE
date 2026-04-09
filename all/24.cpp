//圓周率的無窮乘積計算式
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isP(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ifstream f("c.txt");
    int n, curr = 3;
    if (!(f >> n)) return 0;

    cout << n << endl;

    vector<int> num, den;

    while ((int)num.size() < n) {
        if (isP(curr)) {
            num.push_back(curr);
            den.push_back((curr - 1) % 4 != 0 ? curr - 1 : curr + 1);
        }
        curr++;
    }

    for (int k = 0; k < 2; k++) {
        cout << "Ans=";
        vector<int>& target = (k == 0 ? num : den);
        for (int i = 0; i < n; i++)
            cout << target[i] << (i == n - 1 ? "" : "*");
        cout << endl;
    }

    return 0;
}
