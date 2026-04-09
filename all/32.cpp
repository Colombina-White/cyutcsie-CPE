//星號字元的長方形 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void printLine(int n) {
    for (int i = 0; i < n; i++) cout << "*";
    cout << endl;
}

int main() {
    ifstream f("e.txt");
    string line, word;
    if (!getline(f, line)) return 0;

    cout << line << endl;

    stringstream ss(line);
    vector<string> v;
    int maxL = 0;
    while (ss >> word) {
        v.push_back(word);
        if ((int)word.length() > maxL) maxL = word.length();
    }

    printLine(maxL + 2);

    for (int i = 0; i < (int)v.size(); i++) {
        cout << "*" << v[i];
        for (int j = 0; j < (maxL - (int)v[i].length()); j++) cout << " ";
        cout << "*" << endl;
    }

    printLine(maxL + 2);

    return 0;
}
