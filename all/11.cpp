#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ifstream f("e.txt");
    string s;
    if (!(f >> s)) return 0;

    cout << s << endl;

    stack<char> st;
    string left = "([{", right = ")]}";
    bool ok = true;

    for (int i = 0; i < (int)s.length(); i++) {
        size_t p;
        if ((p = left.find(s[i])) != string::npos) {
            st.push(s[i]);
        } 
        else if ((p = right.find(s[i])) != string::npos) {
            if (st.empty() || st.top() != left[p]) {
                ok = false;
                break;
            }
            st.pop();
        }
    }

    cout << "Ans=" << (ok && st.empty() ? "CORRECT" : "ERROR") << endl;
    return 0;
}
