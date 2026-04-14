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
//不用函示
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream f("19.txt");
    string s;
    if (!(f >> s)) return 0;

    cout << s << endl;
    char res[1000]; 
    int resLen = 0; 
    for (int i = 0; i < (int)s.length(); ) {
        char cmd = s[i];
        
        if (cmd == '~' || cmd == '@' || cmd == '%') {
            int n = 0;
            while (i + 1 < (int)s.length() && s[i+1] >= '0' && s[i+1] <= '9') {
                n = n * 10 + (s[++i] - '0');
            }
            i++; 

            if (cmd == '~') {
                for (int j = 0; j < n && i < (int)s.length(); j++) {
                    res[resLen + j] = s[i + n - 1 - j];
                }
                resLen += n;
                i += n;
            } 
            else if (cmd == '@') {
                int del = (n > resLen ? resLen : n);
                for (int j = 0; j < resLen - del; j++) {
                    res[j] = res[j + del];
                }
                resLen -= del;
            } 
            else if (cmd == '%') {
                int del = (n > resLen ? resLen : n);
                resLen -= del;
            }
        } else {
            res[resLen++] = s[i++];
        }
    }

    cout << "Ans=";
    for (int i = 0; i < resLen; i++) {
        cout << res[i];
    }
    cout << endl;

    return 0;
}
