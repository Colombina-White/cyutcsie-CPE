/*curSum (目前子陣列和)：
如果 前一個 curSum + 當前數字 比 當前數字 還小，代表前面的累計和已經變成「負債」，此時應捨棄前面，令 curSum = 當前數字。
maxSum (歷史最大總和)：
比較 maxSum 與 curSum，紀錄過程中出現過的最大值。*/
//連續整數和為最大值
/*資料預載：
使用 vector<int> nums 將檔案 e.txt 中的所有數字先存進記憶體。這樣做的好處是之後可以用索引（Index）反覆存取。
動態規劃計算：
curSum = max((long long)nums[i], curSum + nums[i]);
這一行是取「自己」或「自己+前面的總和」兩者中的較大值。*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("e.txt");
    vector<int> nums;
    int val;
    while (file >> val) nums.push_back(val);
    if (nums.empty()) return 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        cout << nums[i] << (i == n - 1 ? "" : " ");
    cout << endl;
    long long maxSum = nums[0], curSum = nums[0];
    for (int i = 1; i < n; i++) {
        curSum = max((long long)nums[i], curSum + nums[i]);
        maxSum = max(maxSum, curSum);
    }
    cout << "Ans=" << maxSum << endl;
    return 0;
}
//不用函示
/*
直接透過 while (f >> val) 讀取一個數字就處理一個數字。
if (val > curSum + val) curSum = val;
這行取代了 max() 函式，功能完全相同：如果當前數字 val 獨自一人都比加上先前的總和還大，就重置 curSum。
利用 first 變數來控制空白輸出的位置，確保數字之間有空白但結尾沒有多餘空白。*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("e.txt");
    int val, first = 1;
    long long maxSum, curSum;

    while (f >> val) {
        if (!first) cout << " ";
        cout << val;

        if (first) {
            maxSum = curSum = val;
            first = 0;
        } else {
            if (val > curSum + val) curSum = val;
            else curSum += val;
            if (curSum > maxSum) maxSum = curSum;
        }
    }

    if (first) return 0;
    cout << "\nAns=" << maxSum << endl;
    return 0;
}
