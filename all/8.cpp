#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("e.txt");
    string s;
    if (!getline(file, s)) return 0;
    file.close();

    cout << s << "\nAns=";

    cout << hex; 

    int cnt = 1;
    for (int i = 0; i < (int)s.length(); i++) {
        if (i + 1 < (int)s.length() && s[i] == s[i+1]) {
            cnt++;
        } else {
            cout << cnt << s[i];
            cnt = 1;
        }
    }
    cout << endl;

    return 0;
}
