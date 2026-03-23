#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    ifstream f("e.txt");
    vector<double> v;
    string s;
    double sum = 0, varSum = 0;

    while (f >> s) {
        if (s.at(s.length() - 1) == ',') s.erase(s.length() - 1);
        double val = atof(s.c_str());
        v.push_back(val);
        sum += val;
        cout << val << (f.peek() == EOF ? "" : ", ");
    }
    cout << endl;

    int n = v.size();
    if (n == 0) return 0;

    double avg = sum / n;
    for (int i = 0; i < n; i++)
        varSum += pow(v[i] - avg, 2);

    double sigma = sqrt(varSum / n);

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (fabs(v[i] - avg) > sigma) ans++;

    cout << "Ans=" << ans << endl;
    return 0;
}
