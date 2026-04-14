/*雜湊(hashing)是用來計算一個鍵值(key value)對應之索引(index)的方法，而「折疊法」是
雜湊函數的方法之一，假設有一個鍵值為 5120969190600791，而折疊的長度為 3，折疊
的計算過程如下，首先鍵值先依照折疊長度加以切割，由於鍵值有 16 個數字，每 3 個數
字進行切割的話，可以切出 6 段，如下所示：
512 096 919 060 079 1*/
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
