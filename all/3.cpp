//AL字串
/*s.find_last_of("Aa")：
從字串的尾端往前搜尋，找到第一個出現的 'A' 或 'a' 的位置。

s.find_first_of("Ll", a_pos)：
從剛才找到的 a_pos 位置往後搜尋，找到第一個出現的 'L' 或 'l'。

s.erase(起始位置, 長度)：
直接移除這段區間。長度的計算公式是 l_pos - a_pos + 1（加 1 是為了連同 'L' 本身一起刪掉）。*/
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
/*計算長度：
while (s[n]) n++; 透過尋找字串結束符號 \0 來確定字串總長。

反向掃描：
for (int i = n - 1; i >= 0; i--) 從最後一個字元往回找 'A'。

尋找對應的 L：
找到 'A' 之後，用 int j = i 往後跑，直到撞到 'L' 或字串結束。

手寫刪除邏輯（關鍵）：
當找到 'L'（即 s[j] 存在）時，程式執行覆蓋動作：
s[i + k] = s[j + 1 + k]：將 'L' 之後的所有字元（包含 \0）往前搬移到 'A' 的位置。
這相當於把 A...L 這一段直接消失。*/
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
