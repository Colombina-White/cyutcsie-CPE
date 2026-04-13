//Cyut54is a356good 72school 
//Ne125ver 56give22 66up
/*isdigit(line[i])：判斷字元是否為數字。
temp += line[i]：將數字字元拼接到一個字串 temp 中。
atoll(temp.c_str())：
c_str()：將 C++ string 轉回傳統的 C 語言字元陣列 (char*)。
atoll：將字串轉換為 long long 型別的整數。
vector<string> allLines：先把每一行存起來，最後才一次輸出原本的內容。*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    ifstream file("d.txt");
    if (!file) return 0;
    string line;
    long long totalSum = 0;
    vector<string> allLines;
    while (getline(file, line)) {
        allLines.push_back(line);
        string temp = "";
        for (int i = 0; i < (int)line.length(); i++) {
            if (isdigit(line[i])) {
                temp += line[i];
            } else if (!temp.empty()) {
                totalSum += atoll(temp.c_str()); 
                temp = "";
            }
        }
        if (!temp.empty()) totalSum += atoll(temp.c_str());
    }
    for (int i = 0; i < (int)allLines.size(); i++) {
        cout << allLines[i] << endl;
    }
    cout << "Ans=" << totalSum << endl;

    return 0;
}
//不用函示
/*f.get(c)：這會讀取包含空白、換行在內的每一個字元。
數值組裝公式：
num = num * 10 + (c - '0');
這行取代了 atoll。例如讀到 '5' 然後讀到 '4'：
第一步：num = 0 * 10 + 5 = 5
第二步：num = 5 * 10 + 4 = 54
has_num 旗標：
用來判斷「目前是否真的有讀到數字」。這可以防止連續遇到多個非數字字元時，重複把 0 加入總和。*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("d.txt");
    if (!f) return 0;
    char c;
    long long total = 0, num = 0;
    bool has_num = false;

    while (f.get(c)) {
        cout << c; 

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            has_num = true;
        } else {
            if (has_num) {
                total += num;
                num = 0;
                has_num = false;
            }
        }
    }
    if (has_num) total += num;

    cout << "\nAns=" << total << endl;

    return 0;
}
