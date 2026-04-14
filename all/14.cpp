//異常值
/*逗號處理：
if (s.at(s.length() - 1) == ',') s.erase(s.length() - 1);
將數據讀取為字串，檢查最後一個字元是否為逗號，若是則移除。這讓它能處理 1.2, 3.4, 5.6 這種格式。

使用 pow(x, 2) 計算平方，使用 sqrt(x) 計算平方根，使用 fabs(x) 取絕對值。

動態存儲：使用 vector<double>，不需要預設資料筆數。*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    ifstream f("e.txt");
    vector<double> v;
    string s;
    double sum = 0, varSum = 0;

    while (f >> s) {
        if (s.at(s.length() - 1) == ',') s.erase(s.length() - 1);
        double val = atof(s.c_str());
        v.push_back(val);
        sum += val;
        cout << val << (f.peek() == EOF ? "" : ", ");
    }
    cout << endl;

    int n = v.size();
    if (n == 0) return 0;

    double avg = sum / n;
    for (int i = 0; i < n; i++)
        varSum += pow(v[i] - avg, 2);

    double sigma = sqrt(varSum / n);

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (fabs(v[i] - avg) > sigma) ans++;

    cout << "Ans=" << ans << endl;
    return 0;
}
//不用函示
/*流處理優化：
if (f.peek() == ',') { f.ignore(); }
它利用 f.ignore() 直接跳過檔案中的逗號。
避開開根號運算：
判定異常時，比較的是「離差平方」與「變異數」：diff * diff > sigmaSquared。
在數學上，a > b <=> a^2 > b^2$（當 a, b >= 0）。*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("14.txt");
    double v[1000]; 
    double val, sum = 0;
    int n = 0;
    while (f >> val) {
        v[n++] = val;
        sum += val;
        
        cout << val;
        
        if (f.peek() == ',') {
            cout << ", ";
            f.ignore();
        }
    }
    cout << endl;
    if (n == 0) return 0;

    double avg = sum / n;
    double varSum = 0;
    for (int i = 0; i < n; i++) {
        double diff = v[i] - avg;
        varSum += diff * diff;
    }
    double sigmaSquared = varSum / n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        double diff = v[i] - avg;
        if (diff * diff > sigmaSquared) {
            ans++;
        }
    }

    cout << "Ans=" << ans << endl;
    return 0;
}
