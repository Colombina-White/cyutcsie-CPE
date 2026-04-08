//連續整數和為最大值
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
