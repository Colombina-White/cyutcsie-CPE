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
