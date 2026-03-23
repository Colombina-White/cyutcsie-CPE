#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("a.txt");
    string n, L;
    if (!(file >> n)) return 0;
	cout <<n<< endl;
    L = n.substr(0, (n.length() + 1) / 2);

    if (next_permutation(L.begin(), L.end())) {
        string R = L.substr(0, n.length() / 2);
        reverse(R.begin(), R.end());
        cout << "Ans=" << L << R << endl;
    } else {
        cout << "Ans=No Solution" << endl;
    }

    return 0;
}
