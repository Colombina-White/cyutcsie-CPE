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
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("34.txt");
    int n;
    if (!(file >> n)) return 0;

    int total = 2 * n;
    int cards[100];      // 儲存卡片數值
    bool paired[100];    // 紀錄是否已配對
    bool remembered[100]; // 紀錄是否已翻開看過

    // 1. 初始化與讀取資料
    for (int i = 0; i < total; i++) {
        file >> cards[i];
        paired[i] = false;
        remembered[i] = false;
    }

    // 印出原始資料
    cout << n << endl;
    for (int i = 0; i < total; i++) {
        cout << cards[i] << (i == total - 1 ? "" : " ");
    }
    cout << endl;

    int totalFlips = 0;
    int i = 0;

    // 2. 模擬遊戲流程
    while (i < total) {
        // 如果這張牌已經配對過，跳過
        if (paired[i]) {
            i++;
            continue;
        }

        // 翻開第一張牌 i
        int mIdx = -1;
        // 檢查記憶中是否有跟 i 一樣的牌且還沒配對
        for (int j = 0; j < total; j++) {
            if (remembered[j] && !paired[j] && cards[j] == cards[i] && j != i) {
                mIdx = j;
                break;
            }
        }

        if (mIdx != -1) {
            // 記憶中有配對：翻開 i 和 mIdx，花費 2 次，完成配對
            totalFlips += 2;
            paired[i] = true;
            paired[mIdx] = true;
            i++;
        } else {
            // 記憶中沒有：翻開 i (記入記憶)
            remembered[i] = true;
            
            // 尋找下一張還沒配對的牌 nIdx
            int nIdx = -1;
            for (int j = i + 1; j < total; j++) {
                if (!paired[j]) {
                    nIdx = j;
                    break;
                }
            }

            if (nIdx != -1) {
                // 翻開第二張牌 nIdx (記入記憶)
                remembered[nIdx] = true;
                if (cards[i] == cards[nIdx]) {
                    // 運氣好直接配對成功：花費 2 次
                    totalFlips += 2;
                    paired[i] = true;
                    paired[nIdx] = true;
                } else {
                    // 配對失敗：翻了兩張不同的牌，花費 4 次 (翻開再翻回去)
                    totalFlips += 4;
                }
                i = nIdx + 1;
            } else {
                i++;
            }
        }
    }

    // 3. 處理最後可能剩下的配對 (雖然理論上 while 已處理完畢，保留此邏輯確保完整性)
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

    // 4. 輸出最終總翻牌次數
    cout << "Ans=" << totalFlips << endl;

    return 0;
}
