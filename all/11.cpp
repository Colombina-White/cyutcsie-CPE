//()[]{}所組成之字串
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
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("11.txt");
    char s[1000];
    if (!(f >> s)) return 0;
    cout << s << endl;
    char st[1000];
    int top = -1; 
    bool ok = true;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st[++top] = c;
        } 
        else {
            if (top == -1) { ok = false; break; }

            if ((c == ')' && st[top] == '(') || 
                (c == ']' && st[top] == '[') || 
                (c == '}' && st[top] == '{')) {
                top--;
            } else {
                ok = false;
                break;
            }
        }
    }
    if (ok && top == -1) cout << "Ans=CORRECT" << endl;
    else cout << "Ans=ERROR" << endl;

    return 0;
}
