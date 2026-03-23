#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream f("d.txt");
    string s;
    if (!(f >> s)) return 0;

    int n = s.length();
    vector<int> safe(n, 1);

    for (int i = 0; i < n; i++) {
        int dist = (s[i] == 'x' ? 1 : (s[i] == 'X' ? 2 : 0));
        if (dist > 0) {
            for (int j = i - dist; j <= i + dist; j++)
                if (j >= 0 && j < n) safe[j] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0' && safe[i]) ans++;

    cout << s << "\nAns=" << ans << endl;
    return 0;
}
