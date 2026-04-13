/*讀取第一個數字：先讀入 res 作為運算的起點。
迴圈讀取配對：每次讀取一個 op（運算子）和一個 next（下一個數字）。
執行運算：根據 op 的種類，將 res 與 next 進行計算。
終止條件：讀到 = 符號時停止運算。*/

//算術運算式
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("c.txt");
    string expr;
    if (!(file >> expr)) return 0;
    stringstream ss(expr);
    double res, next;
    char op;
    ss >> res;
    while (ss >> op && op != '=') {
        ss >> next;
        switch (op) {
            case '+': res += next; break;
            case '-': res -= next; break;
            case '*': res *= next; break;
            case '/': if (next != 0) res /= next; break;
        }
    }
    int finalRes = (int)(res + 0.5);
    cout << expr << finalRes << endl;
    return 0;
}
//不用函示
/*f >> res：這會跳過空白，讀取第一個浮點數。
f >> op：讀取一個字元（運算子）。
f >> next：緊接著讀取下一個浮點數。*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("c.txt");
    double res, next;
    char op;

    if (!(f >> res)) return 0;
    cout << res;
    while (f >> op) {
        cout << op; 
        if (op == '=') break;
        f >> next;
        cout << next; 
        if (op == '+') res += next;
        else if (op == '-') res -= next;
        else if (op == '*') res *= next;
        else if (op == '/' && next != 0) res /= next;
    }
    cout << (int)(res + 0.5) << endl;

    return 0;
}
