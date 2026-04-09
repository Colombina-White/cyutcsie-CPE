//中值濾波演算法
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
