#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("e.txt");
    int A, B, H, F;

    if (!(f >> A >> B >> H >> F)) return 0;

    cout << A << " " << B << " " << H << " " << F << endl;

    int num = F - B * H;
    int den = A - B;

    if (den != 0 && num % den == 0) {
        int x = num / den;
        int y = H - x;

        if (x >= 0 && y >= 0) {
            cout << "Ans=" << x << " " << y << endl;
            return 0;
        }
    }

    cout << "Ans=No Solution" << endl;
    return 0;
}
