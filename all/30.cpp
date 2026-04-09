//二維陣列，然後輸出最長的一條路。 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream f("e.txt");
    int H, W;
    if (!(f >> H >> W)) return 0;

    vector<string> g(H);
    for (int i = 0; i < H; i++) f >> g[i];

    cout << H << " " << W << endl;
    for (int i = 0; i < H; i++) cout << g[i] << endl;

    int maxL = 0;
    int dr[] = {0, 1, 1, 1};
    int dc[] = {1, 0, 1, -1};

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (g[r][c] != '1') continue;

            for (int d = 0; d < 4; d++) {
                int cnt = 0, currR = r, currC = c;

                while (currR >= 0 && currR < H && currC >= 0 && currC < W && g[currR][currC] == '1') {
                    cnt++;
                    currR += dr[d];
                    currC += dc[d];
                }
                if (cnt > maxL) maxL = cnt;
            }
        }
    }

    cout << "Ans=" << maxL << endl;
    return 0;
}
