//AL字串
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("b.txt");
    string s;
    if (!getline(file, s)) return 0;
    file.close();
    cout << s << endl;
    size_t a_pos;
    while ((a_pos = s.find_last_of("Aa")) != string::npos) {
        size_t l_pos = s.find_first_of("Ll", a_pos);
        
        if (l_pos != string::npos) {
            s.erase(a_pos, l_pos - a_pos + 1);
        } else {
            break; 
        }
    }
    cout << "Ans=" << s << endl;
    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("b.txt");
    char s[1000];
    if (!(f.getline(s, 1000))) return 0;
    cout << s << endl;

    int n = 0;
    while (s[n]) n++;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A' || s[i] == 'a') {
            int j = i;
            while (s[j] && s[j] != 'L' && s[j] != 'l') j++;

            if (s[j]) {
                int k = 0;
                while (s[j + 1 + k]) {
                    s[i + k] = s[j + 1 + k];
                    k++;
                }
                s[i + k] = '\0';
                i = i; 
            }
        }
    }

    cout << "Ans=" << s << endl;
    return 0;
}
