 //排序
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream f("b.txt");
    int mode, val;
    if (!(f >> mode)) return 0;

    string line;
    getline(f, line); 
    getline(f, line); 
    
    vector<int> v;
    stringstream ss(line);
    while (ss >> val) v.push_back(val);

    cout << mode << endl;
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << (i == (int)v.size() - 1 ? "" : " ");
    cout << endl;

    sort(v.begin(), v.end());
    if (mode == 1) reverse(v.begin(), v.end());

    cout << "Ans=";
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << (i == (int)v.size() - 1 ? "" : " ");
    cout << endl;

    return 0;
}
