//撲克牌配對 
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("e.txt");
    int n;
    if (!(file >> n)) return 0;

    int total = 2 * n;
    vector<int> cards(total);
    for (int i = 0; i < total; i++) file >> cards[i];
    file.close();

    cout << n << endl;
    for (int i = 0; i < total; i++) cout << cards[i] << (i == total - 1 ? "" : " ");
    cout << endl;

    vector<bool> paired(total, false), remembered(total, false);
    int totalFlips = 0, i = 0;

    while (i < total) {
        if (paired[i]) { i++; continue; }

        int mIdx = -1;
        for (int j = 0; j < total; j++) {
            if (remembered[j] && !paired[j] && cards[j] == cards[i] && j != i) {
                mIdx = j; break;
            }
        }

        if (mIdx != -1) {
            totalFlips += 2;
            paired[i] = paired[mIdx] = true;
            i++;
        } else {
            remembered[i] = true;
            int nIdx = -1;
            for (int j = i + 1; j < total; j++) {
                if (!paired[j]) { nIdx = j; break; }
            }

            if (nIdx != -1) {
                remembered[nIdx] = true;
                if (cards[i] == cards[nIdx]) {
                    totalFlips += 2;
                    paired[i] = paired[nIdx] = true;
                } else {
                    totalFlips += 4;
                }
                i = nIdx + 1;
            } else i++;
        }
    }

    for (int k = 0; k < total; k++) {
        if (paired[k]) continue;
        for (int m = k + 1; m < total; m++) {
            if (!paired[m] && cards[k] == cards[m]) {
                totalFlips += 2;
                paired[k] = paired[m] = true;
                break;
            }
        }
    }

    cout << "Ans=" << totalFlips << endl;
    return 0;
}
