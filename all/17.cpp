//存款複利率 
//模組化：將計算總金額的邏輯寫成 getVal 函式。

//格式化輸出：使用 <iomanip> 中的 setprecision(2) 來控制小數點位數。
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double getVal(double P, int n, double r) {
    double total = 0;
    for (int i = 0; i < n; i++)
        total = (total + P) * (1.0 + r);
    return total;
}

int main() {
    ifstream file("a.txt");
    double P, target, low = 0, high = 1, mid;
    int n;

    if (!(file >> P >> n >> target)) return 0;

    cout << fixed << setprecision(0) << P << "\n" << n << "\n" << target << endl;

    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2.0;
        if (getVal(P, n, mid) < target) low = mid;
        else high = mid;
    }

    cout << "Ans=" << setprecision(2) << mid * 100 << "%" << endl;
    return 0;
}
//不用函示
/*
int dPart = (int)((ans - iPart) * 100 + 0.5); // 加 0.5 後取整數 = 四捨五入
if (dPart >= 100) { iPart++; dPart = 0; }     // 處理進位（如 0.999 變 1.00）
if (dPart < 10) cout << "0";                  // 補零（確保 5.06% 不會印成 5.6%）*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("17.txt");
    double P, target, low = 0, high = 1, mid;
    int n;
    if (!(file >> P >> n >> target)) return 0;

    cout << P << "\n" << n << "\n" << target << endl;

    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2.0;
        double total = 0;
        for (int j = 0; j < n; j++) {
            total = (total + P) * (1.0 + mid);
        }
        if (total < target) low = mid;
        else high = mid;
    }

    double ans = mid * 100;
    int iPart = (int)ans;                  
    int dPart = (int)((ans - iPart) * 100 + 0.5);  
    if (dPart >= 100) {
        iPart++;
        dPart = 0;
    }
    cout << "Ans=" << iPart << ".";
    if (dPart < 10) cout << "0";
    cout << dPart << "%" << endl;

    return 0;
}
