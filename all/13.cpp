#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    ifstream f("b.txt");
    string s, part;
    int len;

    if (!(f >> s >> len)) return 0;
    cout << s << "\n" << len << endl;

    long long sum = 0;
    for (int i = 0; i < (int)s.length(); i += len) {
        part = s.substr(i, len);
        
        sum += (long long)atof(part.c_str());
    }

    cout << "Ans=" << sum << endl;
    return 0;
}
