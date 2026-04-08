/*假設有一個英文小寫(‘a’~’z’)的字串S，長度最多為100，小明設計了一個編碼方式，
就是把連續相同字元的數量N串接在該字元的前面，並且N會以小寫的16進位來表示，
底下是一個實際編碼的例子: 
假設S=“cccccyyyyyyyyyyyyuttt” */
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
