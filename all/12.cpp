/*
A.尋找模反元素 
int yi = 1;
while ((Mi * yi) % p[i] != 1) yi++;
使用暴力搜尋法來找 yi。優點：邏輯極其簡單，不需額外寫「擴展歐幾里得算法」。
限制：如果 pi 非常大（例如大於 10^7），這個 while 迴圈會跑很久。
B. 防止溢位兩段程式碼都使用了 long long 來宣告變數 N 和 X。這是必要的，因為 N 是所有除數的乘積，極容易超過 int 的範圍（約 21 億）。
C. 第一段 vs 第二段 的差異
第一段 ：使用 vector<int> p, r：不需要預設大小，能處理任意數量的方程。
使用 p.empty() 進行空防禦。
第二段 ：使用 int p[100], r[100]：預留了 100 個空間，適用於已知資料量不大的情況。
使用 n 來手動追蹤目前讀入了多少筆資料。*/
//中國餘數定理
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream f("e.txt");
    vector<int> p, r;
    int v1, v2;
    while (f >> v1 >> v2) {
        p.push_back(v1); r.push_back(v2);
        cout << v1 << " " << v2 << " ";
    }
    cout << endl;
    if (p.empty()) return 0;
    long long N = 1, X = 0;
    for (int i = 0; i < (int)p.size(); i++) N *= p[i];
    for (int i = 0; i < (int)p.size(); i++) {
        long long Mi = N / p[i];
        int yi = 1;
        while ((Mi * yi) % p[i] != 1) yi++;
        
        X += Mi * yi * r[i];
    }
    cout << "Ans=" << X % N << endl;
    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("12.txt");
    int p[100], r[100]; 
    int n = 0;         
    while (f >> p[n] >> r[n]) {
        cout << p[n] << " " << r[n] << " ";
        n++;
    }
    cout << endl;
    if (n == 0) return 0;
    long long N = 1;
    for (int i = 0; i < n; i++) {
        N *= p[i];
    }
    long long X = 0;
    for (int i = 0; i < n; i++) {
        long long Mi = N / p[i];
        int yi = 1;
        while ((Mi * yi) % p[i] != 1) {
            yi++;
        }
        X += Mi * yi * r[i];
    }
    cout << "Ans=" << X % N << endl;

    return 0;
}
