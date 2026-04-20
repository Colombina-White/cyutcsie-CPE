//將每個正整數經過轉換並比較之後，輸出轉換後最大數值與對應的正整數
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int conv(int n) {
    if (n == 0) return 10;
    int sum = 0, digits = 0;
    for (; n > 0; n /= 10) {
        sum += (n % 10);
        digits++;
    }
    return (digits * 10) + (sum % 10);
}

int main() {
    ifstream f("e.txt");
    int n, val;
    if (!(f >> n)) return 0;

    cout << n << endl;

    vector<int> v(n);
    int maxV = -1, bestO = -1;

    for (int i = 0; i < n; i++) {
        f >> v[i];
        cout << v[i] << (i == n - 1 ? "" : " ");

        int cur = conv(v[i]);
        if (cur > maxV) {
            maxV = cur;
            bestO = v[i];
        }
    }
    cout << "\nAns=" << maxV << " " << bestO << endl;

    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("27.txt");
    int n, val;

    // 1. 讀取資料個數 n
    if (!(f >> n)) return 0;
    cout << n << endl;

    int maxV = -1;  // 轉換後的最高分
    int bestO = -1; // 對應的原始數值

    // 2. 直接在迴圈中處理讀取與轉換邏輯
    for (int i = 0; i < n; i++) {
        int original;
        f >> original;
        // 印出原始數值
        cout << original << (i == n - 1 ? "" : " ");
        // --- 手動執行 conv 轉換邏輯 ---
        int currentConv = 0;
        if (original == 0) {
            currentConv = 10;
        } else {
            int temp = original;
            int sum = 0;
            int digits = 0;
            // 計算位數與各個數位之和
            while (temp > 0) {
                sum += (temp % 10);
                digits++;
                temp /= 10;
            }
            currentConv = (digits * 10) + (sum % 10);
        }
        // 3. 比較並更新最大值
        if (currentConv > maxV) {
            maxV = currentConv;
            bestO = original;
        }
    }
    // 4. 輸出最終答案
    cout << "\nAns=" << maxV << " " << bestO << endl;

    return 0;
}
