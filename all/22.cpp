//猜數字
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream f("a.txt");
    string s1, s2;
    if (!(f >> s1 >> s2)) return 0;

    cout << s1 << "\n" << s2 << endl;

    int A = 0, B = 0;
    int n1 = s1.length(), n2 = s2.length();

    int count1[256] = {0}, count2[256] = {0};

    for (int i = 0; i < n1; i++) {
        if (i < n2 && s1[i] == s2[i]) {
            A++;
        } else {
            count1[(unsigned char)s1[i]]++;
            if (i < n2) count2[(unsigned char)s2[i]]++;
        }
    }
    
    for (int i = n1; i < n2; i++) count2[(unsigned char)s2[i]]++;

    for (int i = 0; i < 256; i++) {
        if (count1[i] > 0 && count2[i] > 0)
            B += (count1[i] < count2[i] ? count1[i] : count2[i]);
    }
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("22.txt");
    char s1[100], s2[100];
    // 1. 讀取與印出原始字串
    if (!(f >> s1 >> s2)) return 0;
    cout << s1 << "\n" << s2 << endl;
    int A = 0, B = 0;
    int c1[256] = {0}, c2[256] = {0};
    // 2. 一次迴圈處理 A 和 統計字元頻率
    // 直接用索引 j 走過 s1，直到遇到字串結尾 '\0'
    int j = 0;
    while (s1[j] != '\0') {
        if (s1[j] == s2[j]) {
            A++;
        } else {
            // 記錄沒對上的字元
            c1[(unsigned char)s1[j]]++;
            if (s2[j] != '\0') c2[(unsigned char)s2[j]]++;
        }
        j++;
    }
    // 如果 s2 比 s1 長，繼續統計 s2 剩下的字元
    while (s2[j] != '\0') {
        c2[(unsigned char)s2[j]]++;
        j++;
    }
    // 3. 計算 B (字元相同但位置不同)
    for (int i = 0; i < 256; i++) {
        if (c1[i] > 0 && c2[i] > 0) {
            // 手動取較小值，不呼叫 min 函式
            B += (c1[i] < c2[i] ? c1[i] : c2[i]);
        }
    }
    cout << "Ans=" << A << "A" << B << "B" << endl;

    return 0;
}
    cout << "Ans=" << A << "A" << B << "B" << endl;
    return 0;
}
