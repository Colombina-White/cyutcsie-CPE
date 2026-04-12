//質因數
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("a.txt");
    long long n, temp;
    if (!(file >> n)) return 0;
    temp = n;
    string res = "";
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            stringstream ss;
            ss << i << "(" << cnt << ")" << res;
            res = ss.str();
        }
    }
    if (n > 1) {
        stringstream ss;
        ss << n << "(1)" << res;
        res = ss.str();
    }
    cout << temp << "\nAns=" << res << endl;
    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

void factor(long long n, int i) {
    if (n == 1) return;
    while (i * i <= n && n % i != 0) i++;
    if (n % i == 0) {
        int cnt = 0;
        long long next_n = n;
        while (next_n % i == 0) {
            cnt++;
            next_n /= i;
        }
        factor(next_n, i + 1);
        cout << i << "(" << cnt << ")";
    } else {
        cout << n << "(1)";
    }
}

int main() {
    ifstream f("a.txt");
    long long n;
    if (!(f >> n)) return 0;
    cout << n << "\nAns=";
    factor(n, 2);
    cout << endl;
    return 0;
}
