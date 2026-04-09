//三個字串的運算符號 
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream f("e.txt");
    string s, res = "";
    if (!(f >> s)) return 0;

    cout << s << endl;

    for (int i = 0; i < (int)s.length(); ) {
        char cmd = s[i];
        if (cmd == '~' || cmd == '@' || cmd == '%') {
            int n = 0;
            
            while (i + 1 < (int)s.length() && isdigit(s[i+1]))
                n = n * 10 + (s[++i] - '0');
            i++; 

            if (cmd == '~') {
                string t = s.substr(i, n);
                reverse(t.begin(), t.end());
                res += t;
                i += n;
            } else { 
                int len = res.length(), del = (n > len ? len : n);
                res.erase((cmd == '@' ? 0 : len - del), del);
            }
        } else {
            res += s[i++];
        }
    }

    cout << "Ans=" << res << endl;
    return 0;
}
