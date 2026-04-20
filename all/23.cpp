 //排序
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream f("b.txt");
    int mode, val;
    if (!(f >> mode)) return 0;

    string line;
    getline(f, line); 
    getline(f, line); 
    
    vector<int> v;
    stringstream ss(line);
    while (ss >> val) v.push_back(val);

    cout << mode << endl;
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << (i == (int)v.size() - 1 ? "" : " ");
    cout << endl;

    sort(v.begin(), v.end());
    if (mode == 1) reverse(v.begin(), v.end());

    cout << "Ans=";
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << (i == (int)v.size() - 1 ? "" : " ");
    cout << endl;

    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("23.txt");
    int mode, n = 0;
    int v[1000]; // 預設最大容量
    // 1. 讀取模式
    if (!(f >> mode)) return 0;
    // 2. 讀取數列：利用 peek 檢查換行，手動完成讀取
    int val;
    while (f >> val) {
        v[n++] = val;
        // 檢查下一個字元，如果是換行或檔案結尾就停
        while (f.peek() == ' ') f.ignore(); // 跳過空格
        if (f.peek() == '\n' || f.peek() == '\r' || f.peek() == EOF) break;
    }
    // 3. 印出原始資料
    cout << mode << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    // 4. 手動排序 (冒泡排序)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // mode == 0: 升序 (v[j] > v[j+1])
            // mode == 1: 降序 (v[j] < v[j+1])
            bool swapNeeded = false;
            if (mode == 0 && v[j] > v[j + 1]) swapNeeded = true;
            if (mode == 1 && v[j] < v[j + 1]) swapNeeded = true;

            if (swapNeeded) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    // 5. 輸出結果
    cout << "Ans=";
    for (int i = 0; i < n; i++) {
        cout << v[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
