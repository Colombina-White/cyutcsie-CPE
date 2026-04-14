/*字母映射表 (getLetterVal)
int vals[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
字母對應並非單純的 ASCII 順序。例如：

A 索引為 0，對應 10

I 索引為 8，對應 34

O 索引為 14，對應 35

加權迴圈

for (int i = 1; i <= 8; i++) {
    sum += (id[i] - '0') * (9 - i);
}
這裡 (id[i] - '0') 是將字元（例如 '5'）轉換為真正的數字（5）。迴圈範圍從 1 到 8（即身分證第 2 到第 9 碼）。

檢查碼的輸出

cout << "Ans=" << id << checkNum << endl;
程式最後將原始輸入的 9 碼與計算出來的檢查碼 checkNum 拼接在一起輸出，形成完整的 10 碼身分證字號。*/
//身份證號碼
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getLetterVal(char c) {
    int vals[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
    return vals[c - 'A'];
}

int main() {
    ifstream file("c.txt");
    string id;
    if (!(file >> id)) return 0;
    file.close();

    cout << id << endl;

    int n = getLetterVal(id[0]);//英文字
    int sum = (n / 10) + (n % 10) * 9;//英文轉的數字

    for (int i = 1; i <= 8; i++) {
        sum += (id[i] - '0') * (9 - i);//加權累加
    }

    int checkNum = (10 - (sum % 10)) % 10;//計算檢查碼

    cout << "Ans=" << id << checkNum << endl;

    return 0;
}
