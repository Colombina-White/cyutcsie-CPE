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
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("30.txt");
    int H, W;
    // 1. 讀取長寬
    if (!(f >> H >> W)) return 0;
    cout << H << " " << W << endl;
    // 2. 使用傳統二維陣列代替 vector<string>
    char g[100][100]; 
    for (int i = 0; i < H; i++) {
        f >> g[i];
        cout << g[i] << endl;
    }
    int maxL = 0;
    // 四個方向：右、下、右下、左下
    int dr[] = {0, 1, 1, 1};
    int dc[] = {1, 0, 1, -1};
    // 3. 尋找最長路徑
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            // 只從 '1' 開始計算
            if (g[r][c] != '1') continue;

            for (int d = 0; d < 4; d++) {
                int cnt = 0;
                int currR = r;
                int currC = c;

                // 往特定方向延伸，直到不是 '1' 或出界
                while (currR >= 0 && currR < H && currC >= 0 && currC < W && g[currR][currC] == '1') {
                    cnt++;
                    currR += dr[d];
                    currC += dc[d];
                }

                // 手動更新最大值
                if (cnt > maxL) {
                    maxL = cnt;
                }
            }
        }
    }

    cout << "Ans=" << maxL << endl;

    return 0;
}
    cout << "Ans=" << maxL << endl;
    return 0;
}
