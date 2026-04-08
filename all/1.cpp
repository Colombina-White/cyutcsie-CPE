//迴文
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("a.txt");
    string n;
    if (!(file >> n)) return 0;
    cout << n << endl;
    int len = n.length();
    int mid_idx = len / 2;
    string L = n.substr(0, mid_idx);
    if (next_permutation(L.begin(), L.end())) {
        string R = L;
        reverse(R.begin(), R.end());
        string mid = (len % 2 == 0) ? "" : string(1, n[mid_idx]);
        cout << "Ans=" << L << mid << R << endl;
    } else {
        cout << "Ans=No Solution" << endl;
    }
    return 0;
}
