/*假設有一個英文小寫(‘a’~’z’)的字串S，長度最多為100，小明設計了一個編碼方式，
就是把連續相同字元的數量N串接在該字元的前面，並且N會以小寫的16進位來表示，
底下是一個實際編碼的例子: 
假設S=“cccccyyyyyyyyyyyyuttt” */

/*透過 ifstream 開啟 e.txt，並使用 getline 讀取整行字串。

使用 cout << hex;。告訴 C++ 之後所有輸出的整數都要轉化為 16進位（例如數字 12 會顯示為 c，15 顯示為 f）。

如果下一個字元與當前字元相同（s[i] == s[i+1]），則計數器 cnt 加 1。

如果不同，或是已經到達字串末尾，則執行輸出。

輸出目前的計數 cnt（此時會自動變 16 進位）與該字元 s[i]，然後將 cnt 重設為 1，開始下一輪計數。*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("e.txt");
    string s;
    if (!getline(file, s)) return 0;
    file.close();
    cout << s << "\nAns=";
    cout << hex; 
    int cnt = 1;
    for (int i = 0; i < (int)s.length(); i++) {
        if (i + 1 < (int)s.length() && s[i] == s[i+1]) {
            cnt++;
        } else {
            cout << cnt << s[i];
            cnt = 1;
        }
    }
    cout << endl;
    return 0;
}
