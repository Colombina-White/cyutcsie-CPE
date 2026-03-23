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
