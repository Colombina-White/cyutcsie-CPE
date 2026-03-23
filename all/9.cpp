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
