#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream f("d.txt");
    string s, res = "";
    if (!(f >> s)) return 0;

    cout << s << endl;

    int n = s.length();
    for (int i = 0; i < n; ) {
        if (s[i++] == 'C' && i < n) {
            int shift = s[i++] - '0';

            while (i < n && s[i] != 'C') {
                int enc = s[i++] - '0';
                int dec = (enc - shift + 10) % 10;
                res += (dec + '0');
            }
        }
    }

    cout << "Ans=" << res << endl;
    return 0;
}
