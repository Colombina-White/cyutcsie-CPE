//圓周率的無窮乘積計算式
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isP(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ifstream f("c.txt");
    int n, curr = 3;
    if (!(f >> n)) return 0;

    cout << n << endl;

    vector<int> num, den;

    while ((int)num.size() < n) {
        if (isP(curr)) {
            num.push_back(curr);
            den.push_back((curr - 1) % 4 != 0 ? curr - 1 : curr + 1);
        }
        curr++;
    }

    for (int k = 0; k < 2; k++) {
        cout << "Ans=";
        vector<int>& target = (k == 0 ? num : den);
        for (int i = 0; i < n; i++)
            cout << target[i] << (i == n - 1 ? "" : "*");
        cout << endl;
    }

    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("24.txt");
    int n, curr = 3;
    // 1. 讀取與印出 n
    if (!(f >> n)) return 0;
    cout << n << endl;
    // 2. 使用傳統陣列代替 vector
    int num[1000], den[1000];
    int count = 0;
    // 3. 尋找質數並計算分子分母
    while (count < n) {
        // --- 原本 isP 函式的邏輯直接寫在這裡 ---
        bool isPrime = true;
        if (curr < 2) isPrime = false;
        else {
            for (int i = 2; i * i <= curr; i++) {
                if (curr % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            num[count] = curr;
            // 計算分母邏輯
            if ((curr - 1) % 4 != 0) {
                den[count] = curr - 1;
            } else {
                den[count] = curr + 1;
            }
            count++;
        }
        curr++;
    }
    // 4. 印出分子 (num)
    cout << "Ans=";
    for (int i = 0; i < n; i++) {
        cout << num[i] << (i == n - 1 ? "" : "*");
    }
    cout << endl;
    // 5. 印出分母 (den)
    cout << "Ans=";
    for (int i = 0; i < n; i++) {
        cout << den[i] << (i == n - 1 ? "" : "*");
    }
    cout << endl;

    return 0;
}
