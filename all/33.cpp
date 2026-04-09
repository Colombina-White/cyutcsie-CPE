//字串加密 
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ifstream f("e.txt");
    string s;
    if (!getline(f, s)) return 0;

    cout << s << endl;

    long long sum = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (isalpha(s[i])) {
            sum += (toupper(s[i]) - 'A' + 1);
        }
    }
    int shift = (int)(sum % 26);

    for (int i = 0; i < (int)s.length(); i++) {
        if (islower(s[i])) {
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
        } else if (isupper(s[i])) {
            s[i] = (s[i] - 'A' + shift) % 26 + 'A';
        }
    }

    cout << "Ans=" << s << endl;
    return 0;
}
