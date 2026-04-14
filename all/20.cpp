//部分序列字串指原字串中刪掉一個以上字元且不改變原順序的部份字串。 
/*size_t 類型：這是一種無符號整數類型，專門用於表示記憶體中物件的大小或陣列的索引，比 int 更安全。
貪婪演算法：這種比對方式是貪婪的，只要在 s2 中看到第一個符合的字元就立刻匹配，這是判定子序列最有效率的方法（時間複雜度為O(n)，n 是 s2 的長度）。
字串拼接：del += s2[j] 用於動態收集那些「被刪除」的字元。*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream f("d.txt");
    string s1, s2, del = "";
    if (!(f >> s1 >> s2)) return 0;

    cout << s1 << " " << s2 << endl;

    size_t i = 0;
    for (size_t j = 0; j < s2.length(); ++j) {
        if (i < s1.length() && s1[i] == s2[j]) {
            i++;
        } else {
            del += s2[j]; 
        }
    }

    if (i == s1.length()) 
        cout << "Ans=Yes " << del << endl;
    else 
        cout << "Ans=No" << endl;

    return 0;
}
