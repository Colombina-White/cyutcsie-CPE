#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("e.txt");
    int n, k, count = 0;

    if (!(file >> n >> k)) return 0;
    
    for (int i = 0; i <= n; i++) {
        int sum = 0, temp = i;
        
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        
        if (sum == k) count++;
    }

    cout << n << " " << k << "\nAns=" << count << endl;
    return 0;
}
