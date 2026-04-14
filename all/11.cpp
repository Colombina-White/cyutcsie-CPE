//()[]{}所組成之字串
/*std::stack<char> st：直接利用內建堆疊容器。

left = "([{", right = ")]}"

使用 left.find(s[i]) 來判斷字元類型。如果 find 回傳的不是 npos，代表它是左括號。

這種寫法的好處是，如果你想增加新的括號類型（例如 <>），只需修改這兩個字串即可，不需要改動 if-else 邏輯。

利用 left[p] 找到與當前右括號索引 p 相對應的左括號，並與 st.top() 比較。*/
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
/*使用字元陣列 char st[1000] 作為容器，並定義一個整數 top = -1 指向堆疊最頂端的索引。

Push: st[++top] = c; (先移動指針再放入資料)

Pop: top--; (移動指針即視為彈出)

硬編碼判斷：直接使用 if (c == '(' || c == '[' || c == '{') 判斷。

使用 char s[1000]，並透過 s[i] != '\0' 判斷字串結束。*/
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
