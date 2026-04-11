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
        
        if (pos[next]) { // 如果這個數字的「位置」已經被標記過
            cout << "Ans=" << step - pos[next] + 1 << endl;
            break;
        }
        
        pos[next] = ++step; // 標記這個數字是在第幾步出現的
        n = next;
    }
    return 0;
}