/*內插法：為了擴大數值的數量，內插是常見的作法，通常需要增加數值的位置，就以該
位置前一個數值與該位置的數值，計算平均並取四捨五入後插入，舉例來說，假設一串
數值如下： 
3 2 5 7 8 1 
內插間隔為2，表示每2個數值之後插入1個數值，所以插入的過程如下： 
第1個插入位置為3，所以插入位置數值5與前一個位置數值2，取平均後得到4 
第2個插入位置為5，所以插入位置數值8與前一個位置數值7，取平均後得到8 
第3個插入位置為7，沒有數值，所以內插動作結束。 
插入後的結果為： 
3 2 4 5 7 8 8 1*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("e.txt");
    string line;
    vector<int> nums, res;
    int k, val;
    if (getline(file, line)) {
        stringstream ss(line);
        while (ss >> val) nums.push_back(val);
    }
    if (!(file >> k)) k = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        cout << nums[i] << (i == n - 1 ? "" : " ");
    cout << "\n" << k << endl;
    if (n > 0 && k > 0) {
        for (int i = 0; i < n; i++) {
            if (i > 0 && i % k == 0) {
                res.push_back((nums[i-1] + nums[i] + 1) / 2);
            }
            res.push_back(nums[i]);
        }
    } else {
        res = nums;
    }
    cout << "Ans=";
    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << (i == (int)res.size() - 1 ? "" : " ");
    cout << endl;

    return 0;
}
//不用函示
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("9.txt");
    int val, k, prev, count = 0;
    bool first = true;
    while (f >> val) {
        break; 
    }
    
    int nums[1000], n = 0;
    f.clear(); f.seekg(0); 
    
    while (f.peek() != '\n' && f >> val) {
        nums[n++] = val;
        cout << val << (f.peek() == '\n' ? "" : " ");
    }
    
    if (!(f >> k)) k = 0;
    cout << "\n" << k << "\nAns=";

    for (int i = 0; i < n; i++) {
        if (k > 0 && i > 0 && i % k == 0) {
            cout << (nums[i-1] + nums[i] + 1) / 2 << " ";
        }
        cout << nums[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
