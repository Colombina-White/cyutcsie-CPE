//為了避免計算 a x b 時發生整數溢位（Overflow），程式碼採用了 (a / gcd(a, b)) * b 的順序。
//最小公倍數
/*gcd 函式：使用「輾轉相除法」計算最大公因數。
a %= b; swap(a, b); 這是標準的歐幾里得算法簡寫。
lcm 函式：利用上述公式計算。特別加入了 if (!a || !b) return 0; 的防錯機制，防止除以零或處理輸入為 0 的情況。
main 函式：讀取階段：將所有數字存入 vector<long long> v。使用 file.peek() == EOF 來判斷是否為最後一個數字，藉此控制空白輸出的格式。
計算階段：從 v[0] 開始，依序與後面的數字計算 LCM。這利用了 LCM 的結合律：LCM(a, b, c) = LCM(LCM(a, b), c)。*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b); 
    }
    return a;
}
long long lcm(long long a, long long b) {
    if (!a || !b) return 0;
    return (a / gcd(a, b)) * b;
}
int main() {
    ifstream file("c.txt");
    vector<long long> v;
    long long n;
    while (file >> n) {
        v.push_back(n);
        cout << n << (file.peek() == EOF ? "" : " ");
    }
    cout << endl;
    if (v.empty()) return 0;
    long long res = v[0];
    for (int i = 1; i < (int)v.size(); i++) {
        res = lcm(res, v[i]);
    }
    cout << "Ans=" << res << endl;
    return 0;
}
//不用函示
/*get_gcd 函式：手寫了 swap 的邏輯（使用暫存變數 t），效果與第一段相同。

main 函式：

狀態控制：使用 bool first 來標記是否為讀入的第一個數字。如果是第一個數字，直接設為初始結果 res；之後的數字則與目前的 res 進行 LCM 運算。

邊讀邊算：不使用 vector 儲存，省去了額外的記憶體開銷。

輸出控制：在輸出 val 之前判斷 !first 來補空白，這比第一段的 peek() 更簡潔且保險。*/
#include <iostream>
#include <fstream>

using namespace std;

long long get_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        long long t = a;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ifstream f("c.txt");
    long long val, res = 0;
    bool first = true;
    while (f >> val) {
        if (!first) cout << " ";
        cout << val;

        if (first) {
            res = val;
            first = false;
        } else {
            if (res > 0 && val > 0) {
                res = (res / get_gcd(res, val)) * val;
            }
        }
    }
    if (first) return 0; 
    cout << "\nAns=" << res << endl;
    return 0;
}
