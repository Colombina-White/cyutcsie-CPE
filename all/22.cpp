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

    cout << "Ans=" << A << "A" << B << "B" << endl;
    return 0;
}
