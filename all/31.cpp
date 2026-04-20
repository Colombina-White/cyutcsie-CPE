//卡片號碼是否造假 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int luhnVal(int n, bool doubleIt) {
    if (!doubleIt) return n;
    n *= 2;
    return (n > 9) ? (n - 9) : n;
}

int main() {
    ifstream f("e.txt");
    int n;
    if (!(f >> n)) return 0;

    cout << n << endl;
    string line;
    getline(f, line); 

    vector<string> res;
    while (n--) {
        if (!getline(f, line) || line.empty()) { n++; continue; }
        cout << line << endl;

        stringstream ss(line);
        vector<int> card;
        int num, sum = 0;
        while (ss >> num) card.push_back(num);

        bool doubleIt = false;
        for (int i = (int)card.size() - 1; i >= 0; i--) {
            sum += luhnVal(card[i], doubleIt);
            doubleIt = !doubleIt;
        }

        res.push_back((sum % 10 == 0) ? "valid" : "invalid");
    }

    cout << "Ans=";
    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << (i == (int)res.size() - 1 ? "" : " ");
    cout << endl;

    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("31.txt");
    int n;
    if (!(f >> n)) return 0;
    cout << n << endl;
    // 用來儲存每組卡號檢查結果的「字串指標陣列」
    const char* results[100];
    int resCount = 0;
    for (int g = 0; g < n; g++) {
        int card[50]; // 儲存單組卡號的數字
        int len = 0;
        int num;
        // 讀取一組數字，直到換行或檔案結束
        // 利用 peek 判斷是否還有數字要讀取
        while (f >> num) {
            card[len++] = num;
            // 如果下一個字元是換行，代表這組卡號讀完了
            while (f.peek() == ' ') f.ignore();
            if (f.peek() == '\n' || f.peek() == '\r' || f.peek() == EOF) break;
        }
        // 印出原始內容
        for (int i = 0; i < len; i++) {
            cout << card[i] << (i == len - 1 ? "" : " ");
        }
        cout << endl;
        // --- Luhn 演算法核心邏輯 (取代函式) ---
        int sum = 0;
        bool doubleIt = false;
        // 從最後一個數字往前計算
        for (int i = len - 1; i >= 0; i--) {
            int val = card[i];
            if (doubleIt) {
                val *= 2;
                if (val > 9) val -= 9;
            }
            sum += val;
            doubleIt = !doubleIt; // 交替翻倍
        }
        // 儲存結果
        if (sum % 10 == 0) results[resCount++] = "valid";
        else results[resCount++] = "invalid";
    }
    // 輸出最後結果
    cout << "Ans=";
    for (int i = 0; i < resCount; i++) {
        cout << results[i] << (i == resCount - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
