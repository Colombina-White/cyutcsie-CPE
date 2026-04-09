//部分序列字串指原字串中刪掉一個以上字元且不改變原順序的部份字串。 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream f("d.txt");
    string s1, s2, del = "";
    if (!(f >> s1 >> s2)) return 0;

    cout << s1 << " " << s2 << endl;

    size_t i = 0;
    for (size_t j = 0; j < s2.length(); ++j) {
        if (i < s1.length() && s1[i] == s2[j]) {
            i++;
        } else {
            del += s2[j]; 
        }
    }

    if (i == s1.length()) 
        cout << "Ans=Yes " << del << endl;
    else 
        cout << "Ans=No" << endl;

    return 0;
}
