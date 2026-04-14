//中值濾波演算法
/*動態存儲：使用 vector<int> 存儲原始數據 nums 與結果 res。
快速排序：使用 std::sort(win.begin(), win.end())。這在視窗很大時效率較好。
中值選取：直接透過索引 win[k / 2] 取得。
例如 k=3，索引為 3/2 = 1（第 2 個數）。
例如 k=5，索引為 5/2 = 2（第 3 個數）。*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("e.txt");
    vector<int> nums, res;
    int val, k = 3;

    while (file >> val) {
        nums.push_back(val);
        if (file.peek() == '\n') break; 
    }
    if (!(file >> k)) k = 3;

    int n = nums.size();
    for (int i = 0; i < n; i++)
        cout << nums[i] << (i == n - 1 ? "" : " ");
    cout << "\n" << k << endl;

    for (int i = 0; i <= n - k; i++) {
        vector<int> win;
        for (int j = 0; j < k; j++) win.push_back(nums[i + j]);
        
        sort(win.begin(), win.end());
        res.push_back(win[k / 2]);
    }

    cout << "Ans=";
    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << (i == (int)res.size() - 1 ? "" : " ");
    cout << endl;

    return 0;
}
//不用函示
/*
    氣泡排序 
    for (int x = 0; x < k - 1; x++) {
        for (int y = 0; y < k - x - 1; y++) {
            if (win[y] > win[y + 1]) { // 交換邏輯 }
        }
    }
這是在不使用 std::sort 的情況下，最簡單直覺的排序方法，適合處理 k 值較小的情況。
靜態陣列：使用固定大小的 nums[1000] 與 win[100]。*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("18.txt");
    int nums[1000];
    int res[1000];
    int n = 0, k = 3, val;

    while (file >> val) {
        nums[n++] = val;
        if (file.peek() == '\n' || file.peek() == '\r') break;
    }
    if (!(file >> k)) k = 3;
    for (int i = 0; i < n; i++) {
        cout << nums[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n" << k << endl;

    int resCount = 0;
    for (int i = 0; i <= n - k; i++) {
        int win[100];
        for (int j = 0; j < k; j++) {
            win[j] = nums[i + j];
        }
        for (int x = 0; x < k - 1; x++) {
            for (int y = 0; y < k - x - 1; y++) {
                if (win[y] > win[y + 1]) {
                    int temp = win[y];
                    win[y] = win[y + 1];
                    win[y + 1] = temp;
                }
            }
        }
        res[resCount++] = win[k / 2];
    }
    cout << "Ans=";
    for (int i = 0; i < resCount; i++) {
        cout << res[i] << (i == resCount - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
