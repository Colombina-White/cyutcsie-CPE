/*雜湊(hashing)是用來計算一個鍵值(key value)對應之索引(index)的方法，而「折疊法」是
雜湊函數的方法之一，假設有一個鍵值為 5120969190600791，而折疊的長度為 3，折疊
的計算過程如下，首先鍵值先依照折疊長度加以切割，由於鍵值有 16 個數字，每 3 個數
字進行切割的話，可以切出 6 段，如下所示：
512 096 919 060 079 1*/
/*s.substr(i, len)：從索引 i 開始，抓取長度為 len 的子字串。即使剩下的字元不足 len 個（例如最後的 1），substr 也會自動處理到字串末尾。

atof(part.c_str())：

c_str()：將 C++ string 轉成 C 風格的字元陣列。

atof：雖然原本是用於「字串轉浮點數」，但在此處被用來處理長數字。

注意：通常建議使用 atoll（轉 long long）或 stoll 會更精確，因為 atof 可能會因為浮點數精度問題導致超大數字出現誤差。*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    ifstream f("b.txt");
    string s, part;
    int len;

    if (!(f >> s >> len)) return 0;
    cout << s << "\n" << len << endl;

    long long sum = 0;
    for (int i = 0; i < (int)s.length(); i += len) {
        part = s.substr(i, len);
        
        sum += (long long)atof(part.c_str());
    }

    cout << "Ans=" << sum << endl;
    return 0;
}
//不用函示
/*手動數值構造：
for (int j = i; j < i + len && j < n; j++) {
    currentNum = currentNum * 10 + (s[j] - '0');
}
這是解析數字的標準演算法：每往右讀一位，就把目前的數 *10 並加上新位元的數值。

s[j] - '0'：這是利用 ASCII 碼。字元 '5' 的 ASCII 碼減去 '0' 的 ASCII 碼，剛好就是整數 5。

邊界條件 j < n：這是關鍵，確保在切割到最後一個片段時，如果長度不夠 len，不會讀取到字串範圍外。*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream f("13.txt");
    string s;
    int len;
    if (!(f >> s >> len)) return 0;
    cout << s << "\n" << len << endl;

    long long totalSum = 0;
    int n = s.length();
    for (int i = 0; i < n; i += len) {
        long long currentNum = 0;
        
        for (int j = i; j < i + len && j < n; j++) {
            currentNum = currentNum * 10 + (s[j] - '0');
        }
        totalSum += currentNum;
    }
    cout << "Ans=" << totalSum << endl;
    return 0;
}
