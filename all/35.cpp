#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("e.txt");
    int n, next, step = 0, history[1000] = {0}, pos[1000] = {0};
    if (!(f >> n)) return 0;
    cout << n << endl;
    while (true) {
        next = 0;
        for (int t = n; t > 0; t /= 10) next += (t % 10) * (t % 10);
        if (next == 1) { cout << "Ans=1" << endl; break; }
        if (pos[next]) {
            cout << "Ans=" << step - pos[next] + 1 << endl;
            break;
        }
        pos[next] = ++step;
        n = next;
    }
    return 0;
}
