//質因數
/*試除找因子：
for (int i = 2; i * i <= n; i++)
程式從最小的質數 2 開始嘗試整除 n。使用 i * i <= n 作為條件是為了效能優化：如果到平方根都找不到因子，剩下的 n 一定是質數。

計算次數 (Exponent)：
一旦 n % i == 0（找到因子），就會進入 while 迴圈不斷除以 i，並用 cnt 記錄這個質因數出現了幾次。

逆序拼接：
ss << i << "(" << cnt << ")" << res;
它會將新找到的因子 i 放在舊的結果字串 res 之前。

正常拼接：res + i → 2(2)3(1) (從小到大)

逆序拼接：i + res → 3(1)2(2) (從大到小)

處理最後的質數：
迴圈結束後，如果 n > 1，代表剩下的 n 是一個大於原本所有因子的質數*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("a.txt");
    long long n, temp;
    if (!(file >> n)) return 0;
    temp = n;
    string res = "";
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            stringstream ss;
            ss << i << "(" << cnt << ")" << res;
            res = ss.str();
        }
    }
    if (n > 1) {
        stringstream ss;
        ss << n << "(1)" << res;
        res = ss.str();
    }
    cout << temp << "\nAns=" << res << endl;
    return 0;
}
/*試除找因子：
while (i * i <= n && n % i != 0) i++;
這一行會從 i（初始為 2）開始往後找，直到找到第一個能整除 n 的數，或者 i 超過 sqrt{n}。
計算出現次數 (Exponent)：
當找到因子 i 後，進入 while (next_n % i == 0) 迴圈，不斷將 next_n 除以 i，並用 cnt 記錄除成功的次數。
遞迴呼叫：
factor(next_n, i + 1);
程式會先帶著「除掉所有因子 i 之後的剩餘數字」進入下一層遞迴。
後序輸出 (Post-order Output)：
cout << i << "(" << cnt << ")";
這行指令放在遞迴呼叫 之後。這意味著程式會一直「往下鑽」直到數字被分解完，然後在「回溯」時才開始列印。這就是為什麼輸出順序會與分解順序相反。*/
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

void factor(long long n, int i) {
    if (n == 1) return;
    while (i * i <= n && n % i != 0) i++;
    if (n % i == 0) {
        int cnt = 0;
        long long next_n = n;
        while (next_n % i == 0) {
            cnt++;
            next_n /= i;
        }
        factor(next_n, i + 1);
        cout << i << "(" << cnt << ")";
    } else {
        cout << n << "(1)";
    }
}

int main() {
    ifstream f("a.txt");
    long long n;
    if (!(f >> n)) return 0;
    cout << n << "\nAns=";
    factor(n, 2);
    cout << endl;
    return 0;
}
