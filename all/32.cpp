//星號字元的長方形 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void printLine(int n) {
    for (int i = 0; i < n; i++) cout << "*";
    cout << endl;
}

int main() {
    ifstream f("e.txt");
    string line, word;
    if (!getline(f, line)) return 0;

    cout << line << endl;

    stringstream ss(line);
    vector<string> v;
    int maxL = 0;
    while (ss >> word) {
        v.push_back(word);
        if ((int)word.length() > maxL) maxL = word.length();
    }

    printLine(maxL + 2);

    for (int i = 0; i < (int)v.size(); i++) {
        cout << "*" << v[i];
        for (int j = 0; j < (maxL - (int)v[i].length()); j++) cout << " ";
        cout << "*" << endl;
    }

    printLine(maxL + 2);

    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("32.txt");
    char words[100][100]; // 儲存單字的陣列
    int wordLens[100];    // 儲存每個單字長度的陣列
    int count = 0, maxL = 0;

    // 1. 讀取所有單字並找出最長長度
    // 利用 f >> words[count] 直接讀取空白分隔的字串
    while (f >> words[count]) {
        // 手動計算字串長度 (不使用 strlen)
        int len = 0;
        while (words[count][len] != '\0') {
            len++;
        }
        wordLens[count] = len;

        // 更新最大長度
        if (len > maxL) maxL = len;
        
        count++;
        // 檢查是否換行，若換行則停止讀取 (配合題目邏輯)
        while (f.peek() == ' ') f.ignore();
        if (f.peek() == '\n' || f.peek() == '\r' || f.peek() == EOF) break;
    }

    // 2. 印出原始單字行
    for (int i = 0; i < count; i++) {
        cout << words[i] << (i == count - 1 ? "" : " ");
    }
    cout << endl;

    // 3. 印出上邊框 (maxL + 2 個星號)
    for (int i = 0; i < maxL + 2; i++) cout << "*";
    cout << endl;

    // 4. 印出中間內容
    for (int i = 0; i < count; i++) {
        cout << "*";
        // 印出單字
        for (int j = 0; j < wordLens[i]; j++) cout << words[i][j];
        // 補空白 (最長長度 - 目前單字長度)
        for (int j = 0; j < (maxL - wordLens[i]); j++) cout << " ";
        cout << "*" << endl;
    }

    // 5. 印出下邊框
    for (int i = 0; i < maxL + 2; i++) cout << "*";
    cout << endl;

    return 0;
}
