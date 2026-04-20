//輸出最小的子數列長度
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream f("e.txt");
    int n, m, k;
    if (!(f >> n >> m >> k)) return 0;

    cout << n << " " << m << " " << k << endl;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i <= 3) x[i] = i;
        else x[i] = (x[i-3] + x[i-2] + x[i-1]) % m + 1;
    }

    vector<int> cnt(k + 1, 0);
    int found = 0, ans = -1;

    for (int i = 1; i <= n; i++) {
        if (x[i] <= k && ++cnt[x[i]] == 1) {
            found++;
        }
        
        if (found == k) {
            ans = i;
            break;
        }
    }

    if (ans == -1) cout << "Ans=No" << endl;
    else cout << "Ans=" << ans << endl;

    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("21.txt");
    int n, m, k;
    // 讀取基礎參數：n(總長度), m(取模值), k(需要蒐集的目標數字)
    if (!(f >> n >> m >> k)) return 0;
    cout << n << " " << m << " " << k << endl;

    int x[100000], cnt[1000] = {0}; // 假設 n < 100000, k < 1000
    int found = 0, ans = -1;

    for (int i = 1; i <= n; i++) {
        // 1. 生成數列：前三項為 i，之後為前三項和 % m + 1
        if (i <= 3) x[i] = i;
        else x[i] = (x[i-3] + x[i-2] + x[i-1]) % m + 1;

        // 2. 統計是否包含 1~k 之間的數字
        if (x[i] <= k) {
            if (cnt[x[i]] == 0) found++; // 第一次發現該數字，計數+1
            cnt[x[i]]++;
        }

        // 3. 當蒐集齊全 1 到 k 時，記錄目前的長度並結束
        if (found == k) {
            ans = i;
            break;
        }
    }

    if (ans == -1) cout << "Ans=No" << endl;
    else cout << "Ans=" << ans << endl;

    return 0;
}
