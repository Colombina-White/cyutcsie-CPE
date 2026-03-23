#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    ifstream file("d.txt");
    if (!file) return 0;

    string line;
    long long totalSum = 0;
    vector<string> allLines;

    while (getline(file, line)) {
        allLines.push_back(line);
        string temp = "";
        
        for (int i = 0; i < (int)line.length(); i++) {
            if (isdigit(line[i])) {
                temp += line[i];
            } else if (!temp.empty()) {
                totalSum += atoll(temp.c_str()); 
                temp = "";
            }
        }
        if (!temp.empty()) totalSum += atoll(temp.c_str());
    }

    for (int i = 0; i < (int)allLines.size(); i++) {
        cout << allLines[i] << endl;
    }
    cout << "Ans=" << totalSum << endl;

    return 0;
}
