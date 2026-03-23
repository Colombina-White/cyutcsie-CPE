#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int luhnVal(int n, bool doubleIt) {
    if (!doubleIt) return n;
    n *= 2;
    return (n > 9) ? (n - 9) : n;
}

int main() {
    ifstream f("e.txt");
    int n;
    if (!(f >> n)) return 0;

    cout << n << endl;
    string line;
    getline(f, line); 

    vector<string> res;
    while (n--) {
        if (!getline(f, line) || line.empty()) { n++; continue; }
        cout << line << endl;

        stringstream ss(line);
        vector<int> card;
        int num, sum = 0;
        while (ss >> num) card.push_back(num);

        bool doubleIt = false;
        for (int i = (int)card.size() - 1; i >= 0; i--) {
            sum += luhnVal(card[i], doubleIt);
            doubleIt = !doubleIt;
        }

        res.push_back((sum % 10 == 0) ? "valid" : "invalid");
    }

    cout << "Ans=";
    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << (i == (int)res.size() - 1 ? "" : " ");
    cout << endl;

    return 0;
}
