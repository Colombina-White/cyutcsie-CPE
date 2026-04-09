//保齡球運動的計分方式 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int getS(char c, int prev = 0) {
    if (c == 'X') return 10;
    if (c == '/') return 10 - prev;
    return (c >= '0' && c <= '9') ? c - '0' : 0;
}

int main() {
    ifstream f("e.txt");
    int groups;
    if (!(f >> groups)) return 0;

    cout << groups << endl;
    string line;
    getline(f, line); 

    vector<string> results;
    while (groups--) {
        if (!getline(f, line) || line.empty()) break;
        cout << line << endl;

        stringstream ss(line);
        vector<char> m;
        char c;
        while (ss >> c) m.push_back(c);

        int score = 0;
        bool fail = false;
        int n = m.size();

        for (int i = 0; i < n; i++) {
            if (m[i] == 'X') { 
                if (i + 2 < n) {
                    int b1 = getS(m[i+1]);
                    int b2 = (m[i+2] == '/') ? getS('/', b1) : getS(m[i+2]);
                    score += 10 + b1 + b2;
                } else { fail = true; break; }
            } else if (m[i] == '/') {
                if (i + 1 < n) {
                    score += getS('/', getS(m[i-1])) + getS(m[i+1]);
                } else { fail = true; break; }
            } else {
                score += getS(m[i]);
            }
        }

        if (fail) results.push_back("Unknown");
        else {
            ostringstream oss;
            oss << score;
            results.push_back(oss.str());
        }
    }

    cout << "Ans=";
    for (int i = 0; i < (int)results.size(); i++)
        cout << results[i] << (i == (int)results.size() - 1 ? "" : " ");
    cout << endl;

    return 0;
}
