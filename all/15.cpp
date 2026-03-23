#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getLetterVal(char c) {
    int vals[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
    return vals[c - 'A'];
}

int main() {
    ifstream file("c.txt");
    string id;
    if (!(file >> id)) return 0;
    file.close();

    cout << id << endl;

    int n = getLetterVal(id[0]);
    int sum = (n / 10) + (n % 10) * 9;

    for (int i = 1; i <= 8; i++) {
        sum += (id[i] - '0') * (9 - i);
    }

    int checkNum = (10 - (sum % 10)) % 10;

    cout << "Ans=" << id << checkNum << endl;

    return 0;
}
