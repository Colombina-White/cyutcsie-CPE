//迴文
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
/*取前半段 (L)：
假設字串長度為 len，程式先切出前一半的字元存入 L。

找下一個排列 (next_permutation)：
它會將 L 改成「字典順序」中的下一個組合。

鏡像對稱 (R)：
如果 L 成功找到了下一個排列，程式會將新的 L 反轉（reverse）得到 R，作為後半段。

組合結果：
將新的 L + 中間項 (mid) + R 拼起來。*/
using namespace std;

int main() {
    ifstream file("a.txt");
    string n;
    if (!(file >> n)) return 0;
    cout << n << endl;
    int len = n.length();
    int mid_idx = len / 2;
    string L = n.substr(0, mid_idx);
    if (next_permutation(L.begin(), L.end())) {
        string R = L;
        reverse(R.begin(), R.end());
        string mid = (len % 2 == 0) ? "" : string(1, n[mid_idx]);
        cout << "Ans=" << L << mid << R << endl;
    } else {
        cout << "Ans=No Solution" << endl;
    }
    return 0;
}
