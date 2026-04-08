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
