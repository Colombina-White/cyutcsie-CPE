//保齡球運動的計分方式 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int getS(char c, int prev = 0) {
    if (c == 'X') return 10;
    if (c == '/') return 10 - prev;
    return (c >= '0' && c <= '9') ? c - '0' : 0;
}

int main() {
    ifstream f("e.txt");
    int groups;
    if (!(f >> groups)) return 0;

    cout << groups << endl;
    string line;
    getline(f, line); 

    vector<string> results;
    while (groups--) {
        if (!getline(f, line) || line.empty()) break;
        cout << line << endl;

        stringstream ss(line);
        vector<char> m;
        char c;
        while (ss >> c) m.push_back(c);

        int score = 0;
        bool fail = false;
        int n = m.size();

        for (int i = 0; i < n; i++) {
            if (m[i] == 'X') { 
                if (i + 2 < n) {
                    int b1 = getS(m[i+1]);
                    int b2 = (m[i+2] == '/') ? getS('/', b1) : getS(m[i+2]);
                    score += 10 + b1 + b2;
                } else { fail = true; break; }
            } else if (m[i] == '/') {
                if (i + 1 < n) {
                    score += getS('/', getS(m[i-1])) + getS(m[i+1]);
                } else { fail = true; break; }
            } else {
                score += getS(m[i]);
            }
        }

        if (fail) results.push_back("Unknown");
        else {
            ostringstream oss;
            oss << score;
            results.push_back(oss.str());
        }
    }

    cout << "Ans=";
    for (int i = 0; i < (int)results.size(); i++)
        cout << results[i] << (i == (int)results.size() - 1 ? "" : " ");
    cout << endl;

    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("29.txt");
    int groups;
    if (!(f >> groups)) return 0;

    cout << groups << endl;

    // 儲存每一組結果的整數陣列
    int resScores[100];
    bool resFail[100];
    int count = 0;

    // 跳過第一行後的換行符
    while (f.peek() == '\n' || f.peek() == '\r') f.ignore();

    for (int g = 0; g < groups; g++) {
        char m[50]; // 儲存該組的投球紀錄
        int n = 0;
        char c;
        // 手動讀取一行中的所有字元直到換行 (取代 getline + stringstream)
        while (f.get(c) && c != '\n' && c != '\r') {
            if (c != ' ') {
                m[n++] = c;
            }
        }
        // 印出原始內容
        for (int i = 0; i < n; i++) cout << m[i] << (i == n - 1 ? "" : " ");
        cout << endl;
        int score = 0;
        bool fail = false;
        for (int i = 0; i < n; i++) {
            if (m[i] == 'X') { // 全倒
                if (i + 2 < n) {
                    // 計算接下來兩球的分數 (手動取代 getS)
                    int b1 = (m[i+1] == 'X') ? 10 : (m[i+1] - '0');
                    int b2;
                    if (m[i+2] == 'X') b2 = 10;
                    else if (m[i+2] == '/') b2 = 10 - b1;
                    else b2 = m[i+2] - '0';
                    
                    score += 10 + b1 + b2;
                } else { fail = true; break; }
            } 
            else if (m[i] == '/') { // 補中
                if (i + 1 < n) {
                    int prev = m[i-1] - '0';
                    int next = (m[i+1] == 'X') ? 10 : (m[i+1] - '0');
                    score += (10 - prev) + next;
                } else { fail = true; break; }
            } 
            else { // 普通數字球
                score += (m[i] - '0');
            }
        }
        resScores[count] = score;
        resFail[count] = fail;
        count++;

        // 處理 Windows/Unix 換行符
        if (f.peek() == '\n' || f.peek() == '\r') f.ignore();
    }
    // 輸出最後結果
    cout << "Ans=";
    for (int i = 0; i < count; i++) {
        if (resFail[i]) cout << "Unknown";
        else cout << resScores[i];
        
        if (i < count - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
